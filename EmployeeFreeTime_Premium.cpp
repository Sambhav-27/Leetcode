/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/*

Accepted on lintcode.
Similar to merge k sorted arrays.
Here we merge k sorted arrays where each element is an interval.

After merging, we can just traverse and find the gaps in it.

o(nk log(k));

Alternative:
Put all intervals in one array and then sort.
Time: O(nk log(nk))

*/


#define pb push_back
#define INF 1e7

struct pii {
    int start, end, index;
    pii(int a, int b, int c) {
        start = a;
        end = b;
        index = c;
    }
};

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.start > b.start;
    }
};

class Solution {
public:

    bool overlaps(Interval a, Interval b) {
        if((a.start == INF && a.end == -INF) || (b.start == INF && b.end == -INF)) { // notice this
            return true;
        }
        if(a.end < b.start || b.end < a.start) {
            return false;
        }
        return true;
    }

    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        
        vector<vector<Interval>> a;
        int total =0;
        for(auto intervals: schedule) {
            vector<Interval> temp;
            for(int i=0; i<intervals.size(); i+=2) {
                total++;
                temp.pb(Interval(intervals[i], intervals[i+1]));
            }
            a.pb(temp);
        }


        int k = a.size(); // total k arrays;
        priority_queue<pii, vector<pii>, comp> q;
        vector<int> pos(k); // will store posn for every vector
 
        for(int i=0; i<k; ++i) {
            q.push(pii(a[i][0].start, a[i][0].end, i));
            pos[i] =1;
        }

        vector<Interval> merged;

        int  i=0;
        Interval cur = Interval(INF, -INF);
        while(i < total) {

            pii p = q.top(); q.pop();
            Interval t = Interval(p.start, p.end);
            int vectorNum = p.index;

            Interval nextInterval = Interval(INF, INF);
            if(pos[vectorNum] < a[vectorNum].size()) {
                nextInterval = a[vectorNum][pos[vectorNum]];
            }
            q.push(pii(nextInterval.start, nextInterval.end, vectorNum));
            
            pos[vectorNum]++;

            i++;

            if(overlaps(cur, t)) {
                cur.start = min(cur.start, t.start);
                cur.end = max(cur.end, t.end);
            }
            else {
                merged.pb(cur);
                cur = t;
            }

        }
        merged.pb(cur);
        
       
       // Now we find empty slots in the intervals
        vector<Interval> ans;

        if(merged.size() == 0) {
            return ans;
        }

        cur = merged[0];

        for(int j=1; j<merged.size(); ++j) {
            if(overlaps(cur, merged[j])) {
                cur.end = merged[j].end;
                continue;
            }
            
            ans.pb(Interval(cur.end, merged[j].start));
            cur = merged[j];
        }



        return ans;


    }
};
