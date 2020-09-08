#include <bits/stdc++.h>
using namespace std;
#define N 2002
#define INF 1e9

/*

    dp[i][j]  = choosing exact i items from list having first j items;
    we can either select current item or not;
    select = diagonal value with current item; take max time of each taks in item;
    
    not select = left value;
    
    if j<= i then have to select current item

https://leetcode.com/discuss/interview-question/818100/Google's-Online-Challenge-Coding-Intern-(India)

*/

struct pii {
    int a,b,c,val;
    pii(int a, int b, int c, int val): a(a), b(b), c(c), val(val) {}
    pii(){}
};

int main() {
    
    int i,j,n,m;
    pii v[N],dp[N][N];
    cin>>n>>m;
    
    for(i=0;i<n;++i) {
        int x,y,z;
        cin>>x>>y>>z;
        v[i] = pii(x,y,z,0);
    }
    
    for(i=0; i<=n; ++i){
        for(j=0; j<=m; ++j) {
            dp[i][j] = pii(0,0,0,0);
        }
    }
    
    // for(i=1; i<=m; ++i) {
    //     dp[i][0] = pii(0,0,0,-1);
    // }
    
    
    for(i=1; i<=m; ++i) {
        for(j=1; j<=n; ++j) {
            
            dp[i][j].a = max(dp[i-1][j-1].a, v[j-1].a); // v is 0indexed so j-1
            dp[i][j].b = max(dp[i-1][j-1].b, v[j-1].b);
            dp[i][j].c = max(dp[i-1][j-1].c, v[j-1].c);
            
            
            if(j > i) {
                // now consider left value also
                
                dp[i][j].a = min(dp[i][j].a, dp[i][j-1].a);
                dp[i][j].b = min(dp[i][j].b, dp[i][j-1].b);
                dp[i][j].c = min(dp[i][j].c, dp[i][j-1].c);

            }
            
            dp[i][j].val = dp[i][j].a  + dp[i][j].b + dp[i][j].c;
        }
    }
   
//   for(i=1; i<=m; ++i) {
//       for(j=1; j<=n; ++j) {
//           cout<<dp[i][j].a<<","<<dp[i][j].b<<","<<dp[i][j].c<<"   ";
          
//       }
//       cout<<"\n";
//   }
   cout<<dp[m][n].val<<"\n";
    
	return 0;
}
