#include <iostream>
#include<fstream>
#include <string>
#include <filesystem>

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

int main() {
	std::filesystem::create_directories("sandbox/1/2/a"); // create directories recursively
	//std::filesystem::create_directory("sandbox2/1/2/b"); // error
	
}
