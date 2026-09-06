#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
/***
 * Common Data Strucutres and Algorithms in OOP C++
 * 
 * this is c-style arrays, cpp arrays and vectors and linked-lists 
 */

int main() {

    // c-style arrays with fixed size 
    int arr[5] = {1, 2, 3, 4, 5};
    std::array<int, 5> cpp_arr = {1, 2, 3, 4, 5};
    std::cout << "C-style array first element: " << arr[0] << std::endl;
    std::cout << "C++ array last element: " << cpp_arr[4] << std::endl;

    // std::vector dynamic arrays, most standard way in cpp and like list in python
    std::vector<int> vec = {1, 2, 4, 5};
    std::vector<std::string> string_vec = {"hello", "world"};
    std::cout << "Vector (int): " << vec[2] << std::endl;
    std::cout << "Vector (string): " << string_vec[1] << " " << string_vec[0] << std::endl;
    
    // different common methods for these arrays;
    vec.push_back(6); // same as append
    for (auto i : vec) {
        std::cout << "current element: " << i << std::endl;
    }

    for (auto i : string_vec) {
        std::cout << "current string element: " << i << std::endl;
    }

    //linked-list 
    std::list<int> linked_list = {10, 20, 30};
    linked_list.push_back(40);
    linked_list.push_front(5);
    for (auto i : linked_list) {
        std::cout << "Linked list element: " << i << std::endl;
    }

    return 0;
}