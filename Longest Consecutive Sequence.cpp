#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        for(auto i:nums){
        hashset.insert(i);
        }
        int ans=0;
        for(auto i:nums){
            if(hashset.find(i-1)==hashset.end()){
                int cur=i;
                int tempans=1;
                while(hashset.find(cur+1)!=hashset.end()){
                    tempans++;
                    cur++;
                }
                ans=max(ans,tempans);
            }
        }
        return ans;
    }