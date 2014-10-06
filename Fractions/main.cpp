#include <iostream>
#include "fractions.h"
#include <cstdlib>
#include <time.h>

using namespace std;

// // // // // // // // // // // // // // // // // // //
// Author: Kyle Reinholt                              //
//                                                    //
// Program: Operator Overload Exercise w/Fractions    //
//                                                    //
// Usage: Follow directions prompted and input values //
//                                                    //
// Class: CS 240 MWF 9-9:50                           //
// // // // // // // // // // // // // // // // // // //

int main()
{
    srand(time(NULL));

    int testsPassed = 0; // Counter for all tests passed
    int testsFailed = 0; // "                   " failed
    int randNegNum = 0; // Variable for negative numbers test
    int randInt = 0;
    int userNumerator = 0; // This is how the user will answer the problems
    int userDenominator = 0;  // "                                          "
    int userInput = 0;
    int correctAnswers = 0;
    int wrongAnswers = 0;
    int numOfProblems = 0;// Variable for cin statement that asks user how many problems they want to do
    int n = 0;
    int d = 0;

    bool validInput = 0;
    bool flag = 0;
    bool returnToMenu = true;

    Fraction myFraction;
    Fraction yourFraction;

    //allTests();

    while(returnToMenu == true)
    {
        userMenu(); //Displays the menu.. should I change this?"
        cout << "Enter [100] to quit. " << endl;
        cin >> userInput;

        if(userInput == 100)
        {
            returnToMenu = false;
        }
        else
        {
            validInput = verifyUserInput(userInput);

            if( validInput == true )
            {
                numOfProblems = chooseNumOfProblems();

                if( numOfProblems > 20 || numOfProblems < 1 )
                {
                    flag = 0;

                    while(flag == 0)
                    {
                        numOfProblems = chooseNumOfProblems();

                        if( numOfProblems > 20 || numOfProblems < 1 )
                        {
                            flag = 0;
                        }

                        else
                        {
                            flag = 1;
                        }
                    }

                    cout << "You will now attempt " << numOfProblems << " " << typeOfProblem(userInput) << " problem(s)." << endl;

                    determineProb(userInput, numOfProblems);

                }
                else if( numOfProblems < 21 && numOfProblems > 0 )
                {
                    cout << "You will now attempt " << numOfProblems << " " << typeOfProblem(userInput) << " problem(s)." << endl;

                    determineProb(userInput, numOfProblems);
                }
                else
                {
                    cout << "ERROR" << endl;
                    returnToMenu;
                }

            }
            else if( validInput == false )
            {
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                returnToMenu;
            }
            else
            {
                cout << "ERROR" << endl;
                returnToMenu;
            }
        }
    }

    Fraction temp;

   cout << endl << "You attempted a total of: " << temp.getCorrect() + temp.getWrong() << " problem(s)." << endl;
   cout << endl << "You answered " << temp.getCorrect() << " problem(s) correctly." << endl;
   cout << "You answered " << temp.getWrong() << " problem(s) incorrectly." << endl;

    return 0;
}
