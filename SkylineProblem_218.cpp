/*
https://www.youtube.com/watch?v=gCkbVt166iU

See the example mentinoned in problem. It is good.

Simple line sweep algorithm.
1. For a building (x, y, ht)- form 2 points (x, ht) (y, ht);
2. Just take the max point at every line in the answer.
3.
When you encounter a start point, put it in the data structure(ds). This ds will only store the hts. No need to store Point object.
When you encounter an end point, remove it from the ds.
At every line take the max from the ds, and put it in the answer.
    ans = (x coordinate of current line, max from ds)
    We only take the current max if it is different from the previous max else there is no point in taking it as it will be a redundant point. So we keep a variable to store the previous max without considering current building.
    
    
We just need to take care of cases when start and end of buildings concide & these building can have same/different hts.

sorting criteria:
1. small x first.
2. If X is same then
    if both are starting point -> then larger building first.
    if both are ending point -> then smaller building first.
    If one is start & other is end -> then start wali building first
    
All this can be achieved by simply making the ht of start point as negative and then sorting by x. If x is same the sort by ht.

Consider the cases in the video mentioned above.



*/

#include<bits/stdc++.h>
#define pb push_back

struct Point {
    int x,y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
};

bool comp(Point p1, Point p2) {
    if(p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

class Solution {
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& a) {
        
        vector<Point> points;
        for(auto p: a) {
            points.pb(Point(p[0], -p[2]));
            points.pb(Point(p[1], p[2]));
        }
        
        sort(points.begin(), points.end(), comp);
        vector<vector<int>> ans;
        
        
        multiset<int> s;
        s.insert(0); // insert 0 cause building can be disconnected.
        
        int prevMax = 0, newMax =0;
        for(auto p: points) {
            if(p.y < 0) { // starting point
                s.insert(-p.y); // don't forget this, cause we made it negative intially
            }
            else {
                s.erase(s.find(p.y));
            }
            
            newMax = *s.rbegin(); // rbegin gives iterator pointing to last element.
            if(prevMax != newMax) {
                ans.pb(vector<int>{p.x, newMax});
            
            prevMax = newMax;}
        }
        return ans;
    }
};
