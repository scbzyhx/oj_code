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
#include <cmath>
using namespace std;
#define DEBUG
#define MAXN 128
char arr[MAXN][MAXN];
int black[MAXN*MAXN];
int nodes = 0;
#define BLACK '1'
#define WHITE '0'
#define NW 1
#define NE 2
#define SW 3
#define SE 4


bool dfs(int stx,int sty,int edx,int edy,int num=0,int depth=0) {

    if(stx == edx - 1 && sty == edy - 1) {
        //if(stx == 4 && sty == 2)
           // cout<<"stx="<<stx<<" sty="<<sty<<" edx="<<edx<<" edy="<<edy<<" num="<<arr[stx][sty]<<endl;
        if(arr[stx][sty] == BLACK)
            return true;
        else
            return false;
    }
    int midx = (stx+edx)/2;
    int midy = (sty+edy)/2;

    int sx[] = {stx,stx,midx,midx};
    int ex[] = {midx,midx,edx,edx};
    int sy[] = {sty,midy,sty,midy};
    int ey[] = {midy,edy,midy,edy};

    int num_arr[4] = {0,0,0,0}; //NW,NE,
    int counter = 0;/*
    if(stx == 4 && sty == 2 && edx == 6 && edy == 4) {
        for(int i=0;i<sizeof(sx)/sizeof(int);++i) {
            cout<<sx[i]<< " "<<sy[i]<<" "<<ex[i]<<" "<<ey[i]<<" num="<<pow(5,depth)*(i+1)+num<<endl;

        //else do nothing
        }
    }*/
    for(int i=0;i<sizeof(sx)/sizeof(int);++i) {
        int next =(pow(5,depth))*(i+1)+num;
        /*for(int j=0;j<depth;++j) next = next*5;
        next *= (i+1);
        next += num;
*/

        if(dfs(sx[i],sy[i],ex[i],ey[i],next,depth+1) == true) {
            num_arr[i] = next;
            counter++;
            if(stx == 4 && sty == 2 && edx == 6 && edy == 4) {
               cout<<"in loop:"<<sx[i]<< " "<<sy[i]<<" "<<ex[i]<<" "<<ey[i]<<" num="<<next<<" depth ="<<depth<<endl;
            }
        }else
            num_arr[i] = -1;

        //else do nothing
    }
    if(counter == 4) {
        //black[nodes++] = num;
        //cout<<"stx="<<stx<<" sty="<<sty<<" edx="<<edx<<" edy="<<edy<<" num="<<num<<endl;
        return true;
    }else {
        for(int i=0;i<4;++i) {
            if(num_arr[i] >= 0) {
                black[nodes++] = num_arr[i];
               // cout<<"stx="<<stx<<" sty="<<sty<<" edx="<<edx<<" edy="<<edy<<" num="<<num_arr[i]<<" counter="<<counter<<endl;
            }
        }
        return false;
    }

}
void dfs_int_to_matrix(int stx, int sty, int edx, int edy, int num) {

    if(num == 0) {
        for(int i = stx;i < edx; i++)
            for(int j = sty; j< edy; ++j)
                arr[i][j] = BLACK;
        return ;
    }
    int midx = (stx+edx)/2;
    int midy = (sty+edy)/2;

    switch(num%5) {
    case 1:
        dfs_int_to_matrix(stx,sty,midx,midy ,num/5);
        //dfs_int_to_matrix(stx,sty,midx-1,midy-1 ,num/5);
        break;
    case 2:
        dfs_int_to_matrix(stx,midy,midx, edy,num/5);
       // dfs_int_to_matrix(stx,midy+1,midx-1, edy,num/5);
        break;
    case 3:
        dfs_int_to_matrix(midx,sty,edx,midy,num/5);
       // dfs_int_to_matrix(midx+1,sty,edx,midy-1,num/5);
        break;
    case 4:
        dfs_int_to_matrix(midx,midy,edx,edy,num/5);
        //dfs_int_to_matrix(midx+1,midy+1,edx,edy,num/5);
        break;
    case 0:
        //how ?
        100/0;
      //  assert(0); //error, must be 1,2,3,4
        break;

    }
}

int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG
    int n;
    int count = 0;

    while(cin>>n) {
        if(n==0) break;
        cout<<"Image "<<(++count)<<endl;
        memset(arr,'\0',sizeof(arr));
        nodes = 0;
        if(n>0) {
            for(int i=0;i<n;++i)
                cin>>arr[i];

            if(dfs(0,0,n,n,0,0)) {
                black[nodes++] = 0;
            }
            sort(black,black+nodes);

            //show
            int counter = 0;
            for(int i=0;i<nodes;++i) {
                cout<<black[i]<<" ";
                if(++counter % 12 == 0) cout<<endl;
            }
            cout<<endl;
            cout<<"Total number of black nodes = "<<nodes<<endl;
        }else {
            n = 0 - n;
            int color;
            while(true){
                cin>>color;
                //cout<<"color="<<color<<endl;
                if(color == -1) break;
                dfs_int_to_matrix(0,0,n,n,color);

            }
            for(int i=0;i<n;++i) {
                for(int j=0;j<n;++j) {
                    if(arr[i][j] == BLACK)
                        cout<<"*";
                    else
                        cout<<".";
                }
                cout<<endl;
            }

        }
        cout<<endl;
    }
    return 0;



}

