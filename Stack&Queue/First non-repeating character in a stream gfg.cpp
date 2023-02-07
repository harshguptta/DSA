string FirstNonRepeating(string A){
    int mp[27]={0};
    string ans="";
    queue<char> q;
    for(int i=0;i<A.size();i++){
        mp[A[i]-'a']++;
        q.push(A[i]);
        while(!q.empty()){
            if(mp[q.front()-'a']>1){
                q.pop();
            }
            else {
                ans+=q.front();
                break;
            }
        }
        if(q.empty())
        ans+='#';
    }
    return ans;
}
