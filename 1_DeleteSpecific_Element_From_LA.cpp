#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,element = 5;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int> arr;
    cout<<"Enter values of the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        arr.push_back(m);
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==element)
        {
            arr.erase(arr.begin()+i);
            i--;
        }
    }
    for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;;
}