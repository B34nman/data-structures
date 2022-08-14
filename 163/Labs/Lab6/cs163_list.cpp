#include "cs163_list.h"

// EXERCISE 1
// Use unique pointers to add a node to the beginning of a linear linked list.
int List::new_day() 
{
    unique_ptr<Node> hold = move(head);
    head = make_unique<Node>();
    head->next = move(hold);
}

// EXERCISE 3
// Use a vector's built in functionality to "push" a Task to a node's vector.
int List::add_task(Task & to_add) 
{
    head->tasks.push_back(to_add);
}

// EXERCISE 4.2 (Do Ex: 4.1 in `cs163_task.cpp` first)
// Call the recursive function from a wrapper to traverse the LLL.
bool List::complete_task(char title_to_find[]) 
{
    if(head == NULL)
        return false;
    return complete_task(head, title_to_find);
}

// EXERCISE: 4.3 (Do Ex: 4.2 [above] first)
// NOTE: Most of this function is done for you. You will only be implementing the
// `for loop` to iterate through a vector in a node, comparing each vector's
// title.
bool List::complete_task(unique_ptr<Node> & head, char title_to_find[]) 
{
    if(!head)
        return false;
    bool found{false};

    // IMPLEMENT THIS LOOP
    for (auto & task : head->tasks) 
    {
        if(task.mark_complete(title_to_find)
                found = true;
    }

    return found + complete_task(head->next, title_to_find);
}
