# Attribution

This repository mixes original work with material from a university data
structures & algorithms course. This file records which is which.

## Not my work

**`c/course/ex01_*` … `ex20_*`** and **`python/course/ex21_*` … `ex36_*`**

These directories originate from a university DSA course (C for the first half
of the term, Python for the second). The exercise sequence, problem statements,
and file layout were designed by the course instructor.

Within each exercise:

| Directory | Origin |
|---|---|
| `template/` | **Instructor-authored** starter scaffolding — function signatures, headers, test harnesses, build files |
| `complete/` | Reference solutions, largely **instructor-authored**; some contain my own work filled into the scaffold |

I have not systematically separated my edits from the original scaffolding in
these directories. **Assume the instructor authored anything under
`*/course/`** unless a file says otherwise.

This material is kept here for personal study reference. It is not licensed for
redistribution, is not covered by the repository's LICENSE, and remains the
property of its original author. If you are the course instructor and would
like this removed, open an issue and I will take it down.

## My work

Everything outside `*/course/`:

- **`c/projects/`**, **`cpp/projects/`** — dynamic array, doubly linked list,
  min-heap, hash map. Written from scratch against a provided test suite as
  part of a self-directed roadmap.
- **`python/algorithms/`** — sorting and sliding-window implementations
- **`python/oop/`**, **`cpp/oop/`** — OOP concept exercises written while
  working through tutorials
- **`docs/`** — my own notes

## Third party

- **`neetcode-submissions/`** — a git submodule pointing at a separate
  repository of my NeetCode solutions. Problem statements belong to NeetCode.

## Note on interviews

If any code here comes up in a technical discussion, the honest framing is:
`*/course/` is coursework I studied and modified, `*/projects/` is code I wrote
myself.
