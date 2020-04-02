#include <iostream>
#include <vector>
#include <time.h>

class MyClass {
public:
	MyClass(int a) : num(a) {
		std::cout << "MyClass constructor." << std::endl;
	}
	~MyClass() {
		std::cout << "MyClass destructor." << std::endl;
	}
	MyClass(const MyClass& rhs) {
		this->num = rhs.num;
		std::cout << "MyClass copy constructor." << std::endl;
	}
	MyClass& operator=(MyClass& rhs) {		
		this->num = rhs.num;
		std::cout << "MyClass copy operator." << std::endl;
		return *this;
	}	
private:
	int num;
};

int main() {
	/*std::vector<std::string> vec, vec2;	
	constexpr int kTestCase = 1000000;
	clock_t start;

	start = clock();
	for (int i = 0; i < kTestCase; i++)
		vec.push_back(std::string("hello"));
	std::cout << "vec.push_back() : " << clock() - start << std::endl;
	
	start = clock();
	for (int i = 0; i < kTestCase; i++)
		vec2.emplace_back("hello");
	std::cout << "vec2.emplace_back() : " << clock() - start << std::endl;*/

	std::vector<std::unique_ptr<MyClass>> vec1, vec2;
	vec1.push_back(std::make_unique<MyClass>(10));
	std::cout << "vec.push_back()" << std::endl;

	std::cout << "----------------------" << std::endl;

	vec2.emplace_back(new MyClass(10));
	std::cout << "vec2.emplace_back()" << std::endl;
	std::cout << "----------------------" << std::endl;
}