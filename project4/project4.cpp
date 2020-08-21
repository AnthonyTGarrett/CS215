// Print Job Manager Simulator
// Anthony Garrett
// 04/17/2020
//
// Program to simulate a printer print queue
// Menu based UI to allow users to create print jobs, delete print jobs
// display print jobs, and simulate printing a print job
#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    LinkedList printJobs;    // Class instance
    int choice, total_nodes; // user menu choice and counter to catch ListAll return
    char garbage;            // collecting unused chars from formatting on cin

    string doc_name, user;              // Hold user input
    int month, day, year, hour, minute; // Input for new print job creation

    // Loop to display the available menu until the user enters 5 to quit
    do
    {
        cout << "\n\tPrint Queue Management System\n"
             << endl;
        cout << "\t1) New print job" << endl;
        cout << "\t2) Print a document" << endl;
        cout << "\t3) Cancel a print request - remove print job" << endl;
        cout << "\t4) List all documents waiting to be printed" << endl;
        cout << "\t5) Quit" << endl;

        cout << "\n\tWhat would you like to do? ";
        cin >> choice;
        garbage = cin.get();

        // Handle the input choice made by the user
        switch (choice)
        {
        // User choice for new print job
        // Prompt for new print jobs required arguments and discard garbage formatting
        case 1:
            cout << "\n\tI will need some information regarding the new print Job\n";
            cout << "\tPlease enter the document name: ";
            getline(cin, doc_name);

            cout << "\tPlease enter the date formatted as MM/DD/YYYY: ";
            cin >> month >> garbage >> day >> garbage >> year;
            cout << "\tPlease enter the time formatted as HH:MM: ";
            cin >> hour >> garbage >> minute;
            garbage = cin.get();

            cout << "\tPlease enter the username printing the document: ";
            getline(cin, user);

            // Call member function to insert new print job in the list
            printJobs.InsertNode(doc_name, month, day, year, hour, minute, user);
            break;

        // User choice to print documnt prints the first document in queue
        case 2:
            printJobs.PrintDocument();
            break;

        // User choice to cancel print job
        // Notify user of result of print job deletion attempt
        case 3:
            cout << "\n\tWhich print job would you like to cancel? ";
            getline(cin, doc_name);
            if (printJobs.DeleteNode(doc_name))
            {
                cout << "\n\tThe document was removed and was not printed.\n";
            }
            else
            {
                cout << "\n\tProbably too late, the document was already printed.\n";
            }
            break;

        // User choice to display all print jobs
        case 4:

            cout << "\n\n\tCLASSROOM BUILDING 222 PRINTER - DOCUMENTS WAITING FOR PRINTING\n\n";
            cout << "\t" << left << setw(10) << "SEQUENCE" << right << setw(20) << "NAME" << setw(32) << "ARRIVAL DATE/TIME" << setw(20) << "OWNER\n";
            total_nodes = printJobs.ListAll();
            cout << "\n\tThere are " << total_nodes << " job(s) waiting to be printed.\n";
            break;

        // User choice to quit
        // Thank the user for using the program before exit
        case 5:
            cout << "\nThanks for using the Print Queue Management System\n";
            break;

        // Prompts the user for the correct input if the int entered is incorrect
        default:
            cout << "\n\tPlease choose from 1 to 5\n";
            break;
        }

    } while (choice != 5);

    return 0;
};