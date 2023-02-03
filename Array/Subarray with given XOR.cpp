#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int ans=0,xorr=0;
    for(int i=0;i<A.size();i++){
        xorr^=A[i];
        if(xorr==B)ans++;
        if(mp.find(xorr^B)!=mp.end())
        ans+=mp[xorr^B];
        mp[xorr]++;
    }
    return ans;
}
