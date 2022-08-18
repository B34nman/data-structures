#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
        graph(int size = 5);
        //destructor deallocates all memory
        ~graph();
        //creates a vertex with given name and adds it to the array.
        //takes in a string input for the name of the vertex.
        int insert_vertex(string to_add);
        //creates an edge between two vertices. Takes in the name of the current
        //vertex and the name of the vertex to attach to the current vertex.
        int insert_edge(string current_vertex, string to_attach);
        //displays the adjacency list, traversing through the edge list for each vertex.
        int display_list();
        
    private:
        vertex * adjacency_list;
        int list_size;
};
