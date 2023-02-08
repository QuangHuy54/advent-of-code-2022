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
struct monkey{
    vector<ll> intial; //initial items
    vector<map<int,int>> items; //contain modulo results along with items
    pair<char,int> operation;
    ll divisible,monkeyTrue,monkeyFalse,totalInspect;
};
vector<ll> startItems(string s){
    vector<string> splits=split(s,':');
    splits.erase(splits.begin());
    vector<string> items=split(s,',');
    vector<ll> res;
    for(int i=0;i<items.size();i++){
        ll v=toInt(items[i]);
        res.emplace_back(v);
    }
    return res;
}
pair<char,int> operation(string s){
    vector<string> splits=split(s,'d');
    int res;
    if(splits[1][3]=='o'){
        res=-1; //sign for old value
    }
    else{
        res=toInt(splits[1]);
    }
    char operation=splits[1][1];
    return {operation,res};
}
bool compare(monkey a,monkey b){
    return a.totalInspect>b.totalInspect;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day11.txt","r",stdin);
    freopen("output/day11-2.txt","w",stdout);
    vector<monkey> monkeys(8);
    vector<int> divisibles;
    for(int i=0;i<8;i++){
        string s;
        getline(cin,s);
        getline(cin,s);
        monkeys[i].intial=startItems(s);
        getline(cin,s);
        monkeys[i].operation=operation(s);
        getline(cin,s);
        monkeys[i].divisible=toInt(s);
        divisibles.push_back(monkeys[i].divisible);
        getline(cin,s);
        monkeys[i].monkeyTrue=toInt(s);
        getline(cin,s);
        monkeys[i].monkeyFalse=toInt(s);
        monkeys[i].totalInspect=0;
        cin.ignore();
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<monkeys[i].intial.size();j++){
            map<int,int> results;
            for(int k=0;k<divisibles.size();k++){
                results[divisibles[k]]=monkeys[i].intial[j]%divisibles[k];
            }
            monkeys[i].items.push_back(results);
        }
    }
    for(int i=0;i<10000;i++){
        for(int j=0;j<8;j++){
            monkey x=monkeys[j];
            for(int k=0;k<x.items.size();k++){
                map<int,int> worry=x.items[k];
                for(int z=0;z<divisibles.size();z++){
                    if(x.operation.first=='*'){
                        if(x.operation.second==-1){
                            (worry[divisibles[z]]*=worry[divisibles[z]])%=divisibles[z];
                        }
                        else{
                            (worry[divisibles[z]]*=x.operation.second)%=divisibles[z];
                        }
                    }
                    else{
                        (worry[divisibles[z]]+=x.operation.second)%=divisibles[z];
                    }
                }
                if(worry[x.divisible]==0){
                    monkeys[x.monkeyTrue].items.push_back(worry);
                }
                else{
                    monkeys[x.monkeyFalse].items.push_back(worry);
                }
            }
            monkeys[j].totalInspect+=x.items.size();
            monkeys[j].items.clear();
        }
    }
    sort(monkeys.begin(),monkeys.end(),compare);
    cout<<monkeys[0].totalInspect*monkeys[1].totalInspect<<"\n";
    return 0;
}