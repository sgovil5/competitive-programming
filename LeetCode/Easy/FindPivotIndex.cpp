class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix[nums.size()+1];
        prefix[0]=0;
        bool found= false;    
        for(int i=1; i<=nums.size(); i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int index;
        for(int i=1; i<=nums.size(); i++){
            if(prefix[i]-prefix[0]==prefix[nums.size()]-prefix[i-1]){
                found= true;
                index=i;
                break;
            }
        }
        if(!found) return -1;
        else return index-1;
    }
};
