//#include <iostream>
//#include <mutex>
//#include <thread>
//#include <condition_variable>
///*
//unique_lock, lock_guard 모두 기본적으로 생성시 락을 건다. 하지만 unique_lock은 더해서 락을 걸고 나서 또다시 락을 걸거나 unlock을 할 수 있다.
//*/
//
//void func(int id, std::unique_lock<std::mutex>& lock) {	
//	lock.lock(); // lock 2, lock1에서 락되었으므로 대기
//	std::cout << id << " lock" << std::endl;	
//	lock.unlock();
//	std::cout << id << " unlock" << std::endl;\
//}
//
//int main() {
//	std::mutex mutex;
//
//	std::unique_lock<std::mutex> lock(mutex); // lock 1
//	std::cout << "main lock" << std::endl;
//	try {
//
//		std::thread th1(func, 1,std::ref(lock));
//		std::thread th2(func, 2, std::ref(lock));
//
//		lock.unlock(); // unlock시 lock2의 락이 해제됨과 동시에 쓰레드 수행
//
//		std::cout << "main unlock" << std::endl;
//
//		th1.join();
//		th2.join();
//	}
//	catch (...) {
//		std::cout << "err2" << std::endl;
//
//	}
//	std::cout << "hello" << std::endl;
//
//}
