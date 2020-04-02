#include <iostream>
#include <mutex>

int main() {
	std::mutex mutex;

	std::unique_lock<std::mutex> lock(mutex);
	
	lock.try_lock();

	std::cout << "hello";

}
