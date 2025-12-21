class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> ans;
        long long firstelement=1;
        ans.push_back(firstelement);
        for(int i=1;i<rowIndex;i++){
            firstelement=firstelement*(rowIndex-i);
            firstelement=firstelement/i;
            ans.push_back(firstelement);

        }
        return ans;
    }
};
