/*

������������

��֪һ����������A����ΪN����������a��a�ĸ�������N/2���ΪA����Ԫ��

����0 5 5 3 5 7 5 5 ��Ϊ��Ԫ�� 5

����0 5 5 3 5 1 5 7����û����Ԫ�ء�

�����Ԫ�ر�����һ��һά�����У������һ�������ܸ�Ч���㷨���ҳ�����Ԫ�ء���������Ԫ���������Ԫ�ط������-1��


��������ʽ��

һ����������
�������ʽ��

��Ԫ��
*/
#include <iostream>
#include <sstream>
using namespace std;
int a[10]={0};
int main()
{
    int i=0;
    //���ַ�����ȡ����
    string line;
    getline(cin,line);
    //�ַ�����
    istringstream ss(line);
    int num;
    //ʹ���ַ���������
    while(ss>>num)
    {
        a[num]++;
        i++;
    }
    bool flag = true;
    for(int j =0;j<10;j++)
    {
        //Ѱ����Ԫ�ز����
        if(a[j]>i/2)
        {
            flag = false;
            cout<<j<<endl;
            break;
        }
    }
    //û����Ԫ��
    if(flag)
    {
        cout<<"-1"<<endl;
    }
    return 0;
}


