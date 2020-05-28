#include <condition_variable>
#include <mutex>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <vector>

/*
condition_variable은 락을 거는것이 아니라 대기를 하는 것이다. 락 개념과는 다르다. 대기중에 notify_one을 만나면 하나의 쓰레드를 조건을 확인해 대기상태에서 깨운다.
조건을 확인하는것이 명확한데, 그 이유는 suprious wakeup 현상이 일어 날 수 있기 때문이다.. 운영체제의 성능을 높히기 위해 대기 상태 해제 시그널을 보낼 때 동시에 여러 wait condition이 깨어 날 수 있다. 
이 부분은 성능 을 위해 어쩔수 없이 구현되었으므로 이 상황에 대한 해결은 개발자가 해 주어야 한다.
대기상태에서 notify_one을 호출 하지 않더라도 깨어날 수있는 상황이 발생 할 수 있기 때문에 2중으로 조건을 확인하도록 해야 한다. 조건이 참이 아닌경우 다시 대기상태로 바뀐다.
*/

std::chrono::milliseconds MakeRandomNumber() {
	std::random_device device;  // 시드값을 얻기 위한 random_device
	std::mt19937 gen(device()); // device를 이용해 메르센 트위스터(MT) 난수 생성기 초기화     
	std::uniform_int_distribution<int> dis(1, 10); // 1 부터 10 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	return std::chrono::milliseconds(dis(gen) * 100);
}

void Crawling(std::queue<std::string>& crawled_data, int index, std::condition_variable& cv, std::mutex& mutex) {
	mutex.lock();
	std::cout << "===== Crawling " << index << " start! =====\n";
	mutex.unlock();

	for (int i = 0; i < 10; i++) { // 10장 크롤링 한다고 가정
		std::this_thread::sleep_for(MakeRandomNumber());

		mutex.lock();
		std::string content = "크롤링 : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";
		crawled_data.push(content);
		mutex.unlock();

		cv.notify_one();
	}

}

void Parsing(std::queue<std::string>& crawled_data, int index, std::condition_variable& cv, std::mutex& mutex, bool& is_finish) {
	mutex.lock();
	std::cout << "===== Parsing " << index << " start! =====\n";
	mutex.unlock();
	while (true) {
		std::unique_lock<std::mutex> lock(mutex); // lock
		cv.wait(
			lock, [&]() { return !crawled_data.empty() || is_finish; }
		);
		if (crawled_data.size() == 0) {
			std::cout << "Parsing end" << std::endl;
			lock.unlock();
			return;
		}

		std::string content = crawled_data.front();
		crawled_data.pop();
		lock.unlock();
		std::cout << "content : " << content;
	}
}

int main() {
	std::cout << "===== Start crawling =====\n";

	std::queue<std::string> crawled_data;
	std::vector<std::thread> crawllers, parsers;
	std::mutex mutex;
	std::condition_variable cv;
	bool is_finish = false;

	for (int i = 0; i < 5; i++) {
		crawllers.emplace_back(
			Crawling, std::ref(crawled_data), i, std::ref(cv), std::ref(mutex)
		);
		parsers.emplace_back(
			Parsing, std::ref(crawled_data), i, std::ref(cv), std::ref(mutex), std::ref(is_finish)
		);
	}


	for (auto& t : crawllers)
		t.join();
	is_finish = true;
	cv.notify_all();
	for (auto& t : parsers)
		t.join();
	std::cout << "===== Finish crawling =====\n";
}
