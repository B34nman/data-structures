

int remove_wrapper()
{
    return remove_all(head);
}


int remove_all(node * & head)
{
    if(rear == NULL)
        return 0;
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
    
    


