/*
We divide the number in triplets from right to left & then convert each triplet;
from second triplet onwwards we also need to add a suffix of thousand/million/billion


Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

*/
class Solution {
public:
    
    string ones[21]={"","One", "Two", "Three", "Four", "Five", "Six","Seven","Eight","Nine","Ten",     "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};

    string tens[10]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string units[5] = {"Hundred", "Thousand", "Million", "Billion", "Trillion"};

    string vectorToString(vector<string> v) {
        string words;
        for(auto word: v) {
            if(word != "") {
                words += word;
                words += " ";
            }
        }
        if(words.length() > 0) // for 000 or 00 or 0; we returnn ""
            words.pop_back();
        return words;
    }
    
    string convert3digits(string s) {
        reverse(s.begin(), s.end());
        vector<string> ans;

        if(s.length() == 3 && s[0] != '0') {
            ans.push_back(ones[s[0]-'0']);
            ans.push_back(units[0]);
        }

        if(s.length() >= 2) { // length can be 2 or 3
            int last = s.length()-1;
            int num = (s[last-1]-'0') * 10 + s[last]-'0';
            
            if(num == 0)
                return vectorToString(ans);
            
            if(num <= 20) {
                ans.push_back(ones[num]);
            }
            else {
                ans.push_back(tens[s[last-1]-'0']);
                ans.push_back(ones[s[last]-'0']);
            }
        }
        else {
            ans.push_back(ones[s[0]-'0']);
        }

        return vectorToString(ans);
    }
    
    string convert(int n) {
        if(n ==0) // special case
            return "Zero";
        
        string num = to_string(n);
        vector<string> ans;
        
        int i = num.length()-1;
        int tripletNum = 0;
        while(i>=0) {
             
            int j =i;
            string triplet;
            while(j>=0 && i-j <=2) {
                triplet += num[j--];
            }
            
            string cur;
            string convertedTriplet = convert3digits(triplet);
            cur += convertedTriplet;
            if(tripletNum > 0 && convertedTriplet != "") { // for first triplet we do not need a suffix like milltion, billion
                cur += " ";
                cur += units[tripletNum];
            }
            tripletNum++;
            
            ans.push_back(cur);
            
            i-=3;
        }
        
        string words;
        for(int i=ans.size()-1; i>=0; --i) { // triplets are formed from right to left; so we add in reverse
            if(ans[i] != "") {
                words += ans[i];
                words += " ";
            }
        }
        words.pop_back(); // remove last space
        return words;
    }

    string numberToWords(int num) {
        
        return convert(num);
    }
};
