#include <iostream>
#include <chrono>
#include <thread>

int test() {

	std::thread([]() {
		std::cout << "hello";
		});
}

int main()
{
	try {
		test();
		std::this_thread::sleep_for(std::chrono::duration<int>(10));
	}
	catch (...) {
		std::cout << "exception";
	}
}
