#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,element = 5;
    cout<<"Enter the size of the array :";
    cin>>n;
    int arr[n];
    cout<<"Enter the values for array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            for(int j=i;j<n-1;j++)
            {
                arr[j] = arr[j+1];
            }
            n--;
            i--;
        }
    }
    for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;;
}