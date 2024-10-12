#include <bits/stdc++.h>
using namespace std;

/**
 * Struct representing a fraction.
 * Contains numerator and denominator.
 */
struct Fraction {
    int numerator;
    int denominator;
};

/**
 * Function to simplify a fraction by dividing both the numerator and denominator
 * by their greatest common divisor (GCD).
 * 
 * @param frac - Fraction to be simplified.
 * @return The simplified fraction.
 */
Fraction simplify(Fraction frac) {
    int gcd = __gcd(frac.numerator, frac.denominator);
    frac.numerator /= gcd;
    frac.denominator /= gcd;

    if(frac.denominator < 0) {
        frac.numerator *= -1;
        frac.denominator *= -1;
    }
    return frac;
}

/**
 * Function to read fraction from the user.
 * Prompts the user to enter the numerator and denominator.
 * 
 * @return The input fraction.
 */
Fraction inputFraction() {
    Fraction frac;
    cout << "Enter numerator: ";
    cin >> frac.numerator;
    cout << "Enter denominator: ";
    cin >> frac.denominator;
    return frac;
}

/**
 * Main function to input two fractions, simplify them, and determine which fraction is larger.
 * The program prompts the user to input two fractions, simplifies them, and then
 * compares the two to determine which one is larger.
 * 
 * @return 0 on successful execution.
 */
int main() {
    Fraction frac1, frac2;
    cout << "Enter the first fraction:\n";
    frac1 = inputFraction();
    cout << "Enter the second fraction:\n";
    frac2 = inputFraction();

    Fraction tmp1 = simplify(frac1);
    Fraction tmp2 = simplify(frac2);

    cout << "The larger fraction is: ";
    if (1LL * tmp1.numerator * tmp2.denominator > 1LL * tmp2.numerator * tmp1.denominator) {
        cout << frac1.numerator << "/" << frac1.denominator << endl;
    } else {
        cout << frac2.numerator << "/" << frac2.denominator << endl;
    }

    return 0;
}
