#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int>&A, int n)
    {   
       unordered_map<int,int> mp;
       int sum=0;
       int ans=0;
       
       for(int i=0;i<n;i++){
           sum+=A[i];
           if(sum==0)
           ans=i+1;
           if(mp.find(sum)!=mp.end()){
               ans=max(ans,i-mp[sum]);
           }else{
           mp[sum]=i;}
       }
       return ans;
    }