class Solution {
public:
    double myPow(double x, int n) {
        
        double ans=1.0;
        long long m=n;
        
        long long exp=llabs(n);
        while(exp>0){
            if(exp%2==1){
                ans=ans*x;
                exp=exp-1;
            }
            else{
                x=x*x;
                exp=exp/2;
            }
        }
        
        if(m<0){
            ans=1.0/ans;
        }
    return ans;
    }
};
