// Specification File for the LindedList class
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

using namespace std;

//************************************************************
// Struct for creating a node for the LinkedList class as defined below
//************************************************************

struct MyNode
{
    int sequence_number;
    string document_name;
    int month;
    int day;
    int year;
    int hour;
    int minute;
    string owner;
    string service_required;
    MyNode *next;
};

//************************************************************
// LinkedList class
// data members are pointers to MyNode elements of the list
// Default constructor
// Destructor to delete all nodes
// Member functions usage defined in implementation file
//************************************************************

class LinkedList
{
private:
    MyNode *head;
    MyNode *tail;

public:
    LinkedList();

    ~LinkedList();

    void InsertNode(string, int, int, int, int, int, string);
    bool DeleteNode(string);
    MyNode *SearchNode(string);
    MyNode *PrintDocument();
    int ListAll();
};

#endif