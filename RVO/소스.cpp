#include <iostream>

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

Foo MakeFoo(int n) {
	Foo foo;
	foo.num = n;
	return foo;
}

int main() {
	Foo foo;
	foo = MakeFoo(10);

	return 0;
}