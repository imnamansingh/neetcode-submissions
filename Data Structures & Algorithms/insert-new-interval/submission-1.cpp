class Solution {
public:
    // int findPivot(vector<vector<int>>& intervals, vector<int>& newInterval){
    //     int count = 0;
    //     for(auto& inter: intervals){
    //         if(inter[0] < newInterval[0]) continue;
    //         else{
    //             if(count > 0 && intervals[count-1][1] >= newInterval[0]){
    //                 intervals[count-1][1] = max(newInterval[1],intervals[count-1][1]);
    //                 return count-1;
    //             }else{
    //                 inter[1] = max(inter[1],newInterval[1]);
    //                 inter[0] = newInterval[0];
    //                 return count;
    //             }
    //         }
    //         count++;
    //     }
    //     int last = intervals.size()-1;
    //     intervals[last][1] = max(intervals[last][1],newInterval[1]);
    //     return last;
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // int count;
        // int count2 = 0;
        // count = findPivot(intervals,newInterval);
        // for(int i = count+1;i<intervals.size();i++){
        //     if(intervals[i][0] <= intervals[count][1]){
        //         intervals[count][1] = max(intervals[count][1],intervals[i][1]);
        //         count2++;

        //     }else{
        //         break;
        //     }
        // }
        // auto it = intervals.begin()+count+1;
        // if(it!=intervals.end()){
        //     intervals.erase(it,it+count2);
        // }
        
        // return intervals;

        

        vector<vector<int>> ans;
        if(!intervals.size() || intervals.back()[1]<newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        bool flag = false;
        for(auto inter: intervals){
            if(inter[1]<newInterval[0]) ans.push_back(inter);
            else{
                if(inter[0]>newInterval[1]){
                    if(!flag){
                        ans.push_back(newInterval);
                        flag = true;
                    }
                    ans.push_back(inter);
                }
                else{
                    
                    newInterval[0] = min(inter[0], newInterval[0]);
                    newInterval[1] = max(inter[1], newInterval[1]);
                    if(!flag){
                        ans.push_back(newInterval);
                        flag = true;
                    }else{
                        ans.back() = newInterval;
                    }
                    
                }
            }
        }
        return ans;
        
    }
};
