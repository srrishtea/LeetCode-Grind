class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto& it:times) {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>t(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;

        pq.push({0,k});
        t[k]=0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dis=pq.top().first;
            pq.pop();

            for(auto &iter : adj[node]) {
                int adjnode=iter.first;
                int adjw=iter.second;

                if(dis+adjw<t[adjnode]) {
                    t[adjnode]=dis+adjw;
                    pq.push({t[adjnode],adjnode});
                }

            }
        }

        int max=*max_element(t.begin()+1,t.end());

        if(max==INT_MAX) return -1;

        return max;

    }
};