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
/*1. ֻ������Ҫ�����ıߣ�����һ������ͨ���ͼ��
  2. Ҫ�뾭��ͼ���б߾�����С����Ȼֻ����ÿ����ֻ����һ�Σ������С�ı�ʹ��ͼ�γ�һ��ŷ��ͨ·��
  3. ŷ��ͨ·������������������������Ķ���Ϊ����������ͳ��������ĸ��� N����� (N-2)/2 ������Ҫ��ӵı�����
  4. ����Ϊ�����Ķ���ĸ���Ϊż�����ǳ�����⣬��ÿ������������һ���߼��ɡ�
  5. ����Ϊ�����Ķ������Ϊ������ʵ���������������Ϊ��������Ϊһ���߹����������������Զ�����Ȼ��ż������ˣ�����Ϊ��������ĸ���һ��Ϊż����
  ���䣺���ж���Ķ�����(2m=ż��)=ż�ȶ���Ķ���֮��(ż��)+��ȵ�Ķ������֮�ͣ�������ȵ�Ķ������֮����һ��ż����������������Ϊ��������������ĸ�����Ϊż����
        ���ֶ���Ҳ��Ϊͼ�۵Ļ�������ͼ�ж���Ķ�����ͼ������Ϊ�����ĸ���֮һ��
  6. ע�⣬��һ����ͨ��������Ϊһ��ŷ����·ʱ�Ĵ��� ans += cnt < 2 ? 2 : cnt;
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
                ans += cnt < 2 ? 2 : cnt; //����ͼΪһ��ŷ����·��������Ϊ����������Ϊ2����Ϊ����Ҫ������������������������������Ҫ������ļ�2�������ô���
            }
        }
        //
        int res = max((ans - 2) / 2 ,0)*t + t*e; //remove two hand in the border
        //cout<<ans<<endl;
        cout<<"Case "<<++k<<": "<<res<<endl;
    }


    return 0;



}

