double Median(vector<int>& arr1, vector<int>& arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int l=0,h=n1;
    while(l<=h){
        int cut1=(l+h)/2;
        int cut2=((n1+n2)/2)-cut1;
        int l1=cut1==0?INT_MIN:arr1[cut1-1];
        int l2=cut2==0?INT_MIN:arr2[cut2-1];
        int r1=cut1==n1?INT_MAX:arr1[cut1];
        int r2=cut2==n2?INT_MAX:arr2[cut2];
        if(l1>r2){
            h=cut1-1;
        }
        else if(l2>r1){
            l=cut1+1;
        }
        else
            return (n1+n2)%2==0?(double)((max(l1,l2)+min(r1,r2))/2.0):(double)(min(r1,r2));
    }
    return -0.1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   int n=nums1.size();
    int m=nums2.size();
    if(n>m){
        return Median(nums2,nums1);
    }
    else
        return Median(nums1,nums2);
}