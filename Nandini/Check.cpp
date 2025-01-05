#include <bits/stdc++.h>
using namespace std;

int factorial_mod(int n, int p) {
    if (n >= p) return 0; // If n >= p, n! % p = 0
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % p;
    }
    return result;
}

void solve() {
    int t; 
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        // Compute n! % 3, n! % 7, n! % 9
        int mod3 = factorial_mod(n, 3);
        int mod7 = factorial_mod(n, 7);
        int mod9 = factorial_mod(n, 9);

        // Compute d * (n! % p)
        int d_mod3 = (d * mod3) % 3;
        int d_mod7 = (d * mod7) % 7;
        int d_mod9 = (d * mod9) % 9;

        // Check divisibility for odd digits 1, 3, 5, 7, 9
        vector<int> divisible_odds;
        for (int odd : {1, 3, 5, 7, 9}) {
            if (odd % 3 == 0 && d_mod3 != 0) continue;
            if (odd % 7 == 0 && d_mod7 != 0) continue;
            if (odd % 9 == 0 && d_mod9 != 0) continue;
            divisible_odds.push_back(odd);
        }

        // Output result for this test case
        for (int i = 0; i < divisible_odds.size(); ++i) {
            if (i > 0) cout << " ";
            cout << divisible_odds[i];
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
