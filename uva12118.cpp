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
#define V 1005
vector<vector<int> > g(V);
bool vis[V];
int v,e,t;
int cnt;
/*1. 只考虑需要经过的边，则是一个多连通块的图。
  2. 要想经过图所有边距离最小，显然只能是每个边只遍历一次，添加最小的边使该图形成一个欧拉通路。
  3. 欧拉通路的条件就是至多有两个顶点的度数为奇数，所以统计奇数点的个数 N。最后 (N-2)/2 即是需要添加的边数。
  4. 若度为奇数的顶点的个数为偶数，非常好理解，即每两个顶点间添加一个边即可。
  5. 若度为奇数的顶点个数为奇数，实际上其个数不可能为奇数。因为一个边贡献两个度数，所以度数必然是偶数。因此，度数为奇数顶点的个数一定为偶数。
  补充：所有顶点的度数和(2m=偶数)=偶度顶点的度数之和(偶数)+奇度点的顶点度数之和，所以奇度点的顶点度数之和是一个偶数，而奇数个奇数为奇数，故奇数点的个数必为偶数。
        握手定理也称为图论的基本定理，图中顶点的度数是图论中最为基本的概念之一。
  6. 注意，若一个连通分量本身为一个欧拉回路时的处理： ans += cnt < 2 ? 2 : cnt;
	*/
void dfs(int i) {
    if(vis[i] == true) return;

    vis[i] = true;
    cnt += ((g[i].size() % 2 == 0) ? 0 : 1);
    for(int j =0; j<g[i].size(); ++j) {
        dfs(g[i][j]);
    }
}

int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG
    //ios::sync_with_stdio(false);
    int k = 0;
    while(cin>>v>>e>>t) {
        if(v == 0 && e == 0 && t == 0)
            break;
        int ans = 0;
        for(int i=0;i<V;++i) {
            g[i].clear();
            vis[i] = false;
        }
        int st,ed;
        for(int i=0;i<e;++i) {
            cin>>st>>ed;
            g[st].push_back(ed);
            g[ed].push_back(st);
        }

        for(int i=1;i<=v;++i) {
            if(!vis[i] && !g[i].empty()) {
                cnt = 0;
                dfs(i);
                ans += cnt < 2 ? 2 : cnt; //若子图为一个欧拉回路，则设其为奇数顶点数为2，因为它需要两个出口与其它分量相连（若不需要，后面的减2可以正好处理）
            }
        }
        //
        int res = max((ans - 2) / 2 ,0)*t + t*e; //remove two hand in the border
        //cout<<ans<<endl;
        cout<<"Case "<<++k<<": "<<res<<endl;
    }


    return 0;



}

