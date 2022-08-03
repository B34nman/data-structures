
//may need wrappers for these, if passing in node pointer not ok
//1
//Count number of nodes
int count()
{
    if(head == NULL) return 0;
    if(head->next == NULL) return 1;
    return count(head);
}
int count(node * head)
{
    if(head == NULL) return 0;
    if(head->next == NULL) return 1;

    return 1 + count(head->next);
}
//2
//Sum all data in LLL
int sum_all()
{
    if(head == NULL) return 0;
    return sum_all(head);
}
int sum_all(node * head)
{
    if(head == NULL) return 0;
    return head->data + sum_all(head->next); 
}
//3
//sum all even data 
int sum_all_even()
{
    if(head == NULL) return 0;
    return sum_all_even(head);
}
int sum_all_even(node * head)
{
    if(head == NULL) return 0;

    if (head->data % 2 == 0 ) 
        return head->data + sum_all(head->next);
    else 
        return sum_all(head->next);
}
//4
//average all data in LLL
int average_data()
{
    if(head == NULL) return 0;
    int i = 0;
    int total = 0;
    node * temp = head;
    while(temp != NULL)
    {
        total += temp->data
        temp = temp->next;
        ++i;
    }
    return total / i;
}





//1
//insert node at head
bool insert_head(int data)
{
    node * newNode = new node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return true;
}
//2
//insert at end
bool insert_end(int data)
{
    node * newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
        return true;
    }
    node * temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    return true;
}
//3
//duplicate last node data
bool duplicate_last_node()
{
    int dataStore;
    node * temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    dataStore = temp->data;
    node * newNode = new node();
    newNode->data = dataStore;
    temp->next = newNode;
    newNode->next = NULL;
    return true;
}
//4
//insert node after every node with a 2
bool add_after_2(int data)
{
    if(head == NULL) return false;
    node * temp = head;
    while(temp != NULL)
    {
        if(temp->data == 2)
        {
            node * newNode = new node();
            newNode->data = data;
            newNode->next = temp->next->next;
            temp->next = newNode;
        }
    }
    return true;
}


//1
//remove first node
bool remove_first()
{
    if(head == NULL) return false;
    if(head->next = NULL)
    {
        delete head;
        head = NULL;
    }
    node * temp = head;
    head = temp->next;
    delete temp;
    temp = NULL;
}
//2
//remove last node
bool remove_last()
{
    if(head == NULL) return false;
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return true;
    }
    if(head->next->next == NULL)
    {
        temp = head->next;
        delete temp;
        temp = NULL;
        head->next = NULL;
        return true;
    }

    node * temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    delete temp1;
    temp1 = NULL;
    temp->next = NULL;
    return true;
}
//4
//remove node after every 2
bool remove_after_2()
{
    if(head == NULL) return false;
    node * temp = head;
    while(temp != NULL)
    {
        if(temp->data == 2)
        {
            node * temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;
            temp1 = NULL;
        }
    }
    return true;
}
//5
//remove all nodes
bool remove_all()
{
    node * temp = head;
    while (temp != NULL)
    {	
        head = temp->nextApt; 
        delete temp;
        temp = head; 
    }
    return true;
}







