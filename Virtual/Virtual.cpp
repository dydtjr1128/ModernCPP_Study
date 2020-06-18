// Virtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Root {
    virtual bool print() = 0;
};

class Base : public Root {
public:    
    bool print() override = 0;
    virtual bool print() const = 0;
};

class SubA : public Base {
public:
    bool print() override {
        std::cout << "SubA::print() non-const" << std::endl;
        return true;
    }
    bool print() const override {
        std::cout << "SubA::print() const" << std::endl;
        return true;
    }
};

int main() {    
    Base* b = new SubA();    

    b->print();
}