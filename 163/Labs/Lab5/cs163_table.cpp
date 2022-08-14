#include "cs163_table.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
    hash_table_size = size;
    hash_table = new node * [hash_table_size];
    for (int i = 0; i < hash_table_size; ++i)
        hash_table[i] = NULL;
}
//Do something with the key being passed 
//in and return a number(or in our case an index)
//Make sure you're within the array size!
int table::hash_function(char *key) const
{
    
}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{
    int index = hash_function(key_value);
    node * temp = new node;
    if (!temp->entry.copy_entry(to_add))
    { 
        delete temp;
        return 0;
    } 
    temp->next = hash_table[index];
    hash_table[index] = temp;
}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{
    int index = hash_function(title_to_find);
    if(hash_table[index] == NULL) return 0;
    node * temp = hash_table[index];
    while (temp != NULL)
    {
        if(temp->entry.retrieve(title_to_find, found))
        {
            found.copy_entry(temp->entry);
            return 1; 
        }
        temp = temp->next;
    }
    return 0;
}

