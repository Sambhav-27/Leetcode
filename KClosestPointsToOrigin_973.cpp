// See quick select time
// average = O(n)
// worst = O(n^2); when? 
// elements on left of pindex are smaller than element at pindex; Not necesaarily sorted.
// doing this in recursion sorts the array;

#define pb push_back
struct Point {
    int x,y,d;
    Point(int x, int y) : x(x), y(y), d(x*x + y*y) {}
};

class Solution {
public:
    
    
    int partition(vector<Point> &a, int s, int e) {
        int p = s;
        int pivot = a[e].d;
        
        for(int i=s; i<e; ++i) { // don't compare the last element, as last is pivot
        
            if(a[i].d < pivot) {
                swap(a[i], a[p++]);
            }
        }
        swap(a[p], a[e]);
        return p;
    }
    void quickSelect(vector<Point> &v, int s, int e, int k) {
        if(s>= e) return;
        
        int p = partition(v, s, e);
        if(p==k) return;
        else if(p > k) 
            quickSelect(v, s, p-1, k);
        else 
            quickSelect(v, p+1, e, k);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<Point> v;
        for(auto p: points) {
            v.pb(Point(p[0], p[1]));
        }
        
        quickSelect(v, 0, v.size()-1, k-1);
        
        vector<vector<int>> ans;
        for(int i=0; i<k; ++i) {
            vector<int> point {v[i].x, v[i].y}; // intilize a vector
            ans.pb(point);
        }
        return ans;
        
    }
};
