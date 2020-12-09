/**
For bulls just compare numbers;
For cows, maintain a fequency of each digit & then check in secret

*/


#define N 256

class Solution {
public:
    string getHint(string secret, string guess) {
        
        // given both lengths are same
        int f1[N] = {0};
        
        bool isABull[10000] = {0};
        int bulls =0, cows = 0;
        for(int i=0; i<secret.length(); ++i) {
            if(secret[i] == guess[i]) {
                bulls++;
                isABull[i] = true;
            }
            else {
                f1[secret[i]]++;
            }
        }
        
        for(int i=0; i<guess.length(); ++i) {ac
            char ch = guess[i];
            if(f1[ch] > 0 && !isABull[i]) {
                cows++;
                f1[ch]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
