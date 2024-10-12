#include <bits/stdc++.h>

using namespace std;
long long factorial[25];

/**
 * @brief Computes the power of a number.
 * 
 * This function calculates x raised to the power k using recursion and efficient exponentiation by squaring.
 * 
 * @param x The base value.
 * @param k The exponent value.
 * @return The value of x raised to the power k.
 */
double pw(double x, long long k){
    if(k <= 1) return k ? x : 1;
    double temp = pw(x, k >> 1);
    if (k & 1) return temp * temp * x;
    return temp * temp;
}

/**
 * @brief Approximates the value of sin(x).
 * 
 * This function calculates the sine of x using the Taylor series approximation.
 * The series continues until the value to be added is smaller than the precision value.
 * 
 * @param x The angle in radians for which to compute the sine value.
 * @return The approximated sine value of x.
 */
double Sinx(double x){
    double ans = 0;
    x = fmod(x, 2 * M_PI);       // Adjust x to be within the range [0, 2*PI]
    double check = x;
    long long i = 0;
    while (check > 0.00001){
        if (i++ & 1) ans -= check;
        else ans += check;
        check = pw(x, 2 * i + 1) / factorial[2 * i + 1];
    }
    return ans;
}

/**
 * @brief Main function to approximate sin(x) for a user input.
 * 
 * Initializes factorial values, takes input from the user, and prints the approximated sine value.
 */
int main(){
    double x;
    cout << "Enter x: ";
    cin >> x;

    if(x < 0) x = -x;  

    factorial[0] = 1;
    for(int i = 1; i <= 21; i++){
        factorial[i] = factorial[i - 1] * i; 
    }

    cout << Sinx(x) << '\n';  
    return 0;
}
