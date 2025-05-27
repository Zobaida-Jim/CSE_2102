#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<cctype>
using namespace std;

int precedence(char ch)// Operator precedence
{
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    return 0;
}

string postfix(string q)//Convert Infix to Postfix
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
            s.push(ch);//Push current operator
        }
        else if(ch==')')// step 6
        {
            while (!s.empty() && s.top() != '(') 
            {
                p += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();//remove '(' from stack
        }
    }
    return p;
}

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

int Evalute_postfix(string str)// Evalute Postfix Notation
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
    cout<<"Enter a Infix Notation : ";
    string s;
    getline(cin, s);
    string p = postfix(s);
    int result = Evalute_postfix(p);
    cout<<result<<endl;
    return 0;
}