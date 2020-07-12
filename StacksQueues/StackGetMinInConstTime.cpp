#include<stack>
#include<iostream>
using namespace std;

class MinStack {
    stack< long long int> s;
    long long int minEle;
public:
    /** initialize your data structure here. */
    MinStack() {
        minEle=INT_MAX;
    }
    
    void push(long long int x) {
       if(s.empty())
       {
           minEle=x;
           s.push(x);
           return;
       }
        if(x>minEle)
        {
            s.push(x);
            return;
        }
        else
        {
            //s.push(2*x-minEle);
            s.push(x-minEle+x);
            minEle=x;
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        long long int t=s.top();
        s.pop();
        if(t<minEle)
            minEle=2*minEle-t;
    }
    
    int top() {
        long long int t=s.top();
        if(t<minEle)
            return minEle;
        else
            return t;
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */