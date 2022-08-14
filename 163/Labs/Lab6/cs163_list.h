#include "cs163_task.h"

const int TITLE{21};
const int NOTES{151};

// Nodes for the LLL.
struct Node {
    vector<Task> tasks;
    unique_ptr<Node> next;
};

// Manages the linear linked list.
// List's public functions are called in `main`.
class List {
    public:
        List();
        ~List();

        // IMPLEMENT THESE FUNCTIONS
        int new_day();
        int add_task(Task & to_add);
        bool complete_task(char title_to_find[]);

        // This function is already implemented for you
        void display();

    private:
        bool complete_task(unique_ptr<Node> & head, char title_to_find[]);
        void display(unique_ptr<Node> & tail, int* & count);

        unique_ptr<Node> head;
};

// These functions are implemented for you:
void user_input(char[]);
bool again();