/*
 * hashmap.tpp - template method definitions for HashMap<K, V, Hash>.
 * Fill in the TODOs.
 */

template <typename K, typename V, typename Hash>
HashMap<K, V, Hash>::HashMap(size_t initial_buckets)
{
    // TODO: resize buckets_ to initial_buckets (at least 1).
}

template <typename K, typename V, typename Hash>
size_t HashMap<K, V, Hash>::bucket_index(const K &key, size_t bucket_count) const
{
    // TODO: return hasher_(key) % bucket_count
    return 0;
}

template <typename K, typename V, typename Hash>
void HashMap<K, V, Hash>::put(const K &key, const V &value)
{
    // TODO:
    // 1. find the bucket for `key`.
    // 2. walk its chain; if a node with this key exists, overwrite its
    //    value and return (no size change, no rehash needed).
    // 3. otherwise, prepend (or append) a new Node to the bucket's chain,
    //    increment size_.
    // 4. if load_factor() > kMaxLoadFactor, rehash(bucket_count() * 2).
}

template <typename K, typename V, typename Hash>
V *HashMap<K, V, Hash>::get(const K &key)
{
    // TODO: find the bucket, walk the chain, return &node->value or nullptr.
    return nullptr;
}

template <typename K, typename V, typename Hash>
const V *HashMap<K, V, Hash>::get(const K &key) const
{
    // TODO: same as above, const version. (Can reuse logic via const_cast
    // on `this` and calling the non-const get(), or duplicate the walk.)
    return nullptr;
}

template <typename K, typename V, typename Hash>
bool HashMap<K, V, Hash>::contains(const K &key) const
{
    return get(key) != nullptr;
}

template <typename K, typename V, typename Hash>
bool HashMap<K, V, Hash>::remove(const K &key)
{
    // TODO:
    // 1. find the bucket for `key`.
    // 2. walk the chain keeping a pointer to the previous node's `next`
    //    (or the bucket slot itself if it's the first node).
    // 3. if found, unlink it (unique_ptr ownership transfer handles the
    //    free), decrement size_, return true.
    // 4. otherwise return false.
    return false;
}

template <typename K, typename V, typename Hash>
void HashMap<K, V, Hash>::rehash(size_t new_bucket_count)
{
    // TODO:
    // 1. build a new vector<unique_ptr<Node>> of new_bucket_count buckets.
    // 2. for every existing node (walk old buckets_), recompute its bucket
    //    index against new_bucket_count and move (splice) the node into
    //    the new bucket's chain -- don't reallocate nodes, move the
    //    unique_ptrs.
    // 3. swap buckets_ with the new vector.
}
