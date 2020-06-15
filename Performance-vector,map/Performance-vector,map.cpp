#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <vector>
#include <unordered_map>

int main() {
	constexpr int size = 100'000;
	std::string c;
	std::vector<std::string> vector;
	std::unordered_map<std::string, std::string> map;

	srand(time(NULL));
	std::string findVal;
	std::ostringstream oss;
	for (int i = 0; i < size - 1; ++i) {
		oss << "random" << ((rand() % 10000) + 1);
		vector.push_back(oss.str());
		map.emplace(oss.str(), oss.str());
		oss.str("");
		oss.clear();
	}
	oss << "random" << ((rand() % 10000) + 1);
	vector.push_back(oss.str());
	map.emplace(oss.str(), oss.str());
	findVal = oss.str();
	oss.str("");
	oss.clear();


	auto s = std::chrono::system_clock::now();
	std::cout << "vector loop : ";
	for (const auto& n : vector) {
		c = n;
	}
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - s).count() << "ms" << std::endl;

	s = std::chrono::system_clock::now();
	std::cout << "unordered_map loop : ";
	for (const auto& f : map) {
		c = f.second;
	}
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - s).count() << "ms" << std::endl;



	int loopSize = 10000;

	s = std::chrono::system_clock::now();
	std::cout << "vector loop : ";
	for (int i = 0; i < loopSize; i++) {
		auto t = std::find(vector.begin(), vector.end(), findVal);
	}
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - s).count() << "ms" << std::endl;

	s = std::chrono::system_clock::now();
	std::cout << "unordered_map loop : ";
	for (int i = 0; i < loopSize; i++) {
		auto t = map.find(findVal);
	}
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - s).count() << "ms" << std::endl;

}