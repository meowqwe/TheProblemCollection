/*
Tempter of the Bone
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 173344    Accepted Submission(s): 45963


Problem Description
The doggie found a bone in an ancient maze,
which fascinated him a lot.
However, when he picked it up, the maze began to shake,
and the doggie could feel the ground sinking.
He realized that the bone was a trap, and he tried desperately to get out of this maze.

The maze was a rectangle with sizes N by M.
There was a door in the maze.
At the beginning,
the door was closed and it would open at the T-th second for a short period of time
(less than 1 second).
Therefore the doggie had to arrive at the door on exactly the T-th second.
In every second, he could move one block to one of the
upper, lower, left and right neighboring blocks.
Once he entered a block,
the ground of this block would start to sink and disappear in the next second.
He could not stay at one block for more than one second,
nor could he move into a visited block. Can the poor doggie survive? Please help him.


Input
The input consists of multiple test cases.
The first line of each test case contains three integers
N, M, and T (1 < N, M < 7; 0 < T < 50),
which denote the sizes of the maze and the time at which the door will open, respectively.
The next N lines give the maze layout, with each line containing M characters.
A character is one of the following:

'X': a block of wall, which the doggie cannot enter;
'S': the start point of the doggie;
'D': the Door; or
'.': an empty block.

The input is terminated with three 0's. This test case is not to be processed.


Output
For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 10;
int N, M, T, flag;
int ex, ey, sx, sy;  //the start and end points
char mp[MAXN][MAXN]; //map
int vis[MAXN][MAXN]; //visited
int dt[][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; //directions

void dfs (int x, int y, int step)
{
   if(x == ex && y == ey)
   {
       if(step == T)
       {
           flag = 1;
       }
       return;
   }
   // pruning
   if(flag) return;
   if(step >= T) return;
   vis[x][y] = 1;
   for(int i=0;i<4;i++)
   {
       int tx = x + dt[i][0];
       int ty = y + dt[i][1];
       //judge & search
       if(tx >= 0 && tx < N && ty >= 0 && ty < M && vis[tx][ty] != 1 && mp[x][y] != 'X')
       {
           dfs(tx,ty,step+1);
       }
   }
   vis[x][y] = 0;
}
int main()
{
    while(cin>>N>>M>>T)
    {
        if(N+M+T == 0)
            break;
        memset(vis,0,sizeof(vis));
        flag = 0;
        //input
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                cin>>mp[i][j];
                if(mp[i][j] == 'S') //start point
                {
                    sx = i;
                    sy = j;
                    vis[sx][sy] = 1;
                }
                if(mp[i][j] == 'D') //end point
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        // pruning
        if((int)(T-abs(sx-ex)-abs(sy-ey))%2 == 0)
            dfs(sx,sy,0);
        // searching & output
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
