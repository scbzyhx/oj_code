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

//#define DEBUG
#define N 50002

/*

//unsigned big
class BigNum {
    #define MAXBITS 2000
private:
    char num[MAXBITS];
    int start;
public:
    BigNum(unsigned long long n=0):start(MAXBITS) {
       // cout<<n<<endl;
       if(n==0) start = MAXBITS-1;
        memset(this->num,'\0',sizeof(this->num));
        while(n>0){
         //   cout<<n<<endl;
       // cout<<start<<endl;
            num[--start] = (char)(n % 10);
            n = n / 10;

        }
       // cout<<start<<endl;
    }

    BigNum operator+(BigNum &big) {
        BigNum tmp(0);
        int next = 0;
        int i;
        for(i = MAXBITS-1; i >= big.start && i >= this->start; --i) {
            int sum = next + big.num[i] + this->num[i];
            tmp.num[i] = sum % 10;
            next = sum / 10;
        }
        for(; i >= big.start; --i ) {
            int sum = next + big.num[i] + this->num[i];
            tmp.num[i] = sum % 10;
            next = sum / 10;
        }
        for(; i >= this->start; --i) {
            int sum = next + big.num[i] + this->num[i];
            tmp.num[i] = sum % 10;
            next = sum / 10;
        }
        if(next > 0) {
            tmp.num[i] = next;
            --i;
        }
        tmp.start = i + 1;
        return tmp;
    }
    friend ostream& operator << (ostream& output,BigNum& c) //定义运算符“<<”重载函数
    {
       int i = c.start;
      // cout<<"start = "<<c.start<<endl;
       while(i<MAXBITS) output<<(char)(c.num[i++]+'0');
       //output<<"("<<c.real<<"+"<<c.imag<<"i)"<<endl;
       return output;
    }
    BigNum& operator=(const BigNum &b) {
        memcpy(this->num,b.num,sizeof(b.num));
        this->start = b.start;
        return *this;
    }
    BigNum& operator=(int bb) {
       // cout<<bb<<endl;
        BigNum b(bb);
        //cout<<b<<endl;
        memcpy(this->num,b.num,sizeof(b.num));
        this->start = b.start;
        return *this;
    }


};*/
#define N 76
unsigned long long arr[N];
int main(){
    long long n, bk;
    arr[0] = 1;
    arr[1] = 1;
    int counter = 1;

    while(cin>>n>>bk) {
        if(n>60) break;
        for(int i = 2; i <= n; ++i) {
            arr[i] = 1;
            for(int j=1;j<=bk;++j) {
                if(i-j>0) arr[i] += arr[i-j];
                else arr[i] += 1;
            }
        }
        cout<<"Case "<<counter<<": "<<arr[n]<<endl;
        counter++;

    }

    return 0;
}
