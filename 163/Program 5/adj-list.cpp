#include "adj-list.h"
using namespace std;

//constructor that takes the size of the array to create
//the size is how many vertices the graph can hold
graph::graph(int size = 5)
{
    adjacency_list = new vertex[size];
    list_size = size;
}

//destructor deallocates all memory
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
int graph::insert_edge(string current_vertex, string to_attach)
{
    //add an edge to the array that connects two vertices


}

// displays the adjacency list, traversing through the edge list for each vertex.
int graph::display_list()
{
    //display the adjacency list
    for(int i = 0; i < list_size; ++i)
    {
        cout << adjacency_list[i].placeName << " -> ";
        node * current = adjacency_list[i].head;
        while(current)
        {
            cout << current->adjacent->placeName << " -> ";
            current = current->next;
        }
        cout << "|||" << endl;
    }
}
