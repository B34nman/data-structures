#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest()
{
      display_largest(root);
      return;
}      	//STEP 1
void table::display_largest(node * root)
{
      if(root == NULL)
            return;
      if(root->right == NULL)
            cout << root->data << endl;

      display_largest(root->right);
}

int table::count_root()
{
      return count_root(root, root->data);
}	//STEP 2
int table::count_root(node * root, int match)
{
      if(!root)
            return 0;
      
      if(match == root->data)
            return 1 + count_root(root->left, match) + count_root(root->right, match);
      else
            return count_root(root->left, match) + count_root(root->right, match);
}

void table::copy(table & source)
{
      copy(root, source.root);
}	//STEP 3

void table::copy(node * & destination, node * source)
{
      if(!source)
            return;
      destination = new node;
      destination->data = source->data;
      copy(destination->left, source->left);
      copy(destination->right, source->right);
}



//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root)
{
      if(!root)
            return 0;
      int count = 0;
      if(root->data[2])
            ++count;
      if(root->data[1])
            ++count;
      if(root->data[0])
            ++count;
      return count + count_3_data(root->child[0])
             + count_3_data(root->child[1])
             + count_3_data(root->child[2])
             + count_3_data(root->child[3]);
}

//STEP 5
int table::height()
{
      return height(root234);
}
int table::height(node234 * root)
{
      if(!root)
            return 0;
      int max = 0;
      for(int i = 0; i < 4; ++i)
      {
            int temp = height(root->child[i]);
            if(temp > max)
                  max = temp;
      }
      return max + 1; 
}

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) 
{
      return copy(root234, copy_from.root234);
}
int table::copy(node234 * & destination, node234 * source)
{
      if(!source)
            return 0;
      destination = new node234;
      destination->data[0] = source->data[0];
      destination->data[1] = source->data[1]; 
      destination->data[2] = source->data[2]; 
      destination->data[3] = source->data[3];
      copy(destination->child[0], source->child[0]);
      copy(destination->child[1], source->child[1]);
      copy(destination->child[2], source->child[2]);
      copy(destination->child[3], source->child[3]);
      return 1;  
}
