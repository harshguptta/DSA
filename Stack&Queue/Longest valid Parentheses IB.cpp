//M-1
int longestValidParentheses(string a) {
    int n=a.length();
    stack<int> s;
    s.push(-1);
    int maxx=0;
    for(int i=0;i<n;i++){
        if(a[i]=='(')
        s.push(i);
        else{
            s.pop();
            if(s.empty())
            s.push(i);
            else
            maxx=max(maxx,i-s.top());
        }
    }
    return maxx;
}

//M-2
int longestValidParentheses(string s) {
    int open=0;
    int close=0;
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(')open++;
        else close++;
        if(open==close)ans=max(ans,close*2);
        else if(close>open)open=close=0;
    }
    open=close=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]==')')close++;
        else open++;
        if(open==close)ans=max(ans,close*2);
        else if(open>close)open=close=0;
    }
    return ans;
}
    
//M-3
int longestValidParentheses(string A) {
    
    int sz = A.size();
    
    if(sz <= 1) return 0;
    
    int ans = 0;
    vector<int>longest(sz, 0);
    
    for(int i = 1; i < sz; i++) {
        
        if(A[i] == ')') {
            if(A[i - 1] == '(') {
                
                longest[i] = longest[i - 2] + 2;
 
            } else {
                
                if(i - longest[i - 1] - 1 >= 0 && A[i - longest[i - 1] - 1] == '(') {
                    
                    longest[i] = longest[i - 1] + 2 + 
                    ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0);
                    
                }
                
            }
        }
        ans = max(ans, longest[i]);
    }
    return ans;
}