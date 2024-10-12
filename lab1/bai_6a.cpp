#include <bits/stdc++.h>

using namespace std;

int n, m;

/**
 * Computes the Longest Prefix Suffix (LPS) array used in the KMP pattern matching algorithm.
 * The LPS array helps to avoid redundant comparisons by storing lengths of proper prefixes
 * that are also suffixes.
 *
 * @param A The pattern array for which the LPS array is to be computed.
 * @return A vector containing the LPS values for the given pattern.
 */
vector<int> computeLPSArray(const vector<int>& A) {
    int len = 0;
    int i = 1;
    vector<int> lps(n, 0);

    while (i < n) {
        if (A[i] == A[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

/**
 * Counts the occurrences of array A as a contiguous subarray in array B using the KMP algorithm.
 * The function returns the number of times A appears in B, as well as the starting indices of all occurrences.
 *
 * @param A The pattern array to be found in array B.
 * @param B The target array in which the occurrences of A are to be found.
 * @return A pair containing the count of occurrences and a vector of starting indices of each occurrence.
 */
vector<int> KMPSearch(const vector<int>& A, const vector<int>& B) {
    vector<int> res;

    vector<int> lps = computeLPSArray(A);
    int i = 0, j = 0; 

    while (j < m) {
        if (A[i] == B[j]) {
            i++;
            j++;   
        }
        
        if (i == n) {
            res.push_back(j - i);
            i = lps[i - 1];
        }
        else if (j < m && A[i] != B[j]) {
            if (i != 0) {
                i = lps[i - 1];
            } else {
                j++;
            }
        }
    }

    return res;
}

/**
 * The main function that reads input from the user, finds the occurrences of array A in array B,
 * and prints the results.
 *
 * @return 0 on successful execution.
 */
int main() {
    cout << "Enter the number of elements in array A and array B: ";
    cin >> n >> m;

    vector<int> A(n + 1), B(m + 1);
    cout << "Enter the elements of array A: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << "Enter the elements of array B: ";
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    vector<int> res = KMPSearch(A, B);

    cout << "Number of occurrences: " << res.size() << '\n';
    cout << "Starting indices of occurrences: ";
    for (int pos : res) {
        cout << pos << " ";
    }
    cout << '\n';

    return 0;
}
