class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long total=0;
        long long mod=1e9+7;
        vector<int> nse(arr.size());
        stack<int> st1;

        for(int i=arr.size()-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]>=arr[i]) st1.pop();
            nse[i]=st1.empty()?arr.size():st1.top();
            st1.push(i);
        }
        vector<int> psee(arr.size());
        stack<int> st2;
        for(int i=0;i<arr.size();i++){
            while(!st2.empty() && arr[st2.top()]>arr[i]) st2.pop();
            psee[i]=st2.empty()?-1:st2.top();
            st2.push(i);
        }
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return (int)total;        
    }
};
