#include "adj-list.h"
using namespace std;


//Andy Franck, CS 163, 8/24/22
//This program is the main/driver file. This file creates an adajency table object, and then calls
//all of the functions when they are called. 
//The client program allows the user to test every option themselves,
//and easily manage all events and test all functions. 
//in regards to it's purpose within the entire program, this file exists
//to test the functions of the ADT. 

int main()
{
    
    //way to map favorite routes around an area. 
    //The user can add a new place, add a new route, display all places.

    int size = 7;
    
    //for testing purposes, have ability to load small sample data set:
    cout << "For testing purposes, you have the option to load a small data set." << endl;
    cout << "Would you like to load the data set? (y/n)" << endl;
    char choice;
    cin >> choice;
    cin.ignore(100, '\n');
    if(choice == 'n')
    {
        cout << "Proceeding with standard program." << endl;
        cout << endl << endl;
        
        // create a graph object
        cout << "What should the size of the graph be? e.g. how many places can you add?" << endl;
        cin >> size;
        cin.ignore(100, '\n');
    }
    
    graph my_graph(size);

    if(choice == 'y')
    {
        //load small sample data set
        my_graph.insert_vertex("home");
        my_graph.insert_vertex("stop1");
        my_graph.insert_vertex("stop2"); 
        my_graph.insert_vertex("stop3");
        my_graph.insert_vertex("work");

        my_graph.insert_edge("home", "stop1", "Maple Dr.");
        my_graph.insert_edge("stop1", "stop2", "Crestview Ln.");
        my_graph.insert_edge("stop2", "stop3", "Baker St.");
        my_graph.insert_edge("stop3", "work", "Main St.");

        my_graph.display_list(); 
    }

    //create a menu
    choice = 'a';
    while(choice != 'q')
    {
        cout << "What would you like to do?" << endl;
        cout << "a. Add a new place/stop" << endl;
        cout << "b. Add a new route" << endl;
        cout << "c. Display all places/stops" << endl;
        cout << "q. Quit" << endl;
        cin >> choice;
        cin.ignore(100, '\n');
        if(choice == 'a')
        {
            cout << "Name of the place to add: " << endl;
            string name;
            getline(cin, name);
            my_graph.insert_vertex(name);
        }
        else if(choice == 'b')
        {
            cout << "Name of current place:" << endl;
            string current;
            getline(cin, current);
            cout << "Name of place to create a path to:" << endl;
            string to_add;
            getline(cin, to_add);
            cout << "Name of path:" << endl;
            string street;
            getline(cin, street);
            my_graph.insert_edge(current, to_add, street);
        }
        else if(choice == 'c')
        {
            my_graph.display_list();
        }
    }
     

}