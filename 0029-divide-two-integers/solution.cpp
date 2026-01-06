class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign = true;
        if(dividend<0 && divisor>0) sign=false;
        if(dividend>0 && divisor<0) sign=false;

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long ans=0;
        while(a>=b){
        long long count=0;
            while(a>=(b<<(count+1))){  // b*(2^count)
                count++;
                
            }
        ans+=1LL<<count; // 2^count
        a=a-(b<<count);
        }
        if(sign && ans>INT_MAX) return INT_MAX;
        if(!sign && ans>INT_MAX) return INT_MIN;
        return sign? ans : -ans;

    }
};
