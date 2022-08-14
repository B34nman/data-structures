#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Task {
    public:
        Task();
        // IMPLEMENT THESE FUNCTIONS:
        int create_task(char title_to_add[], char desc_to_add[]);
        bool mark_complete(char title_to_find[]);

        // This function is already implemented for you:
        void display();

    private:
        string title;
        string description;
        bool completed;
};