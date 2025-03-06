#include<bits/stdc++.h>
using namespace std;
#define MAXN 300010

// Global arrays to hold the strip and penalties.
char s[MAXN];
int a[MAXN];

// Decision function: given a candidate X, can we ensure that every cell
// that ends up the wrong color has penalty at most X using at most k operations?
bool canAchieve(int X, int n, int k) {
    int segments = 0;
    int i = 0;
    while(i < n) {
        // Skip forbidden cells.
        // A forbidden cell is one that must remain red: 
        // desired 'R' with a penalty > X.
        if(s[i] == 'R' && a[i] > X) {
            i++;
            continue;
        }
        
        // We are now in an interval (maximal contiguous block with no forbidden cell)
        // that can be painted blue without error.
        bool hasMandatory = false; // flag for blue cells that need painting (penalty > X)
        while(i < n && !(s[i] == 'R' && a[i] > X)) {
            // A blue cell with penalty > X is "mandatory" to cover:
            // if not painted, it would remain red and be wrong.
            if(s[i] == 'B' && a[i] > X) {
                hasMandatory = true;
            }
            i++;
        }
        if(hasMandatory) {
            segments++; // one operation covers this whole interval.
        }
    }
    return segments <= k;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        int maxPenalty = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if(a[i] > maxPenalty)
                maxPenalty = a[i];
        }
        
        // Binary search over the answer X (the maximum allowed penalty among errors)
        int lo = 0, hi = maxPenalty, ans = maxPenalty;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(canAchieve(mid, n, k)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}