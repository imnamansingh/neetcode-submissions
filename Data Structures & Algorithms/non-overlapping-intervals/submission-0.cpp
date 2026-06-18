class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        auto compare = [](vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0]<b[0];
        return a[1]<b[1];
    };
    sort(intervals.begin(),intervals.end(),compare);
        int count = 0;
        int check = -1;
        for(auto inter: intervals){
            if(check == -1){
                check = inter[1];
                continue;
            }
            if(inter[0]<check){
                count++;
            }else{
                check = inter[1];
            }
        }
        return count;
    }
};
