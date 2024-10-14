/**

https://leetcode.com/problems/task-scheduler/discuss/850752/Easy-to-Understand-Detailed-Explanation

Find freq of each task;

first spread the maxFreq task and leave spaces in between.
A _ _ A _ _ A _ _ A

total such chunks = maxFreq -1;
total idle spots = chunks * size of 1 chunk = chunks * cooldown time = chunks * k

Now try to fit every other task in it. Note that freq of these task <= maxFreq

A B _ A B _ A B _ A B

Now fit C

A B C A B _ A B _ A B

if all spots are utilized then ans = total tasks; all tasks will be appended at end and there won't be any blanks space;
else
ans = total tasks + blanks spots left

Alternative:
Using max heap
https://leetcode.com/problems/task-scheduler/discuss/104501/Java-PriorityQueue-solution-Similar-problem-Rearrange-string-K-distance-apart

*/

struct Node {
    char ch;
    int f;
    Node() {}
    Node(char ch, int f):  ch(ch), f(f) {      
    }
};

struct comp {
    bool operator()(const Node &a, const Node &b) {
        return a.f < b.f; // max heap
    }
};

class Solution {
public:
    
    int fun(vector<char> &a, int k) {
        priority_queue<Node, vector<Node>, comp> q;
        
        int freq[256] = {0};
        for(auto ch: a)
            freq[ch]++;
        
        for(int i=0; i<256; ++i) { //  caution: dont traverse the org array 
            if(freq[i] > 0) {
                q.push(Node(char(i), freq[i]));
            }
        }
        
        int ans = 0;
        
        while(!q.empty()) {
            vector<Node> popped;
            
            int m = k+1; // notice this
            while(!q.empty() && m--) {
                Node p = q.top(); q.pop();
                popped.push_back(p);
                ans++;
            }
            
            for(auto node: popped) {
                if(node.f-1 > 0) { // only push while freq is positive
                    q.push(Node(node.ch, node.f-1));
                }
            }
            
            if(q.size() > 0 && m > 0) // q.size is required cause we don't we idle spots at the end
                ans+= m; // we need to be idle for this many time
        }
        return ans;
    }
    
    int leastInterval(vector<char>& a, int k) {
        
        return fun(a, k);
        
        int i, ans, f[256] ={0};
        for(int i=0; i<a.size(); ++i)
            f[a[i]]++;
        
        int maxFreq = f[0];
        int maxTask = 0;
        for(i=0; i<256; ++i) {
            if(f[i] > maxFreq) {
                maxFreq = f[i];
                maxTask = i;
            }
        }
        
        int chunks = maxFreq -1;
        
        int idleSpots = chunks * k;
        
        for(i=0; i<256; ++i) {
            if(i == maxTask) continue;
            
            // if there are two few chunks, we fit the task at the end;
            idleSpots -= min(f[i], chunks);
        }
        
        if(idleSpots < 1)
            return a.size();
        
        return a.size() + idleSpots;
        
        
    }
};
