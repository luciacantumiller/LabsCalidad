//.b =48
#include <iostream>
#include <fstream>
#include <string>

#include "BlankLines.h"
#include "CommentLines.h"
#include "ClassTypeLOC.h"

using namespace std; 

//.i
int main() { 
	string fileName; 
	int numArchivos; 
	int pos = 0; 
	int count = 1; 
	string files[50]; 
	int fileData[50][5];
	string line;
	bool found; 
	//.d=2

	ifstream myfile;
	int totalLines = 0;

	BlankLines blank;
	CommentLines comment;
	ClassTypeLOC file; 

	cout << "Ingresar numero de archivos a leer: "; 
	cin >> numArchivos; 

	for (int r = 0; r < numArchivos; r++) {
		for (int c = 0; c < 5; c++) {
			fileData[r][c] = 0; 
		}
	}

	for (int i = 0; i < numArchivos; i++) {
		cout << "Ingresar nombre del archivo: ";
		cin >> fileName;
		myfile.open(fileName);
		found = false; 

		if (myfile.is_open()) {

			fileName.erase(fileName.find("."), fileName.length());
		
		
			for (int x = 0; x < count; x++) {
				int i = 0; 
				if (files[x] == fileName) { 
					pos = x; 
					found = true; 
				}
			}

			if (!found) {
				files[count-1] = fileName;
				pos = count-1; 
				count++;
			}

			if (myfile.peek() != std::ifstream::traits_type::eof())
			{
				file.setLines(fileData[pos][0], fileData[pos][1], fileData[pos][2], fileData[pos][3], fileData[pos][4]);
				while (!myfile.eof()) {
					getline(myfile, line);
					if (!blank.isBlankLine(line) && !comment.isCommentLine(line)) {
						file.lineCount(line);
					}
					//.d=14
				}
			}

			int* aux = file.getLines();
			fileData[pos][0] = aux[0]; 
			fileData[pos][1] = aux[1]; 
			fileData[pos][2] = aux[2];
			fileData[pos][3] = aux[3];
			fileData[pos][4] = aux[4];

			//.d=7
		}
		else {
			cout << "El archivo seleccionado no existe." << endl;
		}

		myfile.close();
	}
	ofstream ConteoLDC; 
	ConteoLDC.open("ConteoLDC.txt");

	cout << "CLASE BASE:" << endl; 
	for (int x = 0; x < count - 1; x++) { 
		file.setLines(fileData[x][0], fileData[x][1], fileData[x][2], fileData[x][3], fileData[x][4]);
		if (file.getClassType() == "base") {
			cout << files[x] << " T= " << fileData[x][0] << " I= " << fileData[x][1] << " B= " << fileData[x][2] << " D= " << fileData[x][3] << " M= " << fileData[x][4] << " A= " << fileData[x][0] - fileData[x][2] + fileData[x][3] << endl;
		}
	}
	cout << "------------------------------------" << endl; 
	cout << "CLASE NUEVAS:" << endl;
	for (int x = 0; x < count - 1; x++) {
		file.setLines(fileData[x][0], fileData[x][1], fileData[x][2], fileData[x][3], fileData[x][4]);
		if (file.getClassType() == "new") {
			cout << files[x] << " T= " << fileData[x][0] << " I= " << fileData[x][1] << endl;
		}
	}
	cout << "------------------------------------" << endl;
	cout << "CLASE REUSADAS:" << endl;
	for (int x = 0; x < count - 1; x++) {
		file.setLines(fileData[x][0], fileData[x][1], fileData[x][2], fileData[x][3], fileData[x][4]);
		if (file.getClassType() == "reused") {
			cout << files[x] << " T= " << fileData[x][0] << " I= " << fileData[x][1] << " B= "  << fileData[x][2] << endl;
		}
	}
	cout << "------------------------------------" << endl;
	for (int i = 0; i < count-1; i++) {
		totalLines += fileData[i][0]; 
	}
	cout << "Total de LDC= " << totalLines; 
	


	ConteoLDC << "CLASE BASE:" << endl;
	for (int x = 0; x < count - 1; x++) {
		file.setLines(fileData[x][0], fileData[x][1], fileData[x][2], fileData[x][3], fileData[x][4]);
		if (file.getClassType() == "base") {
			ConteoLDC << files[x] << " T= " << fileData[x][0] << " I= " << fileData[x][1] << " B= " << fileData[x][2] << " D= " << fileData[x][3] << " M= " << fileData[x][4] << " A= " << fileData[x][0] - fileData[x][2] + fileData[x][3] << endl;
		}
	}
	ConteoLDC << "------------------------------------" << endl;
	ConteoLDC << "CLASE NUEVAS:" << endl;
	for (int x = 0; x < count - 1; x++) {
		file.setLines(fileData[x][0], fileData[x][1], fileData[x][2], fileData[x][3], fileData[x][4]);
		if (file.getClassType() == "new") {
			ConteoLDC << files[x] << " T= " << fileData[x][0] << " I= " << fileData[x][1] << endl;
		}
	}
	ConteoLDC << "------------------------------------" << endl;
	ConteoLDC << "CLASE REUSADAS:" << endl;
	for (int x = 0; x < count - 1; x++) {
		file.setLines(fileData[x][0], fileData[x][1], fileData[x][2], fileData[x][3], fileData[x][4]);
		if (file.getClassType() == "reused") {
			ConteoLDC << files[x] << " T= " << fileData[x][0] << " I= " << fileData[x][1] << " B= " << fileData[x][2] << endl;
		}
	}
	ConteoLDC << "------------------------------------" << endl;
	for (int i = 0; i < count - 1; i++) {
		totalLines += fileData[i][0];
	}
	ConteoLDC << "Total de LDC= " << totalLines;
	
	ConteoLDC.close(); 
	return 0;
}