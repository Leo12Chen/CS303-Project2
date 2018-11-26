/*##########################################################################################################
By Leo Chen and Steven Hoang
11/25/2018
Project 2A
############################################################################################################
Basic Algorithm for the Project:
For the whole project we have the Folder class and File class,
Folder is able to contain folders and files, they are stored in
two vectors. And we will do the search by the avl tree.
First we have the function to decode the path, which we split the
path by '/'.It is able to add folders and files, delete folders
and files and get the list of files. This main.cpp baiscly is the
simulator for the project. Have to test it manually.
############################################################################################################
*/

#include "AVL_Tree.h"
#include "Folder.h"
#include "File.h"
#include <iostream>
#include <array>
#include <cmath>
#include <vector>

using namespace std;

vector<string> split(string path) {//here is the function to decode the path
	vector<string> vpath;
	string s = path + "/";
	string delimiter = "/";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		vpath.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	return vpath;
}
void add_folders(AVL_Tree<Folder*>& avl, string path, string folder_name) //function for add folder
{
	Folder new_folder(folder_name, 0);
	string s = path + "/";
	string delimiter = "/";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}
	Folder* find_folder = new Folder(token, 0);
	Folder* temp = avl.find(find_folder);
	temp->ListOfFolder.push_back(new_folder);
}

void delete_folders(AVL_Tree<Folder*>& avl, string path, string folder_name) //function for delete folder
{
	Folder new_folder(folder_name, 0);
	string s = path + "/";
	string delimiter = "/";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}
	Folder* find_folder = new Folder(token, 0);
	Folder* temp = avl.find(find_folder);
	temp->ListOfFolder.pop_back();
}

void add_file(string path, string name, double size, vector<Folder> &f) {//function for add files
	vector<string> foldersname = split(path);
	for (int i = 0; i < f.size(); i++) {
		if (f[i].getname() == foldersname[foldersname.size() - 1]) {
			f[i].addfile(File(name, size));
		}
		for (int j = 0; j < foldersname.size() - 1; j++) {
			if (f[i].getname() == foldersname[j]) {
				f[i].addsize(size);
			}
		}

	}
}

File get_files(AVL_Tree<File*>& avl, string path, string file_name)  //function for get files
{
	File new_file(file_name, 0);
	string s = path + "/";
	string delimiter = "/";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}
	File* find_file = new File(token, 0);
	File* re_file = avl.find(find_file);
	return *re_file;

}



void delete_files(AVL_Tree<File*>& avl, string path, string file_name) //function for delete files
{

	File new_file(file_name, 0);
	string s = path + "/";
	string delimiter = "/";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}
	File* find_file = new File(token, 0);
	File* temp = avl.find(find_file);
	temp = NULL;

}

vector<File> get_files(string path, vector<Folder> &f) { //get the list of the files, instead of list, we used vector
	vector<string> foldersname = split(path);
	vector<File> ListOfFile;
	for (int i = 0; i < f.size(); i++) {
		if (f[i].getname() == foldersname[foldersname.size() - 1]) {
			f[i].getfile();
			return ListOfFile;
		}
	}
}


void add_folder(string path, string folder_name, vector<Folder> &f) { //another addfolder for our vector
	vector<string> foldersname = split(path);
	f.push_back(Folder(folder_name, 0));
}

void delete_folder(string path, string folder_name, vector<Folder>&f) { //another deletefolder for our vector
	vector<string> foldersname = split(path);
	for (int i = 0; i < f.size(); i++) {
		if (f[i].getname() == foldersname[foldersname.size() - 1]) {
			double temp = f[i].getsize();
			f.erase(f.begin() + i);
			for (int k = 0; k < f.size(); k++) {
				for (int j = 0; j < foldersname.size() - 1; j++) {
					if (f[k].getname() == foldersname[j]) {
						f[k].deletesize(temp);
					}
				}
			}
		}
	}
}




