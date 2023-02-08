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
int ar[1000][1002][4];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day8.txt","r",stdin);
    freopen("output/day8-1.txt","w",stdout);
    vector<string> a;
    string s;
    while(cin>>s){
        a.push_back(s);
    }
    int res=0;
    int n=a.size();
    int m=a[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                ar[i][j][0]=(int)a[i][j];
            }
            else{
                ar[i][j][0]=max((int)a[i][j],ar[i-1][j][0]);
            }
            if(j==0){
                ar[i][j][1]=(int)a[i][j];
            }
            else{
                ar[i][j][1]=max((int)a[i][j],ar[i][j-1][1]);
            }
        }
        for(int j=m-1;j>=0;j--){
            if(j==m-1){
                ar[i][j][2]=(int)a[i][j];
            }
            else{
                ar[i][j][2]=max((int)a[i][j],ar[i][j+1][2]);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(i==n-1){
                ar[i][j][3]=(int)a[i][j];
            }
            else{
                ar[i][j][3]=max((int)a[i][j],ar[i+1][j][3]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0||a[i][j]>ar[i-1][j][0])||(j==0||a[i][j]>ar[i][j-1][1])
            ||(i==n-1||a[i][j]>ar[i+1][j][3])||(j==n-1||a[i][j]>ar[i][j+1][2])){
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}