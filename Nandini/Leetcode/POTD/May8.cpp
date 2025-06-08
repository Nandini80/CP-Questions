#include<bits/stdc++.h>
using namespace std;
class node{
    public :
    map<char,node*> child;
};
class Solution {
    node* root;
public:
    Solution(){
        root = new node();
    }
    void insert(int val){
        node* temp = root;
        string s = to_string(val);
        for(int i=0 ;i<s.size() ; ++i){
            if(temp->child[s[i]]==NULL) temp->child[s[i]] = new node();
            temp = temp->child[s[i]];
        }
    }
    void traverse(node* r,vector<int> &ans,string str){
        if(!r) return;
        for(auto it : r->child){
            str+=it.first;
            ans.push_back(stoi(str));
            traverse(it.second,ans,str);
            str.pop_back();

        }
    }
    vector<int> lexicalOrder(int n) {
         for(int i=1 ; i<=n ; i++){
            insert(i);
         }
         vector<int> ans;
         node* temp = root;
         traverse(temp,ans,"");
         return ans;    
    }
};