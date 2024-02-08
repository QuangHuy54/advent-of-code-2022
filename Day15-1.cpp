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
    if(s[0]=='-'){
        res*=-1;
    }
    return res;
}

vector<pii> sensors,beacons;
pii get_range_no_contain(pii sensor,pii beacon, ll y){ //Get range of position cannot contain a beacon for a sensor
    ll dis_min=abs(sensor.first-beacon.first)+abs(sensor.second-beacon.second);
    ll temp=abs(sensor.second-y);
    pii res(-1e18,-1e18); 
    //solve equation: temp+|sensor.x-x|<=dis_min
    if(dis_min-temp<0){
        return res;
    }
    res.first=sensor.first-dis_min+temp;
    res.second=sensor.first+dis_min-temp;
    return res;
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input/day15.txt", "r", stdin);
    freopen("output/day15-1.txt", "w", stdout);
    string s;
    while(getline(cin,s)){
        vector<string> splits_by_equal=split(s,'=');
        pii sensor; //Get sensor position
        vector<string> get_sensor_x=split(splits_by_equal[1],','); 
        sensor.first=toInt(get_sensor_x[0]);
        vector<string> get_sensor_y=split(splits_by_equal[2],':');
        sensor.second=toInt(get_sensor_y[0]);
        pii beacon; //Get beacon position
        vector<string> get_beacon_x=split(splits_by_equal[3],','); 
        beacon.first=toInt(get_beacon_x[0]);
        beacon.second=toInt(splits_by_equal[4]);
        sensors.push_back(sensor);
        beacons.push_back(beacon);
    }
    int n=sensors.size();
    vector<pii> range_cannot_contain; //store range of positions cannot contain a beacon for each sensor
    for(int i=0;i<n;i++){
        pii range_no_contain=get_range_no_contain(sensors[i],beacons[i],2000000);
        if(range_no_contain.first==-1e18){
            continue; //all position can be present for a specific sensor so skip
        }
        range_cannot_contain.push_back(range_no_contain);
    }
    ll res=0;
    sort(range_cannot_contain.begin(),range_cannot_contain.end());
    int m=range_cannot_contain.size();
    vector<ll> max_right_value(m);
    for(int i=0;i<m;i++){
        if(i==0){
            max_right_value[i]=range_cannot_contain[i].second;
        }
        else{
            max_right_value[i]=max(max_right_value[i-1],range_cannot_contain[i].second);         
        }
    }
    vector<pii> result_range; //combine overlap range
    for(int i=0;i<m;i++){
        if(i==0){
            result_range.push_back(range_cannot_contain[i]);
            res+=range_cannot_contain[i].second-range_cannot_contain[i].first+1;
        }
        else{
            if(range_cannot_contain[i].first<=max_right_value[i-1]){
                int k=result_range.size();
                res-=(result_range[k-1].second-result_range[k-1].first+1); //remove old value
                result_range[k-1].second=max(result_range[k-1].second,range_cannot_contain[i].second);
                res+=(result_range[k-1].second-result_range[k-1].first+1); //may not change but easy understanding =))
            }
            else{ //new range
                result_range.push_back(range_cannot_contain[i]); 
                res+=range_cannot_contain[i].second-range_cannot_contain[i].first+1;
            }
        }
    }
    set<pii> existing_devices; //avoid duplicate 
    for(int i=0;i<n;i++){ //filter all existing beacon in range
        if(beacons[i].second==2000000){
            bool found=false;
            for(int j=0;j<result_range.size();j++){
                if(beacons[i].first>=result_range[j].first&&beacons[i].first<=result_range[j].second){
                    found=true;
                    existing_devices.insert(beacons[i]); 
                    break;
                }
            }
        }
        if(sensors[i].second==2000000){
            bool found=false;
            for(int j=0;j<result_range.size();j++){
                if(sensors[i].first>=result_range[j].first&&sensors[i].first<=result_range[j].second){
                    found=true;
                    existing_devices.insert(sensors[i]); 
                    break;
                }
            }
        }
    }
    res-=existing_devices.size();
    cout<<res<<"\n";
    return 0;
}