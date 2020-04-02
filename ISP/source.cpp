#include <iostream>

class Eatable {
public:
	virtual void eat() = 0;
};

class WebDevelopable {
public:
	virtual void useCSS() = 0;
};

class AndroidDevelopable {
public:
	virtual void developAndroidLayout() = 0;
};

class Developer : public Eatable, public WebDevelopable, public AndroidDevelopable {
public:
	void eat() {
		std::cout << "Developer::eat()" << std::endl;
	}
	void developAndroidLayout() {
		std::cout << "Developer::developAndroidLayout()" << std::endl;
	}
	void useCSS() {
		std::cout << "Developer::useCSS()" << std::endl;
	}
};

int main() {
	WebDevelopable* webDeveloper = new Developer();
	webDeveloper->useCSS();

}