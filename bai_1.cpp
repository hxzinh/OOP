#include <bits/stdc++.h>

using namespace std;

/**
 * Main function to reduce a fraction to its simplest form.
 * The program prompts the user to input the denominator and numerator of a fraction.
 * It then calculates the greatest common divisor (GCD) and reduces the fraction accordingly.
 * Finally, it outputs the reduced fraction.
 *
 * @return 0 on successful execution.
 */
int main() {
    int denominator, numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;
    cout << "Enter the numerator: ";
    cin >> numerator;

    while(numerator == 0) {
        cout << "Invalid fraction!!.\n"
             << "Please enter the numerator again: ";
        cin >> numerator;
    }

    int gcd = __gcd(denominator, numerator);
    denominator /= gcd;
    numerator /= gcd;

    if(numerator < 0) {
        denominator *= -1;
        numerator *= -1;
    }

    cout << "Reduced fraction: " << denominator << "/" << numerator << endl;

    return 0;
}
