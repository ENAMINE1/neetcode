class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int xdir[4] = {0,0,1,-1};
        int ydir[4] = {1,-1,0,0};
        deque<pair<int,int>>dq;
        vector<vector<int>>cost(n,vector<int>(m,1e9));

        cost[0][0] = 0;
        dq.push_front({0,0});

        while(!dq.empty()){
            auto node = dq.front();
            dq.pop_front();

            int x = node.first;
            int y = node.second;

            for(int i=0; i<4; i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];

                if(nx<0 || nx>=n || ny<0 || ny>=m){
                    continue;
                }

                int nc = (g[x][y] == i+1 ? 0 : 1);  // add +1 cost for other direction

                if(cost[nx][ny] > cost[x][y] + nc){
                    cost[nx][ny] = cost[x][y] + nc;
                    if(nc == 0) dq.push_front({nx,ny});
                    else dq.push_back({nx,ny});
                }
            }
            
        }

        return cost[n-1][m-1];
    }
};