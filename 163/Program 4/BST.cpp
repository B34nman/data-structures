#include "BST.h"
using namespace std;


//constructor
BST::BST()
{
    root = NULL;
}

//destructor
BST::~BST()
{
    //delete all nodes in the tree
    
}

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
    
    cout << "Loading data from file. \n";
    
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
        newNode->entry = to_add;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return 1;
    }
    else
    {
        //otherwise, we call the recursive function to add the node to the tree
        return insert(key_value, to_add);
    }
}
int BST::insert(char * key_value, const collectable & to_add, node * & root)
{

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
        display_sorted(root);
    }
}
int BST::display_sorted(node * root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        display_sorted(root->left);
        cout << "Name of collectible: " << root->entry.name << endl;
        cout << "Type of collectible: " << root->entry.type << endl;
        cout << "Year of creation: " << root->entry.year << endl;  
        cout << "Description: " << root->entry.description << endl;
        cout << "Worth: " << root->entry.worth << endl; 
        display_sorted(root->right);
    }
}

