#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

//Andy Franck, CS 163, 7/22/22
//this file is the header for our ADT. It is made to declare all functions, structs,
//classes, etc. The content of the functions will go inside the .cpp file, but this 
//header allows us to condense all our declarations down. 

const int MAX = 5;

//struct for each event, contains all information about each event
struct event
{
    char * name = NULL; //name of the event
    char * description = NULL; //description of what it is like
    char * review = NULL; //review of what was good/bad
    int rating; //rating out of 10
    int scariness; //scariness rating out of 10

};

//struct for a node in our stack
struct eventNode
{
    event * entry;
    eventNode * nextEvent;
};

//struct for a node in our queue.
struct q_node
{
       event entry; 
       q_node * next;
};

class Stack
{
    public:

    Stack(); //constructor
    ~Stack(); //destructor (deallocates all memory)

    //pushes given event to the top of the stack.
    //takes in one argument, which is an event struct containing event information
    int pushStack(const event & to_add);

    //displays all events in the stack. does not need any arguments
    bool displayEvents();

    //removes the top event off of the stack.
    //no arguments are needed, since we are just removing from the top. 
    int popStack();

    //takes data from top event in the stack and inserts it into the inputted struct. 
    //event struct passed in, which recieves top of stack data. 
    int peekStack(event & at_top) const;

    //function to manage user inputs for the stack. takes in the stack class,
    //so it can call functions, use private variables. 
    bool stackInputManager(Stack & eventStack);

    private:
    eventNode * head; //head pointer for top of stack
    int top_index; //index for where we are in the current array
};

class Queue
{
    public:

    Queue(); //constructor
    ~Queue(); //destructor (deallocates all memory)

    //displays all events in the queue. does not need any arguments
    //wrapper function for recursive call
    bool displayQueue();
    //recursive function. passes in real rear and temp pointer, traverses until
    //it gets back to the original rear, then displays final node. 
    bool displayQueue(q_node * temp, q_node * rear);

    //takes data from front event in the queue and inserts it into the inputted struct. 
    //event struct passed in, which recieves front of queue data.  
    int peekQueue(event & peeked_info);

    //removes the front event of the queue. 
    //no arguments are needed. we are just removing from the front. 
    int dequeue();

    //adds item to the back of the queue. 
    //takes in the event struct for the information to add to our new node
    //created at the back
    int enqueue(event & to_add);

    //function to manage user inputs for the queue. takes in the queue class,
    //so it can call functions, use private variables. 
    bool queueInputManager(Queue & eventQueue);

    private:
        q_node * rear; //tail pointer

};
