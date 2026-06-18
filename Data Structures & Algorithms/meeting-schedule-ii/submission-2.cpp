/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        multiset<int, greater<int>> ans;
        sort(intervals.begin(),intervals.end(),[](auto& a, auto&b){
            if(a.end == b.end) return a.start<b.start;
            return a.end<b.end;
        });

        for(auto inter: intervals){
            if(ans.empty()){
                ans.insert(inter.end);
                continue;
            }
            bool flag = false;
            for(auto& meet: ans){
                if(meet <= inter.start){
                    auto it = ans.find(meet);
                    ans.erase(it);
                    ans.insert(inter.end);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.insert(inter.end);
            }
            
        }
        return ans.size();
    }
};
