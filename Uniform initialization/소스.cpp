#include <iostream>
#include <string>

class Widget
{
public:
	Widget(int i, bool b);
	Widget(int i, double d);
	Widget(std::string a);
	//bool을 원소로 하는 initializer_list 인자로 받음
	Widget(std::initializer_list<bool> il);
};
Widget::Widget(int i, bool b) {
	std::cout << "int+bool" << std::endl;
}
Widget::Widget(int i, double d) {
	std::cout << "int+double" << std::endl;
}
Widget::Widget(std::string a) {
	std::cout << "string" << std::endl;
}
Widget::Widget(std::initializer_list<bool> il) {
	std::cout << "initializer_list" << std::endl;
}
int main() {
	//Widget w{ 10, 5.0 }; //error
	Widget w2{ true }; //ok
	std::string b= "dsk";
	Widget w3{ b }; //ok. call string constructor
	return 0;
}
//class Widget
//{
//public:
//	Widget() {
//		std::cout << "default" << std::endl;
//	}
//
//	Widget(std::initializer_list<int> il) {
//		std::cout << "init" << std::endl;
//	}
//};
//
//int main() {
//	Widget w1; //기본 생성자 호출
//	Widget w2(); //함수! 호출 x
//	Widget w3{}; //기본 생성자 호출
//	Widget w4({});//std::initializer_list 이용해 호출
//	Widget w5{ {} };//std::initializer_list 이용해 호출
//	Widget w6 = {}; // 기본 생성자 호출
//	Widget w7 = { {} }; //std::initializer_list 이용해 호출
//}