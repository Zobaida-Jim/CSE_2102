#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int item = 10,flag=0;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter values for array : ";
    for(int i=0; i<n; i++)
    {
        int m;
        cin>>m;
        arr.push_back(m);
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==item)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        cout<<"Found Successfully"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}