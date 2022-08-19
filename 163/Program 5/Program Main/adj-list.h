#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Andy Franck, CS 163, 8/18/22
//this file is the header for our ADT. It is made to declare all functions, structs,
//classes, etc. The content of the functions will go inside the .cpp file, but this
//header allows us to condense all our declarations down.


struct vertex
{
    //struct not required, just a name
    string placeName;
    struct node * head;
};

struct node
{
    string streetName;
    vertex * adjacent;
    node * next;
};

class graph
{
    public:

        //constructor that takes the size of the array to create
        graph(int size);
        //destructor deallocates all memory
        ~graph();
        //creates a vertex with given name and adds it to the array.
        //takes in a string input for the name of the vertex.
        int insert_vertex(string to_add);
        //creates an edge between two vertices. Takes in the name of the current
        //vertex and the name of the vertex to attach to the current vertex.
        int insert_edge(string current_vertex, string to_attach, string name);
        //displays the adjacency list, traversing through the edge list for each vertex.
        int display_list();
        
    private:

        //finds the location of a vertex in the array. Takes in the name of the vertex.
        int find_location(string key_value);

        vertex * adjacency_list;
        int list_size;
};
