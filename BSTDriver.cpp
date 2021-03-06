#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include "Valtostr.h"
using CSC2110::Valtostr;

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

   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   Valtostr* val = new Valtostr();
   String* value = new String(val->i_to_c(num_items));
   String* end_l = new String("\n");
   value->displayString();
   end_l->displayString();
   
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
   
   //test the remove function
	String* art = new String("Years In Waste");
	bst->remove(art);

    CD** unsorted_cds = cds->toArray();
    CD** sorted_cds = BinarySearchTree<CD>::treeSort(unsorted_cds, num_items, &CD::compare_items, &CD::compare_keys);

	BinaryTreeIterator<CD>* tree_iter = bst->iterator();

	tree_iter->setInorder();
	while(tree_iter->hasNext())
	{
		CD* c = tree_iter->next();
		c->displayCD();
	}
	delete tree_iter;

   deleteCDs(cds);
   delete cds;
   delete end_l;
   delete art;
   delete value;
   delete val;
   return 0;
}
