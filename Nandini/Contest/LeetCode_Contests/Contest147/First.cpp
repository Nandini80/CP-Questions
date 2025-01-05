#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasMatch(string s, string p) {
       int ind = p.find("*");
       int a = s.find(p.substr(0,ind));
       int b = s.rfind(p.substr(ind+1));
       cout << "a=" << a <<",b=" << b << endl;
       return (a!=-1 && b!=-1 && a+ind<=b);   
    }
};