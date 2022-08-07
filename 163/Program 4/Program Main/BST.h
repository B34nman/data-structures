#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

//Andy Franck, CS 163
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
    node * left; //pointer to the next node in the linked list
    node * right; //pointer to the next node in the linked list
};


//class for the table ADT 
class BST
{
    public:

        BST(); //constructor
        ~BST(); //destructor
 
        //loads data into the table from a file. takes in the name of the file. 
        int load(char * filename);

        //Adds collectible to the table.
        //takes in the key argument and the struct to be added to the table. 
        int insert(char * key_value, const collectable & to_add);

        //displays all data in sorted order by name. 
        //takes in no arguments, because it is displaying all data.  
        int display_sorted();

        //displays the information for a match by collectible name
        //takes in the name of the collectible to display 
        int display_matched(char * name_to_find) const;

        //retrieve (not display) all information for a match by type
        //takes in name of collectible and struct to pass info to
        //retrieve all collectables with a certain name and insert them into an array
        int retrieve_by_name(char * name_to_find, collectable * array);

        //removes given collectible from the table.
        //takes in the name of the collectible to remove
        int remove_collectable(char * name_to_find);

        //display all information for a match by type.
        //Takes in the type of collectible to search for
        int display_of_type(char * type_to_find);


    private:
        
        //private functions that are used by the public functions above 
        //all take in the root node
        int insert(char * key_value, const collectable & to_add, node * & root);
        int display_sorted(node * root);
        int display_matched(node * root, char * name_to_find) const;
        //takes in i argument for where we are in the array
        int retrieve_by_name(node * root, char * name_to_find, collectable * array, int i);
        int remove_collectable(node * root, char * name_to_find);
        int display_of_type(node * root, char * type_to_find);

        node * root; //root of the tree
        int num_items; //number of items in the tree


};