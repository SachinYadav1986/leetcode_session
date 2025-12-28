class Solution {
public:
int findmin(vector<int> &bloomDay){
    int minn=INT_MAX;
    for(int i=0;i<bloomDay.size();i++){
        minn=min(minn,bloomDay[i]);
    }
    return minn;
}   
    int findmax(vector<int> &bloomDay){
    int maxx=INT_MIN;
    for(int i=0;i<bloomDay.size();i++){
        maxx=max(maxx,bloomDay[i]);
    }
    return maxx;
}   
    bool findminimumdays(vector<int> &bloomDay,int m, int k,int mid){
        int bloomday=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                count++;
            }
            else{
                bloomday+=count/k;
                count=0;
            }
        }
    bloomday+=count/k;
    if(bloomday>=m) return true;
    else{
        return false;
    }   
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int low=findmin(bloomDay);
        int high=findmax(bloomDay);
        int answer=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(findminimumdays(bloomDay,m,k,mid)){
                answer=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return answer;
    }
};
