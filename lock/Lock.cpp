#include <iostream>
#include <mutex>

std::mutex m1, m2;
int main() {
	std::thread th([&]() {
		std::lock(m1, m2);
		std::cout << "th1" << std::endl;
		m1.unlock();
		m2.unlock();
		});
	std::thread th2([&]() {
		std::lock(m1, m2);
		std::cout << "th2" << std::endl;
		m1.unlock();
		m2.unlock();
		});

	std::cout << "hello" << std::endl;
	th.join();
	th2.join();
}