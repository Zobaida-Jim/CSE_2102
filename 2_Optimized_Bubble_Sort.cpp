#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of the array :  ";
    cin>>n;
    vector<int>arr;
    cout<<"Enter valuse of array : ";
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        arr.push_back(m);
    }
    for(int i=0;i<n-1;i++)
    {
        bool flag = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    cout<<"Sorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}