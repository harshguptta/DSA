int search(vector<int>& nums, int target) {
    int n=nums.size();
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid]>=nums[s]){
            if(target<nums[mid] and target>=nums[s])
                e=mid-1;
            else
                s=mid+1;
        }else{
            if(target>nums[mid] and target<=nums[e])
                s=mid+1;
            else
                e=mid-1;
        }
    }
    return -1;
}