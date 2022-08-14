#include "dlist.h"

//Now let's test doubly linked lists

int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    object.duplicate_last(); 
    //object.display_last_two();
    //object.remove_last_two();

    object.display();
    
    return 0;
}
