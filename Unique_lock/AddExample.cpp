#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

/*
unique_lock �� mutex�� ���۶�� ���� �� �� ������ ����ó���� ���� �� �� �ִ�. ���� �ɼ����� ��Ȳ�� �°� ��ۼ� �ִ�.
std::adopt_lock ��װ� ����(default)
std::defer_lock ����� �ʰ� ���� �Ŀ� lock���� ��ž� ��. ��Ƽ lock�ΰ�� deadlock �߻��� ������ �����Ƿ� �� ������ std::lock(lock1,lock2...) �̷������� ���°��� ���� -> c++17���� shared_lock?�ϵ�
std::try_to_lock ����� �õ��ϰ� �����Ѵ� �Ŀ� if(lock.owns_lock()) �ڵ�� ���� �������� ������ �ִ��� Ȯ�� �ؾ��Ѵ�.
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