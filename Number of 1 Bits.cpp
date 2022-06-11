class Solution {
public:
   int hammingWeight(uint32_t n) 
   {
        int count = 0;//count of set bit
        while (n)//iterate until all bits are traversed
        {
            n &= (n - 1);//changes the first set bit from right to 0
            count++;
        }
        return count;
    }
};
//Time: O(k): k is the number of set bits
//Space: O(1)
