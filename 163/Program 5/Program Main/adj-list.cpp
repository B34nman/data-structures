#include "adj-list.h"
using namespace std;

//TODO: breadth first traversal for the display all function

//Andy Franck, CS 163, 8/24/22
//this file is where all of our code for the functions goes. It is used to 
//write out all the code that belongs in each function, so they can operate properly.
//this file has functions for our adjacency list, which include insert_vertex, insert_edge,
//and display_all 
//The functions are designed to be plug and play with our client program, so they can be used easily without 
//knowing how each one works. 

//constructor that takes the size of the array to create
//the size is how many vertices the graph can hold
graph::graph(int size)
{
    adjacency_list = new vertex[size];
    list_size = size;
}

//destructor, deallocates all memory
graph::~graph()
{
    //deallocate all memory
    for(int i = 0; i < list_size; ++i)
    {
        node * current = adjacency_list[i].head;
        while(current)
        {
            node * temp = current;
            current = current->next;
            delete temp;
        }
    }
}

// creates a vertex with given name and adds it to the array.
// takes in a string input for the name of the vertex.
int graph::insert_vertex(string to_add)
{
    //add a vertex to the array

    //check if the vertex already exists
    for(int i = 0; i < list_size; ++i)
    {
        if(adjacency_list[i].placeName == to_add)
        {
            return 0;
        }
    }
    //if it doesn't exist, add it to the array
    for(int i = 0; i < list_size; ++i)
    {
        if(adjacency_list[i].placeName == "")
        {
            adjacency_list[i].placeName = to_add;
            return 1;
        }
    }
}

// creates an edge between two vertices. Takes in the name of the current
// vertex and the name of the vertex to attach to the current vertex.
int graph::insert_edge(string current_vertex, string to_attach, string name)
{
    //add an edge to the array that connects two vertices

    int connect_from = find_location(current_vertex);
    int connect_to = find_location(to_attach);
     
    if (connect_from == -1 || connect_to == -1)
    {
        return -1;
    }
    else
    {
        //two way street, so we can go from one to the other and back.
        //one of these could be removed if we wanted to make it a one way street

        node *new_node = new node;
        new_node->streetName = name;
        new_node->adjacent = &adjacency_list[connect_to];
        new_node->next = adjacency_list[connect_from].head;
        adjacency_list[connect_from].head = new_node;

        node *temp = new node;
        temp->streetName = name;
        temp->adjacent = &adjacency_list[connect_from];
        temp->next = adjacency_list[connect_to].head;
        adjacency_list[connect_to].head = temp;

        return 0;
    }
}
// finds the value in the array that the key_value is located at
int graph::find_location(string key_value)
{
    //find the location of a vertex in the array
    for(int i = 0; i < list_size; ++i)
    {
        if(adjacency_list[i].placeName == key_value)
        {
            return i;
        }
    }
    return -1;
}

//displays the adjacency list, traversing through the edge list for each vertex.
int graph::display_list()
{
    cout << endl;
    //display the adjacency list
    for(int i = 0; i < list_size; ++i)
    {
        if(adjacency_list[i].placeName != "")
        {
            cout << adjacency_list[i].placeName << " is connected to: " << endl;
            node * current = adjacency_list[i].head;
            while(current)
            {
                if(current->adjacent->placeName != "")
                {
                    cout << current->adjacent->placeName << " via " << current->streetName << endl;
                }
                current = current->next;
            }
            cout << endl;
        }
    }
    return 0;
}