class Solution {
public:
    int minBitFlips(int start, int goal) {
        int getbits=start^goal;
        
        int countbits=0;
        while(getbits!=0){
            getbits=getbits&(getbits-1);
            countbits++;
        }
        return countbits;

    }
};
