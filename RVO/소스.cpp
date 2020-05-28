#include <iostream>
//함수에서 객체를 반환할 때는 참조자 반환을 사용하지 말고 RVO를 사용하려고 노력하자.
class Foo {
public:
	Foo() {
		std::cout << "This is constructor." << std::endl;
	}
	~Foo() {
		std::cout << "This is destructor." << std::endl;
	}
	Foo(const Foo& rhs) {
		std::cout << "This is copy constructor." << std::endl;
	}
	Foo& operator=(const Foo& rhs) {
		std::cout << "This is copy operator." << std::endl;
		return *this;
	}
	int num;
};

Foo MakeFoo(int n) {// NRVO  최적화 옵션 /O1 부터 실행
	Foo foo;
	foo.num = n;
	return foo;
}

int main() {
	Foo foo;
	foo = MakeFoo(10);

	return 0;
}