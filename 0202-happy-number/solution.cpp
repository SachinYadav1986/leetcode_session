class Solution {
public:
    int squaresumofdigits(int n){
        if(n==0) return 0;
        int digit=n%10;
        return digit*digit+squaresumofdigits(n/10);
    }
    bool isHappyHelper(int n,unordered_set<int> visited){
        if(n==1) return true;
        if(visited.find(n)!=visited.end()) return false;
        visited.insert(n);
        int next=squaresumofdigits(n);
        return isHappyHelper(next,visited);
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        return isHappyHelper(n,visited);
    }
};
