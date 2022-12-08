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
#include<sstream>
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
/*struct ele{
    ll begin;
    ll end;
    ll res;
    ll resSoFar;
};
ele ar[800005];
long long a[200005];
ele merge(ele a,ele b){
    ele t;
    t.begin=a.begin;
    t.end=b.end;
    if(a.end==b.begin){
        t.res=a.res+b.res-1;
    }
    else{
        t.res=a.res+b.res;
    }
    t.resSoFar=a.resSoFar*b.resSoFar+t.res;
    return t;
}
void build(int id,int l,int r){
    if(l==r){
        ar[id].begin=a[l];
        ar[id].end=a[l];
        ar[id].res=1;
        ar[id].resSoFar=1;
        return;
    }
    int m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    ar[id]=merge(ar[2*id],ar[2*id+1]);
}
void update(int id,int l,int r,int idx,ll x){
    if(idx<l||idx>r){
        return;
    }
    if(l==r){
        ar[id].begin=x;
        ar[id].end=x;
        ar[id].res=1;
        ar[id].resSoFar=1;
        return;
    }
    int m=(l+r)/2;
    if(idx<=m){
        update(2*id,1,m,idx,x);
    }
    else{
        update(2*id+1,m+1,r,idx,x);
    }
    ar[id]=merge(ar[2*id],ar[2*id+1]);
}
int query(int id,int l,int r,ll num){
    if(ar[id]<num){
        return 0;
    }
    if(l==r){
        ar[id]=ar[id]-num;
        return l;
    }
    int m=(l+r)/2;
    if(ar[2*id]>=num){
        int res=query(2*id,l,m,num);
        ar[id]=max(ar[2*id],ar[2*id+1]);
        return res;
    }
    else{
        int res=query(2*id+1,m+1,r,num);
        ar[id]=max(ar[2*id],ar[2*id+1]);
        return res;
    }
}*/
// Segment tree
// int p[502];
// ll siz[502];
// int r[502];
// int get(int u){
//     return p[u]==u ? u :get(p[u]);
// }
// bool uni(int u,int v){
//     u=get(u);
//     v=get(v);
//     if(u!=v){
//         if(r[u]==r[v]){
//             r[u]++;
//         }
//         if(r[u]>r[v]){
//             p[v]=u;
//             siz[u]+=siz[v];
//         }
//         else{
//             p[u]=v;
//             siz[v]+=siz[u];
//         }
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// DSU
/*ll powermod(ll a,ll b){
    ll res=1;
    if(a==0) return 0;
    while(b){
        if(b&1){
            res=(res*a);
        }
        b=b>>1;
        a=(a*a);
    }
    return res;
}
*/
// ll powermod(ll a,ll b,ll m){
//     ll res=1;
//     if(a==0) return 0;
//     while(b){
//         if(b&1){
//             res=(res*a)%m;
//         }
//         b=b>>1;
//         a=(a*a)%m;
//     }
//     return res%m;
// }
// Codeforce
// int tmp[200002];
// ll dp[200002];
vector<string> split(string s, char del)
{
    vector<string> a;
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        a.push_back(word);
    }
    return a;
}
ll toInt(string s){
    ll res=0;
    for(int i=0;i<s.size();i++){
        res*=10;
        res+=(s[i]-'0');
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    ll res=0;
    vector<string> a;
    while(cin>>s){
        vector<string> two=split(s,',');
        ll a,b,c,d;
        vector<string> first=split(two[0],'-');
        vector<string> second=split(two[1],'-');
        a=toInt(first[0]);
        b=toInt(first[1]);
        c=toInt(second[0]);
        d=toInt(second[1]);
        if(!(b<c||d<a)){
            res++;
        }
    }
    cout<<res;
    return 0;
}