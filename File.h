#pragma once
#include <string>
#include <cmath>
using namespace std;

class File {
private:
	string name;
	double size;
public:
	File();
	File(string n, double s) { name = n; size = s; };
	void setname(string n) { name = n; };
	string getname() { return name; };
	void setsize(double s) { size = s; };
	double getsize() { return size; };
};
