#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <memory>
#include <functional>
#include <cstddef>
#include <utility>

/*
 * Generic HashMap<K, V> using separate chaining (linked list per bucket,
 * via unique_ptr node chains) and a custom Hash functor (defaults to
 * std::hash<K>). Rehashes to double the bucket count whenever the load
 * factor would exceed 0.75 after an insert.
 */
template <typename K, typename V, typename Hash = std::hash<K>>
class HashMap {
public:
    explicit HashMap(size_t initial_buckets = 8);

    // Inserts or overwrites the value for `key`. May trigger a rehash.
    void   put(const K &key, const V &value);

    // Returns pointer to the value for `key`, or nullptr if absent.
    V     *get(const K &key);
    const V *get(const K &key) const;

    // Removes `key`. Returns true if it was present.
    bool   remove(const K &key);

    bool   contains(const K &key) const;

    size_t size() const { return size_; }
    bool   empty() const { return size_ == 0; }
    size_t bucket_count() const { return buckets_.size(); }
    double load_factor() const { return static_cast<double>(size_) / buckets_.size(); }

private:
    struct Node {
        K key;
        V value;
        std::unique_ptr<Node> next;
        Node(const K &k, const V &v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<std::unique_ptr<Node>> buckets_;
    size_t size_ = 0;
    Hash hasher_;

    static constexpr double kMaxLoadFactor = 0.75;

    size_t bucket_index(const K &key, size_t bucket_count) const;
    void   rehash(size_t new_bucket_count);
};

#include "hashmap.tpp"

#endif // HASHMAP_H
