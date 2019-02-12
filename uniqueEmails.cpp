// https://leetcode.com/problems/unique-email-addresses/submissions/
// 929. Unique Email Addresses
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        for(int i=0; i<emails.size(); i++){
            string email = "";
            bool atFound = false, plusFound = false;
            for(int j=0; j<emails[i].length(); j++){
                if(emails[i][j] == '@') atFound = true;
                if(atFound) email += emails[i][j];
                if(!atFound && !plusFound){
                    if(emails[i][j] == '+') plusFound = true; 
                    else if(emails[i][j] != '.') email += emails[i][j];
                }
            }
            uniqueEmails.insert(email);
        }
        return uniqueEmails.size();
    }
};