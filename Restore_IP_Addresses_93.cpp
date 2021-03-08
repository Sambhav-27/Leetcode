// good back tracking practice.
// not mentioned in questions: whole input string should be consumed
// time: 3^n; n = tree height


#define pb push_back

class Solution {
public:
    
    string s;
    vector<string> ans;
    
    void add(vector<string> cur) {
        string curstr;
        for(auto x: cur) {
            curstr += x;
            curstr += ".";
        }
        curstr.pop_back();
        ans.pb(curstr);
    }
    
    // leading zeros are not allowed; so if first character is 0 then string size should be 1.
    bool check(string s) { 
        if(s[0] == '0') {
            return s.length() == 1;
        }
        return 1;
    }
    
    void fun(int j, vector<string> cur) {
        if(j== s.length()) {
            if(cur.size() == 4) {
               add(cur);
            }
            return;
        }
        
        if(cur.size() == 4) {
            // add(cur); // cause the whole input string should be consumed.
            return;
        }
        
        string num;
        for(int i=j; i<s.length(); ++i) {
            num += s[i];
            if(num.length() <= 3) {
                if(stoi(num) <= 255 && check(num)) {
                    cur.pb(num);
                    fun(i+1, cur);
                    cur.pop_back();
                }
            }
        }
        
    }
    
    vector<string> restoreIpAddresses(string str) {
        s = str;
        ans.clear();
        
        vector<string> v;
        fun(0, v);
        return ans;
        
    }
};
