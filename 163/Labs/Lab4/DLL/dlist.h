//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
	int insert_after(int to_add);
	int insert_before(int to_add);
	int display_last_two();
	int remove_last_two();

    int duplicate_last();
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL

	 int insert_after(node * & head, int to_add);
	 int insert_before(node * & head, int to_add);
	 int display_last_two(node * head);
	 int remove_last_two(node * & head);
     int duplicate_last(node * & head, int lastData);
};
