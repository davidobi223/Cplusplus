#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float initInvest, monDeposit, anuInterest, months, years; //Variables 
    float totalAm, intAmt, yearTotInterest; //Variables

    cout << "********************************\n"; //Display menu 
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    system("PAUSE"); //Wait for user input

    cout << "********************************\n"; // Data from the user 
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initInvest;
    cout << "Monthly Deposit: $";
    cin >> monDeposit;
    cout << "Annual Interest: %"; 
    cin >> anuInterest;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12; 

    system("PAUSE"); //Wait for user input

    totalAm = initInvest; //Set total amount to initial investment so it can update

    cout << "\nBalance and Interest Without Additional Monthly Deposits\n"; //Display year data without monthly deposits
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";


    for (int i = 0; i < years; i++) {

        intAmt = (totalAm) * ((anuInterest / 100)); //Yearly interest calculation

        totalAm = totalAm + intAmt; //Year end total calculation

        //Prints results to table with only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";

    }

    totalAm = initInvest; //Set total amount to initial investment so it can update

    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";      //Display year data with monthly deposits
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {

        yearTotInterest = 0; //Set yearly interest to zero at the start of the year

        for (int j = 0; j < 12; j++) {

            intAmt = (totalAm + monDeposit) * ((anuInterest / 100) / 12); //Monthly interst calculation

            yearTotInterest = yearTotInterest + intAmt; //Month end interest calculation

            totalAm = totalAm + monDeposit + intAmt; // Month end total calculation

        }

        //Prints results to table with only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << yearTotInterest << "\n";


    }

    return 0;
}

