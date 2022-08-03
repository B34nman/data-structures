#include "cs163_entry.h"


//Step #7: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{

       //Place your code here
    
    if(copy_from.title == nullptr || copy_from.notes == nullptr)
    { 
        return 0;
    }
    
    title = new char[strlen(copy_from.title) + 1];
    notes = new char[strlen(copy_from.notes) + 1];

    strcpy(title, copy_from.title);
    strcpy(notes, copy_from.notes);

    //copy the data into the class
   
    return 1;


}


//Step #8: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{

      //Place your code here

    if(matching_title == title)
    {
        //copy data etc
        found.title = new char[strlen(found.title) + 1];
        strcpy(found.title, matching_title);
        return 1;
    }
    else{
        std::cout << "titles do not match" << std::endl;
        return 0;
    }
    

}

