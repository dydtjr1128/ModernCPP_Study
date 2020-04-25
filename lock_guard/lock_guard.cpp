#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
int main() {
	std::thread th([&]() {
		std::lock_guard<std::mutex> lock_guard(m1);
		for (int i = 0; i < 100; i++) {
			std::cout << "th1" << std::endl;
		}
		});
	std::thread th2([&]() {
		std::lock_guard<std::mutex> lock_guard(m1);
		for (int i = 0; i < 100; i++) {
			std::cout << "th2" << std::endl;
		}
		});

	std::cout << "hello" << std::endl;
	th.join();
	th2.join();
}