#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#ifdef _WIN32
	#include <Windows.h>
#endif // WIN


#include <string.h>

using namespace std::string_literals; // enables s-suffix for std::string literals

std::string to_utf8(const std::string& ansi) {
#ifdef _WIN32
	WCHAR unicode[1500];
	char utf8[1500];

	memset(unicode, 0, sizeof(unicode));
	memset(utf8, 0, sizeof(utf8));

	::MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), -1, unicode, sizeof(unicode));
	::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, utf8, sizeof(utf8), NULL, NULL);

	return std::string(utf8);
#elif
	return ansi;
#endif
}
#include <atlstr.h>
std::string ToUTF8(const std::string& ansi) { // ansi(멀티바이트)를 utf로 변경하기 위해서는 ansi-> utf16(유니코드) -> utf8로 변경이 필요하다(윈도우의 경우)

	////ansi -> utf16(유니코드)으로 변경
	//int nLen = MultiByteToWideChar(CP_ACP, 0, &ansi[0], ansi.size(), NULL, NULL);
	//std::wstring strUni(nLen, 0); 
	//MultiByteToWideChar(CP_ACP, 0, &ansi[0], ansi.size(), &strUni[0], nLen);


	////utf16 -> utf8
	//char strUtf8[256] = { 0, }; 
	//int nLen = WideCharToMultiByte(CP_UTF8, 0, strUni, lstrlenW(strUni), NULL, 0, NULL, NULL);
	//WideCharToMultiByte(CP_UTF8, 0, strUni, lstrlenW(strUni), strUtf8, nLen, NULL, NULL);
}

std::string ANSIToUTF8(const std::string& ansi)
{
	int size = MultiByteToWideChar(CP_ACP, MB_COMPOSITE, ansi.c_str(),
		ansi.length(), nullptr, 0);
	std::wstring utf16_str(size, '\0');
	MultiByteToWideChar(CP_ACP, MB_COMPOSITE, ansi.c_str(),
		ansi.length(), &utf16_str[0], size);

	int utf8_size = WideCharToMultiByte(CP_UTF8, 0, utf16_str.c_str(),
		utf16_str.length(), nullptr, 0,
		nullptr, nullptr);
	std::string utf8_str(utf8_size, '\0');
	WideCharToMultiByte(CP_UTF8, 0, utf16_str.c_str(),
		utf16_str.length(), &utf8_str[0], utf8_size,
		nullptr, nullptr);

	return utf8_str;
}

std::wstring utf8_to_wstring(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(str);
}

// convert wstring to UTF-8 string
std::string wstring_to_utf8(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}
std::string to_utf88(const std::string& str) {
	return wstring_to_utf8(utf8_to_wstring(str));
}



int main() {
	//SetConsoleOutputCP(CP_UTF8);
	//CONSOLE_FONT_INFOEX cfi;
	//cfi.cbSize = sizeof cfi;
	//cfi.nFont = 0;
	//cfi.dwFontSize.X = 0;
	//cfi.dwFontSize.Y = 20;
	//cfi.FontFamily = FF_DONTCARE;
	//cfi.FontWeight = FW_NORMAL;
	////getchar();
	//wcscpy_s(cfi.FaceName, L"D2Coding");
	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//
	//std::locale::global(std::locale(""));
	//std::cout.imbue(std::locale());
	//std::wcout.imbue(std::locale());	
	//system("chcp 949");
	std::wcout.imbue(std::locale("korean"));
	const std::string texts[] =
	{
		"안녕하세요 만나서 반가워요."s, // 한국어
		"Hi, it's nice to meet you."s, // 영어
		"こんにちは。お会いできて嬉しいです。"s, // 일본어
		"你好,很高兴见到你。"s, // 중국어
		"Encantado de conocerte."s, // 스페인어
		"Hallo, schön, Sie kennenzulernen."s, // 독일어
		"Привет всем, рад встрече."s, // 러시아어
		"Xin chào, rất vui được gặp bạn."s, // 베트남어
		"สวัสดีค่ะ ยินดีที่ได้พบนะคะ"s, // 태국어
		"हाय, यह आप को पूरा करने के लिए अच्छा है।"s, // 힌디어
		"Oi, é um prazer conhecê-lo."s, // 포르투갈어		
		"✌😃💕🐱‍🏍🏍✝⛎💛(❁´◡`❁)"s // 이모티콘
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
		L"Oi, é um prazer conhecê-lo."s, // 포르투갈어			
		L"✌😃💕🐱‍🏍🏍✝⛎💛(❁´◡`❁)"s // 이모티콘
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
		u8"Oi, é um prazer conhecê-lo."s, // 포르투갈어			
		u8"✌😃💕🐱‍🏍🏍✝⛎💛(❁´◡`❁)"s // 이모티콘
	};

	const std::u16string u16texts[] =
	{
		u"안녕하세요 만나서 반가워요."s, // 한국어
		u"Hi, it's nice to meet you."s, // 영어
		u"こんにちは。お会いできて嬉しいです。"s, // 일본어
		u"你好,很高兴见到你。"s, // 중국어
		u"Encantado de conocerte."s, // 스페인어
		u"Hallo, schön, Sie kennenzulernen."s, // 독일어
		u"Привет всем, рад встрече."s, // 러시아어
		u"Xin chào, rất vui được gặp bạn."s, // 베트남어
		u"สวัสดีค่ะ ยินดีที่ได้พบนะคะ"s, // 태국어
		u"हाय, यह आप को पूरा करने के लिए अच्छा है।"s, // 힌디어
		u"Oi, é um prazer conhecê-lo."s, // 포르투갈어
		u"✌😃💕🐱‍🏍🏍✝⛎💛(❁´◡`❁)"s // 이모티콘
	};

	constexpr int length = 12;

	std::cout << "================ std::string ================" << std::endl;

	for (size_t i = 0; i < length; i++) {

		std::cout << to_utf88(texts[i]) << std::endl;
	}

	/*std::wcout << L"================ std::wstring ================" << std::endl;

	
	for (size_t i = 0; i < length; i++) {
		std::wcout << wtexts[i] << std::endl;
	}*/
	std::cout << "================ utf-8 ================" << std::endl;

	for (size_t i = 0; i < length; i++) {
		std::cout << u8texts[i] << std::endl;
	}

	std::cout << "================ utf-16 ================" << std::endl;

	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> codecvt;
	for (size_t i = 0; i < length; i++) {
		std::cout << codecvt.to_bytes(u16texts[i]) << std::endl;		
	}
	std::wstring temp = L"hello";
	std::wcout << temp;
	


}
