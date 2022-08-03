#include "functions.h"
using namespace std;

//Andy Franck, CS 163, 7/22/22

//this file is where all of our code for the functions goes. It is used to 
//write out all the code that belongs in each function, so they can operate properly.
//This function contains both functions for the stack and queue classes. They are separated.
//Stack functions are listed first.

Stack::Stack()
{
    head = NULL;
    top_index = 0;
}

Stack::~Stack()
{
    //destroy pointer memory
    eventNode * temp = head;
    //traverse through list and remove all features of nodes, then nodes themselves
    while (temp != NULL)
    {
        //cleaning all parts of the array of each node
        for (int i = 0; i < MAX; ++i)
        {
            if(head->entry[i].name != NULL)
                delete [] head->entry[i].name;   
            if(head->entry[i].description != NULL)
                delete [] head->entry[i].description;
            if(head->entry[i].review != NULL)
                delete [] head->entry[i].review;
        }

        delete [] temp->entry;
        head = temp->nextEvent; 
        delete temp;
	temp = head; 
    }
    if(head) delete head;
    head = NULL;
}

//pushes given event to the top of the stack.
//takes in one argument, which is an event struct containing event information
int Stack::pushStack(const event & to_add)
{
    if (head == NULL)
    {
        head = new eventNode;
        head->entry = new event[MAX];
        head->nextEvent = NULL;
        top_index = 0;
    }
    if(top_index == MAX)
    {
        eventNode * temp = head;
        head = new eventNode;
        head->entry = new event[MAX];
        head->nextEvent = temp;
        top_index = 0;
    }
    //two checks, now just do standard
    //if(!head->entry[top_index].copy_entry(to_add))
    //    return 0;

    //we need to copy entry into head->entry[top_index]
    if(to_add.name == nullptr || to_add.description == nullptr || to_add.review == nullptr)
    { 
        return 0; //this means that the entry had null inputs 
    }
    
    //this may need to go into main, use temporary struct similar to program 1
    head->entry[top_index].name = new char[strlen(to_add.name) + 1];
    head->entry[top_index].description = new char[strlen(to_add.description) + 1];
    head->entry[top_index].review = new char[strlen(to_add.review) + 1];

    strcpy(head->entry[top_index].name, to_add.name);
    strcpy(head->entry[top_index].description, to_add.description);
    strcpy(head->entry[top_index].review, to_add.review);

    head->entry[top_index].rating = to_add.rating;
    head->entry[top_index].scariness = to_add.scariness;

    ++top_index;
    return 1;
}

//displays all events in the stack. does not need any arguments
bool Stack::displayEvents()
{
    if (head == NULL) return 0;
    //destroy pointer memory
    eventNode * temp = head;
    //traverse through list and display all parts of the nodes
    while (temp != NULL)
    {
        //going thru all array parts
        //if no node after, we go until top_index
        if(temp->nextEvent == NULL)
        {
            for (int i = 0; i < top_index; ++i)
            {
                cout << "Name of event: " << head->entry[i].name << endl;
                cout << "Description of event: " << head->entry[i].description << endl;
                cout << "Review of event: " << head->entry[i].review << endl;
                cout << "Rating /10 of event: " << head->entry[i].rating << endl;
                cout << "Scariness /10 of event: " << head->entry[i].scariness << endl;
                cout << endl;
            }
            return true;
        }
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                cout << "Name of event: " << head->entry[i].name << endl;
                cout << "Description of event: " << head->entry[i].description << endl;
                cout << "Review of event: " << head->entry[i].review << endl;
                cout << "Rating /10 of event: " << head->entry[i].rating << endl;
                cout << "Scariness /10 of event: " << head->entry[i].scariness << endl;
                cout << endl;
            }
        }

        //move down the list of nodes
        temp = temp->nextEvent; 
    }
    return 1;
}

//removes the top event off of the stack.
//no arguments are needed, since we are just removing from the top. 
int Stack::popStack()
{
    if(head == NULL) return 0;

    eventNode * temp = head; 
    if(top_index == 1)
    {
        delete [] temp->entry[top_index - 1].name; ///get this checked
        delete [] temp->entry[top_index - 1].review;
        delete [] temp->entry[top_index - 1].description;
        delete [] temp->entry;
        head = head->nextEvent;
        delete temp;
        if(head != NULL) top_index = MAX; 
        else top_index = 0; 
        return 1;
        //we use delete here because there is a node we are not using
    }

    --top_index;
    return 1;
}

//takes data from top event in the stack and inserts it into the inputted struct. 
//event struct passed in, which recieves top of stack data. 
int Stack::peekStack(event & at_top) const
{
    if(head == NULL) return 0;

    if(top_index == 0)
    {
        //go to next node and get that data
        if(head->nextEvent != NULL)
        {
            //check if this is possible. if not, we must copy like pop
            at_top = head->nextEvent->entry[MAX];
            return 1; 
        }
        else return 0;
    }
    at_top = head->entry[top_index - 1];
    return 1;
}

//function to manage user inputs for the stack. takes in the stack class,
//so it can call functions, use private variables. 
//below is function for main, used to manage inputs

