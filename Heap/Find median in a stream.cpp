class Solution
{
    private:
	double median; //Stores current median
	priority_queue<int> max; //Max heap for lower values
	priority_queue<int, vector<int>, greater<int> > min;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(max.size()==0)
    	{
    	    max.push(x);
    	    getMedian();
    	}
    	else if(x>max.top())
    	{
    	    min.push(x);
    	    balanceHeaps();
    	    getMedian();
    	}
    	else
    	{max.push(x);balanceHeaps();getMedian();}
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if((max.size()-min.size())==2)
    	{
    	    min.push(max.top());
    	    max.pop();
    	}
    	else if((min.size()-max.size())==2)
    	{
    	    max.push(min.top());
    	    min.pop();
    	}
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(max.size()-min.size()==1)
	        return(max.top());
	    if(min.size()-max.size()==1)
	        return(min.top());
    	else
    	    return((max.top()+min.top())/2);  
    }
};
