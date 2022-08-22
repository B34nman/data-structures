#include "cs163_2-3.h"
using namespace std;

int main()
{
    table trees;
    trees.build();
    trees.display();

    table trees2;
    trees2.build();  
    
    /*  PLACE YOUR FUNCTION CALL HERE */
    trees.display_23();
    bool largest = trees.find_largest();
    cout << "More than once? " << largest << endl;
    trees.copy(trees2);
    trees.display();

    return 0;
}
