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
        priority_queue<int, vector<int>, greater<int>> ans;
        sort(intervals.begin(),intervals.end(),[](auto& a, auto&b){
            return a.start<b.start;
        });

        for(auto inter: intervals){
            if(ans.empty()){
                ans.push(inter.end);
                continue;
            }
            
            auto topInter = ans.top();
            if(topInter <= inter.start){
                ans.pop();
                ans.push(inter.end);
            }else{
                ans.push(inter.end);
            }
            
        }
        return ans.size();
    }
};
