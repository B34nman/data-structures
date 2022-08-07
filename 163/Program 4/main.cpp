#include "BST.h"
using namespace std;


//This program is the main/driver file. This file creates a table object, and then calls
//all of the functions when they are called. 
//The client program allows the user to test every option themselves,
//and easily manage all events and test all functions. 
//in regards to it's purpose within the entire program, this file exists
//to test the functions of the ADT. 


int main()
{
    //int SIZE = 1000;
    //char * key_value = NULL;
    char * data = new char[strlen("newdata.txt") + 1];
    strcpy(data, "newdata.txt");

    BST bst;
    int numLines = bst.load(data);
    
    bst.display_sorted();

}



