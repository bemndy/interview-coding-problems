#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <cstddef>
#include <stdexcept>

/*
 * Generic binary min-heap / priority queue over std::vector<T>.
 * T must be comparable with operator<.
 */
template <typename T>
class MinHeap {
public:
    MinHeap() = default;

    void   push(const T &value);
    T      pop();              // removes and returns the min; throws if empty
    const T &top() const;      // peeks the min; throws if empty
    bool   empty() const { return data_.empty(); }
    size_t size()  const { return data_.size(); }

private:
    std::vector<T> data_;

    static size_t parent(size_t i) { return (i - 1) / 2; }
    static size_t left(size_t i)   { return 2 * i + 1; }
    static size_t right(size_t i)  { return 2 * i + 2; }

    void sift_up(size_t i);
    void sift_down(size_t i);
};

#include "minheap.tpp"

#endif // MINHEAP_H
