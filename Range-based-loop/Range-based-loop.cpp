#include <iostream>


//void testLoop(int array[]) {
//    for (int num : array) {
//
//    }
//}

void testLoop(int (&array)[5]) {
    for (int num : array) {
        std::cout << "int " << num << std::endl;
    }
}

int main() {
    int array[] = { 1,2,3,4,5 };    ;

    for (int num : array) {
        std::cout << "int " << num << std::endl;
    }
    testLoop(array);

}