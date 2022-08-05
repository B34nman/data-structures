#include "table.h"
using namespace std;


//Andy Franck, CS 163, 8/1/22

//This program is the main/driver file. This file creates a table object, and then calls
//all of the functions when they are called. 
//The client program allows the user to test every option themselves,
//and easily manage all events and test all functions. 
//in regards to it's purpose within the entire program, this file exists
//to test the functions of the ADT. 

int main()
{
    int table_size; 
    int SIZE = 1000;
    char * key_value = NULL;
    char * data = new char[strlen("newdata.txt") + 1]; 
    strcpy(data, "newdata.txt"); 
    
    cout << "Enter the size of the table: ";
    cin >> table_size;

    //create the table with inputted size 
    table table(table_size);

    //load the table with data from a file
    //we assign it to numlines, because when displaying all of a certain type we need an array.
    //we can allocate that array to the size of numlines, so we can display all of possible data
    //without the array being too large. 
    int numLines = table.load(data);
    if(numLines == 0)
        cout << "Error loading data from file" << endl;
    else
        cout << "Data loaded successfully" << endl;

    //while loop for user inputs to manage the data 
    bool userEdit = true;
    while(userEdit)
    {
        int choice;
        cout << endl << "Press 1 to add a collectable to the table\n";
        cout << "Press 2 to display a collectable\n";
        cout << "Press 3 to remove a collectable from the table\n";
        cout << "Press 4 to display all collectables of a certain type\n";
        cout << "Press 5 to retrieve a collectable from the table.\n";
        cout << "Press 6 to quit.\n";
        cout << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; cin.ignore(SIZE, '\n');
        cout << endl;  
        switch(choice)
        {
            case 1:
                {
                    collectable to_add;
                    char name[SIZE];
                    char type[SIZE];
                    char description[SIZE];
                    cout << "Enter the name of the collectable: "; 
                    cin.get(name, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');

                    key_value = new char[strlen(name) + 1];
                    strcpy(key_value, name);
                    to_add.name = new char[strlen(name) + 1];
                    strcpy(to_add.name, name);

                    cout << "Enter the type of the collectable: ";
                    cin.get(type, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');
                    to_add.type = new char[strlen(type) + 1];
                    strcpy(to_add.type, type);

                    cout << "Enter the year the collectable was created: ";
                    cin >> to_add.year; 
                    cin.ignore(100, '\n');
                    
                    cout << "Enter the description of the collectable: ";
                    cin.get(description, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');
                    to_add.description = new char[strlen(description) + 1];
                    strcpy(to_add.description, description);

                    cout << "Enter the worth of the collectable: ";
                    cin >> to_add.worth; 
                    cin.ignore(100, '\n');
                    
                    if(to_add.name && to_add.type && to_add.description)
                        table.add_collectable(key_value, to_add);
                    else
                        cout << "One or more inputs were NULL. Cannot create a collectable. \n";

                    delete [] to_add.name;
                    delete [] to_add.type;
                    delete [] to_add.description;
                    delete [] key_value;
                    break;
                }
            case 2:
                {
                    char * name_to_find = NULL;
                    char name[SIZE];
                    
                    cout << "Enter the name of the collectable to find: ";
                    cin.get(name, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');
                    name_to_find = new char[strlen(name) + 1];
                    strcpy(name_to_find, name);
                    cout << endl;
                    if (!table.display(name_to_find))
                    {
                        cout << "Collectable not found.\n";
                    }
                    delete [] name_to_find;
                    break;
                }
            case 3:
                {
                    char * name_to_find = NULL;
                    char name[SIZE]; 
                    
                    cout << "Enter the name of the collectable to remove: ";
                    cin.get(name, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');
                    name_to_find = new char[strlen(name) + 1];
                    strcpy(name_to_find, name);
                    cout << endl;
                    if(!table.remove_collectable(name_to_find))
                    {
                        cout << "Collectable not found.\n";
                    }
                    delete [] name_to_find;
                    break;
                }
            case 4:
                {
                    char * type_to_find = NULL;
                    char type[SIZE]; 
                    
                    cout << "Enter the type of the collectable to find: ";
                    cin.get(type, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');
                    type_to_find = new char[strlen(type) + 1];
                    strcpy(type_to_find, type);
                    cout << endl;
                    if(!table.display_of_type(type_to_find))
                    {
                        cout << "No collectables of that type found.\n";
                    }
                    delete [] type_to_find;
                    break;
                }
            case 5:
                {
                    char * name_to_find = NULL;
                    char name[SIZE];

                    cout << "Enter the name of the collectable to retrieve: ";
                    cin.get(name, SIZE, '\n'); 
                    cin.ignore(SIZE, '\n');
                    name_to_find = new char[strlen(name) + 1];
                    strcpy(name_to_find, name);
                    
                    //ask about what size to allocate this...
                    //is there any way other than this??? 
                    collectable array[numLines];

                    cout << endl;
                    int numItem = table.retrieve_by_name(name_to_find, array);
                    if (numItem == 0)
                    {
                        cout << "Collectable not found.\n";
                    }
                    else
                    {
                        for(int i = 0; i < numItem; i++) 
                        {
                            if (array[i].name)
                            {
                                cout << "Name: " << array[i].name << endl;
                                cout << "Type: " << array[i].type << endl;
                                cout << "Year: " << array[i].year << endl;
                                cout << "Description: " << array[i].description << endl;
                                cout << "Worth: " << array[i].worth << endl;
                                cout << endl;
                            }
                        }
                    }
                    delete [] name_to_find; 
                    for (int i = 0; i < numItem; i++)
                    {
                        delete [] array[i].name;
                        delete [] array[i].type;
                        delete [] array[i].description;
                    }

                    break; 
                } 
            case 6:
                {
                    userEdit = false;
                    break;
                }
            default:
                {
                    cout << "Invalid choice.\n";
                    break;
                }
        }
    }
    delete [] data;
    return 0;
}


