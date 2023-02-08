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
vector<string> split(string s)
{
    vector<string> a;
    stringstream ss(s);
    string word;
    while (ss>>word) {
        a.push_back(word);
    }
    return a;
}
vector<string> split(string s, char del)
{
    vector<string> a;
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word,del);
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
    freopen("input/day10.txt","r",stdin);
    freopen("output/day10-2.txt","w",stdout);
    string s;
    vector<pii> order; //{val,completed?}
    order.push_back({0,1});
    while(cin>>s){
        if(s=="noop"){
            order.push_back({0,1});
        }
        else{
            int val;
            cin>>val;
            order.push_back({val,0});
            order.push_back({val,1});
        }
    }
    int X=1;
    string res="";
    for(int i=1;i<order.size();i++){
        if(X-1==(i-1)%40||X==(i-1)%40||X+1==(i-1)%40){
            res+="#";
        }
        else{
            res+=".";
        }
        if(order[i].second==1){
            X+=order[i].first;
        }
        if(i%40==0){
            cout<<res<<"\n";
            res="";
        }
    }
    cout<<res;
    return 0;
}