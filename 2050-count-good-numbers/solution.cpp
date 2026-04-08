class Solution {
public:
    const int mod=1e9+7;
    long long solution(long long a,long long b){
        if(b==0) return 1;

        long long half=solution(a,b/2);
        long long ans=half*half%mod;
        if(b%2){
            ans=ans*a%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

        return solution(5,even)*solution(4,odd)%mod;   
    }
};
