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
map<char,int> score;
char result(char a,char b){
    if(b=='X'){
        if(a=='A') return 3;
        if(a=='B') return 0;
        return 6;
    }
    else if(b=='Y'){
        if(a=='A') return 6;
        if(a=='B') return 3;
        return 0;
    }
    else{
        if(a=='A') return 0;
        if(a=='B') return 6;
        return 3;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("input/day2.txt","r",stdin);
    freopen("output/day2-1.txt","w",stdout);
    score['X']=1;
    score['Y']=2;
    score['Z']=3;
    string s;
    int res=0;
    while(getline(cin,s)){
        res+=result(s[0],s[2])+score[s[2]];
    }
    cout<<res;
    return 0;
}