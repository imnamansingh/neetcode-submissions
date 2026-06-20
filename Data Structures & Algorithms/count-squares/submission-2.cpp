class CountSquares {
public:
    unordered_map<int,vector<pair<int,int>>> xaxis,yaxis;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        

        bool flag = false;

        for(auto& [yPoint,fre]: xaxis[x]){
            if(yPoint == y){
                fre++;
                flag = true;
                break;
            }
        }
        if(!flag){
            xaxis[x].push_back({y,1});
            yaxis[y].push_back({x,1});
        }else{
            for(auto& [xPoint,fre]:yaxis[y]){
                if(xPoint == x){
                    fre++;
                }
            }
        }
        return;
    }

    int searchPair(pair<int,int> point1, pair<int,int> point2, int count1){
        int x1 = point1.first,x2 = point2.first,y1 = point1.second,y2 = point2.second;
        int ans = 1 * count1;
        if(xaxis.find(x1) == xaxis.end()) return 0;
        else{
            bool flag = true;
            for(auto& [ypoint,fre]:xaxis[x1]){
                if(ypoint == y1){
                    ans *= fre;
                    flag = false;
                    break;
                }
            }
            if(flag) return 0;
        }
        if(xaxis.find(x2) == xaxis.end()) return 0;
        else{
            bool flag = true;
            for(auto& [ypoint,fre]:xaxis[x2]){
                if(ypoint == y2){
                    ans *= fre;
                    flag = false;
                    break;
                }
            }
            if(flag) return 0;
        }
        return ans;
        
        
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x = point[0];
        int y = point[1];

        int xlength = xaxis[x].size();
        int ylength = yaxis[y].size();

        if(!xlength && !ylength) return 0;
        
        if(!ylength || (xlength && xlength < ylength)){
            for(auto [xpoint, fre]: xaxis[x]){
                int nx = x;
                int ny = xpoint;
                int sideL = abs(ny-y);
                if(sideL == 0) continue;
                pair<int,int> requiredUP1 = {nx+sideL,ny};
                pair<int,int> requiredUP2 = {x+sideL,y};
                pair<int,int> requiredLP1 = {nx-sideL,ny};
                pair<int,int> requiredLP2 = {x-sideL,y};
                int upperCount = searchPair(requiredUP1,requiredUP2,fre);
                int lowerCount = searchPair(requiredLP1,requiredLP2,fre);
                count = count + upperCount + lowerCount;
            }
        }else{
            for(auto [ypoint,fre]: yaxis[y]){
                int nx = ypoint;
                int ny = y;
                int sideL = abs(nx-x);
                if(sideL == 0) continue;
                pair<int,int> requiredUP1 = {nx,ny+sideL};
                pair<int,int> requiredUP2 = {x,y+sideL};
                pair<int,int> requiredLP1 = {nx,ny-sideL};
                pair<int,int> requiredLP2 = {x,y-sideL};
                int upperCount = searchPair(requiredUP1,requiredUP2,fre);
                int lowerCount = searchPair(requiredLP1,requiredLP2,fre);
                count = count + upperCount + lowerCount;
            }

        }
        return  count;

        
    }
};
