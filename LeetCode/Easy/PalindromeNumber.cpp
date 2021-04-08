//Time Complexity O(log10(N))
//Space Complexity O(log10(N))
class Solution {
public:
    bool isPalindrome(int x) {
        //Special Cases
        if(x<0) return false;
        else if(x==0) return true;
        
        //Find Digits of X
        int copyX = x;
        int digitCounter = 0;
        while(copyX>0){
            copyX/=10;
            digitCounter++;
        }
        
        // Populate array of all digits of X
        int arr[digitCounter];
        int currIndex = 0;
        while(x>0){
            arr[currIndex++] = x%10;
            x/=10;
        }
        
        // Traverse array and compare to check palindrome
        bool ans = true;
        for(int i=0; i<digitCounter/2; i++){
            if(arr[digitCounter-i-1]!=arr[i]) ans = false;
        }
        
        return ans;
    }
};
