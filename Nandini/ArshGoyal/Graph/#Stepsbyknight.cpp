#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>&kn, vector<int>&target, int n) {
        vector<pair<int, int>> steps = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
        
        queue<pair<int, int>> q;
        kn[0]--; kn[1]--;
        target[0]--; target[1]--;
        if (kn[0] == target[0] && kn[1] == target[1]) return 0;

        q.push({kn[0], kn[1]});
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[kn[0]][kn[1]] = 1;

        int moves = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front().first,y = q.front().second;
                q.pop();
                
                if (x == target[0] && y == target[1]) 
                    return moves;

                for (auto it: steps) {
                    int dx = it.first,dy = it.second;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            moves++;
        }
        return -1; 
    }
};
