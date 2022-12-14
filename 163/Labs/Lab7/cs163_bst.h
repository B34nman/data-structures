//This class was prepared for a binary search tree implementation of
//a table abstraction. For the lab we will keep the underlying data
//simple - just an integer.
//
//Please see below for the prototypes that you will be implementing!
//These must be implemented before you can compile and run.

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

struct node
{
    int data;
    node * left;
    node * right;;
};

class table
{
    public:

	//  ***These functions are called "wrapper" functions and
    //  are provided as a sample on how to call your recursive functions
	~table();

	// * practice functions for proficiency demo
	int insert(int to_add);
	int count();
	int disp_sorted();
	int count_pass(int passed_val);
	int add_item(int to_add);
	int count_no_children();
	int average_all_data();
	int count_greater_node();

	
    //  ***Now it is your turn to write these in the .cpp file!
	int sum();
 	int height();	//simply call the private version of the functions
	int remove_all();
	int copy(const table & to_copy); 

    // ***These functions have already been written for you   
	table();
	int build(); 
	int display();  //Provided for you. 

    private:

	node * root;
	int disp_sorted(node * root);
	int count_pass(node * root, int passed_val);
	int add_item(node * root, int to_add);
	int count_no_children(node * root);
	float average_all_data(node * root, float sum, float count);
	int count_greater_node(node * root, int rootVal);
	
	
	//  ***These are the functions you will be writing recursively!
	int insert(node * root, int to_add);
	int count (node * root);	
	int sum (node * root);		
	int height (node * root);	
	int remove_all(node * & root);	
	int copy (node * & destination, node * source);	


};






 
  

