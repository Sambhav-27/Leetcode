/*

Do a bfs from 1 to n*n;

important info is to convert an index to row & col and get the actual value of the board from those indexes.


*/


struct Pair {
    int vertex, level;
    Pair(int v, int l) {
        vertex = v;
        level = l;
    }
};

class Solution {

    

public:

    queue<Pair> q;
    int n;
    
    vector<vector<int>> a;


    int getValue(int index) {

        int rowFromBottom = (index-1)/n; // 0th index; -1 because numbers start from 1
        int rowFromTop = n - rowFromBottom - 1;

        int col = (index - 1) %n;
        if(rowFromBottom %2 == 1) { // right to left
            col = n - col - 1;
        }

        return a[rowFromTop][col];

    }

    int bfs(int start) {

        vector<bool> visited(n*n+1, 0);

        q.push(Pair(start, 0));
        visited[start] = 1;

        while(!q.empty()) {
            Pair parent = q.front(); q.pop();

            if(parent.vertex == n*n) {
                return parent.level;
            }

            for(int i=1; i<=6; ++i) {
                int child = parent.vertex + i;

                if(child <= n*n) {
                    int actualValue = getValue(child);

                    if (actualValue != -1) { // if it's not -1 then it's a snake or a ladder; then directly add the destination in the queue
                        child = actualValue;
                    }
                    if(!visited[child]) {
                        q.push(Pair(child, parent.level+1));
                        visited[child] =1;
                    }

                }
            }
        }

        return -1;

    }

    int snakesAndLadders(vector<vector<int>>& board) {

        n = board.size();
        a= board;

        return bfs(1);
        
    }
};


--------------







/**
1. You can do it with bfs; Just make sure to add edges of only weight 1; If you add edge of weight 0 then bfs won't work.
2. Here, one extra condition is that one's you take a ladder or a snake, you can't take further ladders/snakes in that turn.
Ex: If a ladder from 2 goes to 17 and there is a ladder at 17, you can't take the ladder at 17 if you came to 17 from a ladder.




*/

#define N 405
#define INF 1e8

struct Node {
    int v, w;
    Node() {}
    Node(int v, int w) : v(v), w(w) {}
};

class Solution {
public:
    
    int gr[N][N];
    bool visited[N];
    
    int bfs(int src, int dst, int tot) {
        queue<Node> q;
        q.push(Node(src, 0));
        
        while(!q.empty()) {
            Node parent = q.front(); q.pop();
            
            visited[parent.v] = 1;
            if(parent.v == dst) {
                return parent.w;
            }
            
            for(int i=1; i<=tot; ++i) {
                if(gr[parent.v][i] != INF) {
                    if(!visited[i]) {
                        q.push(Node(i, parent.w+1));
                    }
                }
            }
        }
        return -1;
    }
    
    void addEdge(vector<vector<int>>& a, int i, int j, int v) {
        int n = a.size();
        
        if(a[i][j] == -1) { // -1 means there is no ladder or snake starting at this point.
            for(int t=1; t<=6; ++t) {
                if(v+t <=n*n) {
                    gr[v][v+t] =1;
                }
            }
        }
        else { // any other value means, that src is this node; dest is the value at this node
            int src = v;
            int dst = a[i][j];
            // in the following loop, we never actually create a ladder from src to dst of 0 edge weight; instead we modify other edges that come to src & that leave src.
            for(int t=1; t<=6; ++t) {
                if(src-t >=1) {
                    gr[src-t][dst] = 1; // any of the previous 6 numbers will directly go to dst.
                    gr[src-t][src] = INF; // any of previous 6 numbers can't come to src
                    // Here, we are removing an edge; so adjacency list will be difficult to maintain
                }
                if(src+t <=n*n) { // also, if you reach src somehow by following another ladder, you can't go to dest, you can just move 6 more steps
                    gr[src][src+t] =1;
                }
            }
        }
    }
    int snakesAndLadders(vector<vector<int>>& a) {
        
        int i,j,t;
        for(i=0; i<N; ++i){
            for(j=0;j<N; ++j)
                gr[i][j] = INF;
        }
        fill(visited, visited+N, 0);
        
        int n = a.size();
        int k=1;
        int dir =0; // left to right
        
        // converting the input to a graph;
        for(i=n-1; i>=0; --i) {
            if(dir == 0) {
                for(j=0;j<n; ++j) {
                    addEdge(a, i, j, k);
                    k++;
                }
                dir = 1;
            }
            else {
                for(j=n-1; j>=0; --j) {
                    addEdge(a, i, j, k);
                    k++;
                }
                dir = 0;
            }
        }
        
        return bfs(1, n*n, n*n);
        
    }
};
