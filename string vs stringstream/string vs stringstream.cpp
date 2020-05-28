#include <chrono>
#include <iostream>
#include <sstream>

int main() {

	int n = 5000000;
	std::string a = "have";
	std::string b = "a";
	std::string c = "good";
	std::string d = "day";

	volatile unsigned int count = 0;
	
	auto s = std::chrono::system_clock::now();
	for (int i = 0; i < n; ++i) { // 3등
		std::ostringstream os;
		os << a << " " << b << " " << c << " " << d << "\r\n";
		std::string t = os.str();
		count += t.size();
	}
	std::chrono::duration<double> second = std::chrono::system_clock::now() - s;
	std::cout << "ostringstream : " << second.count() << " second, count : " << count << std::endl;

	count = 0;
	s = std::chrono::system_clock::now();
	for (int i = 0; i < n; ++i) { // 3등
		std::stringstream ss;
		ss << a << " " << b << " " << c << " " << d << "\r\n";
		std::string t = ss.str();
		count += t.size();
	}
	second = std::chrono::system_clock::now() - s;
	std::cout << "stringstream : " << second.count() << " second, count : " << count << std::endl;

	count = 0;
	s = std::chrono::system_clock::now();
	for (int i = 0; i < n; ++i) { // 가장 빠름
		std::string t;
		t.append(a).append(" ").append(b).append(" ").append(c).append(" ").append(d).append("\r\n");
		count += t.size();
	}
	second = std::chrono::system_clock::now() - s;
	std::cout << "string : " << second.count() << " second, count : " << count << std::endl;


	count = 0;
	s = std::chrono::system_clock::now();
	for (int i = 0; i < n; ++i) { // 2등 <- release 기준임
		std::string t = a + " " + b + " " + c + " " + d + "\r\n";
		count += t.size();
	}
	second = std::chrono::system_clock::now() - s;
	std::cout << "string add : " << second.count() << " second, count : " << count << std::endl;
}