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
//	unique_ptr<list<string>>  producers;//Song class�� unique_ptr�� ����.
//public:
//	// list<string> �⺻ �����ڿ� make_unique�� �̿��� �ʱ�ȭ
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
//	//unique_ptr ���� �� vector�� �߰�
//	songs.push_back(make_unique<Song>("Anne-Marie", "2002"));
//	songs.push_back(make_unique<Song>("Namie Amuro", "Funky Town"));
//	songs.push_back(SongFactory("Twice","FANCY"));
//
//	auto song = make_unique<Song>("Ayumi Hamasaki", "Poker Face");
//	
//	unique_ptr<Song> song2 = std::move(song);//song�� "Ayumi Hamasaki" & "Poker Face"�� ���� �� �� ����.
//	
//	//songs.push_back(song2);//����! song2�� song2��� ���۷����� ������ �ΰ� �����Ƿ� move�� ���� ������ �Ű��־�� �Ѵ�.
//	songs.push_back(std::move(song2));
//
//	for (const auto& song : songs)
//	{
//		printf("Artist: %15s Title: %s\n", song->getArtist().c_str(), song->getTitle().c_str());
//	}
//	
//	song.reset(); // song�� ����Ű�� �ִ� �޸� ������ ������.
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
		std::cout << "�ڿ��� ȹ����!" << std::endl;
		data = new int[100];
	}

	void some() { std::cout << "�Ϲ� �����Ϳ� �����ϰ� ��밡��!" << std::endl; }

	~A() {
		std::cout << "�ڿ��� ������!" << std::endl;
		//delete[] data;
	}
};

void do_something() {
	std::unique_ptr<A> pa = std::make_unique<A>();
	std::cout << "pa : ";
	pa->some();

	// pb �� �������� ����.
	std::unique_ptr<A> pb = std::move(pa);
	std::cout << "pb : ";
	pb->some();
}
int* do_something2() {
	std::unique_ptr<int[]> pa = std::make_unique<int[]>(1000);
	std::cout << "pa[0] : " << pa[0] << std::endl;
	pa[0] = 10;

	// pb �� �������� ����.
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
	std::cout << "���α׷� ����" << std::endl;

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

	const int* a = &t;//��
	int const* b = &t;//��
	const int* const c = &t;//��
	const int const* d = &t;//��

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