//simplified main by implimenting a function to manage each choice and respond accordingly 
//manager function to manage our main. 
//takes user input in form of an int, and runs functions
//based on what the user has inputted.
bool Stack::stackInputManager(Stack & eventStack)
{
    int choice;
    event tempEvent;
    int SIZE = 100;
    char name[100];
    //int review;

    cout << std::endl;
    cout << "To add an event to stack, press 0. \n";
    cout << "To pop the stack, press 1. \n";
    cout << "To peek the stack, press 2. \n";
    cout << "To display all events in the stack, press 3. \n";
    cout << "To quit, press 4. \n";

    cin >> choice; cin.ignore(99, '\n');

    if(choice == 0)
    {
        //template for char* input from user
        cout << "Enter name of event: \n";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
        tempEvent.name = new char[strlen(name) + 1];
        strcpy(tempEvent.name, name);

        cout << "Enter review of event: \n";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
        tempEvent.review = new char[strlen(name) + 1];
        strcpy(tempEvent.review, name);

        cout << "Enter description of event: \n";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
        tempEvent.description = new char[strlen(name) + 1];
        strcpy(tempEvent.description, name);

        cout << "Enter rating/10: \n";
        cin >> tempEvent.rating; cin.ignore(100, '\n');

        cout << "Enter scariness/10: \n";
        cin >> tempEvent.scariness; cin.ignore(100, '\n');

        eventStack.pushStack(tempEvent);
        
        delete []tempEvent.name;
        tempEvent.name = NULL;
        delete []tempEvent.description;
        tempEvent.description = NULL;
        delete []tempEvent.review;
        tempEvent.review = NULL;
        cout << endl; 
        return true;
    }
    else if (choice == 1)
    {
        cout << "Popping stack... \n";
        if (eventStack.popStack() == 0)
        {
            cout << "Unable to pop stack. \n";
            return true;
        }
        cout << endl;

        cout << "Stack popped.\n";
        return true;
    } 
    else if (choice == 2)
    {

        cout << "Peeking stack... \n";
        if (eventStack.peekStack(tempEvent) == 0)
        {
            cout << "Unable to peek stack. \n";
            return true;
        }
        cout << endl;
        cout << "Peeked event info: \n";
        cout << "Event name: " << tempEvent.name << endl;
        cout << "Event description: " << tempEvent.description << endl;
        cout << "Event review: " << tempEvent.review << endl;
        cout << "Event rating: " << tempEvent.rating << "/10" << endl;
        cout << "Event scariness: " << tempEvent.scariness << "/10" << endl; 
        cout << endl; 
        return true;
    }
    else if (choice == 3)
    {
        if(eventStack.displayEvents() == 0)
        {
            cout << "Unable to display events. Have you added any?\n";
        }
        return true;
    }
    else if (choice == 4)
    {
        return false;
    }
    else 
    {
        cout << "Please enter value in requested range. \n";
        return true;
    }
    return true;
}


//constructor 
Queue::Queue()
{
    rear = NULL;
}

//destructor
Queue::~Queue()
{
    if (!rear) return;

    //destroy pointer memory
    //hold on to circular part
    q_node * temp = rear->next;
    //make it linear linked list
    rear->next = NULL;
    //go thru list with temp and delete everything
    while (temp != NULL)
    {
        rear = temp->next;
        delete [] temp->entry.name;
        delete [] temp->entry.review;
        delete [] temp->entry.description;
        delete temp;
	temp = rear; 
    }
    //clean up final node
    if (rear) delete rear;
    rear = NULL;
}

//displays all events in the queue. does not need any arguments
//wrapper function for recursive call
bool Queue::displayQueue()
{

    if(rear == NULL) return 0;
    q_node * temp = rear->next;

    return displayQueue(temp, rear);
}

//recursive function. passes in real rear and temp pointer, traverses until
//it gets back to the original rear, then displays final node. 
bool Queue::displayQueue(q_node * temp, q_node * rear)
{
    if(temp == rear)
    {
        cout << "Name of event: " << rear->entry.name << endl;
        cout << "Description of event: " << rear->entry.description << endl;
        cout << "Review of event: " << rear->entry.review << endl;
        cout << "Rating /10 of event: " << rear->entry.rating << endl;
        cout << "Scariness /10 of event: " << rear->entry.scariness << endl;
        cout << endl;
        return true;
    }

    cout << "Name of event: " << temp->entry.name << endl;
    cout << "Description of event: " << temp->entry.description << endl;
    cout << "Review of event: " << temp->entry.review << endl;
    cout << "Rating /10 of event: " << temp->entry.rating << endl;
    cout << "Scariness /10 of event: " << temp->entry.scariness << endl;
    cout << endl;

    return displayQueue(temp->next, rear);
}

//takes data from front event in the queue and inserts it into the inputted struct. 
//event struct passed in, which recieves front of queue data. 
int Queue::peekQueue(event & peeked_info)
{
    if(rear == NULL) return 0;

    peeked_info.name = new char[strlen(rear->next->entry.name) + 1];
    peeked_info.description = new char[strlen(rear->next->entry.description) + 1];
    peeked_info.review = new char[strlen(rear->next->entry.review) + 1];

    strcpy(peeked_info.name, rear->next->entry.name);
    strcpy(peeked_info.description, rear->next->entry.description);
    strcpy(peeked_info.review, rear->next->entry.review);

    peeked_info.rating = rear->next->entry.rating;
    peeked_info.scariness = rear->next->entry.scariness;

    return 1;
}

