class Solution {
public:
    int maxelement(vector<int>& piles){
        int maxx=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxx=max(piles[i],maxx);
        }
        return maxx;
    }
    long long func(vector<int>& piles,int mid){
        long long  totalhours=0;
        
        for(int i=0;i<piles.size();i++){
            totalhours+=(piles[i]+mid-1)/mid;
        }
        return totalhours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1;
        int high=maxelement(piles);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long  totalhours=func(piles,mid);
            if(totalhours<=h){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return ans;
    }
};
