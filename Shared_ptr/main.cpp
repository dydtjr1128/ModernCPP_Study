#include <memory>
#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;
class Song {
private:
	string title;
	string artist;
public:
	Song(string artist, string title) {
		this->artist = artist;
		this->title = title;
	}
	string getTitle() {
		return title;
	}
	string getArtist() {
		return artist;
	}
};

void SongVector()
{
	//shared_ptr 생성 방법
	auto sp1 = make_shared<Song>("The Beatles", "Im Happy Just to Dance With You");

	shared_ptr<Song> sp2(new Song("Twice", "Fancy"));

	shared_ptr<Song> sp3(nullptr);
	sp3 = make_shared<Song>("Elton John", "I'm Still Standing");

	//shared_ptr 변경 및 초기화 방법
	auto sp4(sp2);//복사 생성자를 이용한 초기화 ref_count++
	auto sp5 = sp2;//sp5에 sp2 할당 초기화 ref_count++
	cout << sp5.use_count() << endl;//3
}
int main() {
	SongVector();
}