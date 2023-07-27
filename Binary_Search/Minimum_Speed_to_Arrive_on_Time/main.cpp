#include<bits/stdc++.h>

using namespace std;

class Solution {
    int ans = 0;
    bool check(vector<int> dist, double hour, double speed) {
        int i = 0;
        double time = 0;
        while(time <= hour && i < dist.size() - 1) {
            time+= ceil(dist[i] / speed);
            i++;
        }
        time+= dist[dist.size() - 1] / speed;
        return time <= hour;
    }
    void minSpeedOnTime(vector<int> &dist, int low, int high, double hour) {
        if(hour < dist.size() - 1) return;
        int mid = (low + high) >> 1;
        if(check(dist, hour, mid)) {
            ans = mid;
            minSpeedOnTime(dist, low, mid - 1, hour);
        } else minSpeedOnTime(dist, mid + 1, high, hour);
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        minSpeedOnTime(dist, 0, dist.size() - 1, hour);
        return ans;
    }
};

int main() {}