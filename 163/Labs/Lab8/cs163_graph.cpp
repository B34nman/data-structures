#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to nullptr
      adjacency_list = new vertex[size];
      for(int i = 0; i < size; i++)
      {
            adjacency_list[i].head = nullptr;
            adjacency_list[i].entry = nullptr;
      }
      list_size = size;

}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
      //return the location of this particular key value 
      for (int i = 0; i < list_size; i++)
      {
            if (adjacency_list[i].entry->compare(key_value))
            {
                  return i;
            }
      }
}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{
      //Insert vertex at the first available location
      //Return the location of the vertex
      //If there is no available location, return -1
      for(int i = 0; i < list_size; i++)
      {
            if(adjacency_list[i].entry == nullptr)
            {
                  adjacency_list[i].entry->copy_entry(to_add);
                  return i;
            }
      }
}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
      // Attach this vertices edge to the specified vertex
      int connect_from = find_location(current_vertex);
      int connect_to = find_location(to_attach);
      if(connect_from == -1 || connect_to == -1)
      {
            return -1;
      }
      else
      {
            node * new_node = new node;
            new_node->adjacent = &adjacency_list[connect_to];
            new_node->next = adjacency_list[connect_from].head;
            adjacency_list[connect_from].head = new_node;

            node * temp = new node;
            temp->adjacent = &adjacency_list[connect_from];
            temp->next = adjacency_list[connect_to].head;
            adjacency_list[connect_to].head = temp;

            return 0;
      }
 
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{
      for (int i = 0; i < list_size; i++)
      {
            if (adjacency_list[i].entry->compare(key_value))
            {
                  node * temp = adjacency_list[i].head;
                  while(temp != nullptr)
                  {
                        if(temp->adjacent)
                              temp->adjacent->entry->display();
                        temp = temp->next;
                  }
            }
      }
      return 1;
}
