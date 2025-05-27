#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(),m = grid[0].size();
        vector<int> v; // add all elements of grid in this as there is no need of grid in this ques
        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int size = n*m, ans=0;
        int mid = size%2?size/2:(size+1)/2;
        // if every element is multiple of x after subtracting min element then it is possible else not possible
        int st = v[0];
        for(int i=0 ; i<size ; i++){
           v[i] = v[i] - st;
           if(v[i]%x) return -1;
        }

        // v = 0,2,4,6 
        // ways to make every element = centeral element is min way to make it x
        for(int i=0 ; i<size ; i++){
            ans+= abs(v[i]-v[mid])/x;
        }
        return ans;
    }
};