#include <iostream>
#include<fstream>
#include <string>

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

int main()
{
	FileReader reader;
	reader.TestReceive();
}
