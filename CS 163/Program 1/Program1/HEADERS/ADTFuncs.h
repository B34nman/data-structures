#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

//Andy Franck, CS 163, 7/7/22
//this file is the header for our ADT. It is made to declare all functions, structs,
//classes, etc. The content of the functions will go inside the .cpp file, but this 
//header allows us to condense all our declarations down. 

//we want an apartment struct to simplify all the apartment data
//it makes it very simple to pass into functions & search through
struct Apartment
{
	char* aptName;
	int rent;
	int numBath;
	int numBed;
	bool containsPool;
};

//we need a node for each apartment object for our linked list
//we also need a next pointer, but more importantly
//a pointer to our head of our feature list for that apartment
struct aptNode
{
	Apartment apartmentObject; //struct containing all apartment information

	aptNode * nextApt; //pointer to next apartment node
	struct featureNode * featureHead; //pointer to the head of the features
};

//Since featureNode is defined later, the keyword 
//struct will be needed for your featureHead (and the data type needs to be struct featureNode)

//we need another node for our features, for that linear linked list
//just has the name of the feature and review out of 5 stars
struct featureNode
{
	char * featureName;
	int featureReview; // this will be out of 5 (for 5 stars)
	featureNode * nextFeature; //pointer to next feature node
};

//this is our required list class.
class list
{
	public:
		
		list(); //constructor
		~list(); //destructor, frees all memory allocated
		
		//creates apartment in the linear linked list. Pass in apartment struct
		//which has information about the apartment.
		//creates a new node for the apartment, and sorts alphabetically
		bool createAppt(Apartment & apartmentObject); 

		//remvoves apartment with the name given.
		//pass in apartment name, it will be removed from linked list, and memory freed
		//recursive function, so there is a wrapper that takes in apartment name
		bool removeAppt(char * aptName);

		//displays all apartments currently in the list.
		//no info required
		//top function is wrapper for recursive traversal
	    bool displayAppts();	
		bool displayAppts1(aptNode * head);

		//displays all features of a passed in apartment.
		//pass in the name of an apartment, then lists all features
		bool displayFeature(char * aptName);
		
		//adds a feature to a certain apartment.
		//takes name of the apartment, name of feature, and review
		bool addFeature(char * aptName, char * featureName, int featureReview);
		
		//searches for a given feature and lists all apartments 
		//that contain it. Passes in the name of the feature to be searched for
		bool featureSearch(char * featureName);


	private:
		aptNode * head;

};



