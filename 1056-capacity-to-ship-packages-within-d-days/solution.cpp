class Solution {
public:
    int minimumcapacity(vector<int>& weights, int days,int mid){
        int sum=0;
        int day=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                day++;
                sum=weights[i];
            }else{
                sum+=weights[i];
            }
            
        }
        return day;
    }
    int maxcapacity(vector<int>& weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];

        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=maxcapacity(weights);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;

            int totaldays=minimumcapacity(weights,days,mid);
            if(totaldays<=days){
                ans=min(mid,ans);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return ans;
    }
};
