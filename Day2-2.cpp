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
map<char,int> score1;
char result(char a,char b){
    if(b=='Z'){
        if(a=='A') return 'Y';
        if(a=='B') return 'Z';
        return 'X';
    }
    else if(b=='Y'){
        if(a=='A') return 'X';
        if(a=='B') return 'Y';
        return 'Z';
    }
    else{
        if(a=='A') return 'Z';
        if(a=='B') return 'X';
        return 'Y';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day2.txt","r",stdin);
    freopen("output/day2-2.txt","w",stdout);
    score['X']=1;
    score['Y']=2;
    score['Z']=3;
    score1['X']=0;
    score1['Y']=3;
    score1['Z']=6;
    string s;
    int res=0;
    while(getline(cin,s)){
        res+=score[result(s[0],s[2])]+score1[s[2]];
    }
    cout<<res;
    return 0;
}