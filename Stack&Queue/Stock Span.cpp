vector <int> calculateSpan(int price[], int n)
{
   stack<int> s;
   vector<int> ans;
   s.push(0);//index of first element
   ans.push_back(1);
   for(int i=1;i<n;i++){
       while(!s.empty() and price[i]>=price[s.top()]){
           s.pop();
       }
       int val=(s.empty())?i+1:(i-s.top());
       ans.push_back(val);
       s.push(i);
   }
   return ans;
}