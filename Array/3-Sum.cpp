vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    if(nums.size()<3)
        return ans;
    for(int i=0;i<nums.size()-2;i++){
        int x=nums[i];
        int j=i+1,k=nums.size()-1;
        while(j<k){
            if(nums[j]+nums[k]+x==0){
                vector<int> trip{x,nums[j],nums[k]};
                ans.push_back(trip);
                while(j<k and nums[j]==trip[1])
                j++;
                while(j<k and nums[k]==trip[2])
                k--;
            }    
            else if(nums[j]+nums[k]+x<0){
                j++;
            }
            else
                k--;
        }
        while(i<nums.size()-2 and nums[i]==nums[i+1])
            i++;
    }
    return ans;
}