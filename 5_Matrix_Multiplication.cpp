#include<iostream>
using namespace std;
int main()
{
    int r1,c1,r2,c2;
    cout<<"Enter r1, c1, r2, c2 "<<endl;
    cin>>r1>>c1>>r2>>c2;
    int m1[r1][c1], m2[r2][c2], ans[r1][c2];
    if(c1 != r2)
    {
        cout<<"Multiplication not possible"<<endl;
        return 0;
    }
    cout<<"Enter the value for first matrix "<<endl;
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cin>>m1[i][j];
        }
    }
    cout<<"Enter the value for second matrix "<<endl;
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cin>>m2[i][j];
        }
    }
    // Multiplication
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            ans[i][j]=0;
            for(int k=0;k<c1;k++)
            {
                ans[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}