class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size() == 0) return -1;
        int size = heights.size()*heights[0].size();
        int horSize = heights[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<int> parent(size, -1);
        parent[0] = 0;
        vector<int> ans(size, INT_MAX);
        ans[0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.first;
            int dist = top.second;

            //up
            int up = node-horSize;
            if(up >= 0  && parent[node] != up){
                int currans = max(dist, abs(heights[node/horSize][node%horSize] - heights[up/horSize][up%horSize]));
                if(ans[up] > currans){
                    parent[up] = node;
                    ans[up] = currans;
                    pq.push({up,currans});
                }
                
                //ans[up] = min(ans[up], max(dist, abs(heights[node/horSize][node%horSize] - heights[up/horSize][up%horSize])))
            }

            //right

            int right = node+1;
            if(right%horSize  && parent[node] != right){
                int currans = max(dist, abs(heights[node/horSize][node%horSize] - heights[right/horSize][right%horSize]));
                if(ans[right] > currans){
                    parent[right] = node;
                    ans[right] = currans;
                    pq.push({right,currans});
                }
                //ans[right] = min(ans[right], max(dist, abs(heights[node/horSize][node%horSize] - heights[right/horSize][right%horSize])))
            }

            //down

            int down = node+horSize;
            if(down<size  && parent[node] != down){
                int currans = max(dist, abs(heights[node/horSize][node%horSize] - heights[down/horSize][down%horSize]));
                if(ans[down] > currans){
                    parent[down] = node;
                    ans[down] = currans;
                    pq.push({down,currans});
                }
                //ans[down] = min(ans[down], max(dist, abs(heights[node/horSize][node%horSize] - heights[down/horSize][down%horSize])))
            }

            //left
            int left = node-1;
            if((left+1)%horSize && parent[node] != left){
                int currans = max(dist, abs(heights[node/horSize][node%horSize] - heights[left/horSize][left%horSize]));
                if(ans[left] > currans){
                    parent[left] = node;
                    ans[left] = currans;
                    pq.push({left,currans});
                }
                //ans[left] = min(ans[left], max(dist, abs(heights[node/horSize][node%horSize] - heights[left/horSize][left%horSize])))
            }

        }





        if(ans.back() == INT_MAX) return -1;
        return ans.back();


    }
};