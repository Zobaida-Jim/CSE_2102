#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;

int precedence(char ch)
{
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    return 0;
}

string postfix(string q)
{
    stack<char> s;
    string p = "";
    s.push('(');
    q += ')';
    for(int i=0; i<q.size(); i++)
    {
        char ch = q[i];
        if(ch == ' ') continue;
        if(isalnum(ch))
        {
            p += ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == '+' ||ch == '-' ||ch == '*' ||ch == '/' ||ch == '^')//step 5
        {
            while(!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                if(ch == '(') break;
                p += s.top();
                s.pop();
            }
            s.push(ch);// Push current operator
        }
        else if(ch==')')// step 6
        {
            while (!s.empty() && s.top() != '(') 
            {
                p += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();// remove '(' from stack
        }
    }
    return p;
}

int main()
{
    string s;
    cout<<"Enter Infix Notation : ";
    getline(cin, s);
    string str = postfix(s);
    cout<<"Postfix Notation is : "<<str<<endl;
}