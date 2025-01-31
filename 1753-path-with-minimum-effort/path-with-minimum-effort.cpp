class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>diff(n,vector<int>(m,INT_MAX));

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        diff[0][0]=0;
        pq.push({0,{0,0}});


        while(!pq.empty()) {
            auto current = pq.top();
            int differ = current.first;
            int row = current.second.first;
            int col = current.second.second;
            pq.pop();
            if (row == n - 1 && col == m - 1)
                return differ;

            for(int i=0;i<4;i++) {
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int neweff = max(differ, abs(heights[row][col] - heights[nr][nc]));

                    if(neweff < diff[nr][nc]) {
                        diff[nr][nc]=neweff;
                        pq.push({neweff,{nr,nc}});
                    }
                }
            }


        }   
        return 0;  

    }
};