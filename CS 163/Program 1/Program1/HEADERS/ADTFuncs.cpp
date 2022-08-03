#include "ADTFuncs.h"
using namespace std;

//Andy Franck, CS 163, 7/7/22

//this file is where all of our code for the functions goes. It is used to 
//write out all the code that belongs in each function, so they can operate properly.
//

//constuctor
list::list()
{
    head = nullptr;
}

//destructor, frees all memory allocated
list::~list()
{
    //destroy pointer memory
    aptNode* temp = head;
    //traverse through list and remove all features of nodes, then nodes themselves
    while (temp != NULL)
    {
        //cleaning all features of apartment
        featureNode* temp1 = temp->featureHead;
        while (temp1 != NULL)
        {
            delete []temp1->featureName;
            head->featureHead = temp1->nextFeature;
	        delete temp1; 
	        temp1 = head->featureHead;
        }

        //delete apartmentObject.aptName	
        delete []temp->apartmentObject.aptName;
        head = temp->nextApt; 
        delete temp;
	    temp = head; 
    }

}

//creates apartment in the linear linked list. Pass in apartment struct
//which has information about the apartment.
//creates a new node for the apartment, and sorts alphabetically
//pass in temporary struct in main used to copy data to created node
bool list::createAppt(Apartment & apartmentObject)
{
    //inserts new apartment node at the start of the linear linked list. 
    //check if apartment already exists

    //if list is empty
    if(head == NULL)
    {
        //creates a new node for our new apartment
        aptNode* newNode = new aptNode();

        //assigns data of the newnode to passed in data
        //need to allocate memory for the apartment name since it is a char*
        newNode->apartmentObject.aptName = new char[strlen(apartmentObject.aptName) + 1];
        strcpy(newNode->apartmentObject.aptName, apartmentObject.aptName); 
        newNode->apartmentObject.rent = apartmentObject.rent;
        newNode->apartmentObject.numBed = apartmentObject.numBed;
        newNode->apartmentObject.numBath = apartmentObject.numBath;
        newNode->apartmentObject.containsPool = apartmentObject.containsPool;

        newNode->nextApt = head;
        head = newNode;

        return true;
    }
    else
    {
        aptNode* temp = head;
        aptNode* previous = head;

        while (temp != NULL && strcmp(apartmentObject.aptName, temp->apartmentObject.aptName) > 0)
        {
            previous = temp;
            temp = temp->nextApt;
        }

        //matching name check
        if(strcmp(apartmentObject.aptName, previous->apartmentObject.aptName) == 0)
        {
            cout << "An apartment with the same name already exists. \n";
            cout << endl;
            return false;
        }

        //end of list check
        if(temp == NULL)
        {
            //if we get to the end of the list
            //we know temp is already on the last node if we get thru the while loop,
            //so we can just add the new node after the temp pointer
            aptNode* newNode = new aptNode();

            //assigns data of the newnode to passed in data
            //need to allocate memory for the apartment name since it is a char*
            newNode->apartmentObject.aptName = new char[strlen(apartmentObject.aptName) + 1];
            strcpy(newNode->apartmentObject.aptName, apartmentObject.aptName); 
            newNode->apartmentObject.rent = apartmentObject.rent;
            newNode->apartmentObject.numBed = apartmentObject.numBed;
            newNode->apartmentObject.numBath = apartmentObject.numBath;
            newNode->apartmentObject.containsPool = apartmentObject.containsPool;

            previous->nextApt = newNode;
            newNode->nextApt = nullptr;

            return true;
        }   

        if (strcmp(apartmentObject.aptName, temp->apartmentObject.aptName) < 0)
        {
            //if <0, then we know this is proper place and we can insert here
            //creates a new node for our new apartment
            aptNode* newNode = new aptNode();

            //assigns data of the newnode to passed in data
            //need to allocate memory for the apartment name since it is a char*
            newNode->apartmentObject.aptName = new char[strlen(apartmentObject.aptName) + 1];
            strcpy(newNode->apartmentObject.aptName, apartmentObject.aptName); 
            newNode->apartmentObject.rent = apartmentObject.rent;
            newNode->apartmentObject.numBed = apartmentObject.numBed;
            newNode->apartmentObject.numBath = apartmentObject.numBath;
            newNode->apartmentObject.containsPool = apartmentObject.containsPool;
            
            if(strcmp(temp->apartmentObject.aptName, head->apartmentObject.aptName) == 0)
            {
                //insert and make it the head
                newNode->nextApt = temp;
                head = newNode;
                return true;
            }

            newNode->nextApt = temp;
            previous->nextApt = newNode; 

            return true;
        }
    }
    return false;
}


