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
    freopen("input/day4.txt","r",stdin);
    freopen("output/day4-2.txt","w",stdout);
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
