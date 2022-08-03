#include "cs163_stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list of arrays
//as the data structure

//Add a new item to the top of stack
int stack::push(const journal_entry & to_add)
{

    if (head == NULL)
    {
        head = new node;
        head->entries = new journal_entry[MAX];
        head->next == NULL;
        top_index = 0;
    }
    if(top_index == MAX)
    {
        node * temp = head;
        head = new node;
        head->entries = new journal_entry[MAX];
        head->next = temp;
        top_index = 0;
    }
    //two checks, now just do standard
    if(!head->entries[top_index].copy_entry(to_add))
        return 0;
    else 
    {
        ++top_index;
        return 1;
    }

    return 0; //if we get here, something went wrong
}

//Remove the top of stack
int stack::pop (void)
{
    
    if(head == NULL) return 0;

    node * nextNode = head->next;
    if(top_index == 0)
    {
        delete [] head->entries;
        delete head;
        head = nextNode; 
        if(head != NULL) top_index = MAX; 
        //we use delete here because there is a node we are not using
    }
    else --top_index;
    return 1;
}

//Supply the journal at the top of stack back to the client
//Return 0 if there are no items
//top_index is one beyond where the top of stack is...
//with no items, top_index is zero
int stack::peek(journal_entry & found_at_top) const
{
    if(head == NULL) return 0;

    if(top_index == 0)
    {
        //go to next node and get that data
        if(head->next != NULL)
        {
            found_at_top = head->next->entries[MAX];
            return 1; 
        }
        else return 0;
    }
    found_at_top = head->entries[top_index - 1];
    return 1;
}

