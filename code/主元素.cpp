/*

【问题描述】

已知一个整数序列A长度为N其中若存在a且a的个数大于N/2则称为A的主元素

例如0 5 5 3 5 7 5 5 则为主元素 5

又如0 5 5 3 5 1 5 7则中没有主元素。

假设的元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出的主元素。若存在主元素则输出该元素否则输出-1。


【输入形式】

一个整数数组
【输出形式】

主元素
*/
#include <iostream>
#include <sstream>
using namespace std;
int a[10]={0};
int main()
{
    int i=0;
    //用字符串获取数据
    string line;
    getline(cin,line);
    //字符串流
    istringstream ss(line);
    int num;
    //使用字符串流输入
    while(ss>>num)
    {
        a[num]++;
        i++;
    }
    bool flag = true;
    for(int j =0;j<10;j++)
    {
        //寻找主元素并输出
        if(a[j]>i/2)
        {
            flag = false;
            cout<<j<<endl;
            break;
        }
    }
    //没有主元素
    if(flag)
    {
        cout<<"-1"<<endl;
    }
    return 0;
}


