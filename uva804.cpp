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
#define NP 128
#define NT 128

vector<int> tokens(NP);
vector<int> new_tokens(NP);
vector<vector<int> > in(NT);
vector<vector<int> > out(NT);
int t = 0;

void simulation(int times,int np,int nt) {
    bool state = true;
    bool dead = true;
    for(int time=1;time<=times;++time) {
        dead = true;
        for(int i = 1; i <= nt && dead; ++i) {
            //
            state = true;
            for(int j=0;j<in[i].size(); ++j) {
                if(tokens[in[i][j]] <= 0) {
                    state = false;
                    break;
                }else {
                    tokens[in[i][j]] -= 1;
                    new_tokens[in[i][j]] += 1; //ÔÝÊ±¼ÇÂ¼
                }
            }
            /*fire failed: recovery*/
            if(!state) {
                //recover
                for(int j=0;j<in[i].size(); ++j) {
                    tokens[in[i][j]] +=  new_tokens[in[i][j]];
                    new_tokens[in[i][j]] = 0;
//                    dead = false;

                }
                continue;
            }
            /*fire enabled*/
            for(int j=0;j<in[i].size(); ++j) {
                tokens[in[i][j]] -= 1;
                dead = false;

            }
            /*output place*/
            for(int j=0; j<out[i].size(); ++j)
                new_tokens[out[i][j]] += 1;
            /*just fire one!!*/
            if(state)
                break;

        }
        /*is dead?*/
        if(dead) {
            cout<<"Case "<<t<<": "<<"dead after "<<time-1<<" transitions"<<endl;
            cout<<"Places with tokens:";
            for(int j=1;j<=np;++j) {
                if(tokens[j] > 0) {
                    cout<<" "<<j<<" ("<<tokens[j]<<")";

                }
            }
            cout<<endl;
            return ;
        }
        /*still alive*/
        for(int j=1; j <= np; ++j) {
            tokens[j] += new_tokens[j];
            new_tokens[j] = 0;
        }
    }

    cout<<"Case "<<t<<": "<<"still live after "<<times<<" transitions"<<endl;
    cout<<"Places with tokens:";
    for(int j=1;j<=np;++j) {
        if(tokens[j] > 0) {
            cout<<" "<<j<<" ("<<tokens[j]<<")";
        }
    }
    cout<<endl;
    return ;

}

int main() {
    #ifdef DEBUG
    ifstream fi(".\\io.in");
    cin.rdbuf(fi.rdbuf());
    #endif // DEBUG
    int np,nt,tmp,times;
    while(cin>>np) {
        if(np == 0) break;
        t++;
        for(int i=1;i<=np;++i){
            cin>>tokens[i];
            new_tokens[i] = 0;
        }

        cin>>nt;
        for(int i=1;i<=nt;++i) {
            in[i].clear();
            out[i].clear();
            while(1) {
                cin>>tmp;
                if(tmp == 0) break;
                if(tmp<0) in[i].push_back(-tmp);
                else out[i].push_back(tmp);
            }
        }
        cin>>times;
        simulation(times,np,nt);
        cout<<endl;


    }


    return 0;



}

