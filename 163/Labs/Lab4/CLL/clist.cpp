#include "clist.h"

//Here are the funcitons that we will be writing in lab for CLL
int list::remove_entire()
{
    return remove_entire(rear);
}

int list::remove_entire(node * & rear)
{
    if(!rear) return 0;
    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    int i = 0;
    node * temp = rear;
    rear = rear->next;
    temp->next = NULL;
    while(rear)
    {
        temp = rear->next;
        delete rear;
        rear = temp;
        ++i;
    }
    return i;
}

int list::count_all()
{
    if(rear == NULL)
        return 0;
    return count_all(rear);
}

int list::count_all(node * rear)
{
    if(rear->next == this->rear) return 1;
    return 1 + count_all(rear->next);
}
