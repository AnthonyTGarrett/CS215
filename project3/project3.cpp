// Sorting Algorithm efficiency reporter
// Anthony Garrett
// 03/27/2020
// Sorts array of numbers with user specified amount of members
// Displays the report of the number of loops and swaps in each sort method used
// Sort methods used are bubbleSort, selectionSort, and quickSort

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void bubbleSort(int[], int, int &, int &);
void selectionSort(int[], int, int &, int &);
void quickSort(int[], int, int, int &, int &);
void swap(int &, int &);
int partition(int[], int, int, int &, int &);

int main()
{

    int nums[20001];
    int numsCopy[20001]; // Used to make a copy for each sort function

    int bubbleLoops, selectionLoops, quickLoops = 0; // Counter for loop iteration in each algorithm
    int bubbleSwaps, selectionSwaps, quickSwaps = 0; // Counter for swaps in each algorithm

    int UserNumOfNumbers = 0;
    string user_input = "";

    cout << endl
         << "Welcome to the sort function efficiency reporter" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Please enter the number elements to sort or " << endl;
    cout << "Enter 'choose a number for me' for default: ";
    getline(cin, user_input);

    // Checking for user option to use default
    if (user_input == "choose a number for me")
    {
        UserNumOfNumbers = 10000;
    }

    // Converting string input to int for number of elements
    else
    {
        UserNumOfNumbers = atoi(user_input.c_str());

        // Validating number of elements
        while (UserNumOfNumbers < 10 || UserNumOfNumbers > 20000)
        {
            cout << "Please enter a valid number of elements between 10 and 20000: ";
            cin >> UserNumOfNumbers;
        }
    }

    // Creating a seed for rand() then looping through the array to add random
    // positive numbers between 1 and 1000000
    srand(time(0));
    for (int i = 0; i < UserNumOfNumbers; i++)
    {
        nums[i] = rand() % 1000000 + 1;
    }

    //--------------------------------------------------
    // I am making a fresh copy of the array with the random elements to pass to each sort function
    // The size UserNumOfNumber is also passed to each sort function
    // Each sort function also has counters that are passed by reference to count loops and swaps
    // Quick sort requires the start and stop points which are passed to that function
    //--------------------------------------------------

    for (int i = 0; i < UserNumOfNumbers; i++)
        numsCopy[i] = nums[i];

    bubbleSort(numsCopy, UserNumOfNumbers, bubbleLoops, bubbleSwaps);

    for (int i = 0; i < UserNumOfNumbers; i++)
        numsCopy[i] = nums[i];

    selectionSort(numsCopy, UserNumOfNumbers, selectionLoops, selectionSwaps);

    for (int i = 0; i < UserNumOfNumbers; i++)
        numsCopy[i] = nums[i];

    quickSort(numsCopy, 0, UserNumOfNumbers - 1, quickLoops, quickSwaps);

    // Displaying the final results to the user in a table format
    cout << endl
         << "SORT ALGORITHM RUN EFFICIENCY" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << left << setw(25) << "ALGORITHM" << right << setw(25) << "LOOP COUNT" << setw(25) << "DATA MOVEMENT" << endl;
    cout << left << setw(25) << "Bubble Sort" << right << setw(25) << bubbleLoops << setw(25) << bubbleSwaps << endl;
    cout << left << setw(25) << "Selection Sort" << right << setw(25) << selectionLoops << setw(25) << selectionSwaps << endl;
    cout << left << setw(25) << "Quick Sort" << right << setw(25) << quickLoops << setw(25) << quickSwaps << endl;

    return 0;
};

//--------------------------------------------------
// Accepts array of int, int size of array, int loop count, and int swap count
// Sorts the input array of ints using the bubbleSort algroithm
// Increments counters to store the number of loop passes and swaps during sorting
//--------------------------------------------------

void bubbleSort(int array[], int size, int &loops, int &swaps)
{
    int maxElement;
    int index;
    loops = 0;
    swaps = 0;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            loops++;
            if (array[index] > array[index + 1])
            {
                swaps++;
                swap(array[index], array[index + 1]);
            }
        }
    }
}

//------------------------------------------------
// The swap function swaps a and b in memory.
//------------------------------------------------
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//--------------------------------------------------
// Accepts array of int, int size of array, int loop count, and int swap count
// Sorts the input array of ints using the Selection Sort algroithm
// Increments counters to store the number of loop passes and swaps during sorting
//--------------------------------------------------
void selectionSort(int array[], int size, int &loops, int &swaps)
{
    int minIndex, minValue;
    loops = 0;
    swaps = 0;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];

        for (int index = start + 1; index < size; index++)
        {
            loops++;
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }

        swap(array[minIndex], array[start]);
        swaps++;
    }
}

//--------------------------------------------------
// Accepts array of int, int size of array, int start of info, int end of info, int loop count, and int swap count
// Sorts the input array of ints using the QuickSort algroithm
// Increments counters to store the number of loop passes and swaps during sorting
//--------------------------------------------------
void quickSort(int array[], int start, int stop, int &loops, int &swaps)
{
    int pivotPos, stackTop = 0;
    int stack[20001];
    int pos = 0;
    loops = 0;
    swaps = 0;

    stack[stackTop++] = start;
    stack[stackTop++] = stop;

    while (stackTop > 0)
    {
        stop = stack[--stackTop];
        start = stack[--stackTop];

        if (start >= stop)
        {
            continue;
        }

        pivotPos = partition(array, start, stop, loops, swaps);
        if (pivotPos - start > stop - pivotPos)
        {
            stack[stackTop++] = start;
            stack[stackTop++] = pivotPos - 1;
            stack[stackTop++] = pivotPos + 1;
            stack[stackTop++] = stop;
        }
        else
        {
            stack[stackTop++] = pivotPos + 1;
            stack[stackTop++] = stop;
            stack[stackTop++] = start;
            stack[stackTop++] = pivotPos - 1;
        }
    }
}

int partition(int array[], int start, int stop, int &loops, int &swaps)
{
    int up = start;
    int part = array[stop];
    int down = stop - 1;
    if (stop <= start)
    {
        return start;
    }

    while (true)
    {
        while (array[up] < part)
        {
            loops++;
            up++;
        }
        while ((part < array[down]) && (up < down))
        {
            loops++;
            down--;
        }
        if (up >= down)
        {
            break;
        }
        swaps++;
        swap(array[up], array[down]);
        up++;
        down--;
    }

    swaps++;
    swap(array[up], array[stop]);
    return up;
}