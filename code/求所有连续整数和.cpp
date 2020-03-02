/*
某些整数能分解成若干个连续整数的和的形式，例如

 15 = 1 + 2＋3＋4＋5　

 15 = 4 + 5 + 6

 15 = 7 + 8

 某些整数不能分解为连续整数的和，例如：16

【输入形式】一个整数N（N <= 10000）

【输出形式】整数N对应的所有分解组合，如果没有任何分解组合，则输出NONE。


思路： 1+...+6 = 21
       21-15 = 6 = 1+2+3
       有匹配的表示以6为结尾的连续整数和等于15存在
       且4+5+6=15
*/
#include <iostream>
#include <cstdio>
using namespace std;
//动态规划思想
int sum[5005];//开数组记录以数组下标为结尾的连续整数和
int main()
{
    int N;
    sum[0] = 0;//初态
    while(cin>>N)
    {
        bool flag = true;//记录是否有结果
        for(int i=1;i<=N/2+1;i++)//循环至N/2+1
        {
            sum[i]=i+sum[i-1]; //递推
            //在和大于N的时候往回找
            if(sum[i]>=N)
            {
                //回溯比较有无匹配值
                for(int j = i; sum[j] >= sum[i]-N && j>=0; j--)
                {
                    //正好有匹配的
                    if(sum[i]-N==sum[j])
                    {
                        //标记并输出
                        flag = false;
                        for(int k = j+1; k<=i; k++)
                        {
                            cout<<k<<" ";
                        }
                        cout<<endl;
                    }
                }
            }
        }
        if(flag)
        {
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}

