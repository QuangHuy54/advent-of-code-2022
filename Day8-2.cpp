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
ll ar[1000][1002][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day8.txt","r",stdin);
    freopen("output/day8-2.txt","w",stdout);
    vector<string> a;
    string s;
    while(cin>>s){
        a.push_back(s);
    }
    ll res=0;
    int n=a.size();
    int m=a[0].size();
    for(int i=0;i<n;i++){
        stack<pair<char,int>> left;
        stack<pair<char,int>> right;
        for(int j=0;j<m;j++){
            while(!left.empty()&&left.top().first<a[i][j]){
                left.pop();
            }
            if(left.empty()){
                ar[i][j][0]=j;
            }
            else{
                ar[i][j][0]=j-left.top().second;
            }
            left.push({a[i][j],j});

        }
        for(int j=m-1;j>=0;j--){
            while(!right.empty()&&right.top().first<a[i][j]){
                right.pop();
            }
            if(right.empty()){
                ar[i][j][1]=m-1-j;
            }
            else{
                ar[i][j][1]=abs(j-right.top().second);
            }
            right.push({a[i][j],j});
        }
    }
    for(int j=0;j<m;j++){
        stack<pair<char,int>> left;
        stack<pair<char,int>> right;
        for(int i=0;i<n;i++){
            while(!left.empty()&&left.top().first<a[i][j]){
                left.pop();
            }
            if(left.empty()){
                ar[i][j][2]=i;
            }
            else{
                ar[i][j][2]=i-left.top().second;
            }
            left.push({a[i][j],i});
        }
        for(int i=n-1;i>=0;i--){
            while(!right.empty()&&right.top().first<a[i][j]){
                right.pop();
            }
            if(right.empty()){
                ar[i][j][3]=n-1-i;
            }
            else{
                ar[i][j][3]=abs(i-right.top().second);
            }
            right.push({a[i][j],i});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res=max(res,ar[i][j][0]*ar[i][j][1]*ar[i][j][2]*ar[i][j][3]);
        }
    }
    cout<<res;
    return 0;
}