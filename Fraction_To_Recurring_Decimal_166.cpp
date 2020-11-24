#define lld long long
/**
Test cases: 1/6 2/3 4/333 1/2 negative numbers

If remainder repeats then quotient is reccuring, so we store all intermediate remainders in a map.
*/

class Solution {
public:
    
    void insert(string &s, lld pos) {
        s.insert(pos, "("); // insert string from pos
        s+= ")";
    }
    
    string divide(lld dd, lld div) {
        string ans;
        map<lld, lld> m;
        
        if(dd == 0) return "0";

        // can also multiply div & dd to check if ans is negative but multiplication can overflow.
      
        if(dd< 0 && div >0) {
            ans += "-";
        }
        else if(dd>0 && div <0) {
            ans+= "-";
        }
        
        dd = abs(dd);
        div = abs(div);
        
        ans += to_string(dd/div);
        lld rem = dd%div;
        if(rem != 0) // if perfectly divisble then we don't need decimal
            ans += ".";

        while(rem) {
            
            if(m.find(rem) != m.end()) {
                insert(ans, m[rem]);
                break;
            }
            
            m[rem] = ans.length();
            
            rem *= 10; // this should occur after putting in map cause if you do before then first remainder will never be put into the map; This number will always be less than div here; thus we multiply by 10.
            
            lld quotient = rem/div;
            rem %= div;
            
            ans += to_string(quotient);
        }
        return ans;
        
    }
    
    string fractionToDecimal(int num, int denom) {
        return divide(num, denom);
    }
};
