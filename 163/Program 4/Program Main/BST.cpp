#include "BST.h"
using namespace std;

// Andy Franck, CS 163, 8/18/22
//this file is where all of our code for the functions goes. It is used to 
//write out all the code that belongs in each function, so they can operate properly.
//this file has functions for our BST including load, insert, display, remove, retrieve, and more. 
//The functions are designed to be plug and play with our client program, so they can be used easily without 
//knowing how each one works. 

//constructor
BST::BST()
{
    root = NULL;
}

//destructor
BST::~BST()
{
    //delete all nodes in the tree
    remove_all(root);
}
//removes all nodes in the tree
//takes in the root node
int BST::remove_all(node * & root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        //delete after the recursive call,
        //so we get to the end and then delete going backwards
        remove_all(root->left);
        remove_all(root->right);
        delete [] root->entry.name;
        delete [] root->entry.type;
        delete [] root->entry.description;
        delete root;
        root = NULL;
    }
}

//loads data into the table from a file. takes in the name of the file.
int BST::load(char * filename)
{
    ifstream infile;
    infile.open(filename);
    if (!infile)
    {
        return 0;
    }
     
    char name[100];
    char type[100];
    int year;
    char description[100];
    int worth;
    int numLines = 0;
    
    infile.get(name, 100, '|'); infile.ignore(100, '|'); 
    
    //load data separated by "|" from the file and add it to the hash table
    while (!infile.eof())
    {
        
        collectable data;
        
        data.name = new char[strlen(name) + 1];
        strcpy(data.name, name);
        
        infile.get(type, 100, '|'); infile.ignore(100, '|');
        data.type = new char[strlen(type) + 1];
        strcpy(data.type, type);
        
        infile >> year; infile.ignore(100, '|'); 
        data.year = year;
        
        infile.get(description, 100, '|'); infile.ignore(100, '|');
        data.description = new char[strlen(description) + 1];
        strcpy(data.description, description);
        
        infile >> worth; infile.ignore(100, '\n');
        data.worth = worth;
    
        insert(name, data);
        ++numLines;

        //delete the memory allocated for the data to be copied over 
        //since it has already been copied 
        delete[] data.name;
        delete[] data.type;
        delete[] data.description;
         
        infile.get(name, 100, '|'); infile.ignore(100, '|');
    }

    
    infile.close();
    return numLines; //we return numlines so we can set this value in main,
    //this allows us to allocate an array later in the main file to the size we need.
}

// Adds collectible to the table.
// takes in the key argument and the struct to be added to the table.
int BST::insert(char * key_value, const collectable & to_add)
{
    //if the root is null, then we create a new node and set the root to it
    if (root == NULL)
    {
        node * newNode = new node;
        newNode->entry.name = new char[strlen(to_add.name) + 1];
        strcpy(newNode->entry.name, to_add.name);
        newNode->entry.type = new char[strlen(to_add.type) + 1];
        strcpy(newNode->entry.type, to_add.type);
        newNode->entry.description = new char[strlen(to_add.description) + 1];
        strcpy(newNode->entry.description, to_add.description);
        newNode->entry.worth = to_add.worth;
        newNode->entry.year = to_add.year;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return 1;
    }
    // otherwise, we call the recursive function to add the node to the tree
    return insert(key_value, to_add, root);
}
//recursive function to add a node to the tree
int BST::insert(char * key_value, const collectable & to_add, node * & root)
{
    //if the root is null, then we create a new node and set the root to it
    if (root == NULL)
    {
        node * newNode = new node;
        newNode->entry.name = new char[strlen(to_add.name) + 1];
        strcpy(newNode->entry.name, to_add.name);
        newNode->entry.type = new char[strlen(to_add.type) + 1];
        strcpy(newNode->entry.type, to_add.type);
        newNode->entry.description = new char[strlen(to_add.description) + 1];
        strcpy(newNode->entry.description, to_add.description);
        newNode->entry.worth = to_add.worth;
        newNode->entry.year = to_add.year;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return 1;
    }
    else if (strcmp(key_value, root->entry.name) < 0)
    {
        //if the key is less than the root, we call the function again
        //with the root's left child
        return insert(key_value, to_add, root->left);
    }
    else
    {
        //else, the data is >= so we call the right side  of the tree
        return insert(key_value, to_add, root->right);
    }
    
} 

//displays all data in sorted order by name
//takes in no arguments, because it is displaying all data in the table
int BST::display_sorted()
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return display_sorted(root);
    }
}
//recursive function to display all data in the tree
int BST::display_sorted(node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        //recursively call functions and display between so it displays in sorted order
        display_sorted(root->left);
        cout << "Name of collectible: " << root->entry.name << endl;
        cout << "Type of collectible: " << root->entry.type << endl;
        cout << "Year of creation: " << root->entry.year << endl;  
        cout << "Description: " << root->entry.description << endl;
        display_sorted(root->right);
    }
    return 1;
}

