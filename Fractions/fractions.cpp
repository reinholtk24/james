#include <iostream>
#include "fractions.h"
#include <cstdlib>

int generateRandNegNum() // Generates a negative integer from -100 to -1
{
    int negRandNum = 0;

    negRandNum = ((rand() % 100 + 1) * -1);

    return negRandNum;
}

int randomizeNegToPos() // Takes a negative number, flips a coin: tails - it stays negative,
{                       // heads - it converts it to a positive
    bool tails = false;
    bool heads = true;
    int randomInt = 0;
    int flipOfCoin = 0;

    flipOfCoin = rand() % 2;

        if( flipOfCoin == tails )
        {
            randomInt = generateRandNegNum();
        }
        else if( flipOfCoin == heads )
        {
            randomInt = ((generateRandNegNum()) * -1);
        }
        else
        {
            cout << "ERROR" << endl;
        }

    return randomInt;
}

int numRangeChecker(int randomNum)
{
    bool testPassed = 0;

        if(randomNum >= -100 && randomNum <= 100)
        {
            testPassed = true;
        }
        else
        {
            testPassed = false;
        }

    return testPassed;
}

void printTestResults(int passed, int failed)
{
    cout << endl << "Tests Passed: " << passed << endl;
    cout << "Tests Failed: " << failed << endl;
}

void allTests()
{
    int testsPassed = 0; // Counter for all tests passed
    int testsFailed = 0; // "                   " failed
    int randNegNum = 0; // Variable for negative numbers test
    int randInt = 0;
    int n = 0;
    int d = 0;
    int userNumerator = 0;
    int userDenominator = 0;

    bool trueOrFalse = 0;

     for(int i = 1; i < 11; i++) //Test to verify generation of negative numbers between -1 to -100
    {
        randNegNum = generateRandNegNum();
        trueOrFalse = numRangeChecker(randNegNum); // numRangeChecker(int) verifies that the parameter is between (-101,0) and (0,101)

        cout << "tests: " << i << " = " << randNegNum << endl;
                                                   // and returns true or false
        if( trueOrFalse == true )
        {
            testsPassed++;
        }
        else
        {
            testsFailed++;
        }
    }

    for(int j = 1; j < 11; j++) //Test to verify generation of neg or pos integers from -100 to -1 and 1 to 100
    {
        randInt = randomizeNegToPos();
        trueOrFalse = numRangeChecker(randInt); // refer to line 21

        cout << "Int " << j << " = " << randInt << endl;

        if( trueOrFalse == true )
        {
            testsPassed++;
        }
        else
        {
            testsFailed++;
        }
    }

    printTestResults(testsPassed,testsFailed);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    cout << "n = " << n << endl;
    cout << "d = " << d << endl;

    Fraction myFraction;
    myFraction.setFraction(n,d);

    cout << "getnumerator = " << myFraction.getNumerator() << endl;
    cout << "getdenominator = " << myFraction.getDenominator() << endl;
    //myFraction(n,d);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    cout << "n = " << n << endl;
    cout << "d = " << d << endl;

    Fraction yourFraction;
    yourFraction.setFraction(n,d);

    cout << yourFraction << " + " << myFraction << endl;

    Fraction example = myFraction + yourFraction;
    cout << yourFraction << " + " << myFraction << " = " << endl;
    cout << "Type the answer for the numerator: ";
    cin >> userNumerator;
    cout << "Type the answer for the denominator: ";
    cin >> userDenominator;
    cout << "Here is your answer: " << userNumerator << " / " << userDenominator << endl;

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    myFraction.setFraction(n,d);

    cout << "getnumerator = " << myFraction.getNumerator() << endl;
    cout << "getdenominator = " << myFraction.getDenominator() << endl;
    //myFraction(n,d);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    cout << "n = " << n << endl;
    cout << "d = " << d << endl;

    yourFraction.setFraction(n,d);

    cout << myFraction << " - " << yourFraction << endl;

    example = myFraction - yourFraction;
    cout << myFraction << " - " << yourFraction << " = " << example << endl;

    example = myFraction * yourFraction;
    cout << myFraction << " * " << yourFraction << " = " << example << endl;

    myFraction++;
    cout << myFraction << " post-increment ++" << endl;

    ++myFraction;
    cout << myFraction << " pre-increment++" << endl;

    --myFraction;
    cout << myFraction << " pre-increment--" << endl;

    myFraction--;
    cout << myFraction << " post-increment--" << endl;



    myFraction.setFraction(n,d);
    yourFraction.setFraction(n,d);

    example = myFraction / yourFraction;

    cout << myFraction << " / " << yourFraction << " = " << example << endl;

    myFraction.setFraction(1,2);
    yourFraction.setFraction(1,2);

    yourFraction--;
    cout << yourFraction << endl;

    --yourFraction;
    cout << yourFraction << endl;

    if(myFraction == yourFraction)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

    if(myFraction!=yourFraction)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }


    if(myFraction < yourFraction)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

    if(myFraction > yourFraction)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

    if(myFraction >= yourFraction)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

    if(myFraction <= yourFraction)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

}


