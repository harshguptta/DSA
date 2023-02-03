#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans=0;
    int i=0,j=0;
    int count=0;
    unordered_map<char,int> mp;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp[s[j]]==1)count++;
        // if(count>(j-i+1))j++;
        if(count==(j-i+1)){
            ans=max(ans,j-i+1);
            j++;
        }
        else if(count<(j-i+1)){
            while(i<=j and count<(j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    count--;
                }
                i++;
            }
            j++;
        }
    }
    return ans;
    }