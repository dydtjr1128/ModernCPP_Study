#include <iostream>
#include<fstream>
#include <string>
#include <filesystem>

#include "FileWatcher.h"

class FileReader {
public:
	void TestReceive();
private:

};

void FileReader::TestReceive() {
	//system("dir");
	std::string resultFileaa = "./test.txt";
	std::ifstream readStream(resultFileaa, std::ifstream::in);

	char referenceFileBufferSize[400];
	char referenceFileBuffer[1000];
	std::string line;
	if (readStream.is_open()) {
		while (std::getline(readStream, line)) {
			std::cout << line << std::endl;
		}
		readStream.close();

	}
}

void demo_perms(std::filesystem::perms p) {
	std::cout << ((p & std::filesystem::perms::owner_read) != std::filesystem::perms::none ? "r" : "-")
		<< ((p & std::filesystem::perms::owner_write) != std::filesystem::perms::none ? "w" : "-")
		<< ((p & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ? "x" : "-")
		<< ((p & std::filesystem::perms::group_read) != std::filesystem::perms::none ? "r" : "-")
		<< ((p & std::filesystem::perms::group_write) != std::filesystem::perms::none ? "w" : "-")
		<< ((p & std::filesystem::perms::group_exec) != std::filesystem::perms::none ? "x" : "-")
		<< ((p & std::filesystem::perms::others_read) != std::filesystem::perms::none ? "r" : "-")
		<< ((p & std::filesystem::perms::others_write) != std::filesystem::perms::none ? "w" : "-")
		<< ((p & std::filesystem::perms::others_exec) != std::filesystem::perms::none ? "x" : "-")
		<< '\n';
}

int main() {
	std::filesystem::path p("C:\\2019-11-20.log");
	//std::filesystem::permissions(p.string(),
	//	std::filesystem::perms::owner_all | std::filesystem::perms::group_all,
	//	std::filesystem::perm_options::add);
	if (std::filesystem::exists(p)) {
		std::cout << "exist" << std::endl;
		demo_perms(std::filesystem::status(p.string()).permissions());
		std::filesystem::remove(p);
	}
	std::cout << std::filesystem::current_path();	
	//std::filesystem::remove(p);

	//std::filesystem::create_directories("sandbox/1/2/a"); // create directories recursively
	////std::filesystem::create_directory("sandbox2/1/2/b"); // error

	//FileWatchar fileWatchar;
	//fileWatchar.addPath("C:/Users/CYS/Downloads/temp2.txt");
	//fileWatchar.start([](std::filesystem::path path, FileStatus status) {
	//	switch (status)
	//	{
	//	case FileStatus::Created:
	//		std::cout << path.string() << " Created!" << std::endl;
	//		break;
	//	case FileStatus::Modified:
	//		std::cout << path.string() << " Modified!" << std::endl;
	//		break;
	//	case FileStatus::Erased:
	//		std::cout << path.string() << " Erased!" << std::endl;
	//		break;
	//	default:
	//		std::cout << "error!" << std::endl;
	//		break;
	//	}
	//	});
	
}
