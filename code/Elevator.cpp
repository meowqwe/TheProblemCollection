/*
Elevator
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 100580    Accepted Submission(s): 54493


Problem Description
The highest building in our city has only one elevator.
A request list is made up with N positive numbers.
The numbers denote at which floors the elevator will stop, in specified order.
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list.
The elevator is on the 0th floor at the beginning
and does not have to return to the ground floor when the requests are fulfilled.


Input
There are multiple test cases.
Each case contains a positive integer N, followed by N positive numbers.
All the numbers in the input are less than 100.
A test case with N = 0 denotes the end of input. This test case is not to be processed.


Output
Print the total time on a single line for each test case.
*/
#include <iostream>
using namespace std;
int main()
{
    int N;
    //multiple test case
    while(cin>>N)
    {
        if(N == 0)  break;
        int time = 0, floor = 0;
        //cumulative
        while(N--)
        {
            int nextfloor;
            //input
            cin>>nextfloor;
            int sub = nextfloor - floor;
            if(sub > 0)
            {
                time += sub * 6 + 5;
            }
            else
            {
                time += -sub *4 + 5;
            }
            floor = nextfloor;
        }
        //output
        cout<<time<<endl;
    }
    return 0;
}
