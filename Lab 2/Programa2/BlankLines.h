//.b =13

#include <string>
#include <iostream>
using namespace std;

class BlankLines {
public:
	BlankLines();
	int getBlankLines();
	void setBlankLines();
	bool isBlankLine(string line); 
private:
	int totalBlankLines; //.m
};

//.i
BlankLines::BlankLines() {
	this->totalBlankLines = 0; //.m
}

//.i
int BlankLines::getBlankLines() {
	return totalBlankLines; //.m
}

//.i
void BlankLines::setBlankLines() {
	totalBlankLines++; //.m
}

//.i
bool BlankLines::isBlankLine(string line) {
	int size = 0; 
	for (size_t i = 0; i <= line.length(); i++) {
		if (isspace(line[i])) size++;
	}
	if (size == line.length()) { 
		setBlankLines();
		size = 0; 
		return true; 
	}

	return false;
}