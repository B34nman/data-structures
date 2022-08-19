#include "cs163_tree.h"
using namespace std;

int main()
{
    table trees;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    trees.display_largest();
    int rootCount = trees.count_root();
    cout << "Root count: " << rootCount << endl;
    cout << endl << endl;

    table treeCopy;
    treeCopy.copy(trees);
    treeCopy.display();
    
    cout << endl << endl;

    int count = trees.count_3_data();
    cout << "Count of 3 data nodes: " << count << endl;
    cout << endl;

    int height = trees.height();
    cout << "Height of 2-3-4 tree: " << height << endl;
    cout << endl;

    table treeCopy2;
    treeCopy2.copy_234(trees);
    treeCopy2.display();

    return 0;
}
