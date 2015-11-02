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
/*
void getnext(int next[], char data[], int n) {
    int i,j;
    if(n == 0) return ;
    next[0] = -1;
    j = -1;
    i = 0;
    while(i<n) {
        if(j == -1 || data[i] == data[j]) {
            i++;
            j++;
            //
           // i+1, j+1, here
            if(data[i] != data[j])
               next[i] = j;
            else
               next[i] = next[j];

        }else {
            j = next[j];
        }
    }
}

*/

#define RC 16
int vis[RC][RC];

static inline int ch2int(char ch) {
    if(isdigit(ch)) return (ch - '0');
    //else isalpha()
    return (ch - 'a' + 1);
}
int dx[] = {1,  2,2,1,-1,-2,-2,-1};
int dy[] = {-2,-1,1,2, 2, 1,-1,-2};
int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG

    int dstx,dsty,srcx,srcy;

    char where[5];
    while(cin>>where) {

        //alpha is column
        //cout<<where<<endl;
        srcy = ch2int(where[0]);
        srcx = ch2int(where[1]);
        cin>>where;
        dsty = ch2int(where[0]);
        dstx = ch2int(where[1]);
        queue<int> qx,qy;
        //
        for(int i=0;i<RC;++i)
            for(int j=0;j<RC;++j)
                vis[i][j] = -1;
       // memset(vis,'\0',sizeof(vis));
        qx.push(srcx);
        qy.push(srcy);

        vis[srcx][srcy] = 0;
        int nx,ny,nowx,nowy;
        bool iscont = true;
        while(!qx.empty()) {
            nowx = qx.front();
            nowy = qy.front();
            qx.pop();
            qy.pop();
            for(int i =0;i<sizeof(dx)/sizeof(int);++i) {
                nx = nowx + dx[i];
                ny = nowy + dy[i];
                if( nx < 1 || nx > 8 || ny < 1 || ny > 8) continue; //³¬³ö¾ØÕó

                if(vis[nx][ny] < 0) {
                    //not visit

                    vis[nx][ny] = vis[nowx][nowy]+1;
                    qx.push(nx);
                    qy.push(ny);
                }
                if(nx == dstx && ny == dsty) {
                    cout<<"To get from "<< (char)(srcy+'a'-1)<<srcx<<" to "<< (char)(dsty+'a'-1)<<dstx<<" takes "<< vis[nx][ny] <<" knight moves."<<endl;
                    iscont = false;
                    break;
                }

            }
            if(!iscont)
                break;
        }





    }




    return 0;

}

