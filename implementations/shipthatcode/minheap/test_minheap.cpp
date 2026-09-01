/*
 * test_minheap.cpp - tests for MinHeap<T>. Don't edit these -- make them pass.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "minheap.h"

static void test_ints_sorted_pop_order(void)
{
    MinHeap<int> h;
    assert(h.empty());

    std::vector<int> values = {5, 3, 8, 1, 9, -2, 4, 4, 0};
    for (int v : values) h.push(v);
    assert(h.size() == values.size());

    std::sort(values.begin(), values.end());
    std::vector<int> popped;
    while (!h.empty()) popped.push_back(h.pop());

    assert(popped == values);
    std::cout << "test_ints_sorted_pop_order: ok\n";
}

static void test_top_does_not_remove(void)
{
    MinHeap<int> h;
    h.push(10);
    h.push(2);
    h.push(7);
    assert(h.top() == 2);
    assert(h.size() == 3);
    assert(h.pop() == 2);
    assert(h.top() == 7);
    std::cout << "test_top_does_not_remove: ok\n";
}

static void test_empty_throws(void)
{
    MinHeap<int> h;
    bool threw = false;
    try { h.pop(); } catch (const std::out_of_range &) { threw = true; }
    assert(threw);

    threw = false;
    try { h.top(); } catch (const std::out_of_range &) { threw = true; }
    assert(threw);
    std::cout << "test_empty_throws: ok\n";
}

static void test_generic_strings(void)
{
    MinHeap<std::string> h;
    h.push("banana");
    h.push("apple");
    h.push("cherry");
    assert(h.pop() == "apple");
    assert(h.pop() == "banana");
    assert(h.pop() == "cherry");
    std::cout << "test_generic_strings: ok\n";
}

int main()
{
    std::cout << "running tests...\n";
    test_ints_sorted_pop_order();
    test_top_does_not_remove();
    test_empty_throws();
    test_generic_strings();
    std::cout << "all tests passed\n";
    return 0;
}
