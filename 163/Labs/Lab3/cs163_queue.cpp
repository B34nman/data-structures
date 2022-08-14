#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
    if (rear == NULL)
    {
        rear = new q_node;
        rear->next = rear;//needs to point to itself if first item
    }
    //else do normal case
    q_node * temp = rear->next;
    rear->next = new q_node;
    rear = rear->next;
    rear->next = temp;
    if(rear->entry.copy_entry(to_add))
        return 1;
    
    return 0;
}

//Remove the node at the front
int queue::dequeue ()
{
    if(rear = NULL) return 0;

    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    
    q_node * temp = rear->next;
    rear->next = temp->next;
    delete temp;
    return 1;

}

