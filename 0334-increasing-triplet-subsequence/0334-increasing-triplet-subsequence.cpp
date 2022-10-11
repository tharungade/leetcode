class Solution {
    public:   
    bool increasingTriplet(vector<int>& nums) {       
        int  n = nums.size();        
        if(n < 3) return false;          
        int mini = nums[0];      
        for(int i = 1; i < n-1; i++)     
        {          
            if(nums[i] < mini)       
            {                
                int temp = nums[i];      
                nums[i] = 2*nums[i] - mini;
                mini = temp;       
            }        
        }  
        for(auto & i : nums) cout << i << " "; 
        cout << endl;
        int maxi = nums[n-1];     
        for(int i = n-2; i >= 0; i--)        
        {           
            if(nums[i] < mini)  
            {               
                maxi = max(maxi, mini);     
                mini = 2*mini - nums[i];      
            }           
            else{         
                maxi = max(maxi, nums[i]);   
                if(mini < nums[i] && maxi > nums[i])      
                    return true;         
            }       
        }            
        return false;  
    }
};