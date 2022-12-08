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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    ll res=0;
    while(cin>>s){
        int n=s.size();
        char k;
        for(int i=0;i<(n/2);i++){
            for(int j=(n/2);j<n;j++){
                if(s[i]==s[j]){
                    k=s[i];
                    break;
                }
            }
        }
        if(k>='a'&&k<='z'){
            res+=(int)(k-'a'+1);
        }
        else{
            res+=(int)(k-'A'+27);
        }
    }
    cout<<res;
    return 0;
}