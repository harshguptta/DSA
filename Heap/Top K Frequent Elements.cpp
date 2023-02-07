vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    for(auto elem:freq){
        pq.push({elem.second,elem.first});
        if(pq.size()>k)
            pq.pop();
    }
    vector<int> ans,element;
    while(!pq.empty()){
        element=pq.top();
        pq.pop();
        ans.push_back(element[1]);
    }
    return ans;
}