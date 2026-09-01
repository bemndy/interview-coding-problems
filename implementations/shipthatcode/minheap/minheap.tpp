/*
 * minheap.tpp - template method definitions for MinHeap<T>. Fill in the TODOs.
 *
 * Included at the bottom of minheap.h (templates need their definitions
 * visible at the point of instantiation, so this isn't compiled separately).
 */

template <typename T>
void MinHeap<T>::push(const T &value)
{
    // TODO: append to data_, then sift_up the new last index.
}

template <typename T>
T MinHeap<T>::pop()
{
    if (empty()) {
        throw std::out_of_range("pop from empty heap");
    }
    // TODO:
    // 1. save data_[0] (the min) to return
    // 2. move the last element into slot 0
    // 3. shrink data_ by one (pop_back)
    // 4. if not empty, sift_down(0)
    // 5. return the saved min
    return T();
}

template <typename T>
const T &MinHeap<T>::top() const
{
    if (empty()) {
        throw std::out_of_range("top of empty heap");
    }
    return data_[0];
}

template <typename T>
void MinHeap<T>::sift_up(size_t i)
{
    // TODO: while i has a parent and data_[i] < data_[parent(i)], swap and
    // move i to parent(i).
}

template <typename T>
void MinHeap<T>::sift_down(size_t i)
{
    // TODO: repeatedly compare data_[i] against its children (if in range),
    // find the smallest of {i, left(i), right(i)}, swap with it and continue
    // from there; stop when i is already the smallest.
}
