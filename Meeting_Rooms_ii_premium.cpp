/*

https://www.lintcode.com/problem/meeting-rooms-ii/
Time: nlogk

k = min rooms required

sort intervals by start time.
For every interval, check if there is an interval finishing befor start of this interval.
If yes, then this interval can take that room. Else we need a new room.

Maintain a min heap of interval based on their end time.

If for cur interval, heap top <= cur interval start
then we pop & insert this interval.
else
we just insert this interval which means adding a new room.

Take care when q is empty.

At the end total intervals in heap == rooms required

*/

struct comp {
    bool operator() (const Interval& a, const Interval &b) {
        return a.end > b.end; // min heap
    }
};

bool sortcomp(Interval a, Interval b) {
    return a.start < b.start; // sort by start time
}
class Solution {
public:
    
    int minMeetingRooms(vector<Interval> &intervals) {

        sort(intervals.begin(), intervals.end(), sortcomp);
        priority_queue<Interval, vector<Interval>, comp> q;

        for(auto interval: intervals) {
            if(q.empty()) {
                q.push(interval);
                continue;
            }
            Interval p = q.top();

            if(p.end <= interval.start) {
                q.pop();
            }
            q.push(interval);
        }
        return q.size();
    }
};
