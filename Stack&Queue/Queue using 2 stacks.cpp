//O(n)

#include<iostream>
#include<stack>
using namespace std;

class Queue
{
	stack<int> s1,s2;
public:
	void enqueue(int data){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(data);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dequeue(){
		if(s1.empty()){
			exit(0);
		}
		int element=s1.top();
		s1.pop();
		return element;
	}
	
};

int main(){
	int n;
	cin>>n;
	Queue ob;
	for(int i=0;i<n;i++){
		ob.enqueue(i);
	}
	for(int i=0;i<n;i++){
		cout<<ob.dequeue()<<" ";
	}

}


 //Amortised O(1)

#include <bits/stdc++.h>

using namespace std;

class MyQueue {
  public:
    stack < int > input, output;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    cout << "The element pushed is " << x << endl;
    input.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();

    int x = output.top();
    output.pop();
    return x;
  }

  /** Get the front element. */
  int top() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }

  int size() {
    return (output.size() + input.size()); 
  }

};
int main() {
  MyQueue q;
  q.push(3);
  q.push(4);
  cout << "The element poped is " << q.pop() << endl;
  q.push(5);
  cout << "The top of the queue is " << q.top() << endl;
  cout << "The size of the queue is " << q.size() << endl;

}