void Fraction::counterR(int correctAnswers)
{
    if(correctAnswers == 1)
    {
        right = right++;
    }
}

void Fraction::counterW(int wrongAnswers)
{
    if(wrongAnswers == 1)
    {
        wrong = wrong++;
    }
}

void determineProb(int userInput, int numOfProblems)
{
    Fraction temp;

    int correct = 0;
    int correctAnswers = 0;
    int wrongAnswers = 0;

    switch(userInput)
    {
    case 1:
        for(int i = 0; i < numOfProblems;i++)
        {
            bool answer = additionProb(i);

            if(answer == 1)
            {
                correctAnswers = 1;
                temp.counterR(correctAnswers);
            }
            else
            {
                wrongAnswers = 1;
                temp.counterW(wrongAnswers);
            }
        }
        break;

    case 2:
        for(int j = 0; j < numOfProblems;j++)
        {
            bool answer = subtractionProb(j);

            if(answer == 1)
            {
                correctAnswers = correctAnswers++;
                temp.counterR(correctAnswers);
            }
            else
            {
                wrongAnswers = wrongAnswers++;
                temp.counterW(wrongAnswers);
            }
        }
        break;

    case 3:
        for(int k = 0; k < numOfProblems;k++)
        {
            bool answer = multiplicationProb(k);

            if(answer == 1)
            {
                correctAnswers = correctAnswers++;
                temp.counterR(correctAnswers);
            }
            else
            {
                wrongAnswers = wrongAnswers++;
                temp.counterW(wrongAnswers);
            }
        }
        break;

    case 4:
        for(int l = 0; l < numOfProblems;l++)
        {
            bool answer = divisionProb(l);

            if(answer == 1)
            {
                correctAnswers = correctAnswers++;
                temp.counterR(correctAnswers);
            }
            else
            {
                wrongAnswers = wrongAnswers++;
                temp.counterW(wrongAnswers);
            }
        }
        break;
    }

    return temp;
}

int additionProb(int i)
{
    Fraction myFraction;
    Fraction yourFraction;

    int n = 0;
    int d = 0;
    int userNumerator = 0;
    int userDenominator = 0;
    int correct = 0;

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    myFraction.setFraction(n,d);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    yourFraction.setFraction(n,d);

    Fraction example = myFraction - yourFraction;

    cout << "Problem: " << i+1 << endl;
    cout << myFraction << " + " << yourFraction << " = " << endl;

    cout << "Type the answer for the numerator: ";
    cin >> userNumerator;

    cout << "Type the answer for the denominator: ";
    cin >> userDenominator;

    cout << "Here is your answer: " << userNumerator << " / " << userDenominator << endl;
    cout << "Here is the correct answer: " << example << endl;

    if( userNumerator == example.getNumerator() && userDenominator == example.getDenominator() )
    {
        correct = 1;
    }
    else
    {
        correct = 0;
    }

    return correct;
}

int subtractionProb(int j)
{
    Fraction myFraction;
    Fraction yourFraction;

    int n = 0;
    int d = 0;
    int userNumerator = 0;
    int userDenominator = 0;
    int correct = 0;

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    myFraction.setFraction(n,d);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    yourFraction.setFraction(n,d);

    Fraction example = myFraction - yourFraction;

    cout << "Problem: " << j+1 << endl;
    cout << myFraction << " - " << yourFraction << " = " << endl;

    cout << "Type the answer for the numerator: ";
    cin >> userNumerator;

    cout << "Type the answer for the denominator: ";
    cin >> userDenominator;

    cout << "Here is your answer: " << userNumerator << " / " << userDenominator << endl;
    cout << "Here is the correct answer: " << example << endl;

    if( userNumerator == example.getNumerator() && userDenominator == example.getDenominator() )
    {
        correct = 1;
    }
    else
    {
        correct = 0;
    }

    return correct;
}

