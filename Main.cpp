//Assignment 1: Linked List
//By: Clayton Hinderline
// 7-22-2023

//Include our librarie(s)
#include <iostream>
#include <string>

using namespace std;


//*************************** Start of Stack *****************************


//Hardcode in a max value that our stack can hold
#define MAX 20

//Create our class Stack
class Stack
{
	//Create our accessors, Public and Private
	//Create a top variable to hold the top, or first value in our stack
	int top;
public:
	//Create our stack array, and pass in our MAX value that defines how many elements can be in our stack
	int myStack[MAX];

	//Our class Stack constructor
	Stack()
	{
		//Starts our top at -1, since our array indexing will start at 0
		top = -1;
	}
	//Create our push method to push elements to the top of our stack 
	bool Push(string);
	//Create our pop method to take the top element off the stack
	string pop();
	//Create our isEmpty method, which checks to see if the stack is empty. Returns a true or false
	bool isEmpty();

private:
};

//Define our push method
bool Stack::Push(string textMessage)
{
	//First check if the top is greater than or equal to the value of our MAX - 1
	if (top >= (MAX - 1))
	{
		//Display that the stack has overflowed, meaning that there is too many elements in our stack already
		cout << "Stack Overflow!!!";
		//Return false, which means that we can't add any more elements to our stack
		return false;
	}
	else
	{
		//Add a textMessage to the top of the stack
		myStack[++top] = ;
	}
}


//*************************** End of Stack *****************************


//*************************** Start of Linked List *****************************


//Create a struct to hold our variables for our nodes
struct node
{
	//Our data variable to be stored within nodes
	string webSites;
	//Our node pointer that points to the next node in the sequence
	node* next;
	//Another node pointer that points to the previous node in the sequence
	node* prev;
};

class linked_list
{
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
		current = NULL;
	}

	//Create a method to add another node of webSites
	void add_node(string webURL)
	{
		//Create a tmp pointer that points to a new node
		node* tmp = new node;
		//Assign our webSites to our webURL parameter
		tmp->webSites = webURL;
		//Sets the next node to NULL, since it will be added at the back of the sequence
		tmp->next = NULL;

		//If there is no head then set the head and the tail to our tmp value
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
			
		}
		//If there is a head then set the next node after tail to the tmp value
		//Then create a extra NULL node after to end the sequence
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
	}

	//Create a method to find a URL in our linked list
	void Find(string value)
	{
		//Create a boolian vairable called found so we can know weither we have found the correct value or not
		bool found = false;
		
		//Set the current pointer to the head
		current = head;

		//While there is a node for the current pointer, we can search through our data for the requested value
		//It also checks if the value has already been found, since we wouldn't want it just infinitely repeating
		while (current != NULL && found == false)
		{
			//Run this if we have found the value that we are looking for
			if (current->webSites == value)
			{
				//Set found to true, since we have found the value we are looking for
				found = true;
				//Let the user know where the value is in the memory address
				cout << "\nElement found at memory adress " << current << endl;
			}
			//If we do not find the data we are looking for we keep walking through the list
			else
			{
				current = current->next;
			}
		}
		//If we do not find the requested value in the linked list, we report it to the console
		if (found != true)
		{
			cout << "\nElement not found..." << endl;
		}
	}

	//Create the ability to print our linked list
	void printList()
	{
		//Create a temporary pointer to the head
		node* temp = head;

		//If the head is empty, or NULL then tell the user that its empty
		if (head == NULL)
		{
			cout << "The list is empty" << endl;
			//return to the main function
			return;
		}

		//If temp pointer does have data, then we print that data out to the console, and walk another node
		while (temp != NULL)
		{
			cout << temp->webSites << " " << endl;
			temp = temp->next;
		}
	}

private:
	//Create a pointer node for our head to our tail
	node* head, * tail, * current;
};

//*************************** End of Linked List *****************************


//Declare our main function
int main()
{
	cout << "\n\t********* List of Website URLS **********\n\n";
	//Create a object of our linked list class called url
	linked_list url;
	//Create our 20 nodes that have website URLS as data
	url.add_node("Amazon.com");
	url.add_node("Ebay.com");
	url.add_node("Facebook.com");
	url.add_node("Youtube.com");
	url.add_node("CraigsList.com");
	url.add_node("NewEgg.com");
	url.add_node("Codepen.io");
	url.add_node("gg.deals");
	url.add_node("Stackoverflow.com");
	url.add_node("store.steampowered.com");
	url.add_node("Google.com");
	url.add_node("synchronic.uat.edu");
	url.add_node("Quora.com");
	url.add_node("Twitter.com");
	url.add_node("Instagram.com");
	url.add_node("Wikipedia.org");
	url.add_node("cnn.com");
	url.add_node("discord.com");
	url.add_node("W3School.com");
	url.add_node("GeeksforGeeks.org");
	//Print the list of URLS
	url.printList();

	cout << "\n\t********* End Of List **********\n\n";

	cout << "\n\t********* Examples of the Find Function **********\n\n";

	//Search our nodes for certain urls
	url.Find("Google.com");
	url.Find("Twitter.com");
	url.Find("Minecraft.net");
	url.Find("cnn.com");

	//Exit the program
	return 0;
}