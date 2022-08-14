#include "cs163_list.h"

// This is a to-do list program that allows a user to give a title
// and description for tasks to be done on different days. The user
// may also search for a task to mark it as complete.

int main() 
{
    // Instantiate objects of the data structure classes.
    List my_list;
    Task my_task;
    
    // Declare and initialize variables.
    int entry_counter{0};
    int day_counter{0};
    char temp_title[TITLE]{'\0'};
    char temp_notes[NOTES]{'\0'};

    // Introduce the user and explain how to use the program.
    cout 
    << "To-do list! Add tasks for the first day until done,\n"
    << "then add another day of tasks if desired.\n ";

    // Nested do-while loops: 
    // Outer loop for each day, inner loop for each task of a day.
    do
    {
        // Create a "new day" (a new Node in the List).
        my_list.new_day(); // TIP: Test this function with its return value!

        ++day_counter;
        entry_counter = 0;

        // Get input from user, pass it to Task object, pass object to List.
        do 
        {
            ++entry_counter;

            // Get user input for title and notes.
            cout << "\nDay " << day_counter << ", " << "task " << entry_counter << ":" << endl;

            cout << "Title > ";
            user_input(temp_title);

            cout << "Description > ";
            user_input(temp_notes);

            // Add title and notes to a Task, then add the Task to the List.
            my_task.create_task(temp_title, temp_notes);
            my_list.add_task(my_task);

            cout << "\nAdd another task for day " << day_counter << "? ";
        } while (again());
        
        cout << "Add tasks for a new day? ";
    }
    while (again());

    cout << "\n-----\nHere are your tasks: " << endl;
    my_list.display();
    cout << "-----" << endl;

    // User marks a task 'complete' by entering task title.
    do
    {
        cout << "\nSearch by title for a task to mark as completed:" << endl << "> ";
        user_input(temp_title);

        if(!my_list.complete_task(temp_title))
            cout << "\nTask \"" << temp_title << "\" was not found." << endl;
        else
            cout << "\nTask \"" << temp_title << "\" was marked as completed." << endl;

        cout << "Complete another task? ";
    } while (again());

    // Displays all tasks in the LLL and if they are complete.
    cout << "\n-----\nHere are your tasks now: " << endl;
    my_list.display();
    cout << "-----" << endl;

    return 0;
}
