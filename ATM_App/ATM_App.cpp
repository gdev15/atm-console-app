#include <iostream>
using namespace std;

int main()
{
    int usersChoice;

    double availableFunds = 1000.75;
    double inputAmount;

    bool isProcessing = true;
    bool isContinuing = false;
    bool isMenuDisplayed = true;

    //Prompt the user to make a selection
    cout << "Welcome to the atm app" << endl;
    cout << "Please make a selection below" << endl << endl;
    cout << "1) Check Account Balance" << endl;
    cout << "2) Withdrawl Money" << endl;
    cout << "3) Deposit Money" << endl;
    cout << "4) Cancel Transaction" << endl;

    cin >> usersChoice;
    cout << endl;
    while (isProcessing) {



        if (!isMenuDisplayed) {

            cout << endl << "Would you like to perform another transaction? " << endl;
            cout << "1) YES" << endl;
            cout << "2) NO" << endl;
            cin >> usersChoice;
            cout << endl;

            switch (usersChoice) {
                //Display Menu
            case 1:
                cout << endl << "Please make a selection below: " << endl;

                cout << "1) Check Account Balance" << endl;
                cout << "2) Withdrawl Money" << endl;
                cout << "3) Deposit Money" << endl;
                cout << "4) Cancel Transaction" << endl;

                cin >> usersChoice;
                cout << endl;
                isMenuDisplayed = true;
                break;
                //Exit current scope
            case 2:
                isProcessing = false;
                break;
            }
            //Exit current scope so that the app will close
            if (isProcessing == false) {
                break;
            }

        }

        switch (usersChoice) {
            //Account balance
        case 1:
            cout << "Your current balance is: $" << availableFunds << endl;
            break;

            //Withdrawl logic
        case 2: cout << endl << "How much would you like to withdrawl? ";

            cin >> inputAmount;

            if (inputAmount <= availableFunds) {
                cout << "Would you like to continue your withdrawl for $" << inputAmount << "?" << endl;
                cout << "1) YES" << endl;
                cout << "2) NO" << endl;

                cin >> usersChoice;
                cout << endl;
                //Confirmation for deposit
                switch (usersChoice) {
                case 1:
                    cout << "You have withdrew $" << inputAmount << endl;
                    availableFunds = availableFunds - inputAmount;
                    cout << "Your current balance is $" << availableFunds << endl;
                    break;
                case 2:
                    cout << "Transaction Cancelled. " << endl;
                    isProcessing = false;
                    break;
                }
            }
            else
            {
                cout << "Insufficient Funds " << endl;
            }
            //Exits this scope of the code
            break;



            //Deposit logic
        case 3:
            cout << "How much money would you like to Deposit?" << endl;
            cin >> inputAmount;
            cout << endl;
            cout << "Would you like to continue your deposit for $" << inputAmount << "?" << endl;
            cout << "1) YES" << endl;
            cout << "2) NO" << endl;

            cin >> usersChoice;
            cout << endl;
            switch (usersChoice) {
                //Confirmation for deposit
            case 1:

                cout << "You have deposited $" << inputAmount << endl;
                availableFunds = availableFunds + inputAmount;
                cout << "Your new balance is $" << availableFunds << endl;

                break;
            case 2:
                cout << "Transaction Cancelled ";
                isProcessing = false;
                break;
            }
            if (isProcessing == false) {
                break;
            }

            break;

            //Exit Application
        case 4:
            isProcessing = false;
            break;

            //Invalid Choice
        Default: cout << "Invalid selection";
            break;
        }


        isMenuDisplayed = false;
    }

    //Exiting prompt
    cout << "Thank you for using the ATM Application! Have a nice day!" << endl;

    return 0;

}
