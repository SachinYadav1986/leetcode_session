class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            int left=i; //odd palindrome
            int right=i;
            while((left>=0 && right<s.size()) && s[left]==s[right]){
                left--;
                right++;
            }
            string temp=s.substr(left+1,right-left-1);  
            if(temp.size()>=res.size()) res=temp;

            left=i; //even palindrome
            right=i+1;
            while((left>=0 && right<s.size()) && s[left]==s[right]){
                left--;
                right++;
            }
            temp=s.substr(left+1,right-left-1);
            if(temp.size()>=res.size()) res=temp;
        }
    return res;
    }
};