//remvoves apartment with the name given.
//pass in apartment name, it will be removed from linked list, and memory freed
bool list::removeAppt(char * aptName)
{
    //traverses the linear linked list, compares name of apartment until
    //match, then removes that apartment. 
    aptNode * temp = head;
    aptNode * previous = head;
   
    //condition if we need to remove the first object in the list
    if(strcmp(aptName, temp->apartmentObject.aptName) == 0)
    {
	
        //cleaning all features of apartment
        featureNode* temp1 = temp->featureHead;
        while (temp1 != NULL)
        {
            delete []temp1->featureName;
            head->featureHead = temp1->nextFeature;
	    delete temp1; 
	    temp1 = head->featureHead;
        }

        //delete apartmentObject.aptName	
        delete []temp->apartmentObject.aptName;
        head = temp->nextApt;	

	delete temp; // delete features also

        
	return true;
    }

    while (temp != NULL && strcmp(aptName, temp->apartmentObject.aptName) != 0)
    {
        previous = temp;
        temp = temp->nextApt;
    }

    if(temp == NULL) return false; //means that there was no apartment with that name

    if(strcmp(aptName, temp->apartmentObject.aptName) == 0)
    {

        //if not the head, remove as usual

        //cleaning all features of apartment
        featureNode* temp1 = temp->featureHead;
        while (temp1 != NULL)
        {
            delete []temp1->featureName;
            head->featureHead = temp1->nextFeature;
	        delete temp1; 
	        temp1 = head->featureHead;
        }

        //delete apartmentObject.aptName	
        delete []temp->apartmentObject.aptName;
        previous->nextApt = temp->nextApt;
        delete temp;
        return true;
    }
    
    return false;
}


//displays all apartments currently in the list.
//no info required
//top function is wrapper for recursive traversal
//wrapper function for recursive traversal
bool list::displayAppts()
{
	if (head == NULL)
	{
	    return false;
    }	    
		
	return displayAppts1(head);
}
bool list::displayAppts1(aptNode * head)
{
    //traverses the linear linked lists and displays all the apartments
    //recursively
    if (head == NULL)
    {
        return true;
    }

    cout << endl;
	cout << "Apartment Name: " << head->apartmentObject.aptName << endl;
    cout << "Apartment Rent: $" << head->apartmentObject.rent << endl;
    cout << "Apartment Baths: " << head->apartmentObject.numBath << endl;
    cout << "Apartment Beds: " << head->apartmentObject.numBed << endl;
    if (head->apartmentObject.containsPool)
    {
        cout << "Apartment has a pool. \n";
        cout << endl;
    }
    else
    {
        cout << "Apartment does not have a pool. \n";
        cout << endl;
    }
    
    return displayAppts1(head->nextApt);
}

//displays all features of a passed in apartment.
//pass in the name of an apartment, then lists all features
bool list::displayFeature(char * aptName)
{
    //traverses linked list, compares name of apartment until
    //match, the displays features of that apartment
    aptNode * temp = head;

    while (temp != NULL && strcmp(temp->apartmentObject.aptName, aptName) != 0)
    {
        temp = temp->nextApt;
    }

    if (temp == NULL) return false; //if we get to the end, and no name matches

    if(strcmp(temp->apartmentObject.aptName, aptName) == 0) 
    {
        //display all features of apartment
        featureNode * temp1 = temp->featureHead;
        while (temp1 != NULL)
        {
            cout << "Feature Name: " << temp1->featureName << endl;
            cout << "Feature Review: " << temp1->featureReview << "/5 stars" << endl;
            cout << endl;
            temp1 = temp1->nextFeature;
        }

        return true;
    }

    return false;
}

//adds a feature to a certain apartment.
//takes name of the apartment, name of feature, and review
bool list::addFeature(char * aptName, char * featureName, int featureReview)
{
    //traverses linked list, compares name of apartment until
    //match, then adds feature into linked list of features
    //for that apartment
    aptNode * temp = head;
    while (temp != NULL && strcmp(temp->apartmentObject.aptName, aptName) != 0)
    {
        temp = temp->nextApt;
    }

    if (temp == NULL) return false;//if we get to the end, and no name matches

    if(strcmp(temp->apartmentObject.aptName, aptName) == 0) 
    {
        //add the feature
            
        //create node
        featureNode * testNode = new featureNode();
    
        //assigns data of the newnode to passed in data
        //we need to allocate memory here because it is char*
        testNode->featureName = new char[strlen(featureName) + 1];
        strcpy(testNode->featureName, featureName);

        testNode->featureReview = featureReview;

        //inserts node at the head of linear linked list (these do not need to be sorted)
        testNode->nextFeature = temp->featureHead;
        temp->featureHead = testNode;

        //breaks out of the while loop
        return true;
    }


    return false;
}

//searches for a given feature and lists all apartments 
//that contain it. Passes in the name of the feature to be searched for
bool list::featureSearch(char * featureName)
{
    //nested while loop to search for features
    //within the while loop to go through the main apartment
    //linear linked list
    aptNode* temp = head;
    while (temp != NULL)
    {
        featureNode * temp1 = temp->featureHead;
        while (temp1 != NULL)
        {
            if (strcmp(temp1->featureName, featureName) == 0)
            {
                //feature found
                cout << "Name of apartment with requested feature: " 
                    << temp->apartmentObject.aptName << endl;
                cout << endl; 
            }
            temp1 = temp1->nextFeature;
        }

        temp = temp->nextApt;
    }

    return true;
}


