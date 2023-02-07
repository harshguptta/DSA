vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n,-1);
    stack<int> s;
    for(int i=0;i<2*n;i++){
        while(!s.empty() and nums[s.top()]<nums[i%n]){
        res[s.top()]=nums[i%n];
            s.pop();
        }
        s.push(i%n);
    }
    return res;
}