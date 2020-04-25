
#include <chrono>              // std::chrono::miliseconds
#include <condition_variable>  // std::condition_variable
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m,
	int index, std::condition_variable* cv) {
	for (int i = 0; i < 5; i++) {
		// ������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶� �����ϸ� �ȴ�.
		// �� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" +
			std::to_string(index) + ")\n";

		// data �� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		// consumer ���� content �� �غ�Ǿ����� �˸���.
		cv->notify_one();
	}
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m,
	int* num_processed, std::condition_variable* cv) {
	while (*num_processed < 25) {
		std::unique_lock<std::mutex> lk(*m);
		std::cout << "lock �ɸ�~!";
		cv->wait(
			lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });

		std::cout << *num_processed << std::endl;
		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		// �� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
		std::string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		// content �� ó���Ѵ�.
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() {
	// ���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
	std::queue<std::string> downloaded_pages;
	std::mutex m;
	std::condition_variable cv;
	m.lock();
	m.lock();

	std::vector<std::thread> producers;
	for (int i = 0; i < 1; i++) {
		producers.push_back(
			std::thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;
	for (int i = 0; i < 1; i++) {
		consumers.push_back(
			std::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}
	std::cout << "producers join" << std::endl;
	for (int i = 0; i < 1; i++) {
		producers[i].join();
	}

	std::cout << "notify_all" << std::endl;
	// ������ �ڰ� �ִ� ��������� ��� �����.
	cv.notify_all();

	std::cout << "consumers join" << std::endl;
	for (int i = 0; i < 1; i++) {
		consumers[i].join();
	}
}
