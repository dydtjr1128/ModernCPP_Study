#include <iostream>
#include <functional>
#include <thread>


class Test {
public:
	Test(std::string name, int x) : name(name),x(x) { std::cout << name << " constructor" << std::endl; }
	~Test() { std::cout << name << " desstructor" << std::endl; }
	Test(const Test& test) { this->x = test.x; this->name = test.name; std::cout << name << " copy contructor" << std::endl; }
	Test(Test&& test) noexcept { this->x = test.x; this->name = test.name; std::cout << name << " move contructor" << std::endl; }
	std::string name;
	int x;
};

void print(const int& i) {
	std::cout << i << " thread id : " << std::this_thread::get_id() << '\n';
}

void print2(const Test i) {
	std::cout <<i.name << " : " << i.x << " thread id : " << std::this_thread::get_id() << '\n';
}


int main() {
	int i = 10, j = 10;

	auto f1 = std::bind(print, i);
	auto f2 = std::bind(print, std::ref(j));

	i = j = 20;

	f1(); // 10
	std::cout << "i : " << i << std::endl; // 20

	std::cout << "================" << std::endl;

	f2(); // 70
	std::cout << "j : " << j << std::endl; // 70

	/*
	이유

	bind는 bind 될 때의 상태를 가져오기 때문에 일반 변수를 넣어주게 되면 참조로 받더라도 복사된 값(복사 생성자 호출)을 참조한다. 이를 방지하기위해 std::ref로 넣어주어야 bind된 함수 내 외부에서 실제 변수를 참조 할 수 있다.

	*/

	Test a("a",10), b("b",10);// a constuctor, b constructor

	std::thread t1(print2, a);// copy constructor
	std::thread t2(print2, std::ref(b)); // reference

	t1.join();
	t2.join();
	/*
	이유
	print의 인자가 참조 타임인 경우 std::ref를 이용해 연결 해 주어야 한다. 그렇지 않은경우 컴파일 시 오류를 발생시킨다. 예외적으로 const int& i 인경우는 ref로 감싸지 않더라도 오류는 발생하지 않지만 복사 생성자가 불린다.
	그렇기 때문에 참조된 객체 혹은 변수를 사용하고 싶다면 함수에서 &로 받는것 뿐만 아니라 std::ref를 이용해 넘겨 주어야 한다.
	함수가 &가 아닌경우에는 a객체의 경우 복사생성자에 이동생성자까지 불리므로 매우 비효율적이다.
	*/
	//std::cout << a << " " << b << std::endl;    

}