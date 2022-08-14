#include "dlist.h"

//Here are the functions you will be implementing for doubly linked lists
//
// ! all inserts are before/after a 2

int list::insert_after(int to_add)
{
    if(!head) return 0;
    int count = insert_after(head, to_add); 
    
}
int list::insert_after(node * & head, int to_add)
{
    if(!head) return 0; 
    if(head->data == 2)
    {
        node * temp = new node;
        node * hold = head->next; 
        temp->next = head->next;
        head->next = temp;
        temp->data = to_add; 
        temp->previous = head;
        if(hold) hold->previous = temp;
        //return insert_after(head->next->next, to_add) + 1;
    }
    return insert_after(head->next, to_add) + 1;
}

int list::insert_before(int to_add)
{
    if(!head) return 0; 
    int count = insert_before(head, to_add); 
}

int list::insert_before(node * & head, int to_add)
{
    if(!head) return 0;
    int count = insert_before(head->next, to_add) + 1;
    if(head->data == 2)
    {
        node * temp = new node;
        temp->data = to_add;
        temp->next = head;
        temp->previous = head->previous;
        head->previous = temp;
        head = temp;
    }
    return count;
}   

//removes the last two nodes in the list
int list::display_last_two()
{
    if(!head) return 0;
    if(head->next == NULL) return 0;
    return display_last_two(head);
}

//displays the last two nodes in the doubly linked list
int list::display_last_two(node * head)
{
    if(!head) return 0;
    if(head->next->next == NULL)
    {
        cout << head->data << endl;
        cout << head->next->data << endl;
        return 1;
    }
    return display_last_two(head->next) + 1;
}

//removes the last two nodes in the list
int list::remove_last_two()
{
    if(!head) return 0;
    return remove_last_two(head->next);
}

//removes the last two nodes in the list
int list::remove_last_two(node * & head)
{
    if(head == NULL) return 0;
    if(head->next->next == NULL)
    {
        delete head->next;
        head->next = NULL;
        return 1;
    }
    return remove_last_two(head->next) + 1;
}

//duplicates the last node in the list only if it has not appeared before
int list::duplicate_last()
{
    int lastData = tail->data;
    if(!head) return 0;
    if(head->next == NULL)
    {
        node * temp = new node;
        temp->data = lastData;
        temp->next = NULL;
        temp->previous = head;
        head->next = temp;
        tail = temp;
        return 1;
    }
    return duplicate_last(head->next, lastData);
}
int list::duplicate_last(node * & head, int lastData)
{
    if(!head) return 0;
    if(head->next != NULL && head->data == lastData)
    {
        return 0;
    }
    if(head->next == NULL && head->data == lastData)
    {
        node * temp = new node;
        temp->data = lastData;
        temp->next = NULL;
        temp->previous = head;
        head->next = temp;
        tail = temp;
        cout << "duplicated " << lastData << endl;
        return 1;
    }
    return duplicate_last(head->next, lastData) + 1;
}