void delete_file(string path, string name, vector<Folder> &f) {// another delete file for out vector
	vector<string> foldersname = split(path);

	for (int i = 0; i < f.size(); i++) {
		if (f[i].getname() == foldersname[foldersname.size() - 1]) {
			double temp = f[i].getsizeofFile(name);
			f[i].deletefile(name);
			for (int k = 0; k < f.size(); k++) {
				for (int j = 0; j < foldersname.size() - 1; j++) {
					if (f[k].getname() == foldersname[j]) {
						f[k].deletesize(temp);
					}
				}
			}
		}
	}
}


void get_file(string path, string file_name, vector<Folder>&f) {
	vector<string> foldersname = split(path);
	for (int i = 0; i < f.size(); i++) {
		if (f[i].getname() == foldersname[foldersname.size() - 1]) {
			f[i].findfile(file_name);
		}
	}
}


int main() {                          //the simulator
	Folder root = Folder("root", 0);  //creat the root folder


	vector<Folder> folders;
	folders.push_back(root);
	int choice;
	int counter = 0;
	cout << "Welcome to our awesome file system!" << endl;
	cout << "We have already created a root folder for you." << endl << endl;
	cout << "Hit the 'Enter' key to continue..." << endl;
	cin.ignore();
	system("CLS");

	while (counter == 0) {
		cout << endl << "please start your path with root/ ... / ..." << endl << endl;
		cout << "Now tell me what you want to do:" << endl;
		cout << "1. Add new folder" << endl;
		cout << "2. Add new file" << endl;
		cout << "3. Delete folder" << endl;
		cout << "4. Delete file" << endl;
		cout << "5. Show all files under a specific folder by enter path" << endl;
		cout << "6. Show information of all folders!" << endl;
		cout << "7. Quit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			string path;
			string name;
			system("CLS");
			cout << "What is path? Please be careful and follow the format" << endl;
			cin >> path;
			cout << endl << "What is the name of the folder?" << endl;
			cin >> name;
			add_folder(path, name, folders);
			cout << endl << "The folder " << name << " under path " << path << " has been added" << endl << endl;

			break;
		}
		case 2: {
			string path;
			string name;
			double size;
			system("CLS");
			cout << "What is path? Please be careful and follow the format" << endl;
			cin >> path;
			cout << endl << "What is the name of the file?" << endl;
			cin >> name;
			cout << endl << "What is the size of the file?" << endl;
			cin >> size;
			add_file(path, name, size, folders);
			cout << endl << "The file " << name << " with size of " << size << " under path " << path << " has been added." << endl;
			break;
		}
		case 3: {
			string path;
			string name;
			system("CLS");
			cout << "Make sure it is the full path! if you want to remove door in the path 'root/door', the path must be 'root/door'!" << endl << endl;
			cout << "What is path? Please be careful and follow the format" << endl;
			cin >> path;
			cout << endl << "What is the name of the folder?" << endl;
			cin >> name;
			delete_folder(path, name, folders);
			cout << endl << "The folder " << name << " under path " << path << " has been removed" << endl;
			break;
		}
		case 4: {
			string path;
			string name;
			system("CLS");
			cout << "What is path? Please be careful and follow the format" << endl;
			cin >> path;
			cout << endl << "What is the name of the file?" << endl;
			cin >> name;
			delete_file(path, name, folders);
			cout << endl << "The file " << name << " under path " << path << " has been removed" << endl;
			break;
		}
		case 5: {
			string path;
			vector<File> tf;
			system("CLS");
			cout << "What is path? Please be careful and follow the format" << endl;
			cin >> path;
			tf = get_files(path, folders);
			break;
		}
		case 6: {
			system("CLS");
			for (int i = 0; i < folders.size(); i++) {
				cout << "Name: " << folders[i].getname() << "  Size: " << folders[i].getsize() << endl;
			}
			break;
		}
		case 7: {
			counter = 1;
			system("CLS");
			cout << "Thank you very much for grading our project, hope you have a beautiful day!" << endl;
			break;
		}
		default:
			cout << "Carefully! Hit the right number!" << endl << endl;
		}
	}
	system("pause");
	return 0;
}