// displays the information for a match by collectible name
// takes in the name of the collectible to display
int BST::display_matched(char * name_to_find) const
{
    if (root == NULL)
    {
        return 0;
    }
    
    return display_matched(root, name_to_find);
}
//recursive function to display the data for a match
int BST::display_matched(node * root, char * name_to_find) const
{
    if (root == NULL)
    {
        return 0;
    }
    //checks each node and if the name matches, displays it 
    if (strcmp(root->entry.name, name_to_find) == 0)
    {
        cout << "Name of collectible: " << root->entry.name << endl;
        cout << "Type of collectible: " << root->entry.type << endl;
        cout << "Year of creation: " << root->entry.year << endl;
        cout << "Description: " << root->entry.description << endl;
        cout << "Worth: " << root->entry.worth << endl;
    }
    
    return 1 + display_matched(root->left, name_to_find) + display_matched(root->right, name_to_find);
}

// retrieve (not display) all information for a match by type
// takes in name of collectible and struct to pass info to
// retrieve all collectables with a certain name and insert them into an array
int BST::retrieve_by_name(char * name_to_find, collectable * array)
{
    int i = 0; 
    return retrieve_by_name(root, name_to_find, array, i);
}
//recursive function to retrieve all data for a match
int BST::retrieve_by_name(node * root, char * name_to_find, collectable * array, int i)
{
    if (root == NULL)
    {
        if (i == 0)
        {
            return 0;
        }
        else
        {
            return i;
        } 
    }

    //searches thru each node, if it finds a match, adds it to the array
    if (strcmp(root->entry.name, name_to_find) == 0)
    {
        array[i].name = new char[strlen(root->entry.name) + 1];
        array[i].type = new char[strlen(root->entry.type) + 1];
        array[i].description = new char[strlen(root->entry.description) + 1];
        strcpy(array[i].name, root->entry.name);
        strcpy(array[i].type, root->entry.type);
        strcpy(array[i].description, root->entry.description);
        array[i].year = root->entry.year;
        array[i].worth = root->entry.worth;
        ++i; 
    }

    //return i, because that is where we are in the array so we can add to empty spot
    return retrieve_by_name(root->left, name_to_find, array, i) + retrieve_by_name(root->right, name_to_find, array, i);
}

// retrieve (not display) all information for a match by type
// takes in type of collectible and struct to pass info to
// retrieve all collectables with a certain type and insert them into an array
int BST::remove_collectable(char * name_to_remove)
{
    if (root == NULL)
    {
        return 0;
    }
    return remove_collectable(root, name_to_remove);
}
//recursive function to remove a collectable
int BST::remove_collectable(node * & root, char * name_to_remove)
{
    //means we have not found the item and we are at the end of the list 
    if(root == NULL)
    {
        return 0;
    }
    //if the name is less than the root, we go to the left 
    if(strcmp(name_to_remove, root->entry.name) < 0)
    {
        return remove_collectable(root->left, name_to_remove);
    }
    //if the name is greater than the root, we go to the right
    if(strcmp(name_to_remove, root->entry.name) > 0)
    {
        return remove_collectable(root->right, name_to_remove);
    }
    // if the name equals the root, we have arrived!

    //case with no children, so just delete leaf
    if (root->left == NULL && root->right == NULL)
    {
        // remove the leaf node
        delete[] root->entry.name;
        delete[] root->entry.type;
        delete[] root->entry.description;
        delete root;
        root = NULL;
        return 1;
    }
    //case with one child so just delete node and replace with child 
    else if (root->left == NULL)
    {
        // remove the node with one right child
        node *temp = root->right;
        delete[] root->entry.name;
        delete[] root->entry.type;
        delete[] root->entry.description;
        delete root;
        root = temp; 
        return remove_collectable(root, name_to_remove);
    }
    else if (root->right == NULL)
    {
        // remove the node with one left child
        node *temp = root->left;
        delete[] root->entry.name;
        delete[] root->entry.type;
        delete[] root->entry.description;
        delete root;
        root = temp;
        return remove_collectable(root, name_to_remove);
    }
    //case with two children, oh no...
    else
    {
        // remove the node with two children
        //find in order successor 
        
        node * current = root->right;
        node * parent = root;
        while(current->left != NULL)
        {
            parent = current;
            current = current->left;
        }
        node * temp = current->right;
        
        strcpy(root->entry.name, current->entry.name);
        strcpy(root->entry.type, current->entry.type);
        strcpy(root->entry.description, current->entry.description);
        root->entry.year = current->entry.year;
        root->entry.worth = current->entry.worth;

        
        delete[] current->entry.name;
        delete[] current->entry.type;
        delete[] current->entry.description;
        delete current;
        
        parent->right = temp;

        return remove_collectable(root, name_to_remove);
    }
    return 0;

}

// display all information for a match by type.
// takes in type of collectible to find
int BST::display_of_type(char * type_to_find)
{
    if (root == NULL)
    {
        return 0;
    }
    return display_of_type(root, type_to_find);
}
//recursive function to display all data for a match
int BST::display_of_type(node * root, char * type_to_find)
{
    if (root == NULL)
    {
        return 0;
    }
    if (strcmp(root->entry.type, type_to_find) == 0)
    {
        cout << "Name of collectible: " << root->entry.name << endl;
        cout << "Type of collectible: " << root->entry.type << endl;
        cout << "Year of creation: " << root->entry.year << endl;
        cout << "Description: " << root->entry.description << endl;
        cout << "Worth: " << root->entry.worth << endl;
    }
    return display_of_type(root->left, type_to_find) + display_of_type(root->right, type_to_find);
}
