class Solution {
public: 

    long long sumSubarrayMins(vector<int>& arr) {
        long long total=0;

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
            total+=left*right*1LL*arr[i];
        }
        return total;        
    }
    long long sumSubarraymax(vector<int> & arr){
        long long total=0;
        stack<int> st1;
        vector<int> pge(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st1.empty() && arr[i]>=arr[st1.top()]){
                st1.pop();
            }
            pge[i]=st1.empty()?-1:st1.top();
            st1.push(i);
        }
        stack<int> st2;
        vector<int> nge(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st2.empty() && arr[i]>arr[st2.top()]){
                st2.pop();
            }
            nge[i]=st2.empty()?arr.size():st2.top();
            st2.push(i);
        }
        for(int i=0;i<arr.size();i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            total+=left*right*1LL*arr[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
     long long maximum=sumSubarraymax(nums);
     long long minimum=sumSubarrayMins(nums);
     long long range=maximum-minimum;
     return range; 
    }
};
