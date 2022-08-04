#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

//Andy Franck, CS 163, 8/1/22
//this file is the header for our ADT. It is made to declare all functions, structs,
//classes, etc. The content of the functions will go inside the .cpp file, but this 
//header allows us to condense all our declarations down. 

//struct of items, contains name, type, year it was created, description, and worth.
struct collectable
{
    char * name;
    char * type;
    int year;
    char * description;
    int worth;
};

//node for linked list for each entry of the arrray in the table.
struct node
{
    collectable entry; //contains all information about the collectable
    node * next; //pointer to the next node in the linked list
};


class table
{
    public:
        
        table(int size = 5); //constructor
        ~table(); //destructor
        
        //loads data into the table from a file. takes in the name of the file. 
        int load(char * filename);
        
        //Adds collectible to the table.
        //takes in a key value and collectable struct with the data to be added
        //to that key value in the table.  
        int add_collectable(char * key_value, const collectable & to_add); 

        //search function, searches for a collectable in the table and displays it
        //takes in the name of the collectible to display 
        //this is the wrapper function for the private function below
        int display(char * name_to_find) const; 

        //retrieve (not display) all information for a match by type 
        //takes in name of collectible and struct to pass info to 
        //retrieve all collectables with a certain name and insert them into an array
        int retrieve_by_name(char * name_to_find, collectable * array); 

        //removes given collectible from the table.
        //takes in the name of the collectible to remove 
        int remove_collectable(char * name_to_find); //remove collectable by name

        //display all information for a match by type. 
        //Takes in the type of collectible to search for
        int display_of_type(char * type_to_find); 
    
    private:

        //hash function, returns the index of the hash table
        int hash_function(char * key) const; //hash function
        int display(node * head, char * name_to_find) const; //display function

        int hash_table_size; //size of hash table
        node ** hash_table;  //a dynamically allocated array of head pointers
              
};
