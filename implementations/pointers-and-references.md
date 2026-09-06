# Pointers & References: C vs C++

Notes on passing arguments, when to use pointers vs references, and why C++
added references at all. Written while building `shipthatcode/minheap`.

---

## The root fact

**C is pass-by-value, always, with no exceptions.** Every argument is copied
into the function.

A pointer does not change that rule — the *pointer itself* is copied. What you
gain is that a copy of an address still refers to the same original object. So
"pass by reference in C" is really "pass a copy of an address."

**C has no references.** `&` in a C++ parameter list is a C++ feature. In C you
simulate it with pointers. Keep these separate: in `dll.c` it's `Node *n`, in
`minheap.tpp` it's `const T &v`.

---

## Part 1 — What pointers are for (C)

### 1. Modifying a caller's argument

```c
void bad(int x)   { x = 42; }   // modifies a copy; caller unaffected
void good(int *x) { *x = 42; }  // modifies what x points at

int n = 0;
good(&n);                        // n is now 42
```

The `&` at the call site is the visible signal that `n` may change. C has no way
to hide it (unlike C++ references).

This is also how C returns **multiple values**, since a function returns only
one thing. The dominant idiom — return code carries the error, out-param
carries the value:

```c
int parse(const char *s, int *out);   // 0 = success, result written to *out
```

### 2. Strings and arrays

Deeper than "we pass strings by pointer": **in C you cannot pass an array by
value at all.** Arrays *decay* into a pointer to their first element.

```c
void f(char s[]);   // these two are
void f(char *s);    // literally the same declaration
```

A C string isn't a type — it's a convention: a `char *` to a sequence ending in
`\0`. No length is stored anywhere. That's why `strlen` walks memory hunting for
the terminator, and why buffer overruns are C's signature bug.

Consequence to internalize: **`sizeof` inside the function gives the pointer
size, not the array size.** Hence nearly every C function taking an array also
takes a length:

```c
void process(int *arr, size_t n);
```

### 3. Dynamic memory (`malloc` suite)

`malloc` returns `void *` — an address to memory the compiler knows nothing
about. It must be a pointer: the size isn't known at compile time and you
control the lifetime manually.

```c
int *arr = malloc(n * sizeof(int));
if (!arr) return -1;   // malloc can fail — always check
free(arr);
arr = NULL;            // avoids use-after-free / double-free
```

Where C's danger concentrates: leaks, double-frees, use-after-free, dangling
pointers. This is exactly what `std::vector` eliminates — `data_` in `MinHeap`
allocates and frees itself, which is why `minheap.tpp` contains no memory
management code.

### 4. Self-referential data structures

A node can't *contain* another node (infinitely sized), so it holds an address:

```c
struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
```

Every non-contiguous structure — lists, trees, graphs, hash chains — exists only
because pointers do. `NULL` marks the ends.

> Note: a binary heap needs **no** pointers. It's a tree stored in a flat array,
> with index arithmetic (`2i+1`, `2i+2`) replacing the links. That's precisely
> why heaps are cache-friendly.

### 5. Avoiding copies of large structs

```c
void print(const struct BigThing *b);   // copies 8 bytes
void print(struct BigThing b);          // copies the whole struct
```

`const` here means "I won't write through this pointer" — the direct C ancestor
of C++'s `const T &`.

### 6. Function pointers

Passing behavior as data; C's callback / lambda:

```c
void qsort(void *base, size_t n, size_t size,
           int (*cmp)(const void *, const void *));
```

### 7. Generic programming via `void *`

`void *` holds any object address, and is C's only route to a container working
across types. Look at `qsort` above and note what it costs:

- no type safety (nothing stops you passing a wrong-typed comparator)
- an explicit `size` parameter
- an indirect function call per comparison

**This is the single best argument for C++ templates.** `MinHeap<T>` gets
compile-time type checking and inlined comparisons; `qsort` gets neither.

### Mental model

A pointer is **an integer that happens to be a memory address**, plus a type
telling the compiler how to interpret what's there and how far `p + 1` moves:

```c
int  *p;   p + 1   // advances 4 bytes
char *c;   c + 1   // advances 1 byte
```

---

## Part 2 — References (C++)

Mechanically, a reference compiles to the same address-passing a pointer does.
The difference is entirely in **what the type system lets you express and what
it prevents.**

```cpp
void push(const T *value);   // pointer
void push(const T &value);   // reference
```

```cpp
h.push(&x);                  // caller must remember &
if (value == nullptr) ...    // callee must check
data_.push_back(*value);     // callee must deref
```
vs.
```cpp
h.push(x);
data_.push_back(value);
```

### What references buy you

- **Cannot be null.** The big one. A `const T *` parameter has an extra state —
  "no object" — so every function taking one either checks for null or carries a
  latent crash. A `const T &` is guaranteed to refer to a real object. The
  failure mode is gone at compile time rather than defended against at runtime.
- **Cannot be reseated.** Once bound, always the same object. A pointer
  parameter can be accidentally reassigned mid-function, silently redirecting
  the rest of the code.
