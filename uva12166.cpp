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
//本题关键在于其思路
map<long long,int> mymap;
int nodes = 0;
void dfs(string& s, int ind,int depth) {
    int w = 0;
    if(ind >= s.length()) return;

    if(s[ind] == '[') {
        dfs(s,ind+1,depth+1);
    }else if(s[ind] == ']') {
        dfs(s,ind+1,depth-1);
    }else if(s[ind] == ',')
       //ind++;
        dfs(s,ind+1,depth);
    else {
        for(;ind < s.length() && isdigit(s[ind]);++ind)

        //if(ind<s.length()) ind--;
        //cout<<"w="<<w<<" depth="<<depth<<endl;
        nodes++;
        mymap[w<<depth] = mymap[w<<depth] + 1;

        dfs(s,ind,depth);
    }




}

void dfs(string &s, int st, int ed, int depth) {
    if(s[st] == '[') {
        //cout<<"st="<<st<<endl;
        int p = 0;
        for(int i=st+1; i<ed; ++i) {
            if(s[i] == '[') ++p;
            else if(s[i] == ']') --p;
            else if(p == 0 && s[i] == ','){
                //cout<<"i="<<i<<endl;
                dfs(s,st+1,i-1,depth+1);
                dfs(s,i+1,ed-1,depth+1);
                return; //
            }
        }
    }else {
        long long w = 0;
        for(int i=st;i<=ed && isdigit(s[i]);++i) w = w*10 + s[i] - '0';
        mymap[w<<depth] = mymap[w<<depth] + 1;

    }
}
int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG

    int t;
    cin>>t;
    while(t-- > 0) {
        string s;
        mymap.clear();
        cin>>s;
        //long long total = 0;
        nodes = 0;
       dfs(s,0,s.length()-1,0);

      // dfs(s,0,0);
       // cout<<nodes<<endl;
        map<long long, int> :: iterator it;
        int mmax = 0;
        for(it = mymap.begin();it != mymap.end();it++) {
            //cout<<it->first<<" "<<it->second<<endl;
            nodes += it->second;
            mmax = mmax < it->second ? it->second : mmax;
        }
        cout<<nodes - mmax<<endl;

    }



}

