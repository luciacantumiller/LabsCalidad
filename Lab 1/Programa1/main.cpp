#include <iostream>
#include <fstream>
#include <string>

#include "BlankLines.h"
#include "CommentLines.h"

using namespace std; 

int main() {
	string fileName; 
	string line; 
	int size = 0; 
	bool isCommentBlock = false;

	int totalLines = 0;

	BlankLines blank; 
	CommentLines comment; 

	cout << "Ingresar nombre del archivo: "; 
	cin >> fileName; 
	cout << endl; 

	ifstream myfile;
	myfile.open(fileName);

	if (myfile.is_open()) {
		if (myfile.peek() != std::ifstream::traits_type::eof())
		{
			while (!myfile.eof()) {
				getline(myfile, line); 

				if (line.find("//") != string::npos) {
					comment.setCommentLines();
				} else if (line.find("*/") != string::npos) {
					comment.setCommentLines();
					isCommentBlock = false; 
				} else if (line.find("/*") != string::npos || isCommentBlock) {
					comment.setCommentLines();
					isCommentBlock = true; 
				}
				else {
					for (int i = 0; i < line.length(); i++) {
						if (isspace(line[i])) size++; 
					}
					if (size == line.length()) blank.setBlankLines();
					size = 0; 
				}

				totalLines++;
			
			}
		}

		cout << "Nombre del archivo : " << fileName << endl; 
		cout << "--------------------------------------------" << endl;
		cout << "Cantidad de lineas en blanco : " << blank.getBlankLines() << endl;
		cout << "Cantidad de lineas con comentarios : " << comment.getCommentLines() << endl;
		cout << "Cantidad de lineas con codigo : " << (totalLines - blank.getBlankLines() - comment.getCommentLines()) << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Cantidad  total de lineas : " << totalLines << endl;

	}
	else {
		cout << "El archivo seleccionado no existe." << endl; 
	}

	myfile.close();

	return 0; 
}