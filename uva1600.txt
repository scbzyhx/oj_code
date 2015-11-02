#include <iostream>
#include<string>

#include<memory.h>
#include<vector>
#include<unordered_set>
#include<cmath>
#include<stack>
#include<map>
#include<sstream>
#include<unordered_set>
#include<algorithm>
#include<queue>
#include<cstddef>
#include <fstream>
using namespace std;
#define DEBUG
#define MAXMNK 24
int arr[MAXMNK][MAXMNK][MAXMNK];
int mmap[MAXMNK][MAXMNK];
struct Node {
    int x;
    int y;
    int k;
    Node(int xx = 0, int yy = 0, int kk = 0):x(xx),y(yy),k(kk){}
};
int dx[] = {-1, 1,  0, 0};
int dy[] = { 0, 0, -1, 1};
#define OBSTACLE 1
#define FREE 0
int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG
    int t;
    int m,n,k;
    cin>>t;
    while(t>0) {
        t--;

        cin>>m>>n>>k;
        //cout<<k<<endl;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                cin>>mmap[i][j];
        for(int kk=0;kk<=k;++kk)
            for(int i=1;i<=m;++i)
                for(int j=1;j<=n;++j)
                    arr[kk][i][j] = -1;
     /*   for(int i=1;i<=m;++i) {
            for(int j=1;j<=n;++j)
                cout<<mmap[i][j]<<" ";
            cout<<endl;
        }*/

        queue<Node> q;
        q.push(Node(1,1,0));
        arr[0][1][1] = 0;
        bool iscont = true;

        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            int nx,ny;
            int tmpk;
            for(int i=0;i<sizeof(dx)/sizeof(int);++i) {
                nx = node.x + dx[i];
                ny = node.y + dy[i];
               // cout<<nx<<
                if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
                if(mmap[nx][ny] == OBSTACLE) {
                    if(mmap[node.x][node.y] == OBSTACLE)
                        tmpk = node.k + 1;
                    else
                        tmpk = 1;
                    //if(node.k + 1 > k) continue; // too much obstacle
                }else {
                    //mmap[nx][ny] == FREE

                    tmpk = 0;
                }
                if(tmpk > k) continue;

                if(arr[tmpk][nx][ny] >= 0) continue;
                //arr[tmpk][nx][ny] < 0
                arr[tmpk][nx][ny] = arr[node.k][node.x][node.y] + 1;

               // cout<<"push in "<<nx<<" "<<ny<<" "<<tmpk<<endl;//" "<<k<<" "<<m<<" "<<n<<endl;
                q.push(Node(nx,ny,tmpk));


                if(nx == m && ny == n) {
                    cout<<arr[tmpk][nx][ny]<<endl;
                    iscont = false;
                }

            }
            if(!iscont) break;
        }
        if(iscont)
            cout<<-1<<endl;


    }



}

