#include<bits/stdc++.h>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1,s2;
    ListNode* q1=l1;ListNode* q2=l2;
    while(q1!=NULL){
        s1.push(q1->val);
    q1=q1->next;}
     while(q2!=NULL){
        s2.push(q2->val);
    q2=q2->next;}
    ListNode* temp=NULL;
    int carry=0;
    while(!s1.empty() or !s2.empty() or carry!=0){
        int sum=0;
        if(!s1.empty()){
            sum+=s1.top();
            s1.pop();
        }
         if(!s2.empty()){
            sum+=s2.top();
            s2.pop();
        }
        sum+=carry;
        carry=sum/10;
         ListNode* node=new ListNode(sum%10);
        node->next=temp;
        temp=node;;
    }
    return temp;
}