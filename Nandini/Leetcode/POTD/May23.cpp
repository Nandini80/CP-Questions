#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    bool isMirrork(ll val, int k) {
        string str = "";
        while (val > 0) {
            int c = val % k;
            str += c + '0';  // Base k string
            val = val / k;
        }
        int n = str.size();
        // Check if the string is a palindrome
        for (int i = 0; i <= n / 2; i++) {
            if (str[i] != str[n - i - 1]) return false;
        }
        return true;
    }

    // Function to generate palindromic numbers
    void generatePalindromes(int numDigits, vector<ll>& palindromes) {
        int half = (numDigits + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);
        
        for (int i = start; i < end; i++) {
            string halfStr = to_string(i);
            string revHalfStr = halfStr;
            reverse(revHalfStr.begin(), revHalfStr.end());
            string fullStr = halfStr + revHalfStr.substr(numDigits % 2, revHalfStr.size());
            ll fullNum = stoll(fullStr);
            palindromes.push_back(fullNum);
        }
    }

    long long kMirror(int k, int n) {
        ll sum = 0;
        int numDigits = 1;
        vector<ll> palindromes;
        
        // Generate palindromes and check each
        while (n > 0) {
            generatePalindromes(numDigits, palindromes);
            for (ll num : palindromes) {
                if (isMirrork(num, k)) {
                    sum += num;
                    n--;
                    if (n == 0) break;
                }
            }
            palindromes.clear();
            numDigits++;
        }
        
        return sum;
    }
};
