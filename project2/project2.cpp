// The average calculator
// Anthony Garrett
// 02/21/2020
// Displays the class that is entered by the user followed by
// the averages of scores < 70 and averages of scores >= 70
#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
double calculate_average(double, double);
void print_result(string, double, double);


int main() {

    string class_name;
    char menu_choice = 'y';
    double score,              // score entered by the user
           low_total,          // total of scores < 70
           low_count,          // number of scores < 70
           high_count,         // number of scores >= 70
           high_total,         // total of scores >= 70
           low_average,        // average of scores < 70
           high_average;       // average of scores >= 70

    //Prompting user for class name
    cout << "\nWelcome to the Average Calculator\n";
    cout << "Please enter the name of the class: ";

    // inputing classname including spaces
    getline(cin, class_name);

    // Initializing totals and counts
    low_total = 0;
    high_total = 0;
    low_count = 0;
    high_count = 0;

    // Control loop to prompt user for more scores
    while (tolower(menu_choice) != 'n'){

        cout <<"\nPlease enter a score for the class: ";
        cin >> score;

        // Making sure the score entered is between 0 and 100
        if(score >= 0 && score <= 100){

            // separating the scores to increment counts and add to totals
            if(score < 70){
            low_total += score;
            low_count++;
            }
            else {
                high_total += score;
                high_count++;
            }
        }
        else{
            // Restarting the loop if the score is not between 0 and 100
            cout << "Please enter a score between 0 and 100.\n";
            continue;
        }

        cout <<"\nWould you like to enter another score? (Y/n): ";
        cin >> menu_choice;
            
        
    }

    // Getting the average of the low and high scores
    low_average = calculate_average(low_total, low_count);
    high_average = calculate_average(high_total, high_count);

    // Printing the results to the screen for the user
    print_result(class_name, low_average, high_average);
    
    return 0;
}

//--------------------------------------------------
// Accepts a string and 2 doubles as input
// Prints the formatted output containing the input
//--------------------------------------------------

void print_result(string class_name, double low, double high){

    cout << setprecision(1) << fixed << endl;

    cout << "\n" << class_name << ": mean of grades >= C is ";
    cout << high << "; mean of grades < C is " << low << "\n\n";
}

//--------------------------------------------------
// Accepts 2 doubles as input
// Calculates the average and returns a double
//--------------------------------------------------
double calculate_average(double total, double count){

    // Preventing division by 0
    if (count == 0){
        return 0;
    }
    else {
        return total / count;
    }
}