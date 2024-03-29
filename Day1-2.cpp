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
long long toInt(string s){
    long long res=0;
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
    freopen("input/day1.txt","r",stdin);
    freopen("output/day1-2.txt","w",stdout);
    string s;
    long long res=0,cur=0;
    vector<ll> a;
    while(getline(cin,s)){
        if(s.size()==0){
            a.push_back(cur);
            cur=0;
        }
        else{
            cur+=toInt(s);
        }
    }
    sort(a.begin(),a.end());
    cout<<(a[a.size()-1]+a[a.size()-2]+a[a.size()-3])<<"\n";
    return 0;
}