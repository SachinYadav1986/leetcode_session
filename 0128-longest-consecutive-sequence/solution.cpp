class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> st;
        int length=1;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        
        for(auto it:st){
            if(st.find(it-1)==st.end()){
               int element=it;
               int count=1;
               while(st.find(element+1)!=st.end()){
                element+=1;
                count+=1;
                length=max(length,count);
               } 
            }
        }
        return length;
    }
};
