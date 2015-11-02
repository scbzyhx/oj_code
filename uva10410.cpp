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

int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG
    int n;
    int node;
    while(cin>>n) {
        map<int,int> mmap;
        stack<int> st;
        vector<vector<int> > vec(n+1);
        for(int i=0;i<n;++i) {
            cin>>node;
            mmap[node] = i;
        }
        cin>>node;
        st.push(node);
        int u = node;

        for(int i=1;i<n; ++i) {
            cin>>node;
            while(u != st.top() && mmap[node] <= mmap[st.top()]+1) { 
             //第二个条件是因为：栈中只有一个与该结点同级（BFS访问时同层次）的结点。
             //所以两个结点之间如果距离根的距离只相差为1（BFS序列中相差1），说明两个结点是同一层的两个结点。
                st.pop();
            }
            vec[st.top()].push_back(node);
            st.push(node);
        }
        for(int i=1;i<=n;++i) {
            cout<<i<<":";
            for(int j =0;j<vec[i].size();++j)
                cout<<" "<<vec[i][j];
            cout<<endl;
        }


    }



}