//removes the front event of the queue. 
//no arguments are needed. we are just removing from the front. 
int Queue::dequeue()
{
    if(rear == NULL) return 0;

    if(rear->next == rear)
    {
        delete [] rear->entry.name;
        delete [] rear->entry.review;
        delete [] rear->entry.description;
        delete rear;
        rear = NULL;
        return 1;
    }
    
    q_node * temp = rear->next->next;
    delete [] rear->next->entry.name;
    delete [] rear->next->entry.review;
    delete [] rear->next->entry.description;
    delete rear->next;
    rear->next = temp;

    return 1;
}

//adds item to the back of the queue. 
//takes in the event struct for the information to add to our new node
//created at the back
int Queue::enqueue(event & to_add)
{
    if(to_add.name == nullptr || to_add.description == nullptr || to_add.review == nullptr)
    { 
        return 0; //this means that the entry had null inputs 
    }

    if (rear == NULL)
    {
        rear = new q_node;
        rear->next = rear;//needs to point to itself if first item
    }
    //else do normal case
    else 
    {
        q_node * temp = rear->next;
        rear->next = new q_node;
        rear = rear->next;
        rear->next = temp;
    }

    
    rear->entry.name = new char[strlen(to_add.name) + 1];
    rear->entry.description = new char[strlen(to_add.description) + 1];
    rear->entry.review = new char[strlen(to_add.review) + 1];

    strcpy(rear->entry.name, to_add.name);
    strcpy(rear->entry.description, to_add.description);
    strcpy(rear->entry.review, to_add.review);

    rear->entry.rating = to_add.rating;
    rear->entry.scariness = to_add.scariness;

    return 1;
}

//function to manage user inputs for the queue. takes in the queue class,
//so it can call functions, use private variables. 

//simplified main by implimenting a function to manage each choice and respond accordingly 
//manager function to manage our main. 
//takes user input in form of an int, and runs functions
//based on what the user has inputted.
bool Queue::queueInputManager(Queue & eventQueue)
{
    int choice;
    event tempEvent;
    int SIZE = 100;
    char name[100];
    //int review;

    cout << endl;
    cout << "To add an event to queue (enqueue), press 0. \n";
    cout << "To remove an event from queue (dequeue) press 1. \n";
    cout << "To peek the queue, press 2. \n";
    cout << "To display all events in the queue, press 3. \n";
    cout << "To quit, press 4. \n";

    cin >> choice; cin.ignore(99, '\n');

    if(choice == 0)
    {
        //template for char* input from user
        cout << "Enter name of event: \n";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
        tempEvent.name = new char[strlen(name) + 1];
        strcpy(tempEvent.name, name);

        cout << "Enter review of event: \n";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
        tempEvent.review = new char[strlen(name) + 1];
        strcpy(tempEvent.review, name);

        cout << "Enter description of event: \n";
        cin.get(name, SIZE, '\n'); cin.ignore(SIZE, '\n');
        tempEvent.description = new char[strlen(name) + 1];
        strcpy(tempEvent.description, name);

        cout << "Enter rating /10: \n";
        cin >> tempEvent.rating; cin.ignore(100, '\n');

        cout << "Enter scariness /10 : \n";
        cin >> tempEvent.scariness; cin.ignore(100, '\n');

        eventQueue.enqueue(tempEvent);
       
        delete []tempEvent.name;
        tempEvent.name = NULL;
        delete []tempEvent.description;
        tempEvent.description = NULL;
        delete []tempEvent.review;
        tempEvent.review = NULL;
        cout << endl; 
        return true;
    }
    else if (choice == 1)
    {
        cout << "dequeueing... \n";
        if (eventQueue.dequeue() == 0)
        {
            cout << "Unable to dequeue. \n";
            return true;
        }

        return true;
    } 
    else if (choice == 2)
    {

        cout << "Peeking queue... \n";
        if (eventQueue.peekQueue(tempEvent) == 0)
        {
            cout << "Unable to peek queue. \n";
            return true;
        }
        cout << "Peeked event info: \n";
        cout << "Event name: " << tempEvent.name << endl;
        cout << "Event description: " << tempEvent.description << endl;
        cout << "Event review: " << tempEvent.review << endl;
        cout << "Event rating: " << tempEvent.rating << "/10" << endl;
        cout << "Event scariness: " << tempEvent.scariness << "/10" << endl; 
        cout << endl; 
        return true;
    }
    else if (choice == 3)
    {
        if(!eventQueue.displayQueue())
        {
            cout << "Unable to display events. Have you added any?\n";
        }
        return true;
    }
    else if (choice == 4)
    {
        cout << "Quitting...\n";
        return false;
    }
    else
    {
        cout << "Please enter value in requested range. \n";
        return true;
    }

    return true;
}
