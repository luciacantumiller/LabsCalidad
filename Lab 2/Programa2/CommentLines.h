//.b =13

#include <string>
using namespace std;

class CommentLines {
public:
	CommentLines();
	int getCommentLines();
	void setCommentLines();
	bool getIsCommentBlock();
	bool isCommentLine(string line);
private:
	int totalCommentLines; //.m
	bool isCommentBlock; 
};

//.i
CommentLines::CommentLines() { 
	this->totalCommentLines = 0; //.m
	this->isCommentBlock = false; 
}

//.i
int CommentLines::getCommentLines() {
	return totalCommentLines; //.m
}

//.i
void CommentLines::setCommentLines() {
	totalCommentLines++; //.m
}

//.i
bool CommentLines::getIsCommentBlock() {
	return isCommentBlock;
}

//.i
bool CommentLines::isCommentLine(string line) {
	if (line.find("*/") != string::npos) {
		setCommentLines();
		isCommentBlock = false;
		return true;
	}
	else if (line.find("//") != string::npos) {
		size_t found = line.find("//"); 
		if (line[found += 2] == '.' || !isalpha(line[found--])) {
			return false;
		}
		setCommentLines();
		return true; 
	}
	else if (line.find("/*") != string::npos || isCommentBlock) {
		setCommentLines();
		isCommentBlock = true;
		return true;
	}
	return false; 
}