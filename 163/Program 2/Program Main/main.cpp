#include "functions.h"
using namespace std;

//Andy Franck, CS 163, 7/22/22

//This program is the main/driver file. This file calls both utility functins for queue and stack,
//and these functions manage all of the user inputs to manage the ADT.
//The client program allows the user to test every option themselves,
//and easily manage all events and test all functions. 
//in regards to it's purpose within the entire program, this file exists
//to test the functions of the ADT. 

int main()
{

    Stack eventStack; //create queue and list stack
    Queue eventQueue;
    bool addEvent = true, queue = true;;
    
    while(addEvent) //two while loops to manage user inputs
    {
        if(!eventStack.stackInputManager(eventStack)) addEvent = false;
    }
    while(queue)
    {
        if(!eventQueue.queueInputManager(eventQueue)) queue = false;
    }

    return 0;
}


