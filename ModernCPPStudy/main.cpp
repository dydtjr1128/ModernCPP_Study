//#include <memory>
//#include <vector>
//#include <list>
//#include <string>
//#include <stdio.h>
//
//using namespace std;
//class Song {
//private:
//	string title;
//	string artist;
//	unique_ptr<list<string>>  producers;//Song class는 unique_ptr을 소유.
//public:
//	// list<string> 기본 생성자와 make_unique를 이용한 초기화
//	Song(string artist, string title) : producers(make_unique<list<string>>()) {
//		this->artist = artist;
//		this->title = title;		
//	}
//	string getTitle() {
//		return title;
//	}
//	string getArtist() {
//		return artist;
//	}
//};
//unique_ptr<Song> SongFactory(const string& artist, const string& title)
//{
//	return make_unique<Song>(artist, title);
//}
//
//void SongVector()
//{
//	vector<unique_ptr<Song>> songs;
//	//unique_ptr 생성 및 vector에 추가
//	songs.push_back(make_unique<Song>("Anne-Marie", "2002"));
//	songs.push_back(make_unique<Song>("Namie Amuro", "Funky Town"));
//	songs.push_back(SongFactory("Twice","FANCY"));
//
//	auto song = make_unique<Song>("Ayumi Hamasaki", "Poker Face");
//	
//	unique_ptr<Song> song2 = std::move(song);//song은 "Ayumi Hamasaki" & "Poker Face"에 접근 할 수 없다.
//	
//	//songs.push_back(song2);//에러! song2는 song2라는 레퍼런스가 연결을 맺고 있으므로 move를 통해 연결을 옮겨주어야 한다.
//	songs.push_back(std::move(song2));
//
//	for (const auto& song : songs)
//	{
//		printf("Artist: %15s Title: %s\n", song->getArtist().c_str(), song->getTitle().c_str());
//	}
//	
//	song.reset(); // song이 가리키고 있는 메모리 영역을 삭제함.
//}
//int main() {
//	SongVector();
//}
#include <iostream>
#include <memory>

class A {
	int *data;

public:
	A() {
		std::cout << "자원을 획득함!" << std::endl;
		data = new int[100];
	}

	void some() { std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl; }

	~A() {
		std::cout << "자원을 해제함!" << std::endl;
		//delete[] data;
	}
};

void do_something() {
	std::unique_ptr<A> pa = std::make_unique<A>();
	std::cout << "pa : ";
	pa->some();

	// pb 에 소유권을 이전.
	std::unique_ptr<A> pb = std::move(pa);
	std::cout << "pb : ";
	pb->some();
}
int* do_something2() {
	std::unique_ptr<int[]> pa = std::make_unique<int[]>(1000);
	std::cout << "pa[0] : " << pa[0] << std::endl;
	pa[0] = 10;

	// pb 에 소유권을 이전.
	std::unique_ptr<int []> pb = std::move(pa);
	std::cout << "pb[0] : " << pb[0] << std::endl;
	int *p = pb.get();
	std::cout << p[0] << std::endl;

	return pb.get();
}

int main() {
	int *p = do_something2();
	std::cout << p[0] << std::endl;
	_sleep(1000);
	std::cout << "프로그램 종료" << std::endl;

	//rvalue example

	int rr = 100;
	auto &&q = rr;
	int &r = q;
	int *pp = &rr;


	*pp = 600;
	int &ab = *pp;
	std::cout << rr << " " << typeid(q).name() << " " << typeid(r).name() << std::endl;
	q = 100;
	ab = 400;
	std::cout << rr << " " << typeid(q).name() << " " << typeid(r).name() << std::endl;
	r = 5;
	std::cout << rr << " " << typeid(q).name() << " " << typeid(r).name() << std::endl;

	//end


	const int t = 10;
	const int& num = 0;

	const int* a = &t;//①
	int const* b = &t;//②
	const int* const c = &t;//③
	const int const* d = &t;//④

	std::cout << "a : " << *a << std::endl;
	std::cout << "b : " << *b << std::endl;
	std::cout << "c : " << *c << std::endl;
	std::cout << "d : " << *d << std::endl;
	int ii = 10;
	auto myFunc = [=]()mutable-> int{
		ii *= 5;
		return ii;
	};

	

/*
		int const* const
		int const*
		int* const*/

	
}