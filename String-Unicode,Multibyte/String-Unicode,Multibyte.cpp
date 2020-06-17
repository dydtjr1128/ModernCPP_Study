#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>

using namespace std::string_literals; // enables s-suffix for std::string literals
void string_example() {
	// Character literals
	auto c0 = 'A'; // char
	auto c1 = u8'A'; // char
	auto c2 = L'A'; // wchar_t
	auto c3 = u'A'; // char16_t
	auto c4 = U'A'; // char32_t

	// Multicharacter literals
	auto m0 = 'abcd'; // int, value 0x61626364

	// String literals
	auto s0 = "hello"; // const char*
	auto s1 = u8"hello"; // const char*, encoded as UTF-8
	auto s2 = L"hello"; // const wchar_t*
	auto s3 = u"hello"; // const char16_t*, encoded as UTF-16
	auto s4 = U"hello"; // const char32_t*, encoded as UTF-32

	// Raw string literals containing unescaped \ and "
	auto R0 = R"("Hello \ world")"; // const char*
	auto R1 = u8R"("Hello \ world")"; // const char*, encoded as UTF-8
	auto R2 = LR"("Hello \ world")"; // const wchar_t*
	auto R3 = uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
	auto R4 = UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32

	// Combining string literals with standard s-suffix
	auto S0 = "hello"s; // std::string
	auto S1 = u8"hello"s; // std::string
	auto S2 = L"hello"s; // std::wstring
	auto S3 = u"hello"s; // std::u16string
	auto S4 = U"hello"s; // std::u32string

	// Combining raw string literals with standard s-suffix
	auto S5 = R"("Hello \ world")"s; // std::string from a raw const char*
	auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char*, encoded as UTF-8
	auto S7 = LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
	auto S8 = uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
	auto S9 = UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32
}

#include <Windows.h>
#include <string.h>
int main() {
	system("chcp 65001");
	SetConsoleOutputCP(CP_UTF8);
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 20;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//getchar();
	wcscpy_s(cfi.FaceName, L"D2Coding");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	//std::locale::global(std::locale(""));
	//std::cout.imbue(std::locale());
	//std::wcout.imbue(std::locale());

	const std::string texts[] =
	{
		"안녕하세요 만나서 반가워요.", // 한국어
		"Hi, it's nice to meet you.", // 영어
		"こんにちは。お会いできて嬉しいです。", // 일본어
		"你好,很高兴见到你。", // 중국어
		"Encantado de conocerte.", // 스페인어
		"Hallo, schön, Sie kennenzulernen.", // 독일어
		"Привет всем, рад встрече.", // 러시아어
		"Xin chào, rất vui được gặp bạn.", // 베트남어
		"สวัสดีค่ะ ยินดีที่ได้พบนะคะ", // 태국어
		"हाय, यह आप को पूरा करने के लिए अच्छा है।", // 힌디어
		"Oi, é um prazer conhecê-lo." // 포르투갈어		
	};

	const std::wstring wtexts[] =
	{
		L"안녕하세요 만나서 반가워요."s, // 한국어
		L"Hi, it's nice to meet you."s, // 영어
		L"こんにちは。お会いできて嬉しいです。"s, // 일본어
		L"你好,很高兴见到你。"s, // 중국어
		L"Encantado de conocerte."s, // 스페인어
		L"Hallo, schön, Sie kennenzulernen."s, // 독일어
		L"Привет всем, рад встрече."s, // 러시아어
		L"Xin chào, rất vui được gặp bạn."s, // 베트남어
		L"สวัสดีค่ะ ยินดีที่ได้พบนะคะ"s, // 태국어
		L"हाय, यह आप को पूरा करने के लिए अच्छा है।"s, // 힌디어
		L"Oi, é um prazer conhecê-lo."s // 포르투갈어			
	};

	const std::string u8texts[] =
	{
		u8"안녕하세요 만나서 반가워요."s, // 한국어
		u8"Hi, it's nice to meet you."s, // 영어
		u8"こんにちは。お会いできて嬉しいです。"s, // 일본어
		u8"你好,很高兴见到你。"s, // 중국어
		u8"Encantado de conocerte."s, // 스페인어
		u8"Hallo, schön, Sie kennenzulernen."s, // 독일어
		u8"Привет всем, рад встрече."s, // 러시아어
		u8"Xin chào, rất vui được gặp bạn."s, // 베트남어
		u8"สวัสดีค่ะ ยินดีที่ได้พบนะคะ"s, // 태국어
		u8"हाय, यह आप को पूरा करने के लिए अच्छा है।"s, // 힌디어
		u8"Oi, é um prazer conhecê-lo."s // 포르투갈어			
	};

	constexpr int length = 10;

	std::cout << "================ std::string ================" << std::endl;

	for (size_t i = 0; i < length; i++) {

		std::cout << texts[i] << std::endl;
	}

	std::cout << "================ std::wstring ================" << std::endl;

	for (size_t i = 0; i < length; i++) {
		std::wcout << wtexts[i] << std::endl;
	}

	std::cout << "================ utf-8 ================" << std::endl;

	for (size_t i = 0; i < length; i++) {
		std::cout << u8texts[i] << std::endl;
	}

}
