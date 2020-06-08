#include <chrono>
#include <iostream>
#include <sstream>

template <class T>
void swap1(T& a, T& b) {
	T tmp(a);   // a의 copy가 2개가 됨.
	a = b;      // b의 copy가 2개가 됨 (+ a의 copy 중 하나가 사라짐)
	b = tmp;    // tmp의 copy가 2개가 됨 (+b의 copy 중 하나가 사라짐)
}

//move를 쓰면 copy하지 않고 swap이 가능해 짐
template <class T>
void swap2(T& a, T& b) {
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

class People {
public:
	explicit People(int age, const char* name) :age_(age) {
		len_ = strlen(name) + 1;
		name_ = new char[len_];

		for (int i = 0; i < len_; i++)
			name_[i] = name[i];
		std::cout << "Call People Constructor" << std::endl;
	};

	~People() {
		std::cout << "Call People Destructor" << std::endl;
		if (name_)
			delete[] name_;
	}

	People(const People& rhs) { // 복사 생성자, 깊은 복사
		auto start_time = std::chrono::system_clock::now();
		this->age_ = rhs.age_;
		this->len_ = rhs.len_;
		this->name_ = new char[len_];
		for (int i = 0; i < len_; i++) {
			this->name_[i] = rhs.name_[i];
		}
		std::cout << "Copy Constructor : " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start_time).count() << "ms" << std::endl;
	}

	People(People&& rhs) { // 이동 생성자, 얕은 복사 개념
		auto start_time = std::chrono::system_clock::now();
		this->age_ = rhs.age_;
		this->len_ = rhs.len_;
		this->name_ = rhs.name_;

		rhs.name_ = nullptr;
		std::cout << "Move Constructor : " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start_time).count() << "ms" << std::endl;
	}

	People& operator=(const People& rhs) { // 복사 대입 연산자
		auto start_time = std::chrono::system_clock::now();
		delete[] name_;
		this->age_ = rhs.age_;
		this->len_ = rhs.len_;
		this->name_ = new char[len_];
		for (int i = 0; i < len_; i++) {
			this->name_[i] = rhs.name_[i];
		}
		std::cout << "Copy Assignment Operator : " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start_time).count() << "ms" << std::endl;
		return *this;
	}
	
	People& operator=(People&& rhs) noexcept { // 이동 대입 연산자, 없는 경우 기본적으로 복사 대입 연산자가 호출됨.
		auto start_time = std::chrono::system_clock::now();
		this->age_ = rhs.age_;
		this->len_ = rhs.len_;
		this->name_ = rhs.name_;

		rhs.name_ = nullptr;
		std::cout << "Move Assignment Operator : " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start_time).count() << "ms" << std::endl;

		return *this;
	}

	std::string string() {
		std::ostringstream ss;
		ss << "name_ : [" << name_ << "] age_ : [" << age_ << "] len_ : [" << len_ << "]" << std::endl;
		return ss.str();
	}
private:
	int age_;
	int len_;
	char* name_;
};


int main() {
	People p1(27, "HongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHongHong");
	People p2(28, "KimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKimKim");

	std::cout << "===== Normal Swap =====" << std::endl;
	swap1(p1, p2);
	std::cout << p1.string() << p2.string() << std::endl;

	std::cout << "===== Move Swap =====" << std::endl;
	swap2(p1, p2);
	std::cout << p1.string() << p2.string() << std::endl;

	std::cout << "=================" << std::endl;
}