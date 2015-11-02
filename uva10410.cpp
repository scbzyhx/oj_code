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
             //�ڶ�����������Ϊ��ջ��ֻ��һ����ý��ͬ����BFS����ʱͬ��Σ��Ľ�㡣
             //�����������֮�����������ľ���ֻ���Ϊ1��BFS���������1����˵�����������ͬһ���������㡣
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

