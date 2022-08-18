#include "adj-list.h"
using namespace std;

int main()
{
    graph my_graph;
    my_graph.insert_vertex("A");
    my_graph.insert_vertex("B");
    my_graph.insert_vertex("C");
    my_graph.insert_vertex("D");

    my_graph.insert_edge("A", "B");
    my_graph.insert_edge("A", "C");
    my_graph.insert_edge("A", "D");

    my_graph.display_list();

}