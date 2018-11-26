
#include <stdio.h>
#include <string.h>
#include "AVL_Tree.h"
#include "Folder.h"
#include "File.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

void add_folder(AVL_Tree<Folder*>& avl, string path, string folder_name)
{
	Folder new_folder(folder_name);
	string s = path + "/";
	string delimiter = "/";
	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}
	Folder* find_folder = new Folder(token);
	Folder* temp = avl.find(find_folder);
	temp->ListOfFolder.push_back(new_folder);
}

int main(){

	Folder* folder1=new Folder("root",0);  //creat a new folder


	AVL_Tree<Folder*> AVL;                 //apply folder to the AVL Tree
	AVL.insert(folder1);


	File file1 = File("file1", 2);                     //creat a new folder
	Folder* tempfolder = AVL.find(folder1);            //Using Avl Tree Searching to located the target folder
	tempfolder->setname("folder2");                    //change the name of target folder
	tempfolder->addfile(file1);                        //add new file to the target folder

	cout << folder1->getname() << endl;
	cout << folder1->getsize()<<endl;


	return 0;
}
