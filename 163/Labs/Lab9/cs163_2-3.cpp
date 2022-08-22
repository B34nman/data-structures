#include "cs163_2-3.h"
using namespace std;

//These are the functions that you will be writing for Lab #8

//First write the wrapper functions:
//Display all nodes with no children in 2-3 tree
int table::display_23()      
{
    return display_23(root23);
}

//Now implement the recursive function to display all leaves
int table::display_23(node23 * root)
{
    if(!root) return 0;
    if(!root->child[0])
    {
        cout << "Data Items: " << root->data[0] << ", "
            << root->data[1] << endl;
    }
    return 1 + display_23(root->child[0]) + 
        display_23(root->child[1]) + 
        display_23(root->child[2]);
}



// Implement the recursive function to deallocate all items.
// The destructor already calls this function
int table::deallocate_23(node23 * & root)
{
    if(!root) return 0;
    int count = deallocate_23(root->child[0]) + 
        deallocate_23(root->child[1]) + 
        deallocate_23(root->child[2]);
    delete root;
    root = NULL;
    return 1;
}


//First write the wrapper functions:
//Return true if the root's largest value appears more than once
bool table::find_largest()   
{
    int largest; 
    if(root23->data[0] > root23->data[1])
        largest = root23->data[0];
    else
        largest = root23->data[1];

    return find_largest(root23, largest);
}

//Return true if the root's largest value appears more than once
//Write this function recursively
bool table::find_largest(node23 * root, int match)
{
    if(!root) return 0;
    for(int i = 0; i < 2; ++i)
    {
        if(root->data[i] == match)
            return true;
    }
    return find_largest(root->child[0], match) + 
        find_largest(root->child[1], match) + 
        find_largest(root->child[2], match);
}


//First write the wrapper functions:
//Copies the argument's tree into the current object's tree
int table::copy(table & source) 
{
    return copy(root23, source.root23);
}


//Now implement the recursive function to copy the tree
int table::copy(node23 * & dest_root, node23 * source_root)
{
    if(!root23) return 0;
    dest_root->data[0] = source_root->data[0];
    dest_root->data[1] = source_root->data[1];
    return 1 + copy(dest_root->child[0], source_root->child[0]) + 
        copy(dest_root->child[1], source_root->child[1]) + 
        copy(dest_root->child[2], source_root->child[2]);
}
