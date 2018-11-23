#pragma once
#include <string>
#include <cmath>
#include "File.h"
using namespace std;

class Folder {
private:
	string name;
	double size;
	File file;
public:
	Folder();
	Folder(string n, double s) { name = n; size = s; };
	void add_file(){}
	void setname(string n) { name = n; };
	string getname() { return name; };
	void setsize(double s) { size = s; };
	double getsize() { return size; };
};
