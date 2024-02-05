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
    while (ss >> word) {
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
        getline(ss, word, del);
        a.push_back(word);
    }
    return a;
}
int toInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res *= 10;
            res += (s[i] - '0');
        }
    }
    return res;
}
//Brute force solution
struct Item{
    int type; //0=array, 1=number
    vector<Item> arr;
    int number;
    void print(){ //print
        if(type==1){
            cout<<number;
        }
        else{
            cout<<"[";
            for(int i=0;i<arr.size();i++){
                arr[i].print();
                if(i!=arr.size()-1){
                    cout<<",";
                }
            }
            cout<<"]";
        }
    }
    Item convertToList(){
        Item newItem;
        newItem.type=0;
        newItem.arr.push_back((*this));
        return newItem;
    }
};
Item read(string s,int left,int right){
    Item res;
    if(s[left]=='['){
        res.type=0;
        stack<int> open_bracket_index;
        map<int,int> close_bracket_index;
        vector<int> comma_index;
        for(int i=left;i<=right;i++){
            if(s[i]=='['){
                open_bracket_index.push(i);
            }
            else if(s[i]==']'){
                close_bracket_index[open_bracket_index.top()]=i;
                open_bracket_index.pop();
            }
            else if(s[i]==','){
                comma_index.push_back(i);
            }
        }    
        for(int i=left+1;i<right;i++){
            if(s[i]=='['){
                int right_bracket=close_bracket_index[i];
                res.arr.push_back(read(s,i,right_bracket));
                i=right_bracket;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                int right_comma_index=lower_bound(comma_index.begin(),comma_index.end(),i)-comma_index.begin(); //right comma
                if(right_comma_index==comma_index.size()){
                    res.arr.push_back(read(s,i,right-1));
                    break;
                }
                else{
                    int right_comma=comma_index[right_comma_index];
                    res.arr.push_back(read(s,i,right_comma-1));
                    i=right_comma;
                }
            }
        }
    }
    else{
        res.type=1;
        res.number=toInt(s.substr(left,right-left+1));
    }
    return res;
}
int compare(Item res1,Item res2){
    if(res1.type!=res2.type){
        if(res2.type==1){
            return compare(res1,res2.convertToList());
        }
        return compare(res1.convertToList(),res2);
    }
    else{
        if(res1.type==1){
            if(res1.number==res2.number){
                return 0;
            }
            if(res1.number<res2.number){
                return 1;
            }
            return 2;
        }
        int n1=res1.arr.size(),n2=res2.arr.size();
        if(n1==0&&n2==0){
            return 0;
        }
        if(n1!=0&&n2==0){
            return 2;
        }
        if(n1==0&&n2!=0){
            return 1;
        }
        int res_compare=-1;
        for(int i=0;i<min(n1,n2);i++){
            int check=compare(res1.arr[i],res2.arr[i]);
            if(check==1){
                res_compare=1;
                break;
            }
            else if(check==2){
                res_compare=2;
                break;
            }
        }
        if(res_compare==-1){ //check for size
            if(n1==n2){
                return 0;
            }
            else if(n1<n2){
                return 1;
            }
            else{
                return 2;
            }
        }
        return res_compare;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day13.txt", "r", stdin);
    freopen("output/day13-1.txt", "w", stdout);
    string s1,s2;
    int order=1;
    int res=0;
    while(cin>>s1>>s2){
        Item res1=read(s1,0,s1.size()-1);
        Item res2=read(s2,0,s2.size()-1);
        if(compare(res1,res2)<2){
            res+=order;
        }
        order++;
    }
    cout<<res<<"\n";
    return 0;
}