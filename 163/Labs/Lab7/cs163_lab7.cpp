#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    /* 
    BST.count();
    BST.sum();
    BST.height();
    BST.remove_all();
    BST.display();
    */

    BST.copy(BST);
    BST.display();

    return 0;
}
