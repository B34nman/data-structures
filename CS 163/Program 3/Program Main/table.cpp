#include "table.h"
using namespace std;


//Andy Franck, CS 163, 8/1/22

//this file is where all of our code for the functions goes. It is used to 
//write out all the code that belongs in each function, so they can operate properly.
//This function contains both functions for the stack and queue classes. They are separated.
//Stack functions are listed first.

//constructor
table::table(int size)
{
    hash_table_size = size;
    hash_table = new node * [hash_table_size];
    for (int i = 0; i < hash_table_size; ++i)
    {
        hash_table[i] = NULL;
    }
}

//destructor
table::~table()
{
    //Goes through every value in the array, traverses any nodes
    //that may be there, and deallocates all memory. 
    for (int i = 0; i < hash_table_size; ++i)
    {
        node * temp = hash_table[i];
        while (temp != NULL)
        {
            node * temp2 = temp;
            temp = temp->next;
            delete [] temp2->entry.name;
            delete [] temp2->entry.type;
            delete [] temp2->entry.description;
            delete temp2;
            temp2 = NULL;
        }
    }
    delete [] hash_table;
}

//hash function, returns the index of the hash table.
int table::hash_function(char * key) const
{
    int hash = 0;
    //although this is a simple function, because of how different all of the names of 
    //the data is, I've found it works extremely well to just add the ASCII values of the letters.
    //I experimented with a few different hash functions, but the differences were marginal,
    //especially for how much larger they werew 
    for (int i = 0; key[i] != '\0'; ++i)
    {
        hash = hash + key[i];
    }
    return hash % hash_table_size;
}


//Adds collectible to the table.
//takes in a key value and collectable struct with the data to be added
//to that key value in the table.  
int table::add_collectable(char * key_value, const collectable & to_add)
{
    int index = hash_function(key_value);

    if(hash_table[index] != NULL)
        cout << "Collision detected.\n";

    //copies data into new node at the head of the linear linked list at that point in the array 
    node * new_node = new node;
    new_node->entry.name = new char[strlen(to_add.name) + 1];
    new_node->entry.type = new char[strlen(to_add.type) + 1];
    new_node->entry.description = new char[strlen(to_add.description) + 1]; 
    
    strcpy(new_node->entry.name, to_add.name);
    strcpy(new_node->entry.type, to_add.type);
    new_node->entry.year = to_add.year;
    strcpy(new_node->entry.description, to_add.description);
    new_node->entry.worth = to_add.worth;

    new_node->next = hash_table[index];
    hash_table[index] = new_node;
    return 1;
}

//load information from external database and add it to the hash table
int table::load(char * filename)
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
    
        add_collectable(name, data);
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

// search function, searches for a collectable in the table and displays it
// takes in the name of the collectible to display
int table::display(char * name_to_find) const
{
    int index = hash_function(name_to_find);
    if(hash_table[index] == NULL)
    {
        return 0;
    }
    node * temp = hash_table[index];
    while (temp != NULL)
    {
        if (strcmp(temp->entry.name, name_to_find) == 0)
        {
            cout << "Name of collectible: " << temp->entry.name << endl;
            cout << "Type of collectible: " << temp->entry.type << endl;
            cout << "Year of creation: " << temp->entry.year << endl;  
            cout << "Description: " << temp->entry.description << endl;
            cout << "Worth: " << temp->entry.worth << endl; 
        }
        temp = temp->next;
    }
    return 1;
}

// retrieve (not display) all information for a match by type
// takes in name of collectible and struct to pass info to
// retrieve all collectables with a certain name and insert them into an array
int table::retrieve_by_name(char * name_to_find, collectable * array)
{
    int index = hash_function(name_to_find);
    if(hash_table[index] == NULL)
    {
        return 0;
    }
    node * temp = hash_table[index];
    int i = 0;
    while (temp != NULL && strcmp(temp->entry.name, name_to_find) != 0)
    {
        temp = temp->next;
    }
    if (strcmp(temp->entry.name, name_to_find) == 0)
    {
        array[i].name = new char[strlen(temp->entry.name) + 1];
        array[i].type = new char[strlen(temp->entry.type) + 1];
        array[i].description = new char[strlen(temp->entry.description) + 1];
        strcpy(array[i].name, temp->entry.name);
        strcpy(array[i].type, temp->entry.type);
        strcpy(array[i].description, temp->entry.description);
        array[i].year = temp->entry.year;
        array[i].worth = temp->entry.worth;
        i++;
        temp = temp->next;
    }
    while (temp != NULL)
    {
        if (strcmp(temp->entry.name, name_to_find) == 0)
        {
            array[i].name = new char[strlen(temp->entry.name) + 1];
            array[i].type = new char[strlen(temp->entry.type) + 1];
            array[i].description = new char[strlen(temp->entry.description) + 1];
            strcpy(array[i].name, temp->entry.name);
            strcpy(array[i].type, temp->entry.type);
            strcpy(array[i].description, temp->entry.description);
            array[i].year = temp->entry.year;
            array[i].worth = temp->entry.worth;
            i++;
        }
        temp = temp->next;
    }
    return i;
}

// removes given collectible from the table.
// takes in the name of the collectible to remove
int table::remove_collectable(char * name_to_find)
{
    int index = hash_function(name_to_find);
    if(hash_table[index] == NULL)
    {
        return 0;
    }  
    node * temp = hash_table[index];
    node * prev = NULL;
    while (temp != NULL && strcmp(temp->entry.name, name_to_find) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (strcmp(temp->entry.name, name_to_find) == 0)
    {
        if (prev == NULL)
        {
            hash_table[index] = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete[] temp->entry.name;
        delete[] temp->entry.type;
        delete[] temp->entry.description;
        delete temp;
        temp = NULL;
        return 1;
    }

    return 0;
}

// display all information for a match by type.
// Takes in the type of collectible to search for
int table::display_of_type(char * type_to_find)
{
    if(hash_table[hash_function(type_to_find)] == NULL)
    {
        return 0;
    }
    for (int i = 0; i < hash_table_size; ++i)
    {
        node * temp = hash_table[i];
        while (temp != NULL)
        {
            if (strcmp(temp->entry.type, type_to_find) == 0)
            {
                cout << "Name of collectible: " << temp->entry.name << endl;
                cout << "Type of collectible: " << temp->entry.type << endl;
                cout << "Year of creation: " << temp->entry.year << endl;  
                cout << "Description: " << temp->entry.description << endl;
                cout << "Worth: " << temp->entry.worth << endl; 
            }
            temp = temp->next;
        }
    }
    return 0;
}
