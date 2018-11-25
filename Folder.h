#pragma once
#include <string>
#include <cmath>
#include <vector>
#include "File.h"
using namespace std;

class Folder {
private:
	string name;
	double size;
	vector<File> ListOfFile;
	vector<Folder> ListOfFolder;
public:
	Folder();
	Folder(string n, double s) { name = n; size = s; };
	void add_file(File file) {
		ListOfFile.push_back(file);
		size += file.getsize();
	}
	
	void setname(string n) { name = n; };
	string getname() { return name; };
	void setsize(double s) { size = s; };
	double getsize() { return size; };
};
