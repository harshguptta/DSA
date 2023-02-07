//M-1
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

//M-2
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
        if(pq.size()>k)
            pq.pop();
    }
    return pq.top();
}