int multiplicationProb(int k)
{
    Fraction myFraction;
    Fraction yourFraction;

    int n = 0;
    int d = 0;
    int userNumerator = 0;
    int userDenominator = 0;
    int correct = 0;

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    myFraction.setFraction(n,d);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    yourFraction.setFraction(n,d);

    Fraction example = myFraction * yourFraction;

    cout << "Problem: " << k+1 << endl;
    cout << myFraction << " * " << yourFraction << " = " << endl;

    cout << "Type the answer for the numerator: ";
    cin >> userNumerator;

    cout << "Type the answer for the denominator: ";
    cin >> userDenominator;

    cout << "Here is your answer: " << userNumerator << " / " << userDenominator << endl;
    cout << "Here is the correct answer: " << example << endl;

    if( userNumerator == example.getNumerator() && userDenominator == example.getDenominator() )
    {
        correct = 1;
    }
    else
    {
        correct = 0;
    }

    return correct;
}

int divisionProb(int l)
{
    Fraction myFraction;
    Fraction yourFraction;

    int n = 0;
    int d = 0;
    int userNumerator = 0;
    int userDenominator = 0;
    int correct = 0;

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    myFraction.setFraction(n,d);

    n = randomizeNegToPos();
    d = randomizeNegToPos();

    yourFraction.setFraction(n,d);

    Fraction example = myFraction / yourFraction;

    cout << "Problem: " << l+1 << endl;
    cout << myFraction << " / " << yourFraction << " = " << endl;

    cout << "Type the answer for the numerator: ";
    cin >> userNumerator;

    cout << "Type the answer for the denominator: ";
    cin >> userDenominator;

    cout << "Here is your answer: " << userNumerator << " / " << userDenominator << endl;
    cout << "Here is the correct answer: " << example << endl;

    if( userNumerator == example.getNumerator() && userDenominator == example.getDenominator() )
    {
        correct = 1;
    }
    else
    {
        correct = 0;
    }

    return correct;
}

void userMenu()
{
    cout << "Please choose a problem type from below." << endl;

    cout << "1. Addition " << endl;
    cout << "2. Subtraction " << endl;
    cout << "3. Multiplication " << endl;
    cout << "4. Division " << endl;
}

string typeOfProblem(int userInput)
{
    string problemType =" ";

    switch(userInput)
    {
    case 1:
        problemType = "Addition";
        break;
    case 2:
        problemType = "Subtraction";
        break;
    case 3:
        problemType = "Multiplication";
        break;
    case 4:
        problemType = "Division";
        break;
    default:
        cout << "ERROR" << endl;
        break;
    }

    return problemType;
}

bool verifyUserInput(int userInput)
{
    bool validInput = 0;

    if(userInput > 0 && userInput < 5)
    {
        validInput = true;
    }
    else if(cin.fail()==true)
    {
        validInput = false;
    }
    else
    {
        validInput = false;
    }

    return validInput;
}

int chooseNumOfProblems()
{
    int userInput = 0;

    cout << "How many problems would you like attempt? (1-20) " << endl;
    cin >> userInput;

    return userInput;
}

void Fraction::setFraction(int n, int d)
{
    if(d < 0)
    {
        denominator = d * -1;
        numerator = n;
    }
    else
    {
        numerator = n;
        denominator = d;
    }
}

