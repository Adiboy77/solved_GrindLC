//We mostly backtrack, when we store a answer in a current temporary data structure and we need to erase that element if it does not gives the answer at end
class Solution {
public:
   public:
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);//We can pick an element unlimited number of times, so also not incrementing the index
        ds.pop_back();//Popping back before the notPick call:-> Backtracking if solution is not found
      }
      //Not picking up
      findCombination(ind + 1, target, arr, ans, ds);

    }
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};
