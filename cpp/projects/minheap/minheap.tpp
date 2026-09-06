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
    data_.push_back(value);
    sift_up(data_.size() - 1);
}

template <typename T>
T MinHeap<T>::pop()
{
    if (empty()) {
        throw std::out_of_range("pop from empty heap");
    }
    // TODO:
    T min_value = data_[0];
    data_[0] = data_.back();
    data_.pop_back();
    if (!empty()) {
        sift_down(0);
    }
    // 1. save data_[0] (the min) to return
    // 2. move the last element into slot 0
    // 3. shrink data_ by one (pop_back)
    // 4. if not empty, sift_down(0)
    // 5. return the saved min
    return min_value;
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
    while (i > 0) {
        size_t p = parent(i);
        if (data_[i] < data_[p]) {
            std::swap(data_[i], data_[p]);
            i = p;
        } else {
            break;
        }
    } 
}

template <typename T>
void MinHeap<T>::sift_down(size_t i)
{
    // TODO: repeatedly compare data_[i] against its children (if in range),
    // find the smallest of {i, left(i), right(i)}, swap with it and continue
    // from there; stop when i is already the smallest.
    size_t n = data_.size();
    while (true) {
        size_t l = left(i), r = right(i); 
        size_t smallest = i;

        if (l < n && data_[l] < data_[smallest]) smallest = l;
        if (r < n && data_[r] < data_[smallest]) smallest = r;
        if (smallest == i) break;

        std::swap(data_[i], data_[smallest]);
        i = smallest;
    }
}
