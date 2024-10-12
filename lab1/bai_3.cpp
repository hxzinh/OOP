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
 * If the denominator is negative, adjusts the signs to keep the denominator positive.
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
 * Function to add two fractions.
 * Calculates the sum of two fractions and returns the simplified result.
 *
 * @param frac1 - First fraction.
 * @param frac2 - Second fraction.
 * @return The simplified sum of the two fractions.
 */
Fraction add(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return simplify(result);
}

/**
 * Function to subtract two fractions.
 * Calculates the difference between two fractions and returns the simplified result.
 *
 * @param frac1 - First fraction.
 * @param frac2 - Second fraction.
 * @return The simplified difference of the two fractions.
 */
Fraction subtract(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator - frac2.numerator * frac1.denominator;
    result.denominator = frac1.denominator * frac2.denominator;
    return simplify(result);
}

/**
 * Function to multiply two fractions.
 * Calculates the product of two fractions and returns the simplified result.
 *
 * @param frac1 - First fraction.
 * @param frac2 - Second fraction.
 * @return The simplified product of the two fractions.
 */
Fraction multiply(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return simplify(result);
}

/**
 * Function to divide two fractions.
 * Calculates the quotient of two fractions and returns the simplified result.
 *
 * @param frac1 - First fraction.
 * @param frac2 - Second fraction.
 * @return The simplified quotient of the two fractions.
 */
Fraction divide(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;
    return simplify(result);
}

/**
 * Main function to input two fractions, simplify them, and perform basic arithmetic operations.
 * The program prompts the user to input two fractions, simplifies them, and then
 * calculates and displays their sum, difference, product, and quotient.
 *
 * @return 0 on successful execution.
 */
int main() {
    Fraction frac1, frac2;
    cout << "[*] Enter the first fraction:\n";
    cout << "[*] Enter numerator: ";
    cin >> frac1.numerator;
    cout << "[*] Enter denominator: ";
    cin >> frac1.denominator;
    cout << "[*] Enter the second fraction:\n";
    cout << "[*] Enter numerator: ";
    cin >> frac2.numerator;
    cout << "[*] Enter denominator: ";
    cin >> frac2.denominator;

    frac1 = simplify(frac1);
    frac2 = simplify(frac2);

    cout << "[+] Sum of the two fractions: " << add(frac1, frac2).numerator << "/" << add(frac1, frac2).denominator << '\n';
    cout << "[+] Difference of the two fractions: " << subtract(frac1, frac2).numerator << "/" << subtract(frac1, frac2).denominator << '\n';
    cout << "[+] Product of the two fractions: " << multiply(frac1, frac2).numerator << "/" << multiply(frac1, frac2).denominator << '\n';
    cout << "[+] Quotient of the two fractions: " << divide(frac1, frac2).numerator << "/" << divide(frac1, frac2).denominator << '\n';

    return 0;
}
