class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        long long m=n;
        if(m<0) m=-1.0*n;
        while(m!=0){
            if(m%2==0){
                x=x*x;
                m=m/2;
            }else{
                res=res*x;
                m--;
            }
        }
        if(n<0) res=1.0/res;
        return res;
    }
};
