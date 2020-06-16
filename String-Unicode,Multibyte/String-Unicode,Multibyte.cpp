#include <iostream>
#include <vector>
#include <string>
#include <locale> 
#include <cstddef>
#include <io.h>
#include <fcntl.h>


int main() {
	//system("chcp 65001");
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
		L"안녕하세요 만나서 반가워요.", // 한국어
		L"Hi, it's nice to meet you.", // 영어
		L"こんにちは。お会いできて嬉しいです。", // 일본어
		L"你好,很高兴见到你。", // 중국어
		L"Encantado de conocerte.", // 스페인어
		L"Hallo, schön, Sie kennenzulernen.", // 독일어
		L"Привет всем, рад встрече.", // 러시아어
		L"Xin chào, rất vui được gặp bạn.", // 베트남어
		L"สวัสดีค่ะ ยินดีที่ได้พบนะคะ", // 태국어
		L"हाय, यह आप को पूरा करने के लिए अच्छा है।", // 힌디어
		L"Oi, é um prazer conhecê-lo." // 포르투갈어			
	};

	const char * u8texts[] =
	{
		u8"안녕하세요 만나서 반가워요.", // 한국어
		u8"Hi, it's nice to meet you.", // 영어
		u8"こんにちは。お会いできて嬉しいです。", // 일본어
		u8"你好,很高兴见到你。", // 중국어
		u8"Encantado de conocerte.", // 스페인어
		u8"Hallo, schön, Sie kennenzulernen.", // 독일어
		u8"Привет всем, рад встрече.", // 러시아어
		u8"Xin chào, rất vui được gặp bạn.", // 베트남어
		u8"สวัสดีค่ะ ยินดีที่ได้พบนะคะ", // 태국어
		u8"हाय, यह आप को पूरा करने के लिए अच्छा है।", // 힌디어
		u8"Oi, é um prazer conhecê-lo." // 포르투갈어			
	};

	constexpr int length = 10;

	std::cout << "================ std::string ================" << std::endl;

	for (size_t i = 0; i < length; i++)	{
		std::cout << texts[i] << std::endl;
	}
	
	std::cout << "================ std::wstring ================" << std::endl;

	for (size_t i = 0; i < length; i++) {
		std::wcout << wtexts[i] << std::endl;
	}

	std::cout << "================ char * u8 ================" << std::endl;

	for (size_t i = 0; i < length; i++) {
		std::cout << u8texts[i] << std::endl;
	}
}
