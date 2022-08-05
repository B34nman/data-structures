//this is a review for the second midterm exam for CS 163.
#include <iostream>
#include <cstring>
using namespace std;

node * head = NULL;
node * rear = NULL;
int hash_table_size = 17, top_index = 0, MAX = 5;
node ** hash_table;
struct node
{
    char *  data;
    node *next;
};
struct s_node
{
    char *  entries;
    s_node *next;
};
struct journal_entry
{
    char *  date;
    char *  event;
    char *  description;
};


//* STACK *********************************************************************

// ! THIS IS IF WE ARE NOT USING LINEAR LINKED LIST OF ARRAYS

int pushStack(char* to_add) {
    if (head == NULL)
    {
        head = new node;
        head->data = new char[strlen(to_add) + 1];
        strcpy(head->data, to_add);
        head->next = NULL;
    }
    
    node * temp = head;
    head = new node;
    head->data = to_add;
    head->next = temp;

    return 1;
}

int pop() 
{
    if (head == NULL)
    {
        return 0;
    }
    node * temp = head;
    head = head->next;
    delete [] temp->data;
    delete temp;
    return 1;
}


int peek(char *  returned_data)
{
    if (head == NULL)
    {
        return 0;
    }
    strcpy(returned_data, head->data);
    return 1;
}

// ! THIS IS IF WE ARE USING LINEAR LINKED LIST OF ARRAYS

int push(const char *  & to_add)
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

int pop(void)
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

int peek(char* & found_at_top) 
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


//* QUEUE *********************************************************************
// TODO:  NOTE conditional for CLL is if rear->next = rear

int dequeue()
{
    if(rear == NULL) return 0;

    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    
    node * temp = rear->next->next;
    delete [] rear->next.data; 
    delete rear->next;
    rear->next = temp;

    return 1;
}

int enqueue(char * to_add)
{

    if (rear == NULL)
    {
        rear = new node;
        rear->next = rear;//needs to point to itself if first item
    }
    //else do normal case
    else 
    {
        node * temp = rear->next;
        rear->next = new node;
        rear = rear->next;
        rear->next = temp;
    }

    rear->data = new char[strlen(to_add) + 1];
    strcpy(rear->data, to_add);
    return 1;
}


// * HASH TABLES //////////////////////////////////////////////

// !note this is taking in char input, not int
// !but, this should still work!
int hash_function(char * key)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i)
    {
        hash = hash + key[i];
    }
    return hash % hash_table_size;
}


int add(char * key_value, char * to_add)
{
    int index = hash_function(key_value);

    if(hash_table[index] != NULL)
        cout << "Collision detected.\n";

    node * new_node = new node;
    new_node->data = new char[strlen(to_add) + 1];
    strcpy(new_node->data, to_add);
    new_node->next = hash_table[index];
    
    hash_table[index] = new_node;
    return 1;
}

int remove(char * key_value)
{
    int index = hash_function(key_value);
    
    node * temp = hash_table[index];
    node * prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->data, key_value) == 0)
        {
            if (prev == NULL)
            {
                hash_table[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete [] temp->data;
            delete temp;
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

int retrieve(char * key_value, char * & returned_data)
{
    int index = hash_function(key_value);
    node * temp = hash_table[index];
    while (temp != NULL)
    {
        if (strcmp(temp->data, key_value) == 0)
        {
            strcpy(returned_data, temp->data);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int display()
{
    for (int i = 0; i < hash_table_size; ++i)
    {
        node * temp = hash_table[i];
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    return 1;
}

int display_of_name(char * name)
{
    int index = hash_function(name);
    node * temp = hash_table[index];
    while (temp != NULL)
    {
        if (strcmp(temp->data, name) == 0)
        {
            cout << temp->data << " ";
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

