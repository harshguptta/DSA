int kthElement(int arr1[], int arr2[], int n1, int n2, int k)
{
    if(n1 > n2) {
        return kthElement(arr2, arr1, n2, n1, k); 
    }
    
    // int n1=arr1.size();
    // int n2=arr2.size();
    int l=max(0,k-n2),h=min(k,n1);
    while(l<=h){
        int cut1=(l+h)/2;
        int cut2=k-cut1;
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
            return max(l1,l2);
    }

    return 1; 
}