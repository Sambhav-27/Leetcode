
/*

Kahn's algo using bfs.

Another question:
https://www.geeksforgeeks.org/check-if-the-given-array-can-be-constructed-uniquely-from-the-given-set-of-subsequences/

Boils down to checking if only one topo sort exists;

Just check if at any point there are multiple sources i.e. queue size is > 1;
Then multiple topo sorts are possible.

Also put a check if ordering rules for all numbers are present;
i.e.
array is [1,2,3,4] & subsequences are: [1,2] [2,3]

here order for 4 is not present, so we return false;
    
*/
vector<int> topoSort(int n, vector<int> gr[]) {
   
   
   queue<int> q;
   int visited = 0;
   int indegree[10005] = {0};
   
   for(int i=0; i<n; ++i) {
       for(int c: gr[i]) {
           indegree[c]++;
       }
   }
   
   // pushing all 0 degree nodes takes care of a forest
   for(int i=0; i<n; ++i) {
       if(indegree[i] == 0)
            q.push(i);
   }
   
   vector<int> ans;
   
   while(!q.empty()) {
       
    //   if(q.size() > 1) { return -1 }
    
       int p = q.front(); q.pop();
       
       ans.push_back(p);
       visited++;
       
       for(int c: gr[p]) {
           indegree[c]--;
           
           if(indegree[c] == 0) {
               q.push(c);
           }
       }
   }
   
   if(visited != n) {
       // topo sort not possible; graph has a cycle;
   }
   
   // here ans would be in reverse order i.e. bigger to smaller
   return ans;
}
