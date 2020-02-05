/*
Let the Balloon Rise
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 174940    Accepted Submission(s): 69674


Problem Description
Contest time again! How excited it is to see balloons floating around.
But to tell you a secret, the judges' favorite time is guessing the most popular problem.
When the contest is over, they will count the balloons of each color and find the result.

This year, they decide to leave this lovely job to you.


Input
Input contains multiple test cases.
Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed.
The next N lines contain one color each.
The color of a balloon is a string of up to 15 lower-case letters.

A test case with N = 0 terminates the input and this test case is not to be processed.

Output
For each case, print the color of balloon for the most popular problem on a single line.
It is guaranteed that there is a unique solution for each test case.

*/
#include<iostream>
#include<string>
using namespace std;
struct Counter{                 //records color has appeared, and sum
    int sum;
    string color;
};
Counter counter[1005];
int main()
{
    int N;
    while(true)
    {
        string str;
        cin>>N;
        if(N==0)break;
        for(int i=0;i<N;i++)
        {
            counter[i].sum = 0;
        }
        //input & count
        for(int i=0;i<N;i++)
        {
            string bcolor;
            cin>>bcolor;
            bool flag = false;
            for(int j=0;j<i;j++)
            {
                if(bcolor.compare(counter[j].color)==0)
                {
                    counter[j].sum++;
                    flag = true;
                }
            }
            if(flag == false)
            {
                counter[i].color = bcolor;
                counter[i].sum++;
            }
        }
        //search
        int maximum=0;
        string maxcolor;
        for(int i=0;i<N;i++)
        {
            if(counter[i].sum>maximum)
            {
                maximum = counter[i].sum;
                maxcolor = counter[i].color;
            }
        }
        //output
        cout<<maxcolor<<endl;
    }
    return 0;
}