int Fraction::getNumerator() const
{
    return numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

void Fraction::print() const
{
    cout << numerator << "/" << denominator << endl;
}

Fraction::Fraction(int n, int d)
{
    if(d < 0)
    {
        d = d * -1;
    }
    else
    {
        setFraction(n,d);
    }

}

Fraction::Fraction()
{
    numerator = 0;
    denominator = 0;
    right = 0;
    wrong = 0;
}

int Fraction::getCorrect()
{
    return right;
}

int Fraction::getWrong()
{
    return wrong;
}

Fraction Fraction::operator+(const Fraction& fraction) const
{
    Fraction temp;

    int tempDnmntr = 0;
    int tempNmrtr = 0;
    int fractionTempNmrtr = 0;
    int fractionTempDnmntr = 0;

    const int fractionNPlusPlus = fraction.numerator;
    const int fractionDPlusPlus = fraction.denominator;
    const int dPlusPlus = denominator;
    const int nPlusPlus = numerator;

    tempDnmntr = denominator;
    tempNmrtr = numerator;
    fractionTempNmrtr = fraction.numerator;
    fractionTempDnmntr = fraction.denominator;

    while(tempDnmntr != fractionTempDnmntr)
    {
        if (tempDnmntr < fractionTempDnmntr)
        {
            tempDnmntr = tempDnmntr + dPlusPlus;
            tempNmrtr = tempNmrtr + nPlusPlus;
        }
        else if(tempDnmntr > fractionTempDnmntr)
        {
            fractionTempDnmntr = fractionDPlusPlus + fractionTempDnmntr;
            fractionTempNmrtr = fractionNPlusPlus + fractionTempNmrtr;
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }

    temp.numerator = tempNmrtr + fractionTempNmrtr;
    temp.denominator = fractionTempDnmntr;

    return temp;
}

Fraction Fraction::operator-(const Fraction& fraction) const
{
    Fraction temp;

    int tempDnmntr = 0;
    int tempNmrtr = 0;
    int fractionTempNmrtr = 0;
    int fractionTempDnmntr = 0;

    const int fractionNPlusPlus = fraction.numerator;
    const int fractionDPlusPlus = fraction.denominator;
    const int dPlusPlus = denominator;
    const int nPlusPlus = numerator;

    tempDnmntr = denominator;
    tempNmrtr = numerator;
    fractionTempNmrtr = fraction.numerator;
    fractionTempDnmntr = fraction.denominator;

    while(tempDnmntr != fractionTempDnmntr)
    {
        if (tempDnmntr < fractionTempDnmntr)
        {
            tempDnmntr = tempDnmntr + dPlusPlus;
            tempNmrtr = tempNmrtr + nPlusPlus;
        }
        else if(tempDnmntr > fractionTempDnmntr)
        {
            fractionTempDnmntr = fractionDPlusPlus + fractionTempDnmntr;
            fractionTempNmrtr = fractionNPlusPlus + fractionTempNmrtr;
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }

    temp.numerator = (tempNmrtr) - (fractionTempNmrtr);
    temp.denominator = fractionTempDnmntr;

    return temp;
}

Fraction Fraction::operator*(const Fraction& fraction) const
{
    Fraction temp;

    temp.numerator = this -> numerator * fraction.numerator;
    temp.denominator = this -> denominator * fraction.denominator;

    return temp;
}

Fraction Fraction::operator/(const Fraction& fraction) const
{
    Fraction temp;

    temp.numerator = this -> numerator * fraction.denominator;
    temp.denominator = this -> denominator * fraction.numerator;

    return temp;
}

//pre-increment ++something
Fraction Fraction::operator++()
{
    numerator = numerator + denominator;

    return *this;
}

//post-increment something++
Fraction Fraction::operator++(int)
{
    Fraction temp = *this;

    numerator = numerator + denominator;

    return temp;
}

Fraction Fraction::operator--()
{
    numerator = numerator - denominator;

    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this;

    numerator = numerator - denominator;

    return temp;
}

ostream& operator << (ostream& osObject, const Fraction& fraction)
{
    osObject << fraction.numerator << "/" << fraction.denominator;

    return osObject;
}

istream& operator >> (istream& isObject, Fraction& fraction)
{
    isObject >> fraction.numerator >> fraction.denominator;

    return isObject;

}

bool operator==(const Fraction& fractionA, const Fraction& fractionB)
{
    bool flag = 0;

    if(fractionA.getDenominator() == fractionB.getDenominator() && fractionA.getNumerator() == fractionB.getNumerator())
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}

bool operator!=(const Fraction& fractionA, const Fraction& fractionB)
{
    bool flag = 0;

    int fractionAValue = fractionA.getNumerator()/fractionA.getDenominator();
    int fractionBValue = fractionB.getNumerator()/fractionB.getDenominator();

    if(fractionAValue != fractionBValue)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}

bool operator<(const Fraction& fractionA, const Fraction& fractionB)
{
    bool flag = 0;

    int fractionAValue = fractionA.getNumerator()/fractionA.getDenominator();
    int fractionBValue = fractionB.getNumerator()/fractionB.getDenominator();

    if( fractionAValue < fractionBValue )
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}

bool operator>(const Fraction& fractionA, const Fraction& fractionB)
{
    bool flag = 0;

    int fractionAValue = fractionA.getNumerator()/fractionA.getDenominator();
    int fractionBValue = fractionB.getNumerator()/fractionB.getDenominator();

    if( fractionAValue > fractionBValue )
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}

bool operator<=(const Fraction& fractionA, const Fraction& fractionB)
{
    bool flag = 0;

    int fractionAValue = fractionA.getNumerator()/fractionA.getDenominator();
    int fractionBValue = fractionB.getNumerator()/fractionB.getDenominator();

    if( fractionAValue < fractionBValue || fractionAValue == fractionBValue )
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}

bool operator>=(const Fraction& fractionA, const Fraction& fractionB)
{
    bool flag = 0;

    int fractionAValue = fractionA.getNumerator()/fractionA.getDenominator();
    int fractionBValue = fractionB.getNumerator()/fractionB.getDenominator();

    if( fractionAValue > fractionBValue || fractionAValue == fractionBValue )
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}
