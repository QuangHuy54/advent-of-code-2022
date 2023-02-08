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
stack<char> ar[12];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day5.txt","r",stdin);
    freopen("output/day5-2.txt","w",stdout);
    string s;
    ll res=0;
    vector<string> a;
    while(getline(cin,s)){
        a.push_back(s);
        if(a.size()==9){
            for(int i=7;i>=0;i--){
                for(int j=1;j<=min(33,(int)a[i].size()-1);j+=4){
                    if(a[i][j]>='A'&&a[i][j]<='Z'){
                        ar[(j-1)/4+1].push(a[i][j]);
                    }
                }
            }
        }
        else{
            if(s.size()>=2&&s[0]=='m'){
                vector<string> parts=split(s);
                ll a1=toInt(parts[1]),b=toInt(parts[3]),c=toInt(parts[5]);
                vector<char> order;
                for(int i=0;i<a1;i++){
                    if(ar[b].size()>0){
                        char k=ar[b].top();
                        ar[b].pop();
                        order.push_back(k);
                    }
                }
                reverse(order.begin(),order.end());
                for(int i=0;i<order.size();i++){
                    ar[c].push(order[i]);
                }
            }
        }
    }
    for(int i=1;i<=9;i++){
        cout<<ar[i].top();
    }
    return 0;
}