#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */

    int average = BST.average_all_data();
    cout << "sum: " << average << endl;

    /* 
    BST.count();
    BST.sum();
    BST.height();
    BST.remove_all();
    BST.display();
    */

    BST.display();

    return 0;
}
