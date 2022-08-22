
#include "cs163_bst.h"
using namespace std;


int table::count_pass(int passed_val)
{
    return count_pass(root, passed_val);
}

int table::count_pass(node * root, int passed_val)
{
    if(!root) return 0;
    if(root->data == passed_val)
        return 1 + count_pass(root->left, passed_val) + 
            count_pass(root->right, passed_val);
    else 
        return count_pass(root->left, passed_val) + 
            count_pass(root->right, passed_val); 

}

int table::add_item(int to_add)
{
    return add_item(root, to_add);
}

int table::add_item(node * root, int to_add)
{
    if(!root)
    {
        root = new node();
        root->data = to_add;
        return 1;
    }
    if(root->data == to_add) return 0;
    else if(root->data > to_add)
        return add_item(root->left, to_add);
    else
        return add_item(root->right, to_add);
}

int table::count_no_children()
{
    return count_no_children(root);
}

int table::count_no_children(node * root)
{
    if(!root) return 0;
    if(!root->left && !root->right)
        return 1; 
    return count_no_children(root->left) + 
        count_no_children(root->right);
}

int table::average_all_data()
{
    int sum, count;
    average_all_data(root, sum, count);
    return sum/count;
}

int table::average_all_data(node * root, int sum, int count)
{
    if(!root) return 0;
    sum += root->data;
    count++;
    average_all_data(root->left, sum, count);
    average_all_data(root->right, sum, count);
}

//count number of nodes greater than root's data
int table::count_greater_node()
{
    return count_greater_node(root, root->data);
}

int table::count_greater_node(node * root, int rootVal)
{
    if(!root) return 0;
    if(root->data > rootVal)
        return 1 + count_greater_node(root->left, rootVal)
            + count_greater_node(root->right, rootVal);
    else
        return 1 + count_greater_node(root->left, rootVal)
            + count_greater_node(root->right, rootVal);
}
