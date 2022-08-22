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
    if(!root)
        return 0;
    if(!root->child[0] && !root->child[1] && !root->child[2])
    {
        cout << root->data[0] << " ";
        if(root->data[1])
            cout << root->data[1] << " ";
    }
    display_23(root->child[0]);
    display_23(root->child[1]);
    display_23(root->child[2]);
    return 1;
}


// Implement the recursive function to deallocate all items.
// The destructor already calls this function
int table::deallocate_23(node23 * & root)
{
    if(!root) return 0;
    deallocate_23(root->child[0]);
    deallocate_23(root->child[1]);
    deallocate_23(root->child[2]);
    delete root;
    root = nullptr;
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

    return find_largest(root23->child[0], largest) || find_largest(root23->child[1], largest) || find_largest(root23->child[2], largest);
}

//Return true if the root's largest value appears more than once
//Write this function recursively
bool table::find_largest(node23 * root, int match)
{
    if(!root) return false;
    if(root->data[0] == match || root->data[1] == match)
        return true;
    return find_largest(root->child[0], match) || find_largest(root->child[1], match) || find_largest(root->child[2], match);
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
    if(!source_root) return 0;
    dest_root = new node23;
    dest_root->data[0] = source_root->data[0];
    dest_root->data[1] = source_root->data[1];
    copy(dest_root->child[0], source_root->child[0]);
    copy(dest_root->child[1], source_root->child[1]);
    copy(dest_root->child[2], source_root->child[2]);
    return 1;
}