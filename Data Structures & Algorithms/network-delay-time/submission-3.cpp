class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for(auto edge : times){
            m[edge[0]].push_back({edge[1],edge[2]});

        }
        vector<int> visited(n+1,0);
        visited[k] = 1;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        while(!q.empty()){
            auto [distt, curr] = q.top();
            q.pop();
            if(m.find(curr) != m.end()){
                for(auto [first,second]: m[curr]){
                    
                        if(dist[first] > (second+distt)){
                            dist[first] = (second+distt);
                            q.push({second+distt, first});
                        }
                        
                    
                }
            }
            
        }
        int ans = 0;
        for(auto sum: dist){
            if(sum == INT_MAX) return -1;
            ans = max(ans,sum);
        }
        return ans;
        
    }
};
