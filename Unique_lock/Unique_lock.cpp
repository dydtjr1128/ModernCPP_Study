#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

struct Box {
    explicit Box(int num) : num_things{ num } {}

    int num_things;
    std::mutex m;
};

void transfer(Box& from, Box& to, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m);
    std::unique_lock<std::mutex> lock2(to.m);

    from.num_things -= num;
    to.num_things += num;

    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}

int main()
{
    Box acc1(100);
    Box acc2(50);
    for (int i = 0; i < 100; i++) {
        std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
        std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

        t1.join();
        t2.join();
    }
    std::cout << acc1.num_things << " " << acc2.num_things << std::endl;
}