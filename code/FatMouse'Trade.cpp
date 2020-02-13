/*
FatMouse' Trade
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 116291    Accepted Submission(s): 40117


Problem Description
FatMouse prepared M pounds of cat food,
ready to trade with the cats guarding the warehouse containing his favorite food,
JavaBean.The warehouse has N rooms.
The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food.
FatMouse does not have to trade for all the JavaBeans in the room, instead,
he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food.
Here a is a real number.
Now he is assigning this homework to you:
tell him the maximum amount of JavaBeans he can obtain.


Input
The input consists of multiple test cases.
Each test case begins with a line containing two non-negative integers M and N.
Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively.
The last test case is followed by two -1's. All integers are not greater than 1000.


Output
For each test case, print in a single line a real number accurate up to 3 decimal places,
which is the maximum amount of JavaBeans that FatMouse can obtain.
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
//greedy algorithm
struct Profit
{
    double profit; //J[i]/F[i]
    double J;
    double F;
} pt[1005];
//descending order
bool cmp(Profit a, Profit b)
{
    return a.profit > b.profit;
}
int main()
{
    int M, N;
    while(cin>>M>>N)
    {
        if(M == -1 && N == -1) break;
        //input
        for(int i=0; i<N; i++)
        {
            cin>>pt[i].J>>pt[i].F;
            pt[i].profit = pt[i].J / pt[i].F;//div 0?
        }
        sort(pt, pt + N, cmp);
        int i = 0;
        double ans = 0;
        //profit first
        while(M>= 0 && N>0) //consider "free of charge"
        {
            M -= pt[i].F;
            ans += pt[i++].J;
        }
        //sub the overflow
        if(M != 0)
            ans -= (0 - M) * pt[i-1].profit;
        //output
        printf("%.3lf\n",ans);
    }
    return 0;
}
