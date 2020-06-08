#include <iostream>

template <typename T>
void wrapper(T&& u) {//템플릿 타입의 universal reference는 lvalue(좌측값), rvalue(우측값) 모두 받을 수 있다.
    g(std::forward<T>(u));
}

class A {};

void g(A& a) { std::cout << "좌측값 레퍼런스 호출" << std::endl; }
void g(const A& a) { std::cout << "좌측값 상수 레퍼런스 호출" << std::endl; }
void g(A&& a) { std::cout << "우측값 레퍼런스 호출" << std::endl; }

void show_value(int&& t) { std::cout << "우측값 : " << t << std::endl; } // 프리미티브 타입의 universal reference는 rvalue(우측값)만 받을 수 있다.
void show_value2(int& t) { std::cout << "우측값 : " << t << std::endl; } // 참조는 lvalue만 받을 수 있음


void premitive_swap(int&& a, int&& b) {
    int&& t = std::move(a);
    a = std::move(b);
    b = std::move(t);
}

void copy_swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    A a;
    const A ca;

    std::cout << "원본 --------" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "Wrapper -----" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
       
    int x = 10;
    show_value(5);
    //show_value(x);// x는 lvalue여서 넣을 수 없음 move로 rvalue로 변환을 해 주어야 함 => rvalue참조를 lavlue에 바인딩 할 수 없습니다.
    show_value(std::move(x));// x를 rvalue로 변환

    //show_value2(5);// 참조는 lvalue만 받을 수 있기 때문에 rvalue인 5, rvalue로 변환한 std::move(5)는 넣을 수 없음..
    show_value2(x);// 
    //show_value2(std::move(x));//     

    int aa = 10, bb = 20;
    premitive_swap(std::move(aa), std::move(bb));
    std::cout << " aa : " << aa << "   bb : " << bb << std::endl;
}