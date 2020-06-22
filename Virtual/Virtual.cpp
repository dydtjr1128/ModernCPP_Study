#include <iostream>

class Root {
public:
	virtual bool print() = 0;
};

class Base : public Root {
public:
	bool print() override = 0; // from Root
	virtual bool print() const = 0; // from Base
};

class SubA : public Base {
public:
	bool print() override {
		std::cout << "SubA::print() non-const, from Root" << std::endl;
		return true;
	}
	bool print() const override {
		std::cout << "SubA::print() const, from Base" << std::endl;
		return true;
	}
	void test() {
		tt = 10;
	}
private:
	int tt;
};

int main() {
	Base* b = new SubA();
	Root* c = new SubA();
	SubA* d = new SubA();

	b->print(); // SubA::print() non-const, from Root
	c->print(); // SubA::print() non-const, from Root
	d->print(); // SubA::print() non-const, from Root

	const Base* e = new SubA(); // SubA::print() const, from Base
	e->print();
	
	const SubA* f = new SubA();
	f->print();	

	
}