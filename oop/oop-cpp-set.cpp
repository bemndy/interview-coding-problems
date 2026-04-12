#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

/***
 * Common Data Strucutres and Algorithms in OOP C++
 * 
 * this is hashmaps and sets 
 */

int main() {

    // example of using sets in cpp
    std::set<std::string> s = {"apple", "banana", "cherry"};
    s.insert("tomato");
    s.erase("banana");
    for (auto i : s) {
        std::cout << i << std::endl;
    }
    
    //example of using unordered maps in cpp
    std::unordered_map<std::string, int> um;
    um["apple"] = 1;
    um.insert({"banana", 2});
    um["cherry"] = 3;

    for (const auto& pair : um) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}