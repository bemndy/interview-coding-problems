# interview-coding-problems

Data structures, algorithms, and low-level programming practice — organized by
language, then by source.

```
c/
  course/      ex01–ex20  university DSA coursework (C half of the term)
  projects/    dynamic array, doubly linked list — written from scratch
cpp/
  projects/    min-heap, hash map — generic containers via templates
  oop/         classes, sets, vectors
python/
  course/      ex21–ex36  university DSA coursework (Python half)
  oop/         OOP concepts, numbered by topic
  algorithms/  sorting, sliding window, Kadane's
docs/          notes written while working through the above
neetcode-submissions/   git submodule — NeetCode solutions
```

## Attribution

Everything under `*/course/` is **university coursework and is largely
instructor-authored**, including the `template/` scaffolding in each exercise.
It is kept here for study reference only and is not covered by this repo's
license. Everything under `*/projects/`, `python/algorithms/`, `*/oop/`, and
`docs/` is my own work. See [`docs/ATTRIBUTION.md`](docs/ATTRIBUTION.md) for the
full breakdown.

## Projects

Self-directed builds. Each is a self-contained directory with an
implementation, a test suite, and a Makefile — `make run` builds and runs the
tests.

| Project | Language | Notes |
|---|---|---|
| `c/projects/vector` | C | growable array, manual `malloc`/`realloc` |
| `c/projects/dll` | C | doubly linked list |
| `cpp/projects/minheap` | C++ | `MinHeap<T>`, header-only template, array-backed binary heap |
| `cpp/projects/hashmap` | C++ | `HashMap<K,V>`, header-only template |

Build any of them:

```sh
cd cpp/projects/minheap
make run
```

Sanitizers are worth enabling while developing:

```sh
make CXXFLAGS="-Wall -Wextra -g -std=c++17 -fsanitize=address,undefined"
```

## Course exercises

`ex01`–`ex20` are C, `ex21`–`ex36` are Python — the split follows how the
course was taught. Most exercises contain:

- `template/` — starter scaffolding provided by the instructor
- `complete/` — reference solution

## Notes

- [Pointers & References: C vs C++](docs/pointers-and-references.md)

## Submodule

```sh
git clone --recursive https://github.com/bemndy/bemndy-dsa-solutions24.git
# already cloned:
git submodule update --init --recursive
```
