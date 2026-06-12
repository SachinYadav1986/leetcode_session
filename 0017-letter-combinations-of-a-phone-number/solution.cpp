class Solution {
public:
    void gen(int index,string digits, string current, vector<string> &ans, map<int , vector<char> >mpp){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        int digit=digits[index]-'0';
        for(char ch: mpp[digit]){
            gen(index+1,digits,current+ch,ans,mpp);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int , vector<char> >mpp;
        mpp[2]={'a','b','c'};
        mpp[3]={'d','e','f'};
        mpp[4]={'g','h','i'};
        mpp[5]={'j','k','l'};
        mpp[6]={'m','n','o'};
        mpp[7]={'p','q','r','s'};
        mpp[8]={'t','u','v'};
        mpp[9]={'w','x','y','z'};
    
    vector<string> ans;
    gen(0,digits,"",ans,mpp);
    return ans;
    }
};
