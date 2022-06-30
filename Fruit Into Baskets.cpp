//Google Question
class Solution {
public:
    /*
   //Brute Force: Just because it uses a hashmap of size 2
      int totalFruit(vector<int>& fruits) 
    {
        int i = 0, j = 0, k = 2, sz = fruits.size(), maxm = 0 ;
        unordered_map<int, int> umap ;
        
        while(j<sz)
        {
            umap[fruits[j]]++ ;
            
            if(umap.size() <= k)
            {
                maxm = max(maxm, j-i+1) ; j++ ;
            }
            else if(umap.size() > k)
            {
                while(umap.size() > k)
                {
                    umap[fruits[i]]-- ;
                    if(umap[fruits[i]] == 0){ umap.erase(fruits[i]) ; }
                    i++ ;
                }
                j++ ;
            }
        }
        return maxm ;
    }
    */
    
    //Most optimal: O(n) time, O(1) space: 
   int totalFruit(vector<int>& tree) {
        int last_fruit = -1;
        int second_last_fruit = -1;
        int last_fruit_count = 0;
        int curr_max = 0;
        int ans = 0;
        
        for(int fruit : tree) {
            if(fruit==last_fruit || fruit==second_last_fruit) //till now there's atmost 2 types 
                curr_max++;
            else 
                curr_max = last_fruit_count+1;  //when we have encountered the 3rd type             
                                          // so now discard the 1st type and comsider 2nd and 3rd types
                                          //ex.: 2,3,3,4: when we encounter 4, we then take 3,3,4, so its last fruit(ie 3's)count(ie 2) + 1(for the 4) = 3 = curr_max length(3,3,4) = 3 length
            if(fruit==last_fruit) 
                last_fruit_count++;                        
            else{
                last_fruit_count =1;
                second_last_fruit = last_fruit;
                last_fruit = fruit;
            }
            ans = max(ans,curr_max);
        }
        return ans;
    }
};
