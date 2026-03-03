class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        for(auto c:s){
            mpp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto c:mpp){
            pq.push({c.second,c.first});
        }
        string res;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            res.append(top.first,top.second);
        }
        return res;
    }
};
