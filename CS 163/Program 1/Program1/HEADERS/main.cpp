#include "ADTFuncs.h"

//Andy Franck, CS 163, 7/7/22

//This program is the main/driver file. This is where one utility function exists,
//and this function manages all of the user inputs to manage the ADT.
//The client program allows the user to test every option themselves,
//and easily manage all apartments, features, etc. and test all functions. 
//in regards to it's purpose within the entire program, this file exists
//to test the functions of the ADT. 

bool apartmentManager(int, list&); //function declaration for apartment manager

//driver program
int main()
{
     
    list aptList;
    bool makeApt = true;
    int choice;

    while (makeApt)
    {
        std::cout << std::endl;
        std::cout << "To add Apartment, press 1. To add a feature for an apartment, press 2. \n";
        std::cout << "To remove an Apartment, press 3. To dislay apartments with a certain feature, press 4. \n";
        std::cout << "To display all apartments, press 5. To display features of a certain apartment, press 6 \n";
        std::cout << "To exit, press 7 \n";
        std::cin >> choice; std::cin.ignore(100, '\n');
        if (!apartmentManager(choice, aptList)) makeApt = false;
    }
    return 0;
}


//below is function for main, used to manage inputs

//simplified main by implimenting a function to manage each choice and respond accordingly 
//manager function to manage our main. 
//takes user input in form of an int, and runs functions
//based on what the user has inputted. Also takes list argument
//so it can call the list functions 
bool apartmentManager(int i, list & aptList)
{ 
    std::cout << std::endl;
    int SIZE = 100;
    Apartment tempApt; 
    char apt[SIZE], feature[SIZE];
    int review;
    char pool;

    if (i == 1)
    {
        std::cout << "Please enter the apartment name\n";
        std::cin.get(apt, SIZE, '\n'); std::cin.ignore(SIZE, '\n');
        tempApt.aptName = new char[strlen(apt) + 1];
	    strcpy(tempApt.aptName, apt);
        std::cout << "Please enter the rent cost\n";
        std::cin >> tempApt.rent; std::cin.ignore(100, '\n');
        std::cout << "Please enter the number of baths\n";
        std::cin >> tempApt.numBath; std::cin.ignore(100, '\n');
        std::cout << "Please enter the number of beds\n";
        std::cin >> tempApt.numBed; std::cin.ignore(100, '\n');
        std::cout << "Does it contain a pool? Y / N \n";
        std::cin >> pool; std::cin.ignore(100, '\n');
        if (pool == 'Y')
            tempApt.containsPool = true;
        else
            tempApt.containsPool = false;

        if(!aptList.createAppt(tempApt))
        {
            std::cout << "Unable to create apartment.\n";
        }
        else
        {
            std::cout << "Apartment Created.\n";
        }
        delete []tempApt.aptName;
        tempApt.aptName = NULL; 
        return true;
    }
    else if (i == 2)
    {
        std::cout << "Please enter the apartment name\n";
        std::cin.get(apt, SIZE, '\n'); std::cin.ignore(SIZE, '\n');
        std::cout << "Please enter the feature name\n";
        std::cin.get(feature, SIZE, '\n'); std::cin.ignore(SIZE, '\n');
        std::cout << "Please enter the feature review (1,2,3,4,5/5)\n";
        std::cin >> review; std::cin.ignore(100, '\n');
        if(!aptList.addFeature(apt, feature, review))
        {
            std::cout << "Unable to add feature.\n";
        }
        else
        {
            std::cout << "Feature added.\n";
        }
        return true;
    }
    else if (i == 3)
    {
        std::cout << "Please enter the apartment name to remove\n";
        std::cin.get(apt, SIZE, '\n'); std::cin.ignore(SIZE, '\n');
        tempApt.aptName = new char[strlen(apt) + 1];
	    strcpy(tempApt.aptName, apt);
        if(!aptList.removeAppt(tempApt.aptName))
        {
            std::cout << "Apartment removal was unsuccessful.";
        }
        else
        {
            std::cout << "Apartment removed.\n";
        }
         delete []tempApt.aptName;       
         tempApt.aptName = NULL;  
         return true;
    }
    else if (i == 4)
    {
        std::cout << "Please enter the feature name to search for\n";
        std::cin.get(feature, SIZE, '\n'); std::cin.ignore(SIZE, '\n');
        if (!aptList.featureSearch(feature))
        {
            std::cout << "Feature search was unsuccessful.\n";
        }
        return true;
    }
    else if (i == 5)
    {
        if(!aptList.displayAppts())
        {
            std::cout << "Unable to display apartments. Have you added any?\n";
        }
        return true;
    }
    else if (i == 6)
    {
        std::cout << "Please enter the apartment name to display its features\n";
        std::cin.get(apt, SIZE, '\n'); std::cin.ignore(SIZE, '\n');
        tempApt.aptName = new char[strlen(apt) + 1];
	    strcpy(tempApt.aptName, apt);
        if(!aptList.displayFeature(tempApt.aptName))
        {
            std::cout << "Unable to display features for requested apartment\n";
        }
        delete []tempApt.aptName;
        tempApt.aptName = NULL;
	return true; 
    }
    else if (i == 7)
    {
        return false;
    }
    else
    {
        std::cout << "Please input a number from 1-7. " << std::endl;
        return true;
    }
    
}





