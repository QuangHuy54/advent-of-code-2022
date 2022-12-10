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
pii a[10];
void move(pii H,int pos){
    if(a[pos].first==H.first||a[pos].second==H.second){
        int dis=abs(a[pos].first-H.first)+abs(a[pos].second-H.second);
        if(dis==2){
            if(a[pos].first==H.first){
                a[pos].second=(a[pos].second>H.second ? a[pos].second-1 : a[pos].second+1);
            }
            else{
                a[pos].first=(a[pos].first>H.first ? a[pos].first-1 : a[pos].first+1);
            }
        }
    }
    else{
        int dis=abs(a[pos].first-H.first)+abs(a[pos].second-H.second);
        if(dis==3){
            if(abs(a[pos].second-H.second)==2){
                a[pos].first=H.first;
                a[pos].second=(a[pos].second>H.second ? a[pos].second-1: a[pos].second+1);
            }
            else{
                a[pos].second=H.second;
                a[pos].first=(a[pos].first>H.first ? a[pos].first-1: a[pos].first+1);
            }
        }
        else if(dis==4){
                a[pos].first=(a[pos].first>H.first ? a[pos].first-1: a[pos].first+1);
                a[pos].second=(a[pos].second>H.second ? a[pos].second-1: a[pos].second+1);
        }
    }
    if(pos==9){
        visited.insert(a[9]);
    }
    else{
        move(a[pos],pos+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    pii H(0,0);
    for(int i=1;i<=9;i++){
        a[i].first=a[i].second=0;
    }
    visited.insert({0,0});
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        char direction;
        ss>>direction;
        int n;
        ss>>n;
        for(int i=0;i<n;i++){
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
            move(H,1);
        }
    }
    cout<<visited.size();
    return 0;
}