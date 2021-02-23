/*

Maintain a vector & an unorderd map where
we push every new value in the vector &
map key = inputValue
map value = position in the vector


for insert:
just insert in vector & insert in map along with the posn.

for delete:
get post of val from map;
Since, deleting from any random place in vector is O(n);
We apply a hack;
We replace value at pos by the last value in vector & delete the last value; (We can do this, since order doesn't matter in the vector);
Also, we change the pos of this last value in the map; & delete the older key

for random:
just return any random index from vector using rand;



*/

class RandomizedSet {
public:
    
    unordered_map<int, int> m;
    vector<int> v;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        m.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end())
            return false;
        
        v.push_back(val);
        m[val] = v.size() -1;
        return true;    
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;
        
        int pos  = m[val];
        int lastVal = v[v.size()-1];

        v[pos] = lastVal;
        m[lastVal] = pos; // don't forget this line; since we moved last val to pos in vector, we also needs to change its pos in the map
        v.pop_back();
          m.erase(val);
        return true;
        
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()% v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
