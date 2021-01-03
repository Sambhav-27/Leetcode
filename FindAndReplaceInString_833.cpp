/**

Just impl.
For each index check if it can be replaced. Sort the indices then.

Time: nlogn
*/
#define N 10004
#define INF 1e9

struct pii {
    int a;
    string src, tar;
    pii() {}
    pii(int a, string src, string tar) : a(a), src(src), tar(tar) {}
};

bool comp(pii a, pii b) {
    return a.a < b.a;
}

class Solution {
public:
  
    bool found(string s, int j, string t) {
        
       for(int i=0; i<t.length() && i+j <s.length(); ++i) {
           if(s[i+j] != t[i] )
               return false;
       }
        return true;
    }
    
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        
        vector<pii> v;
        
        for(int i=0; i<indexes.size(); ++i) {
            if(found(s, indexes[i], sources[i])) {
               v.push_back(pii(indexes[i], sources[i], targets[i]));
            }
            
        }
        
        sort(v.begin(), v.end(), comp);
        
        string ans = "";
        int i=0;
        int j=0;
        while(i < s.length()) {

            int ind = INF;
            if(j < v.size()) {
                ind = v[j].a;
            }
            while(i < ind && i<s.length()) {
                ans += s[i++];
            }
            if(ind != INF) {
                ans += v[j].tar;
                i+= v[j].src.length();
                j++;
            }
        }
        return ans;
        
    }
};
