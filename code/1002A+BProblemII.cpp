/*
A + B Problem II
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 514196    Accepted Submission(s): 98456


Problem Description
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.


Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow,
each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not
 process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.


Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case.
The second line is the an equation "A + B = Sum", Sum means the result of A + B.
Note there are some spaces int the equation. Output a blank line between two test cases.
*/
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int i,j,y,n,k,h,p,lena,lenb;
int a[1000],b[1000],sum[1000];//store number a, number b and sum.
int main()
{
	string a1,b1;
	cin>>n;
	for(y=1;y<=n;y++)
	{
		cin>>a1>>b1;
		lena=a1.length();//input the number through string
		lenb=b1.length();
		for(i=0;i<1000;i++)
		{
			a[i]=0;b[i]=0;sum[i]=0;//set zero
		}
		for(i=lena-1;i>=0;i--)
		    a[lena-1-i]=a1[i]-'0';//switch char to int from 0 to lena - 1
		for(i=lenb-1;i>=0;i--)
		    b[lenb-1-i]=b1[i]-'0';
	    k=0;
		for(i=0;i<lenb||i<lena;i++)
		{
			h=a[i]+b[i]+k;//store the sum
			sum[i]=h%10;//mod 10
			k=h/10;//store the remainder
		}
		if(k!=0)
		    sum[i++]=k;//add remainder to next digit
		cout<<"Case "<<y<<":"<<endl<< a1<< " + " << b1 <<" = ";
		p=0;//flag
		for(j=i-1;j>=0;j--)
		{
		 	if(p==0&&sum[j]==0)
		 	{
		 	    continue;//skip the leading 0
		 	}
		 	else
		 	{
		 	    p=1;
		 	    cout<<sum[j];
		 	}
		}
		cout<<endl;
		if(y!=n)cout<<endl;
	}
	return 0;
}
