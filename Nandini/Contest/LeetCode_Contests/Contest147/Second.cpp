#include <bits/stdc++.h>
using namespace std;
class TaskManager {
    set<pair<int,pair<int,int>>, greater<pair<int,pair<int,int>>>> st;
    map<int,int> mp1; // task,userid
    map<int,int> mp2; // task,priority
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks)
        {
            mp1[it[1]] = it[0];
            mp2[it[1]] = it[2];
            st.insert({it[2],{it[1],it[0]}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
            mp1[taskId] = userId;
            mp2[taskId] = priority;
            st.insert({priority,{taskId,userId}});
    }
    
    void edit(int taskId, int newPriority) {
        int user_id = mp1[taskId];
        int pri = mp2[taskId];
        st.erase({pri,{taskId,user_id}});
        mp2[taskId] = newPriority;
        st.insert({newPriority,{taskId, user_id}});
    }
    
    void rmv(int taskId) {
        int user_id = mp1[taskId];
        int pri = mp2[taskId];
        st.erase({pri,{taskId,user_id}});
        mp1.erase(taskId);
        mp2.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;
        auto it = *st.begin();
        st.erase(st.begin());
        mp1.erase(it.second.first);
        mp2.erase(it.second.first);
        return it.second.second;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */