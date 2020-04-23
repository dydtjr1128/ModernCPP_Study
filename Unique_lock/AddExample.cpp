#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

/*
unique_lock 은 mutex의 래퍼라고 생각 할 수 있으며 예외처리를 쉽게 할 수 있다. 또한 옵션으로 상황에 맞게 잠글수 있다.
std::adopt_lock 잠그고 시작(default)
std::defer_lock 잠그지 않고 시작 후에 lock으로 잠궈야 함. 멀티 lock인경우 deadlock 발생할 여지가 있으므로 이 때에는 std::lock(lock1,lock2...) 이런식으로 쓰는것이 좋다 -> c++17에서 shared_lock?일듯
std::try_to_lock 잠금을 시도하고 시작한다 후에 if(lock.owns_lock()) 코드로 락의 소유권을 가지고 있는지 확인 해야한다.
*/
int i, n = 1000000;
std::mutex m, m2;
void add() {
	for (int j = 0; j < n; j++) {
		std::unique_lock<std::mutex> lock(m);
		i += 1;
		lock.unlock();
	}
}

void add2() {
	std::unique_lock<std::mutex> lock(m);// std::lock_guard<std::mutex> lg(m);	
	for (int j = 0; j < n; j++) {
		i += 1;
	}
	lock.unlock();
}

void add3() {
	m2.lock();
	for (int j = 0; j < n; j++) {
		i += 1;
	}
	m2.unlock();
}

int main() {
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::thread th1(add);
	std::thread th2(add);

	th1.join();
	th2.join();

	std::cout << "i : " << i << std::endl;
	std::cout << "time : " << ((std::chrono::duration<double>)(std::chrono::system_clock::now() - start)).count() << std::endl;


	i = 0;
	start = std::chrono::system_clock::now();
	th1 = std::thread(add2);
	th2 = std::thread(add2);

	th1.join();
	th2.join();

	std::cout << "i : " << i << std::endl;
	std::cout << "time : " << ((std::chrono::duration<double>)(std::chrono::system_clock::now() - start)).count() << std::endl;


	i = 0;
	start = std::chrono::system_clock::now();
	th1 = std::thread(add3);
	th2 = std::thread(add3);

	th1.join();
	th2.join();

	std::cout << "i : " << i << std::endl;
	std::cout << "time : " << ((std::chrono::duration<double>)(std::chrono::system_clock::now() - start)).count() << std::endl;

}