//#Name: Sofen Haque Anonta  #Problm:
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <utility>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>

using namespace std;

//FOLD ME!!!
namespace{
typedef long long LL;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef map<int,int> mapii;
typedef map<int,bool> mapib;
typedef stringstream strstream;
typedef unsigned long long ULL;

//Macros
LL CC_;
#define sf scanf
#define pf printf
#define PP getchar();
#define NL cout<<"\n";
#define pqueue priority_queue
#define testb(x_, i_) ((x_&1<<i_)!=0)
#define setb(x_, i_) (x_=(x_|(1<<i_)))
#define clrb(x_, i_) (x_=(x_&(!(1<<i_))))
#define all(container) container.begin(),container.end()
#define DC(x_) cout<<">>> "<<#x_<<"\n";DA(x_.begin(), x_.end());
#define DD(x_) cout<<">>>>( "<<++CC_<<" ) "<<#x_<<": "<<x_<<endl;
#define SS printf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++CC_);
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

//constants
const int SZ= 1E6;
const int INF= (1<<29);
const double EPS= 1E-9;
const double PI= 2*acos(0.0);
const long long MOD= 1000000007;

template <class T>void DA(T i,T e){while(i!=e){cout<<"Con>>( "<<++CC_<<" ) "<<*i++<<endl;}}
template <class T>void DA(T* x, int l){for(int i=0; i<l;i++)cout<<"["<<i<<"]>> "<<x[i]<<endl;}
template <class T>inline void sary(T* st, T* nd){while(st<nd)cin>>*st++;/*sf("%d", st++);*/}
template <class T>void tobin(T n,char*bin){int pos= 1<<((int)log2(n));while(pos>=1){if((n & pos)==0)*bin='0';else*bin='1';pos>>=1;bin++;}*bin='\0';}
template <class T>int strOccur(string&s,T&tgt){int oc= 0, p= s.find(tgt);while(p != string::npos){p = s.find(tgt, p+1);oc++;}return oc;}
template <class T>LL factorial(T n){LL f= n;while(--n){f*= n;}return f;}
template <class T>inline T LCM(T x,T y){return((x*y)/__gcd(x,y));}
LL todec(string& num, int b){LL dec=num[0]-(isupper(num[0])? 'A'-10: '0');for(int i=1;num[i];i++){if(num[i]>='A'&& num[i]<='Z')num[i]-='A'-10;else num[i]-='0';dec*= b;dec+= num[i];}return dec;}
int bigMod(int b,int e,int m){if(e==0)return 1;if(!e&1){int temp=bigMod(b,e/2,m)%m;return(temp*temp)%m;}else return((b%m)*(bigMod(b,e-1,m))%m)%m;}
inline LL POW(LL base, int exp){LL p= 1; while(exp-->0){p *= base;} return p;}
bool comp(const int a,const int b){return a>b;}
}


char mine[21][21];
int N,M;
int xm[9]= {1, 0, 1, -1,  0, -1,  1, -1};
int ym[9]= {0, 1, 1, -1, -1,  0, -1,  1};

int mcount(int r, int c, int n){
    if(r < 0 || c< 0 || r>= N || c >= M) return 0;
    if(mine[r][c] == 'F') return 1;
    if(n == 0) return 0;
    int sum= 0;
    for(int i= 0; i<8; i++){
        sum+= mcount(r+xm[i], c+ym[i], 0);
    }
    
    return sum;
}

void solve(void){
    int Tc;
    int n, m;
    
    cin>>Tc;
    cin.ignore();
    
    bool corr, ffonly;
    for(int Case= 1; Case<=Tc; Case++)
    {
        ffonly= true;
        corr= true;
        cin>>n>>m;
        N = n;
        M= m;
        for(int i= 0; i<n; i++){
            for(int j= 0; j<n; j++){
                cin>>mine[i][j];
            }
        }
        
        for(int i= 0; i<n; i++){
            for(int j= 0; j<n; j++){
                if(mine[i][j] != 'F'){
                    ffonly= false;
                    if(mine[i][j] - '0' != mcount(i, j, 1)){
                        corr= false;
                        break;
                    }
                }
            }
            if(corr == false) break;
        }
        
        cout<< ((corr && ffonly!=true)? "Well done Clark!" : "Please sweep the mine again!") <<endl;
        
//        cout<< mcount(0, 1,1) <<endl;
//        cout<< mcount(6, 7,1) <<endl;
    }

}


/*FILL ME WITH INPUTS!!!

1 1
1
 * 
2 2
F1
11
*/


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
   

    
    return 0;
}
