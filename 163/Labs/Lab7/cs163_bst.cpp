#include "cs163_bst.h"
using namespace std;


// ***These are sample wrapper functions
table::~table()
{
     remove_all(root); //call the recursive removal_all private function
}


int table::insert(int to_add)
{
    return insert(root, to_add); 
}
int table::insert(node * root, int to_add)
{
    if(!root)
    {
        root = new node();
        root->data = to_add;
        return 1; 
    }
    if(root->data > to_add)
        insert(root->left, to_add);
    else
        insert(root->right, to_add);
    
    return 0; //we won't get here
}

// This is a wrapper function that will call the recursive count function
int table::count()
{
    //Notice how the returned value from the recursive function is used
    return count(root);
}

// Now it is your turn to write the count function recursively
int table::count (node * root)
{
    if (root == NULL) //if the root is NULL, return 0
    {
        return 0;
    }
    else //otherwise, return the number of nodes in the tree
    {
        return 1 + count(root->left) + count(root->right);
    }
}


// Start with the wrapper function that calls the recursive function
int table::sum()
{
    //Call the recursive function here:
    return sum(root);
}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{
    if (root == NULL) //if the root is NULL, return 0
    {
        return 0;
    }
    else //otherwise, return the number of nodes in the tree
    {
        return root->data + sum(root->left) + sum(root->right);
    }
}


int table::height()   //simply call the private version of the functions
{
    //Call the recursive function here:
    return height(root);
}

//Now write this function recursively
int table::height (node * root)
{
    if (root == NULL) //if the root is NULL, return 0
    {
        return 0;
    }
    else //otherwise, return the number of nodes in the tree
    {
        return 1 + max(height(root->left), height(root->right));
    }
}



int table::remove_all()
{
    //Call the recursive function here:
    remove_all(root); 
}

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        remove_all(root->left);
        remove_all(root->right);
        delete root;
        root = NULL;
    }
}


int table::copy(const table & to_copy)
{
    //Call the recursive function here:

}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root) 
{


}  

