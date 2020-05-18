#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

struct Box {
	explicit Box(int num) : num_things{ num } {}

	int num_things;
	std::mutex m;
};

//void transfer(Box& from, Box& to, int num)
//{
//    std::unique_lock<std::mutex> lock1(from.m);//deadlock 발생 여지 있음
//    std::cout << "<lock1> " << std::this_thread::get_id() << ">" << std::endl;
//    std::unique_lock<std::mutex> lock2(to.m);
//    std::cout << "lock2> " << std::this_thread::get_id() << std::endl;
//    std::cout << from.num_things << " " << to.num_things << std::endl;
//    from.num_things -= num;
//    to.num_things += num;
//
//    std::cout << "lock1 unlock " << std::this_thread::get_id() << std::endl;
//    lock1.unlock();
//    std::cout << "lock2 unlock " << std::this_thread::get_id() << std::endl;
//    lock2.unlock();
//    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
//}
void transfer(Box& from, Box& to, int num)
{
	// don't actually take the locks yet
	std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
	std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);	

	std::lock(lock1, lock2);
		
	from.num_things -= num;
	to.num_things += num;
}

int main()
{
	Box acc1(100);
	Box acc2(50);
	for (int i = 0; i < 1000; i++) {
		std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
		std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

		t1.join();
		t2.join();
	}
	std::cout << acc1.num_things << " " << acc2.num_things << std::endl;
}