#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a ,b, c;
    cin >> a >> b >> c ;
    vector<int> v{a*(b+c),(a+b)*c,a*b*c,a+(b*c),(a*b)+c,a+b+c};
    sort(v.begin(),v.end());
    cout << v[v.size()-1];
}