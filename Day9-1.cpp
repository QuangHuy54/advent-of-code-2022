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
set<pii> visited;
void move(pii& H,pii& T,char direction){
    if(direction=='L'){
        H.second--;
    }
    if(direction=='U'){
        H.first--;
    }
    if(direction=='D'){
        H.first++;
    }
    if(direction=='R'){
        H.second++;
    }
    if(T.first==H.first||T.second==H.second){
        int dis=abs(T.first-H.first)+abs(T.second-H.second);
        if(dis==2){
            if(T.first==H.first){
                T.second=(T.second>H.second ? T.second-1 : T.second+1);
            }
            else{
                T.first=(T.first>H.first ? T.first-1 : T.first+1);
            }
        }
    }
    else{
        int dis=abs(T.first-H.first)+abs(T.second-H.second);
        if(dis==3){
            if(direction=='L'){
                T.first=H.first;
                T.second=H.second+1;
            }
            if(direction=='U'){
                T.second=H.second;
                T.first=H.first+1;
            }
            if(direction=='D'){
                T.second=H.second;
                T.first=H.first-1;
            }
            if(direction=='R'){
                T.first=H.first;
                T.second=H.second-1;
            }
        }
    }
    visited.insert(T);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day9.txt","r",stdin);
    freopen("output/day9-1.txt","w",stdout);
    pii H(0,0);
    pii T(0,0);
    visited.insert({0,0});
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        char direction;
        ss>>direction;
        int n;
        ss>>n;
        for(int i=0;i<n;i++){
            move(H,T,direction);
        }
    }
    cout<<visited.size();
    return 0;
}