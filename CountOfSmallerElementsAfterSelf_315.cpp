/**
The smaller numbers on the right of a number are exactly those that jump from its right to its left during a stable sort.

So, in the merge step of merge sort, count how many elements from right array were pushed before this element & update this in the original index of the left element.

*/

#define pii pair<int, int>
#define pb push_back
#define f first
#define s second

vector<int> selfCount;

vector<pii> merge(vector<pii> a, vector<pii> b) {
    
    vector<pii> ans;
    int i=0, j=0;
    int n= a.size(), m= b.size();
    
    int rcount = 0;
    while(i<n && j<m) {
        if(a[i].s <= b[j].s) { // remove this equal sign, if we want to count smaller or equal numbers on right
            selfCount[a[i].f] += rcount;
            ans.pb(a[i++]);
        }
        else {
            rcount++;
            ans.pb(b[j++]);
        }
    }
    while(i<n) {
        selfCount[a[i].f] += rcount;
        ans.pb(a[i++]);
    }
    
    while(j<m)
        ans.pb(b[j++]);
    
    return ans;
    
}

void sort(vector<pii> &a) {
    
    if(a.size() <= 1)
        return;
    
    int n = a.size();
    int mid = n/2;
    vector<pii> left,right;
    for(int i=0; i<mid; ++i)
        left.pb(a[i]);
    
    for(int i=mid; i<n; ++i)
        right.pb(a[i]);
    
    sort(left);
    sort(right);
    a = merge(left, right); // don't forget to assign to a;
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        selfCount.assign(nums.size(), 0); // assign sets size to n & all values to 0; resize sets size to n, but only new values are set to 0
        
        vector<pii> a; // index is first, value is second
        for(int i=0; i<nums.size(); ++i)
            a.pb({i, nums[i]});
        
        sort(a);
        
        return selfCount;
    }
};
