#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int item = 10;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"ENter values for array : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int LB=0,UP=n-1;
    bool flag = false;
    while(LB<=UP)
    {
        int MID = (LB+UP)/2;
        if(arr[MID]==item)
        {
            flag = true;
            break;
        }
        else if(arr[MID]<item)
        {
            LB = MID+1;
        }
        else
        {
            LB = MID -1;
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