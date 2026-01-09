class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                while(!st.empty() && (asteroids[i]+st.top()<0 && st.top()>0)){   
                st.pop();
                }
                if(!st.empty() && st.top()>0 && asteroids[i]+st.top()==0){
                    st.pop();
                    continue;
                }
                if(!st.empty() && st.top()>0) continue;
                st.push(asteroids[i]);
            }else{
                st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
