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
        if(s[i]>='0'&&s[i]<='9'){
            res*=10;
            res+=(s[i]-'0');
        }
    }
    return res;
}
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day12.txt","r",stdin);
    freopen("output/day12-1.txt","w",stdout);
    vector<string> heightMap;
    string s;
    pair<int,int> start,end;
    while(cin>>s){
        heightMap.push_back(s);
    }
    int n=heightMap.size(),m=heightMap[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(heightMap[i][j]=='S'){
                start=make_pair(i,j);
                heightMap[i][j]='a';
            }
            else if(heightMap[i][j]=='E'){
                end=make_pair(i,j);
                heightMap[i][j]='z';
            }
        }
    }
    queue<pair<int,int>> q; //BFS
    vector<vector<int>> res(n,vector<int>(m,-1));
    q.push(start);
    res[start.first][start.second]=0;
    while(!q.empty()){
        pair<int,int> u=q.front();
        q.pop();
        if(u==end){
            break;
        }
        for(int i=0;i<4;i++){
            int x=u.first+dx[i],y=u.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m
            &&(heightMap[x][y]<=heightMap[u.first][u.second]+1)&&res[x][y]==-1){
                res[x][y]=res[u.first][u.second]+1;
                q.push({x,y});
            }
        }
    }
    cout<<res[end.first][end.second]<<"\n";
    return 0;
}