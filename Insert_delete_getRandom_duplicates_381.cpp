/*

First do the one without duplicates.

Use a vector & a     unordered_map<int, unordered_set<int>> m;

map key = value; Value = positions in vector

insert:
push to vector;
add in the set of m[val];

Remove:
Get set of indices from map[val];
Remove this index from here; Take care if set has only 1 element.

Delete this index in the vector by putting the last element of vector in this position.
Also, update the last elements indices in the map.

Take care of the case when element to be deleted is last in vector.




Another soln using map<int, vector<int>> & vector<pair<int,int>>.
It's a bit complicated.
https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C%2B%2B-128ms-Solution-Real-O(1)-Solution


*/


class RandomizedCollection {
    
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
    
public:
    
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        v.clear();
        m.clear();
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool present = (m.find(val) != m.end());
        
        v.push_back(val);
        m[val].insert(v.size()-1); // we do not need to initialize the set in first iteration unlike java
        return !present;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        
        unordered_set<int> &indices = m[val]; // Notice this; This gets the set by reference; without & it will create a copy of that set
        int index = *indices.begin();
        if( indices.size() == 1) { // if set has only 1 element, delete the key
            m.erase(val);
        }
        else {
             indices.erase(indices.begin());
        }
        
        if(index != v.size()-1) { // only do this if element to delete is not the last element.
            int lastVal = v[v.size()-1];
            int lastPos = v.size()-1;
            v[index] = lastVal;
            
            m[lastVal].erase(lastPos);
            m[lastVal].insert(index);
        }
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()% v.size()]; // make sure vector has at least 1 element.
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
