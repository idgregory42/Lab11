#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   cout << "removeItem\n";
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;
   cout << endl;
	String* end_l = new String("\n");
   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;

   cout << "removeItem\n";
   //DO THIS
   //test your tree sort method
   CD** unsorted_cds = cds->toArray();
   CD** sorted_cds = BinarySearchTree<CD>::treeSort(unsorted_cds, num_items, &CD::compare_items, &CD::compare_keys);
cout << "removeItem\n";
	BinaryTreeIterator<CD>* tree_iter = bst->iterator();
cout << "removeItem\n";
tree_iter->setInorder();
	while(tree_iter->hasNext())
	{
		CD* c = tree_iter->next();
		c->getKey()->displayString();
		end_l->displayString();
	}
	delete tree_iter;






   deleteCDs(cds);
   delete cds;
   delete end_l;
   return 0;
}
