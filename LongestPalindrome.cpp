class Solution {
public:
    string substr(const string& s, const int& left, const int& right){
        string result = "";
        for(int i=left; i<right; i++)
            result += s[i];
        return result;
    }
    string longestPalindrome(string s) {
        string maxPal = "";
        for(int i=0; i<s.length(); i++){
            int left, right;
            //case 1: palindrome is odd and has center at i
            for(left=i, right=i;   left>-1 && right<s.length() && s[left] == s[right]; left--,right++){ }
            if(right-left-1 > maxPal.length()) maxPal = substr(s, left+1,right);
            //case 2: palindrome is even and has center at (i,i+1)
            for(left=i, right=i+1; left>-1 && right<s.length() && s[left] == s[right]; left--,right++){ }
            if(right-left-1 > maxPal.length()) maxPal = substr(s, left+1,right);
            //case 3: palindrome is even and has center at (i-1,i)
            for(left=i-1, right=i; left>-1 && right<s.length() && s[left] == s[right]; left--,right++){ }
            if(right-left-1 > maxPal.length()) maxPal = substr(s, left+1,right);
        }
        return maxPal;
    }
};