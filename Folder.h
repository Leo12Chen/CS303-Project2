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
	
	void add_folder(string path, string folder_name)
	{
		int folder_size = ListOfFolder.size();
		Folder new_folder(folder_name, 0);
		string s = path + "/";
		string delimiter = "/";
		size_t pos = 0;
		string token;

		while ((pos = s.find(delimiter)) != string::npos) {
			token = s.substr(0, pos);
			s.erase(0, pos + delimiter.length());

			for (int i = 0; i != folder_size; i++)
			{
				if (token == ListOfFolder[i].getname() && s == "")
					ListOfFolder[i].ListOfFolder.push_back(new_folder);

				else if (token == ListOfFolder[i].getname() && s != "")
					folder_size = ListOfFolder[i].ListOfFolder.size();

				else
					cout << "Path Does Not Exist!" << endl;
			}
		}
	}
	
	void setname(string n) { name = n; };
	string getname() { return name; };
	void setsize(double s) { size = s; };
	double getsize() { return size; };
};
