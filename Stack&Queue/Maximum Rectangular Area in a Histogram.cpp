long long getMaxArea(long long arr[], int n)
{
    long long maxarea=LLONG_MIN;
    long long area;
    stack<long long> s;
    int i;
    for(i=0;i<n;i++){
        while(!s.empty() and arr[s.top()]>arr[i]){
            long long x=s.top();
            s.pop();
            area=arr[x]*(s.empty()?i:i-s.top()-1);
            maxarea=max(area,maxarea);
        }
        s.push(i);
    }
    while(!s.empty()){
        long long x=s.top();
        s.pop();
        area=arr[x]*(s.empty()?i:i-s.top()-1);
        maxarea=max(area,maxarea);
    }
    return maxarea;
}