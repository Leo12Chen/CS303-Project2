#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include "File.h"
using namespace std;

class Folder {
private:
	string name;
	double size;

public:
	Folder();
	Folder(string n, double s) { name = n; size = s; };
	void setname(string n) { name = n; };
	string getname() { return name; };
	vector<File> ListOfFile;
	vector<Folder> ListOfFolder;
	AVL_Tree<Folder*> AVL_Folder;
	AVL_Tree<File*> AVL_File;

	void addsize(double s) {
		size = size + s;
	}
	void deletesize(double s) {
		size -= s;
	}
	double getsize() { return size; };

void findfile(string name) {
		for (int i = 0; i < ListOfFile.size(); i++) {
			if (ListOfFile[i].getname() == name) {
				cout<< "The name of the file is "<<name<<"   the size of the file is "<<ListOfFile[i].getsize()<<endl;
			}
		}
	}

	void getfile() {
		if (ListOfFile.size() == 0) {
			cout << "The Folder is Empty!" << endl;
		}
		for (int i = 0; i < ListOfFile.size(); i++) {
			cout << "The files this folder has are:" << endl;
			cout << "name: " << ListOfFile[i].getname() << " size: " << ListOfFile[i].getsize() << endl;
		}
	}
	void addfile(File file) {
		ListOfFile.push_back(file);
		size += file.getsize();
	}
	double getsizeofFile(string filename) {
		for (int i = 0; i < ListOfFile.size(); i++) {
			if (ListOfFile[i].getname() == filename) {
				return ListOfFile[i].getsize();
			}
		}
	}

	void deletefile(string filename) {
		for (int i = 0; i < ListOfFile.size(); i++) {
			if (ListOfFile[i].getname() == filename) {
				size -= ListOfFile[i].getsize();
				ListOfFile.erase(ListOfFile.begin() + i);

			}
		}
	}
};
