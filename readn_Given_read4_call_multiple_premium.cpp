/*
https://www.lintcode.com/problem/read-n-characters-given-read4-ii-call-multiple-times/
https://ukpnair.medium.com/157-read-n-characters-given-read4-64d61f43c709



*/

#define N 10000
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:

    // this is like a global variable for this class
    string extra;
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        
        int k=0;
        int totalChars = 0;
        
        char temp[4];

        // first use the extra chars of previous run
        if(extra.length() < n) {
            for(int i=0; i<extra.length(); ++i) {
                buf[k++] = extra[i];
                totalChars++;
            }
            extra = "";
        }
        else {
            for(int i=0; i<n; ++i) {
                buf[k++] = extra[i];
                totalChars++;
            }
            extra = extra.substr(n, extra.length());
            return totalChars;
        }

        n -= totalChars;
        int times = n/4;

        for(int i=0; i<times; ++i) {
            int charsRead = read4(temp);
            for(int j=0; j<charsRead; ++j) {
                buf[k++] = temp[j];
                totalChars++;
            }
        }

        int mod = n%4;
        if(!mod)
        return totalChars;

        int charsRead = read4(temp);

        if(mod < charsRead) {
            for(int j=0; j<mod; ++j) {
                buf[k++] = temp[j];
                totalChars++;
            }

            for(int j=mod; j<charsRead; ++j) {
                extra += temp[j];
            }
        }
        else {
            for(int j=0; j<charsRead; ++j) {
                buf[k++] = temp[j];
                totalChars++;
            }
        }

        return totalChars;
    }
};
