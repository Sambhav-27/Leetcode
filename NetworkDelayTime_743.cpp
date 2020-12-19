#define INF 1e9

struct Edge {
    int a,b,w;
    Edge();
    Edge(int a, int b, int w): a(a), b(b), w(w) {}
};

class Solution {
public:
    
    vector<int> bellman(vector<Edge> edges, int N, int src) {
        vector<int> dist(N+1, INF);
        
        dist[src] =0;
        int i = 0;
        while(i < N-1) {
            bool flag = false;
            
            for(auto edge: edges){
                if(dist[edge.a] < INF && edge.w + dist[edge.a] < dist[edge.b]) {
                    dist[edge.b] = edge.w + dist[edge.a];
                    flag = true;
                }
            }
            ++i;
            if(!flag) break;
        }
        return dist;
    }
    
    int networkDelayTime(vector<vector<int>>& a, int N, int src) {
        
        vector<Edge> edges;
        for(auto v: a) {
            edges.push_back(Edge(v[0], v[1], v[2]));
        }
        
        vector<int> dist = bellman(edges, N, src);
        dist[0] = 0;
        int ans = *max_element(dist.begin(), dist.end());
        if(ans == INF)
            ans = -1;
        return ans;
        
    }
};
