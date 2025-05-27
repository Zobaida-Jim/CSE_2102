#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int operation(stack<int> &s, char ch)
{
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if(ch == '+') return b+a;
    else if(ch == '-') return b-a;
    else if(ch == '*') return b*a;
    else if(ch == '/') return b/a; // a != 0
    else if(ch == '^') return (pow(b,a));
    else
    {
        cout<<"Invalid operator"<<endl;
        exit(1);
    }
}

int postfix(string str)
{
    stack<int>s;
    str += ')';
    for(int i=0;i<str.size();i++)
    {
        char ch = str[i];

        if(ch == ' ') continue;
        if(ch == ')') break;

        if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9')
        {
            int digit = ch - '0';
            s.push(digit);
        }
        else if(ch == '+' ||ch == '-' ||ch == '*' ||ch == '/' ||ch == '^')
        {
            if(s.size()<2)
            {
                cout<<"Not enough Operands"<<endl;
            }
            int result = operation(s,ch);
            s.push(result);
        }
    }
    return s.top();
}

int main()
{
    cout<<"Enter a postfix Notation : ";
    string s;
    getline(cin, s);
    int result = postfix(s);
    cout<<result<<endl;
    return 0;
}