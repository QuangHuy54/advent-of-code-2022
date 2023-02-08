#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <queue>
#include <climits>
#include <deque>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day3.txt","r",stdin);
    freopen("output/day3-2.txt","w",stdout);
    string s;
    ll res=0;
    vector<string> a;
    
    while(cin>>s){
        a.push_back(s);
        if(a.size()==3){
            char k;
            for(int i=0;i<a[0].size();i++){
                char c=a[0][i];
                bool f1=false,f2=false;
                for(int j=0;j<a[1].size();j++){
                    if(c==a[1][j]){
                        f1=true;
                        break;
                    }
                }
                for(int j=0;j<a[2].size();j++){
                    if(c==a[2][j]){
                        f2=true;
                        break;
                    }
                }
                if(f1&&f2){
                    k=c;
                    break;
                }
            }
            if(k>='a'&&k<='z'){
                res+=(int)(k-'a'+1);
            }
            else{
                res+=(int)(k-'A'+27);
            }
            a.clear();
        }
    }
    cout<<res;
    return 0;
}