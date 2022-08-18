#include "adj-list.h"
using namespace std;

int main()
{
    graph my_graph(5);
    my_graph.insert_vertex("A");
    my_graph.insert_vertex("B");
    //my_graph.insert_vertex("C");
    //my_graph.insert_vertex("D");

    my_graph.insert_edge("A", "B", "street1");
    //my_graph.insert_edge("A", "C", "street2");
    //my_graph.insert_edge("A", "D", "street3");

    my_graph.display_list();

}