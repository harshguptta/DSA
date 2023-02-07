int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0)return 0;
    int idx=0;
    int n=nums.size();
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]) continue;
        else{
            idx++;
            nums[idx]=nums[i];
        }
    }
    return idx+1;
}