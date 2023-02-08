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
    freopen("input/day6.txt","r",stdin);
    freopen("output/day6-1.txt","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        set<char> st;
        bool ok=true;
        for(int j=i;j<i+4;j++){
            if(st.find(s[j])!=st.end()){
                ok=false;
                break;
            }
            else{
                st.insert(s[j]);
            }
        }
        if(ok){
            cout<<i+4;
            return 0;
        }
    }
    return 0;
}