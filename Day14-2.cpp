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
ll toInt(string s) {
    ll res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res *= 10;
            res += (s[i] - '0');
        }
    }
    return res;
}
//Brute force solution
int n, m; //size of matrix
int res = 0;
void fall(int x,int y,vector<vector<int>>& map){
    map[x][y]=2;
    res++;
    if(map[x+1][y]==0){
        fall(x+1,y,map);
    }
    if(map[x + 1][y - 1] == 0){
        fall(x+1,y-1,map);
    }
    if(map[x + 1][y + 1] == 0){
        fall(x+1,y+1,map);
    }    
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day14.txt", "r", stdin);
    freopen("output/day14-2.txt", "w", stdout);
    vector<pii> rocks; //rocks coordinates
    string s;
    ll min_y = 1e9, max_y = 0, max_x = 0; //To scale columns indexes and get matrix size
    while (getline(cin, s)) {
        vector<string> splits = split(s);
        if (splits.size() == 1) {
            vector<string> coordinates = split(splits[0], ',');
            ll x = toInt(coordinates[1]), y = toInt(coordinates[0]);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
            max_x = max(max_x, x);
            rocks.push_back({x, y});
        }
        else {
            for (int i = 2; i < splits.size(); i += 2) { //because of "->"
                vector<string> coordinates_1 = split(splits[i - 2], ',');
                vector<string> coordinates_2 = split(splits[i], ',');
                ll x_1 = toInt(coordinates_1[1]), y_1 = toInt(coordinates_1[0]);
                ll x_2 = toInt(coordinates_2[1]), y_2 = toInt(coordinates_2[0]);
                min_y = min({min_y, y_1, y_2});
                max_y = max({max_y, y_1, y_2});
                max_x = max({max_x, x_1, x_2});
                if (x_1 == x_2) {
                    for (int j = min(y_1, y_2); j <= max(y_1, y_2); j++) {
                        if (j == y_2 && i < splits.size() - 1) continue;
                        rocks.push_back({x_1, j});
                    }
                }
                else {
                    for (int j = min(x_1, x_2); j <= max(x_1, x_2); j++) {
                        if (j == x_2 && i < splits.size() - 1) continue;
                        rocks.push_back({j, y_1});
                    }
                }
            }
        }
    }
    ll max_length=1+(max_x+1)*2+2;
    min_y=500-(max_length-1)/2;
    max_y=500+(max_length-1)/2;
    n = max_x + 3;
    m = max_y - min_y + 1;
    vector<vector<int>> matrix(n, vector<int>(m, 0)); //the map
    for (pii rock : rocks) {
        matrix[rock.first][rock.second - min_y] = 1;
    }
    for(int i=0;i<m;i++){
        matrix[n-1][i]=1;
    }
    fall(0,500-min_y,matrix);
    cout << res << "\n";
    return 0;
}