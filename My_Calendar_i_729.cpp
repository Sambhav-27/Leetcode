/**

Just maintain the intervals in sorted order.
Use a set to maintain sorted order.

And try to fit it in the list. It will go the place just before its next greater or equal element. (comparing on start, since all elements are non overlapping)

check overlap with the next & previous element.
*/

struct Interval {
    int s,e;
    Interval() {}
    Interval(int s, int e) : s(s), e(e) {}
};

struct comp {
    bool operator()(const Interval &a, const Interval &b) const { // notice the const
        return a.s < b.s; // ascending
    }
};

class MyCalendar {
public:
    
    set<Interval, comp> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        Interval cur = Interval(start, end);
        
        auto nextIter = s.lower_bound(cur); // first greater or equal element
        
        
        if(nextIter != s.end()) {
            Interval next = *nextIter;
            
            if(next.s < cur.e) // overlap with next element
                return 0;
        }
       
        
        if(nextIter != s.begin()) {
            Interval prev = *(--nextIter);
            if(cur.s < prev.e) { // overlap with previous element
                return 0;
            }
        }
        
        s.insert(cur);
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


