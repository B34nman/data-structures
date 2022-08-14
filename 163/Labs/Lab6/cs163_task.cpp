#include "cs163_task.h"

// EXERCISE 2
// Add the character arrays passed from `main` to a Task object's data.
int Task::create_task(char title_to_add[], char desc_to_add[]) 
{
    title = title_to_add;
    description = desc_to_add;
    if(title.empty() || description.empty())
        return 0;
}

// EXERCISE 4.1 
// Use a string's built-in functionality to compare itself with a passed argument.
bool Task::mark_complete(char title_to_find[]) 
{
    bool success{false};
    if(title == title_to_find)
    {
        completed = true;
        success = true;
    }
    return success;
}
