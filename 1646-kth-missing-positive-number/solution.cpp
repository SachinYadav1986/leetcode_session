class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int missingnum=arr[mid]-mid-1;
            if(k>missingnum){
                low=mid+1;
            }
            else{
                high=mid-1;
            }  
        }
        //->missingnumber=arr[high]+k-arr[high]+high+1
        //->missingnumber=k+high+1=low+k
        int missingnumber=low+k;
        return missingnumber;

    }
};
