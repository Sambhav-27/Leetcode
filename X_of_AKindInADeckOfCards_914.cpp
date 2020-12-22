/**

Divide array in subsets such that each subset has only same kind of elements.
Take care of case when n= 1;
else we just need to find gcd of array, if it is not 1 then it is possible

Cases:
a: 1

a: 4

a: 4,4,4,4,6,6,6,6,6,6

a: 1,1,2,2,2,2
*/

#define N 10004

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& a) {
        
        if(a.size() < 2)
            return false;
        
        int f[N] = {0};
        int minl = N;
        for(int i=0; i<a.size(); ++i) {
            f[a[i]]++;
        }
        
        int gcd = 0;
        for(int i=0; i<N; ++i){
            if(f[i] > 0){
               gcd = __gcd(gcd, f[i]);
            }
        }
        
        return gcd!=1;
    }
};
