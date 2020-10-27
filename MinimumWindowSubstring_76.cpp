/**
just impl of window strategy;

first window = first m characters; m = pattern.length();
then check, if all elements not found then expand on right;
else keep on squeezing from left until found
*/

#define N 256
#define INF 1e6
class Solution {
public:
    bool equal(int *a, int *b) {
        for(int i=0;i<N;++i) {
            if(a[i]<b[i]) // notice this is not equal
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        
        
        int i,j,k,l,r,n=s.length(), m = t.length();
        if(n<m) return ""; // don't forget this
        
        int f[N] ={0};
        int org[N] = {0};
        for(i=0;i<m;++i) {
            f[s[i]]++;
            org[t[i]]++;
        }
        
        int start = 0;
        int size = INF;
        
        i=0; j= m-1; // window is from i to j
        while(j<n) {
            while(i<=j && equal(f, org)) {
                if(j-i+1 < size) {
                    size = j-i+1;
                    start = i;
                }
                f[s[i]]--;
                i++;
            }
            j++;
            f[s[j]]++;
            // j++;
        }
        
        if(size == INF) return "";
        return s.substr(start, size);
        
    }
};
