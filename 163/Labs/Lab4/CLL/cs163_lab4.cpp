#include "clist.h"

//Here is the main you will use for the circular linked list portion

int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	 	//displays the list
    
    int num_counted = object.count_all();
    
    cout << "Num counted: " << num_counted << endl;
    cout << endl;


    //PLEASE PUT YOUR CODE HERE to call the function being tested
    int removed = object.remove_entire();
    num_counted = object.count_all();
    
    cout << "Num counted: " << num_counted << endl;
    cout << endl;
   

    object.display(); //resulting list after your function call!
    
    return 0;
}
