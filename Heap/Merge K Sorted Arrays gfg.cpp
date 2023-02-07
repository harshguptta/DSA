vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    for(int i=0;i<K;i++){
        pq.push({arr[i][0],i,0});
    }
    vector<int> ans;
    vector<int> temp;
    while(!pq.empty()){
        temp = pq.top();
        int val = temp[0];
        int i = temp[1];
        int j = temp[2];
        pq.pop();
        ans.push_back(val);
        if(j+1<K){
            pq.push({arr[i][j+1],i,j+1});
        }
    }
    return ans;
}