class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });
        int remainingRoom = n;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        for(auto meet: meetings){
            if(pq.empty()){
                pq.push({meet[1],{0,1}});
                remainingRoom--;
                continue;
            }
            auto topM = pq.top();
            if(topM.first <= meet[0]){
                stack<pair<int,pair<int,int>>> st;
                int low = topM.second.first;
                while(!pq.empty() && pq.top().first<=meet[0]){
                    auto topMeet = pq.top();
                    pq.pop();
                    low = min(low,topMeet.second.first);
                    st.push(topMeet);
                }
                while(!st.empty()){
                    auto topMeet = st.top();
                    st.pop();
                    if(topMeet.second.first == low){
                        topMeet.second.second += 1;
                        topMeet.first = meet[1];
                    }
                    pq.push(topMeet);
                }
                

            }else{
                if(remainingRoom){
                    pq.push({meet[1],{n-remainingRoom,1}});
                    remainingRoom--;
                }else{
                    pq.pop();
                    int diff = topM.first - meet[0];
                    topM.second.second += 1;
                    topM.first = meet[1]+diff;
                    pq.push(topM);
                }
            }
        }
        int ans = -1;
        int max = -1;
        while(!pq.empty()){
            auto topMeet = pq.top();
            pq.pop();
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