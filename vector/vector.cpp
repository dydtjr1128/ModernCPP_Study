#include <iostream>
#include <vector>

int main() {
    std::vector<char> v;


    std::cout << v.size() << " " << v.capacity() << std::endl;
    for (int i = 0; i < 10; i++) {
        v.push_back('1');
        std::cout << i << " " << v.size() << " " << v.capacity() << std::endl;
    }

    v.reserve(100);

    std::cout << v.size() << " " << v.capacity() << std::endl;
}
