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
ll res=1e18;
struct Object{
    int type;
    ll size;
    string name;
    vector<Object*> list;
    Object* parent;
    void addObject(Object* a){
        list.push_back(a);
    } 
    Object* goBack(){
        return parent;
    }
    void traverseGetSize(){
        size=0;
        for(int i=0;i<list.size();i++){
            if(list[i]->type==1){
                list[i]->traverseGetSize();
                size+=list[i]->size;
            }
            else{
                size+=list[i]->size;
            }
        }
    }
    void traverseDelete(ll temp){
        if(size>=temp){
            res=min(res,size);
        }
        for(int i=0;i<list.size();i++){
            if(list[i]->type==1){
                list[i]->traverseDelete(temp);
            }
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day7.txt","r",stdin);
    freopen("output/day7-2.txt","w",stdout);
    string s;
    Object* mainFolder=new Object();
    mainFolder->type=1;
    mainFolder->name="/";
    mainFolder->size=0;
    mainFolder->parent=mainFolder;
    Object* cur=mainFolder;
    while(getline(cin,s)){
        if(s[0]=='$'){
            vector<string> parts=split(s);
            if(parts.size()==3){
                if(parts[2]=="/"){
                    continue;
                }
                if(parts[2]==".."){
                    cur=cur->parent;
                }
                else{
                    for(int i=0;i<cur->list.size();i++){
                        if(cur->list[i]->name==parts[2]){
                            cur=cur->list[i];
                            break;
                        }
                    } 
                }
            }
        }
        else{
            vector<string> parts=split(s);
            Object* object=new Object();
            if(parts[0]=="dir"){
                object->type=1;
                object->name=parts[1];
            }
            else{
                object->type=0;
                object->name=parts[1];
                object->size=toInt(parts[0]);
            }
            cur->addObject(object);
            object->parent=cur;
        }
    }
    mainFolder->traverseGetSize();
    ll remain=70000000-(mainFolder->size);
    ll temp=30000000-remain;
    mainFolder->traverseDelete(temp);
    cout<<res;
    return 0;
}