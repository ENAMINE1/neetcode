class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int xdir[4] = {0,0,1,-1};
        int ydir[4] = {1,-1,0,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<vector<int>>cost(n,vector<int>(m,1e9));

        cost[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int c = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            int x = node.first;
            int y = node.second;

            if(c > cost[x][y]){
                continue;
            }

            for(int i=0; i<4; i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];

                if(nx<0 || nx>=n || ny<0 || ny>=m){
                    continue;
                }

                int nc = c + (g[x][y] == i+1 ? 0 : 1);  // add +1 cost for other direction

                if(cost[nx][ny] > nc){
                    cost[nx][ny] = nc;
                    pq.push({nc,{nx,ny}});
                }
            }
            
        }

        return cost[n-1][m-1];
    }
};