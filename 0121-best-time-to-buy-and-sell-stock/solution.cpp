class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int maxprofit=INT_MIN;
        int minbuying=INT_MAX;
        for(int i=0;i<prices.size()-1;i++){
            int buying=prices[i];
            int selling=prices[i+1];
            minbuying=min(buying,minbuying);
            profit=selling-minbuying;
            maxprofit=max(profit,maxprofit);

        }
        
        return(maxprofit>0)?maxprofit:0;
    }
};
