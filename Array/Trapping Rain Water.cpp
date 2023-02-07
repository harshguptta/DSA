//M-1
long long trappingWater(int arr[], int n){
    long long water = 0; // To store the final ans
    int left_max = 0; // Which stores the current max height of the left side
    int right_max = 0; // Which stores the current max height of the right side
    int lo = 0; // Counter to traverse from the left_side
    int hi = n - 1; // Counter to traverse from the right_side
    while (lo <= hi)
    {
        if (arr[lo] < arr[hi])
        {
            if (arr[lo] > left_max)
            {
            left_max = arr[lo]; // Updating left_max
            }
            else
            {
            water += left_max - arr[lo]; // Calculating the ans
            }
            lo++;
        }
        else
        {
            if (arr[hi] > right_max)
            {
            right_max = arr[hi]; // Updating right_max
            }
            else
            {
            water += right_max - arr[hi]; // Calculating the ans
            }
            hi--;
        }
    }
    return water;
}

//M-2
int trappingWater(int arr[], int n){
    
    int left[n],right[n];
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        left[i]=max(arr[i],left[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        right[i]=max(arr[i],right[i+1]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(min(left[i],right[i])-arr[i]);
    }
    return ans;
}