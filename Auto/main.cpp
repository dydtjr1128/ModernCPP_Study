//#include <iostream>
//
//using namespace std;
//
//int plusNum(int i) {
//	return i + 1;
//}
//template <typename TBuilder>
//auto MakeAndProcessObject(const TBuilder& builder) -> decltype(builder.makeObject())
//{
//	auto val = builder.makeObject();
//	// process...
//	return val;
//}
//#define CALL_WITH_MAX(a, b)  ((a) > (b) ? (a) : (b) )
//
//decltype(auto) fff(int t) {
//	return t + 10;
//}
//int main() {
//	auto a = true;
//	auto b = 'Y';
//	auto c = L'Y';
//	auto d = "문자열";
//	auto e = 26;
//	auto f = 3.12;
//	auto g = 10000000000;
//
//	auto &h = e;//참조
//	auto *i = &e;//포인터
//	
//	int q = 10, t = 5;
//	CALL_WITH_MAX(q++, t+1);
//	cout << q << t << "@@@@@@@@"<<endl;
//
//
//	cout << "값\t\t크기\t\t자료형" << endl;
//	cout << a << "\t\t" << sizeof(a) << "\t\t" << typeid(a).name() << endl;
//	cout << b << "\t\t" << sizeof(b) << "\t\t" << typeid(b).name() << endl;
//	cout << c << "\t\t" << sizeof(c) << "\t\t" << typeid(c).name() << endl;
//	cout << d << "\t\t" << sizeof(d) << "\t\t" << typeid(d).name() << endl;
//	cout << e << "\t\t" << sizeof(e) << "\t\t" << typeid(e).name() << endl;
//	cout << f << "\t\t" << sizeof(f) << "\t\t" << typeid(f).name() << endl;
//	cout << g << "\t" << sizeof(g) << "\t\t" << typeid(g).name() << endl;
//
//	auto j = plusNum;// 함수 포인터
//	cout << j(3) << endl;
//
//	auto printme = [] {cout << "hello" << endl; };// 매개변수 없는 함수
//	printme();
//
//	auto plus2 = [](int i) {return i + 1; };//매개변수 있는 함수
//	cout << plus2(3) << endl;
//
//	int count = 0;
//	auto k = [&](int i) {count += i; };//함수 자체(함수 내부에서 외부 변수 참조 시 & 대입)
//	k(1);
//	cout << count << endl;
//
//	auto l = [](int *i)->int& {return *i; };// 함수 자체(참조자를 리턴하려는 경우)
//	cout << l(&count) << endl;
//
//
//	auto gg = fff;
//	auto ggg = fff(5);
//	
//	decltype(fff(3)) gg1 = fff(3);
//	
//	cout << gg << "\t" << sizeof(gg) << "\t\t" << typeid(gg).name() << endl;
//	cout << ggg << "\t" << sizeof(ggg) << "\t\t" << typeid(ggg).name() << endl;
//	cout << gg1 << "\t" << sizeof(gg1) << "\t\t" << typeid(gg1).name() << endl;
//	auto aa = count;
//
//
//
//}

#include <iostream>

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule // 오름차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2)
			return true;
		else return false;
	}
};

class DescendingSort : public SortRule // 내림차순
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
			return false;
		else return true;
	}
};

class DataStorage
{
	int *arr, idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			std::cout << "더 이상 저장이 불가능합니다." << std::endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;
	}
	void SortData(const SortRule &functor)
	{ //버블정렬 사용
		bool flag = true;
		for (int i = 0; i < (idx - 1); i++)
			for (int j = 0; j < (idx - 1); j++) {
				flag = false;
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					flag = true;
				}
			}
	}
};
class Adder {
private:
	int a;
public:
	Adder(int a) {
		this->a = a;
	}
	int addNum(int num) {
		return [=]()->int { return a + num; }();
	}
	int addNum2(int num) {
		return [&]()->int { return a + num; }();
	}
};

void addFunc() {
	std::cout << "ff" << std::endl;
}
static int ccc = 10;
int& foo() {
	ccc++;
	return ccc;
}

void do_something(int* ptr) { *ptr=3; }

int main()
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AscendingSort());
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();

	int a = 10;
	int b = 20;
	int c = 30;
	int result = [](int a, int b)->int {return a + b; }(a, b);
	int result2 = [=]()->int {return a + b; }();
	int result3 = [=,&a,&b]()->int {return a + b+c; }();	
	auto result4 = [](int d)->decltype(auto) {return d * 30; }(a);
	int result5 = [a, &b]()->int {return a + b;}();
	[&b](){ b *= 6; }();// =>동일 [](int &v) {v *= 6;}(b);
	//[b]() {b *= 6; }();
	

	std::cout << "result  : " << result << std::endl;
	std::cout << "result2 : " << result2 << std::endl;
	std::cout << "result3 : " << result3 << std::endl;
	std::cout << "result4 : " << result4 << std::endl;
	std::cout << "result5 : " << result5 << std::endl;
	std::cout << "a  : " << a << std::endl;//a : 10
	std::cout << "b  : " << b << std::endl;//b : 120
	
	Adder adder(10);
	std::cout << adder.addNum(1) << std::endl;
	std::cout << adder.addNum2(1) << std::endl;
	auto myFunction = [] {std::cout << "This is my function" << std::endl; };

	myFunction();
	myFunction(); myFunction();

	int aa = 100;
	int &z = aa;
	int *zz = &aa;
	int zzz = (int)(&aa);
	void (*r)();
	r= myFunction;
	
	foo() = 45;
	//std::cout << "foo  : " << foo() << std::endl;

	std::cout << z << " " << *zz << " " << zzz << " " <<&foo() << " " << &ccc << std::endl;
	

	auto rere = [](int d)->decltype(auto) {return d * 30; };
	std::cout << rere(10) << std::endl;
	

	std::unique_ptr<int> pa = std::make_unique<int>(10);
	do_something(pa.get());

	return 0;
}


