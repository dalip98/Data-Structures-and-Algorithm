#include <bits/stdc++.h>
#define ll long long int

using namespace std;

class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

int _stack :: getMin()
{
    stack<int>a = this->s;
    int m = INT_MAX;
    if(a.empty())
        return -1;
    while(!a.empty())
    {
        if(m>a.top())
        {
            m = a.top();
        }
        a.pop();
    }
    this->minEle = m;
    return m;
   //Your code here
}
/*returns poped element from stack*/
int _stack ::pop()
{

    if(this->s.empty())
    {
        return -1;
    }
    else
    {
        int x  = this->s.top();
        this->s.pop();
        return x;

    }
   //Your code here
}
/*push element x into the stack*/
void _stack::push(int x)
{
    this->s.push(x);
   //Your code here
}


int main()
{

    return 0;
}
