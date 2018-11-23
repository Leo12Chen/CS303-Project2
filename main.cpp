

#include "AVL_Tree.h"
#include "Folder.h"
#include "File.h"

using namespace std;

int main(){

	AVL_Tree<Folder> AVL;

	bool result = AVL.is_null();

	Folder* fl = new Folder("X",2);
  Folder* f2 = new Folder("y",3);
  
	AVL_Tree<Folder*> AVL_Folder;

	AVL_Folder.insert(f1);

  Folder* f = AVL_Folder.find(fl);

	f->set_name("Z");


	AVL_Folder.insert(f2);
	AVL_Folder.erase("quick");

	AVL_Tree<Folder*> right_subtree = AVL_Folder.get_right_subtree();

	AVL_Tree<Folder*> left_subtree = AVL_Folder.get_left_subtree();


	return 0;
}
