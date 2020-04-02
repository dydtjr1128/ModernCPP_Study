#include <iostream>

class A {
public:
	int a;
protected:
	int b;
};

class B : public A {
public:
	int ba;
	void print() {
		std::cout << "&this : " << (int)this << std::endl;
		std::cout << "&a : " << (int)& a << std::endl;
		std::cout << "&b : " << (int)& b << std::endl;
		std::cout << "&ba : " << (int)& ba << std::endl;
		std::cout << "&bb : " << (int)& bb << std::endl;
	}
private:
	int bb;
};

int main()
{
	B* t = new B();
	t->print();

	A* a = new B();
	((B*)a)->print();
	return 0;
}