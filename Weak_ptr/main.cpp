#include <memory>
#include <cassert>
class Integer {
private:
	int value;
public:
	constexpr Integer() : value() { }
	constexpr Integer(int value) : value(value) { }
	constexpr operator int() { return value; }
};
constexpr int base_HP = 100;
constexpr int AssignHP(int nPlusHP) {
	return base_HP + nPlusHP;
}

int main() {
	constexpr Integer size = 5; // 컴파일 타임에 정수로
	
	//int x[size]; // Integer::operator int()가 호출된다

	int i = 10, j = 20;
	const int AGE = 30; //OK
	const int AGE2 = i + j; //OK
	constexpr int AGE3 = 26;//OK
	//constexpr int AGE4 = i + j;//ERROR!
	constexpr int AGE5 = 10 + 16;//OK!
	constexpr int a = 20, b = 30;
	constexpr int AGE6 = a + b;
	printf("%d", a);

	assert(i != 10);
	
	i++;

	int NPC_Lv1_HP = AssignHP(0);
	int NPC_Lv2_HP = AssignHP(200);
}