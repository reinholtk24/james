#ifndef FRACTIONS_H
#define FRACTIONS_H

using namespace std;

//  \/TESTS\/
int generateRandNegNum();
int randomizeNegToPos(); // Used this in actual application
int numRangeChecker(int);
void printTestResults(int,int);
void allTests();
//  /\TESTS/\

void userMenu();
bool verifyUserInput(int);
int chooseNumOfProblems();
string typeOfProblem(int);
int additionProb(int);
int subtractionProb(int);
int multiplicationProb(int);
int divisionProb(int);
void determineProb(int,int);
int counterR(int);
int counterW(int);

class Fraction
{
public:
    void setFraction(int n,int d);
    int getNumerator() const;
    int getDenominator() const;
    void print() const;
    int getCorrect();
    int getWrong();
    void counterR(int);
    void counterW(int);

    Fraction();
    Fraction(int n,int d);

    Fraction operator+(const Fraction&) const;
    Fraction operator-(const Fraction&) const;
    Fraction operator*(const Fraction&) const;
    Fraction operator/(const Fraction&) const;
    Fraction operator++(); //pre-increment ++x
    Fraction operator++(int); //post-increment x++
    Fraction operator--();
    Fraction operator--(int);

    friend ostream& operator << (ostream&, const Fraction&);
    friend istream& operator >> (istream&, Fraction&);
    friend Fraction operator*(const Fraction&, const int&);
    friend Fraction operator*(const int&, const Fraction&);

    friend bool operator==(const Fraction&, const Fraction&);
    friend bool operator!=(const Fraction&, const Fraction&);
    friend bool operator< (const Fraction&, const Fraction&);
    friend bool operator> (const Fraction&, const Fraction&);
    friend bool operator<=(const Fraction&, const Fraction&);
    friend bool operator>=(const Fraction&, const Fraction&);

private:
    int numerator;
    int denominator;
    int right;
    int wrong;
};



#endif // FRACTIONS_H
