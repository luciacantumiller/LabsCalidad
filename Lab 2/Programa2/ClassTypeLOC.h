#include <string>
#include <iostream>
using namespace std;

class ClassTypeLOC {
public:
	ClassTypeLOC();
	void setLines(int total, int items, int base, int deleted, int modified); 
	int	* getLines();
	void lineCount(string line);
	string getClassType(); 
private:
	int totalItems;
	int totalBaseLines;
	int totalModified; 
	int totalDeleted;
	int totalLines; 
};

//.i
ClassTypeLOC::ClassTypeLOC() {
	this->totalItems = 0;
	this->totalBaseLines = 0;
	this->totalModified = 0;
	this->totalDeleted = 0;
	this->totalLines = 0; 
}

//.i
void ClassTypeLOC::setLines(int total, int items, int base, int deleted, int modified) {
	totalItems = items;
	totalBaseLines = base;
	totalModified = modified;
	totalDeleted = deleted;
	totalLines = total;
}

//.i
int * ClassTypeLOC::getLines() {
	int lines[5]; 
	lines[0] = totalLines; 
	lines[1] = totalItems;
	lines[2] = totalBaseLines; 
	lines[3] = totalDeleted;
	lines[4] = totalModified;
	return lines;
}

//.i
void ClassTypeLOC::lineCount(string line) {
	if (line.find("\"") == string::npos) {
		if (line.find("//.i") != string::npos) {
			totalItems++;
		}
		else if (line.find("//.m") != string::npos) {
			totalModified++; 
			totalLines++; 
		}
		else if (line.find("//.d") != string::npos) {
			string num = "";
			size_t found = line.find("=");
			found++;

			while (isdigit(line[found])) {
				num.push_back(line[found]);
				found++;
			}

			int i = stoi(num);

			totalDeleted += i;
		}
		else if (line.find("//.b") != string::npos) {
			string num = "";
			size_t found = line.find("=");
			found++;

			while (isdigit(line[found])) {
				num.push_back(line[found]);
				found++;
			}

			int i = stoi(num);
			totalBaseLines += i; 

		}
		else {
			totalLines++; 
		}
	}
}

//.i
string ClassTypeLOC::getClassType() {
	if (totalBaseLines == 0) {
		return "new";
	}
	else if (totalModified == 0 && totalDeleted == 0 && totalLines - totalBaseLines == 0) {
		return "reused";
	}
	else {
		return "base"; 
	}

	return "error";
}