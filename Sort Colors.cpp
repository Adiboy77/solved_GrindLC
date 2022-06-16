class Solution {
public:
    void sortColors(vector<int>& arr) {
        /*Constant space but not one pass solution
        int z = 0, o = 0, t = 0, n = nums.size();        
        for(int i = 0; i<n;i++)
        {
            if(nums[i] == 0)
                z++;
            else if(nums[i] == 1)
                o++;
            else 
                t++;
        }
        
        for(int i = 0;i<z;i++)
            nums[i] = 0;
        for(int i = z;i<(o+z);i++)
            nums[i] = 1;
        for(int i = o+z;i<(o+z+t);i++)
            nums[i] = 2;
        return;
    */  
        //One pass constant space: most optimal
    int mid=0, low=0, high = arr.size()-1;
		
        while(mid<=high){
		
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++; mid++;
            }
            else if(arr[mid]==1)
                mid++;
            else if(arr[mid]==2){
                swap(arr[high], arr[mid]);
                high--;
            }
        }
        return;
    }
};
