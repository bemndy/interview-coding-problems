/*
 * test_hashmap.cpp - tests for HashMap<K, V>. Don't edit these -- make them pass.
 */

#include <cassert>
#include <iostream>
#include <string>
#include "hashmap.h"

static void test_put_get_overwrite(void)
{
    HashMap<std::string, int> m;
    assert(m.empty());
    assert(m.get("a") == nullptr);

    m.put("a", 1);
    m.put("b", 2);
    assert(m.size() == 2);
    assert(*m.get("a") == 1);
    assert(*m.get("b") == 2);
    assert(m.get("c") == nullptr);

    m.put("a", 100);           // overwrite, no size change
    assert(m.size() == 2);
    assert(*m.get("a") == 100);

    std::cout << "test_put_get_overwrite: ok\n";
}

static void test_remove(void)
{
    HashMap<std::string, int> m;
    m.put("x", 1);
    m.put("y", 2);
    assert(m.remove("x") == true);
    assert(m.get("x") == nullptr);
    assert(m.size() == 1);
    assert(m.remove("x") == false);   // already gone
    assert(m.remove("z") == false);   // never existed
    assert(*m.get("y") == 2);

    std::cout << "test_remove: ok\n";
}

static void test_rehash_grows_and_preserves_entries(void)
{
    HashMap<int, int> m(4);   // start tiny to force a rehash quickly
    size_t initial_buckets = m.bucket_count();

    for (int i = 0; i < 100; i++) {
        m.put(i, i * i);
    }

    assert(m.size() == 100);
    assert(m.bucket_count() > initial_buckets);
    assert(m.load_factor() <= 0.75 + 1e-9);

    for (int i = 0; i < 100; i++) {
        int *v = m.get(i);
        assert(v != nullptr);
        assert(*v == i * i);
    }

    std::cout << "test_rehash_grows_and_preserves_entries: ok\n";
}

static void test_contains(void)
{
    HashMap<std::string, int> m;
    assert(m.contains("k") == false);
    m.put("k", 5);
    assert(m.contains("k") == true);
    m.remove("k");
    assert(m.contains("k") == false);

    std::cout << "test_contains: ok\n";
}

int main()
{
    std::cout << "running tests...\n";
    test_put_get_overwrite();
    test_remove();
    test_rehash_grows_and_preserves_entries();
    test_contains();
    std::cout << "all tests passed\n";
    return 0;
}
