//
//struct Command {
//	char cmd;
//	int len;
//};
//template <class T>
//void foo(T& a) {
//	static_assert(sizeof(Command) == sizeof(a.cmd) + sizeof(a.len), "Command size is different");
//}
//int main() {
//	Command a;
//	foo(a);
//}
#include <type_traits>
struct Myclass {
	Myclass(const Myclass&) = delete;
	Myclass() = default;
};

template <class T>
void my_assert(T& a)
{
	static_assert(std::is_copy_constructible<T>::value,
		"Copy constructure is unavailable");
}

int main()
{
	Myclass a;
	my_assert(a);
}