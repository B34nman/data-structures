#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    my_list.build();
    my_list.display_all();
    cout << " " << endl; 

    //PLACE YOUR FUNCTION CALL HERE!
   
    int totalSum = my_list.sum_total();
    cout << "Sum: " << totalSum << endl;

    cout << endl;

    if(my_list.remove_last() == false)
    {
        cout << "nothing to remove" << endl;
    }
    else
    {
        cout << "last node removed. new list: " << endl;
        cout << endl; 
        my_list.display_all();
    }
    

    //my_list.display_all();
    return 0;    
}
