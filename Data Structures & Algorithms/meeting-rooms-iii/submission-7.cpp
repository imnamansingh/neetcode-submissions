class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq1;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq2;
        for(int i = 0;i<n;i++){
            pq2.push({i,{0,0}});
        }
        for(auto meet: meetings){
            if(pq1.empty()){
                auto topM2 = pq2.top();
                pq2.pop();
                pq1.push({meet[1],{topM2.first,1}}); 
                continue;   
            }
            if(meet[0]>=pq1.top().first){
                while(!pq1.empty()  && meet[0]>=pq1.top().first){
                    auto topM1 = pq1.top();
                    pq1.pop();
                    pq2.push({topM1.second.first,{topM1.second.second, topM1.first}});
                }
                auto topMeet2 = pq2.top();
                pq2.pop();
                pq1.push({meet[1],{topMeet2.first,topMeet2.second.first+1}});
            }else{
                if(!pq2.empty()){
                    auto topMeet2 = pq2.top();
                    pq2.pop();
                    pq1.push({meet[1],{topMeet2.first,topMeet2.second.first+1}});
                }else{
                    auto topMeet1 = pq1.top();
                    pq1.pop();
                    int diff = topMeet1.first - meet[0];
                    topMeet1.second.second += 1;
                    topMeet1.first = meet[1]+diff;
                    pq1.push(topMeet1);
                }
            }
        }
        int ans = -1;
        int max = -1;
        while(!pq1.empty()){
            auto topMeet = pq1.top();
            pq1.pop();
            if(topMeet.second.second > max){
                ans = topMeet.second.first;
                max = topMeet.second.second;
            }else if(topMeet.second.second == max){
                ans = min(ans,topMeet.second.first);
            }
        }
        return ans;
    }
};