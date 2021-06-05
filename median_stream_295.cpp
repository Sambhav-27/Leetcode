class MedianFinder {
public:
    
    // don't use the name as maxheap & minheap cause it gets confusing
    // first half is maxheap; right half is min heao
    priority_queue<int, vector<int>> first; // max heap
    priority_queue<int, vector<int>, greater<int>> second; // min heap
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(first.empty() || num < first.top()) {
            first.push(num);
        }
        else {
            second.push(num);
        }
        
        // make sure that diff of size is never more than 1
        // any of the the heaps can become largere
        if(first.size() > second.size() +1) {
            second.push(first.top()); first.pop();
        }
        else if(second.size() > first.size() + 1) {
            first.push(second.top()); second.pop();
        }
    }
    
    double findMedian() {
        if(first.size() == 0) {
            return -1; // take care of this; if find called on empty array
        }
        
        if(second.size() == first.size()) {
            return (second.top() + first.top()) / 2.0;
        }
        
        if(first.size() > second.size()) {
            return first.top();
        }
        return second.top();
    }
};
