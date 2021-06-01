/*

form a set from a vector:
set<string> s(v.begin(), v.end());

form a vector from a set:
vector<string> a(s.begin(), s.end());

concatenate two vectors:
v.insert(v.end(), b.begin(), b.end()); // inserts b behing v

insert vector elements to a set:
copy(v.begin(), v.end(), inserter(s, s.end())); // inserts all elements of vector v to set s


Question looks simple, but naive approach of comparing every pair won't work.
Consider this example:

[["a","0","1"],["a","2","3"],["a","4","2"],["a","4","1"]]

all 4 sets will be merged in the above.

Use disjoint sets.

associate an id to each list & then merge them.
Later on, form the output from the sets.

*/

#define N 100005

class Solution {
public:
    
    int parent[N], rank[N];
    
    void makeSet(int v) {
        parent[v] = v;
        rank[v] =0;
    }
    
    int findParent(int v) {
        if(parent[v] == v)
            return v;
        return parent[v] = findParent(parent[v]);
    }
    
    void unionset(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        
        if(a != b) {
            if(rank[a] < rank[b])
                swap(a, b);
            // a will always be greater
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        
        int n = a.size();
        vector<vector<string>> ans;
        
        for(int i=0; i<n; ++i) {
            makeSet(i);
        }
        
        for(int i=0; i<n; ++i) {
            
            unordered_set<string> first(a[i].begin(), a[i].end()); // set to check element avaiability in O(1)
            for(int j=i+1; j<n; ++j) {
                
                // compare two lists, if any element matches then we union the lists.
                for(int k=1; k<a[j].size(); ++k) {
                    string s = a[j][k];
                    if(first.find(s) != first.end()) {
                        unionset(i, j);
                        break;
                    }
                }
            }
        }
        

        
        unordered_map<int, set<string>> m; // set is used to  remove duplicate elements.
        unordered_map<int, string> names;
        
        for(int i=0; i<n; ++i) {
            names[i] = a[i][0]; // get the name
            
            int p = findParent(i);
            
            if(m.find(p) == m.end()) { // inserting for fist time
                m[p] = set<string>(a[i].begin()+1, a[i].end());
            }
            else { // insert to end of set
                copy(a[i].begin()+1, a[i].end(), inserter(m[p], m[p].end())); // i behind p
            }
        }
        
        for(auto it: m) {
            set<string> st = it.second;
            
            vector<string> v;
            v.push_back(names[it.first]); // insert the names
            
            copy(st.begin(), st.end(), inserter(v, v.end())); // insert emails
            
            ans.push_back(v);
        }
        
        
        
        // following also works.
        // vector<unordered_set<string>> b(n);
        // vector<string> names(n);
        
        
//         // form a set for every vector
//         for(int i=0; i<n; ++i) {
//             unordered_set<string> s(a[i].begin()+1, a[i].end());
//             names[i] = a[i][0]; // store the first element of every list cause we don't want to sort first element.
//             b[i] = s;
//         }
        
//         for(int i=0; i<n; ++i){
//             int p = findParent(i);
//             copy(a[i].begin()+1, a[i].end(), inserter(b[p], b[p].end())); // add the current element to its parent's set; When p[i] = i then also it's fine cause set won't have duplicate elements
//         }
        
//         // add sets of all parents to output.
//         for(int i=0; i<n; ++i) {
//             if(findParent(i) == i) {
//                 vector<string> v;
//                 v.push_back(names[i]);
//                 v.insert(v.end(), b[i].begin(), b[i].end());
                
//                 sort(v.begin()+1, v.end());
//                 ans.push_back(v);
//             }
//         }
        
        return ans;
    }
};








/**
traverse all the emails-
Create a set for every email.
Union cur email with the first email of this list

So, if we encounter an email again, its id would be same. And we will union it with the first element of that list.
In this way both lists would be unioned.

Also maintain a map of email to name & email to set id

Ex: ["a", "b"]
    ["c", "b"]
    
    Here, first b will be unioned with a & then b will be unioned with c;
    Thus a b c will have a common parent


After all this, just traverse all the emails & put them in their parent's list


Time: nlogn
n = total emails

*/

#define N 100005

class Solution {
public:
    
    // int parent[N], rank[N];
    vector<int> parent, rank;
    
    // void makeSet(int v) {
    //     parent[v] = v;
    //     rank[v] =0;
    // }
    
    // notice this new function we are just inserting new element to our set space
    int getId() {
        int id = parent.size();
        parent.push_back(id);
        rank.push_back(0);
        return id;
    }
    
    int findParent(int v) {
        if(parent[v] == v)
            return v;
        return parent[v] = findParent(parent[v]);
    }
    
    void unionset(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        
        if(a != b) {
            if(rank[a] < rank[b])
                swap(a, b);
            // a will always be greater
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        
        int n = a.size();
        vector<vector<string>> ans;

        unordered_map<string, int> emailToId;
        unordered_map<string, string> emailToName;
        
        for(int i=0; i<n; ++i) {
            for(int j=1; j<a[i].size(); ++j) {
                string email = a[i][j];
                
                if(emailToId.find(email) == emailToId.end()) { // email seen for the first time; create a new set for it
                    emailToId[email] = getId();
                }
                
                emailToName[email] = a[i][0];
                unionset(emailToId[email], emailToId[a[i][1]]); // union with first email of this list
                
            }
        }
        
        
        unordered_map<int, set<string>> m; // set is used to  remove duplicate elements.
        
        // traverse every email and add it to its parent list
        for(auto kv: emailToId) {
            int p = findParent(kv.second);
            m[p].insert(kv.first);
        }
        
       
        // form the answer
        for(auto it: m) {
            
            set<string> st = it.second;
            
            vector<string> v;
            v.push_back(emailToName[*st.begin()]); // insert the names
            
            copy(st.begin(), st.end(), inserter(v, v.end())); // insert emails
            
            ans.push_back(v);
        }

        return ans;
    }
};
