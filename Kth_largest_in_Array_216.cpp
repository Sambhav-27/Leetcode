// min heap: O(nlogk)
// quick select: O(n) but worst case is O(n^2)
// Discard half each time: n+(n/2)+(n/4)..1 = n + (n-1) = O(2n-1) = O(n), because n/2+n/4+n/8+..1=n-1.
// worst case occur when array is sorted & k =1
// [1,1,1,1,1] k=1; here pindex = 4,then 3 then2 then 1 then 0



struct comp {
    bool operator()(const int &a, const int &b) {
        return a >b; // min heap
    }
};

class Solution {
public:
   
    int heapsol(vector<int> &a, int k) {
        priority_queue<int, vector<int>, greater<int>> q; // min heap;// deafult is max heap
        
        for(int i=0; i<a.size(); ++i) {
            if(i < k) {
                q.push(a[i]);
            }
            else {
                if(a[i] <q.top()) 
                    continue;
                q.pop();
                q.push(a[i]);
            }
        }
        return q.top();
    }
    
    int part(vector<int> &a, int s, int e) {
        int n = e-s+1;
        int random = rand() %n;
        swap(a[e], a[s + random]);
        
        int pivot = a[e];
        int pindex = s;
        for(int i=s; i<e; ++i) {
            if(a[i] >= pivot) //desc order
                swap(a[i], a[pindex++]);
        }
        swap(a[pindex], a[e]);
        return pindex;
    }
    
    void quickselect(vector<int> &a, int k, int s, int e) {
        if(s>e)
            return;
        int pindex = part(a, s, e);
        if(pindex > k)
            return quickselect(a, k, s, pindex-1);
        else if(pindex < k)
            return quickselect(a, k, pindex+1, e);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // return heapsol(nums, k);
        
        srand(time(NULL));
        quickselect(nums, k-1, 0, nums.size()-1); // notice k is k-1
        return nums[k-1];
    }
};
