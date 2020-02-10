/*
Quoit Design
Time Limit: 10000/5000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 75289    Accepted Submission(s): 20052


Problem Description
Have you ever played quoit in a playground?
Quoit is a game in which flat rings are pitched at some toys, with all the toys encircled awarded.
In the field of Cyberground, the position of each toy is fixed,
and the ring is carefully designed so it can only encircle one toy at a time.
On the other hand, to make the game look more attractive, the ring is designed to have the largest radius.
Given a configuration of the field, you are supposed to find the radius of such a ring.

Assume that all the toys are points on a plane.
A point is encircled by the ring if the distance
between the point and the center of the ring is strictly less than the radius of the ring.
If two toys are placed at the same point, the radius of the ring is considered to be 0.


Input
The input consists of several test cases.
For each case, the first line contains an integer N (2 <= N <= 100,000),
the total number of toys in the field. Then N lines follow,
each contains a pair of (x, y) which are the coordinates of a toy.
The input is terminated by N = 0.


Output
For each test case,
print in one line the radius of the ring required by the Cyberground manager,
accurate up to 2 decimal places.

*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 100007;
int a[N];
struct point
{
    double x, y;
}pt[N];
//compare, x first
bool cmp(point a,point b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
//compare y
bool cmp_y(int id1, int id2)
{
    if(pt[id1].y == pt[id2].y) return pt[id1].x < pt[id2].x;
    return pt[id1].y < pt[id2].y;
}
//get distance between two points
double getdis(const point &a,const point &b)
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x*x + y*y);
}
//divide
double slove(int l,int h)
{
    double ans = 0;
    if(h-l+1 == 1) return 0;
    ans = getdis(pt[l],pt[l+1]);
    if(h-l+1 == 2) return ans;
    if(h-l+1 == 3)
    {
        for(int i=l;i<h;i++)
        {
            for(int j=i+1;j<h;j++)
            {
                ans = min(ans,getdis(pt[i],pt[j]));
            }
        }
        return ans;
    }
    int m = (h+l)>>1;
    double s1 = slove(l,m);
    double s2 = slove(m+1, h);
    ans = min(s1,s2);
    int k=0;
    //get the id of point on two side of mid
    double ldis = pt[m].x - ans;
    double rdis = pt[m].x + ans;
    for(int i=m; i>=l; i--)
    {
        if(pt[i].x>=ldis)
        {
            a[k++]=i;
        }
    }
    for(int j = m+1; j<=h; j++)
    {
        if(pt[j].x<=rdis)
        {
            a[k++]=j;
        }
    }
    sort(a,a+k,cmp_y);
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k&&j<=i+7;j++)
        {
            ans = min(ans, getdis(pt[a[i]],pt[a[j]]));
        }
    }
    return ans;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(!n)break;
        for(int i=0;i<n;i++)
        {
            cin>>pt[i].x>>pt[i].y;
        }
        sort(pt,pt+n,cmp);
        printf("%.2lf\n",slove(0,n-1)/2.0);
    }
    return 0;
}
