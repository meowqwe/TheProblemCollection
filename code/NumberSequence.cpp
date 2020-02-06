/*
Number Sequence
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 234383    Accepted Submission(s): 59503


Problem Description
A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).


Input
The input consists of multiple test cases.
Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000).
Three zeros signal the end of input and this test case is not to be processed.


Output
For each test case, print the value of f(n) on a single line.
*/
#include <iostream>
#include <cstring>
using namespace std;
//fast matrix power algorithm
struct Matrix
{
    int m[2][2];
};
//set unit matrix
void clear(Matrix& A)//pass the reference
{
    memset(A.m,0,sizeof(A.m));
    for(int i=0;i<2;i++)
    {
        A.m[i][i] = 1;
    }
}
//matrix multiplication
Matrix mul(Matrix A,Matrix B)
{
    Matrix ans;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans.m[i][j]=0;
            for(int k=0;k<2;k++)
            {
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j]%7)%7;//(a+b)%mod = (a%mod+b%mod)%mod
            }
        }
    }
    return ans;
}
//fast power algorithm
Matrix pow(Matrix A , int ll)
{
    Matrix ans;
    clear(ans);
    while(ll)
    {
        if(ll&1) ans = mul(ans,A);//mind the return
        A = mul(A,A);
        ll>>=1;
    }
    return ans;
}
int main()
{
    int A,B,n;
    while(true)
    {
        // input
        cin>>A>>B>>n;
        if(!(A&&B&&n)) break;
        //critical value
        if(n<=2)
        {
            cout<<"1"<<endl;
            continue;
        }
        //init
        Matrix X,ans;
        X.m[0][0] = A;
        X.m[0][1] = B;
        X.m[1][0] = 1;
        X.m[1][1] = 0;
        //compute
        ans = pow(X,n-2);
        //output
        cout<<(ans.m[0][0]+ans.m[0][1])%7<<endl;
    }
    return 0;
}
