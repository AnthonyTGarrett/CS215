// Woody's Sales display program
// Anthony Garrett
// 01/28/2020
// Displays a table containing the sales of each style of chair
// that Woody's sells.

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    const float AMERICAN_STYLE_PRICE = 85.00, // price of each chair style
                MODERN_STYLE_PRICE = 57.00, 
                FRESH_STYLE_PRICE = 127.75; 
    
    unsigned int american_style_sold = 0, // for user input for number of sold chairs of each style
                 modern_style_sold = 0, 
                 fresh_style_sold = 0; 

    float american_style_total = 0.0, // total sales for each style of chair
          modern_style_total = 0.0,
          fresh_style_total = 0.0;

    float sum_total_sales = 0.0; // total sales for all chair types

    // Gather user input for each style of chair that is sold
    // Store user input into sold variable for each type
    cout << "\nPlease enter the number of American Colonial Style chairs that were sold: ";
    cin >> american_style_sold;

    cout << "\nPlease enter the number of Modern Style chairs that were sold: ";
    cin >> modern_style_sold;

    cout << "\nPlease enter the number of Fresh Classical Style chairs that were sold: ";
    cin >> fresh_style_sold;

    // Calculate the total for each chair type
    american_style_total = AMERICAN_STYLE_PRICE * american_style_sold;
    modern_style_total = MODERN_STYLE_PRICE * modern_style_sold;
    fresh_style_total = FRESH_STYLE_PRICE * fresh_style_sold;

    // Calculate the total sales of all chair types
    sum_total_sales = american_style_total + modern_style_total + fresh_style_total;

    // setting up the formatting of the money float variables
    cout << setprecision(2) << fixed << showpoint << endl;

    // Creating the labels for the table
    cout << setw(20) << left << "Style" << right << setw(20) << "Price Per Chair" << setw(20) << "Chairs Sold" << setw(20) << "Total Sales" << endl;
    cout << setw(20) << left << "-----" << right << setw(20) << "---------------" << setw(20) << "-----------" << setw(20) << "-----------" << endl;

    // Creating a row for each chair style containing all the necessary information
    // Used setw(), left, right to make it look nice
    cout << left << setw(20) << "American Colonial" << right << setw(14) << "$ " << setw(6) << AMERICAN_STYLE_PRICE << setw(20) << american_style_sold << setw(10) << "$ " << setw(10) << american_style_total << endl;
    cout << left << setw(20) << "Modern" << right << setw(14) << "$ " << setw(6) << MODERN_STYLE_PRICE << setw(20) << modern_style_sold << setw(10) << "$ " << setw(10) << modern_style_total<< endl;
    cout << left << setw(20) << "Fresh Classical" << right << setw(14) << "$ " << setw(6) << FRESH_STYLE_PRICE << setw(20) << fresh_style_sold << setw(10) << "$ " << setw(10) << fresh_style_total << endl;

    // Creating some space and then adding the Total sales for all styles line to the bottom of the table
    cout << endl;
    cout << setw(80) << "----------" << endl;
    cout << setw(40) << left << "TOTAL" << setw(30) << right << "$ " << setw(10) << sum_total_sales << endl;

}