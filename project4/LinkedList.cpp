// Implementation File for the LindedList class
#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//************************************************************
// Constructor to assign points to NULL
//************************************************************

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

//************************************************************
// Destructor to delete all nodes in the list
//************************************************************

LinkedList::~LinkedList()
{
    MyNode *nodePtr;  // Used to step through the list of nodes
    MyNode *nextNode; // Used to keep track of the next node in the list

    // Start at the beginning of the list
    nodePtr = head;

    // Step through the list until the current pointer points to null
    while (nodePtr != NULL)
    {
        // Save the next pointer value
        nextNode = nodePtr->next;

        delete nodePtr;

        nodePtr = nextNode;
    }
}

//************************************************************
// Insert New Node into the Linked List at the head
// Requires 7 inputs string, int, int, int, int, int, string
// Doesn't return anything
//************************************************************

void LinkedList::InsertNode(string doc_name, int new_month, int new_day, int new_year, int new_hour, int new_minute, string user)
{
    MyNode *newNode;

    // Allocate new node and store the values
    newNode = new MyNode;
    newNode->document_name = doc_name;
    newNode->month = new_month;
    newNode->day = new_day;
    newNode->year = new_year;
    newNode->hour = new_hour;
    newNode->minute = new_minute;
    newNode->owner = user;

    // If the list is empty assign head and tail to the new node and then the tail ptr to null
    // to signify the end of the list
    if (!head)
    {
        newNode->sequence_number = 1;
        head = newNode;
        tail = newNode;
        tail->next = NULL;
    }

    // If the list has members then add the new node at the head and increment the sequence_number
    else
    {
        newNode->sequence_number = head->sequence_number + 1;
        newNode->next = head;
        head = newNode;
    }
}

//************************************************************
// Delete Node from the List
// Accepts doc_name string as input
// Returns a bool to represent if the document was found and deleted
//************************************************************

bool LinkedList::DeleteNode(string doc_name)
{
    MyNode *nodePtr;
    MyNode *prevNode;
    MyNode *delNode;

    // Search the list for the node with doc_name as document_name
    delNode = SearchNode(doc_name);

    // If delNode wasn't found by SearchNode then return false
    if (!delNode)
    {
        return false;
    }

    // If delNode is the head of the list
    if (delNode == head)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        return true;
    }
    // All other deletions traverse list and delete if found otherwise return false
    else
    {
        nodePtr = head;

        while (nodePtr != NULL && delNode != nodePtr)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr)
        {
            prevNode->next = nodePtr->next;
            delete nodePtr;
            return true;
        }

        return false;
    }
}

//************************************************************
// Search the list for the given document name
// Accepts string doc_name as input
// Return pointer to the node containing the document or
// null if not found
//************************************************************

MyNode *LinkedList::SearchNode(string doc_name)
{
    MyNode *nodePtr;
    nodePtr = NULL;

    if (!head)
    {
        return nodePtr;
    }
    else
    {
        // Set current pointer to the head of the list
        nodePtr = head;

        // Loop through the list until the document name matches or nodePtr is null
        while ((nodePtr->document_name != doc_name) && (nodePtr != NULL))
        {
            nodePtr = nodePtr->next;
        }

        return nodePtr;
    }
}

//************************************************************
// Delete Node from the List
// Accepts no inputs
// Return a pointer to the tail of the list
//************************************************************

MyNode *LinkedList::PrintDocument()
{
    MyNode *nodePtr;
    MyNode *prevPtr;

    // Check if list is empty then return NULL and notify user
    if (!head)
    {
        cout << "\n\tNo documents to print.\n";
        return NULL;
    }

    // Check if only one node exists in list
    // Delete head and notify user
    if (head == tail)
    {
        nodePtr = head;

        cout << "\n\tThe " << nodePtr->document_name << " document has been printed." << endl;
        head = NULL;
        tail = NULL;
        delete nodePtr;
        return NULL;
    }
    else
    {

        nodePtr = head;

        while (nodePtr != tail)
        {
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr)
        {
            cout << "\n\tThe " << nodePtr->document_name << " document has been printed." << endl;
            tail = prevPtr;
            prevPtr->next = NULL;
            delete nodePtr;
            return tail;
        }
    }
}

//************************************************************
// List all nodes to the console
// Accepts no inputs
// Return the total number of nodes in the list
//************************************************************

int LinkedList::ListAll()
{
    int counter = 0; // Keeps track of the number of nodes in the list

    MyNode *nodePtr;

    if (!head)
        return counter;

    nodePtr = head;

    // Traverse the list printing the required information to the console
    while (nodePtr != NULL)
    {
        counter++;
        cout << "\t" << left << setw(10) << nodePtr->sequence_number << setw(20) << right << nodePtr->document_name << setw(15) << " " << setw(2) << nodePtr->month << "/" << setw(2) << nodePtr->day << "/" << setw(4) << nodePtr->year;
        cout << " " << setw(2) << nodePtr->hour << setw(1) << ":" << setw(2) << nodePtr->minute << right << setw(20) << nodePtr->owner << endl;
        nodePtr = nodePtr->next;
    }

    return counter;
}