- **No dereference noise.** `value`, not `*value`. Not cosmetic: with pointers,
  `value == other` compares *addresses* while `*value == *other` compares
  *values* — and both compile.
- **Bind to temporaries.** `h.push(42)` works; `h.push(&42)` is impossible. With
  a pointer parameter every caller needs a named variable first.
- **Uniform in generic code.** In a template you can't know if `T` is already a
  pointer. `MinHeap<Node*>` with a pointer-based push means `const Node **`.
  `const T &` works identically for `int`, `std::string`, or `Node *`.
- **Operators require them.** `a < b` must pass `b` somehow, and that's a
  reference. This is why the whole standard library is built on `const &`.

### Where pointers are still right in C++

References are a *narrower* tool, not a strictly better one. Use a pointer when
you need something a reference deliberately can't do:

| Need | Use |
|---|---|
| Optional / "no value" (`nullptr`) | pointer (or `std::optional` for values) |
| Reseating — walking a list | pointer |
| Ownership / lifetime | `unique_ptr`, `shared_ptr`, raw `new`/`delete` |
| Pointer arithmetic, raw buffers | pointer |
| Any C code | pointer (no references exist) |

### The heuristic

> **Reference** when the object definitely exists and you're just borrowing it
> for the duration of the call.
> **Pointer** when it might not exist, might change, or you're managing its
> lifetime.

A practical tell in real codebases: a `T *` parameter suggests the argument
might be null or might be modified; a `const T &` says "I'm only reading it."

---

## Part 3 — Choosing how to pass (C++)

### Two independent reasons to use a reference

1. **Mutation** → `T &` — "I will modify your object."
2. **Avoiding a copy** → `const T &` — "I won't modify it, I just don't want to
   pay to duplicate it."

Same mechanism, opposite intent. `const` is what tells the reader and the
compiler which one you mean. `MinHeap::push(const T &value)` is case 2 only.

### The decision rule

Ask two questions, in order:

**1. Do I need to modify the caller's object?**
→ Yes: `T &`. Done.

**2. Is `T` cheap to copy?**
→ Cheap (`int`, `size_t`, `double`, `char`, pointers, small structs ≲ 16 bytes):
  **by value**
→ Expensive (`std::string`, `std::vector`, anything owning heap memory, anything
  you don't know): **`const T &`**

### Pass by value on purpose: local working copies

A copy is what you want when you need **scratch state that must not touch the
caller's variable**. From `sift_down`:

```cpp
void MinHeap<T>::sift_down(size_t i)   // i by value
{
    ...
    i = smallest;   // modifying i — but only OUR copy
}
```

`i` is a walking cursor. The caller's `sift_down(0)` still sees `0` afterward.
If it were `size_t &i`, the loop would clobber the caller's variable.

### Why `std::string` specifically

A `std::string` is not the characters — it's a small object (~32 bytes) holding
a *pointer* to a heap buffer, plus size and capacity. Copying one means a
`malloc` plus copying every byte.

```cpp
void f(std::string s);          // allocates + copies the whole buffer, every call
void f(const std::string &s);   // copies one address, no allocation
```

For a 10 KB string: a heap allocation and a 10 KB memcpy, versus moving 8 bytes.

A bare `char` is the opposite — 1 byte, pass by value. A `char *` in C is
already just an address, which is why C strings feel "free" to pass: you're
passing the pointer, not the text.

### Why this matters more in templates

Inside `MinHeap<T>` you **cannot know what `T` is** — maybe `int`, maybe a
struct holding three vectors.

> In generic code, default to `const T &`. A reference to an `int` costs
> essentially nothing; copying a large `T` does not.

That's why `push(const T &value)` is correct even though the tests only ever use
`int` and `std::string`.

### Returns follow a different rule

```cpp
T pop();                // by VALUE
const T &top() const;   // by REFERENCE
```

Both "return the minimum," but `pop()` calls `data_.pop_back()`, destroying the
element. Returning `const T &` there would hand back a reference to destroyed
storage — dangling, undefined behavior, and the kind of bug that looks fine in
testing.

> **Return by reference only when the referent outlives the call.** `top()`
> qualifies (the element stays in the heap); `pop()` does not.

---

## The through-line

Pointers are one tool doing six unrelated jobs — "might be null," "I'll modify
this," "I own this memory," "this is an array," "this is a callback" — all
spelled identically as `T *`, so the compiler can't tell which you meant.

C++ split them apart:

| Job | C | C++ |
|---|---|---|
| Non-null borrow | `T *` | `T &` |
| Cheap read-only pass | `const T *` | `const T &` |
| Owned dynamic array | `malloc` / `free` | `std::vector<T>` |
| Owned single object | `malloc` / `free` | `unique_ptr` / `shared_ptr` |
| Type-safe generics | `void *` + `size` | templates |

`MinHeap` uses four of those five and contains not a single raw pointer — while
`std::vector` does `malloc`-equivalent work underneath the entire time.

**Exercise worth doing:** write the heap once in C with `void *` and an explicit
`size_t elem_size`. You'll feel exactly what the template buys you.
