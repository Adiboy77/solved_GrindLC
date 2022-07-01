/*
Brute approach: O(nlogn) time, O(logn) or O(n)space: As with the time complexity, the space complexity of the sorting method used can vary from language to language. C++'s STL, for example, uses QuickSort most of the time but will switch to either HeapSort or InsertionSort depending on the nature of the data. 
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        int t1 = (a[0]*a[0]) + (a[1]*a[1]) , t2 = (b[0]*b[0]) + (b[1]*b[1]);
        return t1 < t2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),comp);
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(points[i]);
        }
        return ans;
    }
};
*/

/*
Explanation of quick select:
Algorithm

Return the result of a QuickSelect algorithm on the points array to kk elements.
In the QuickSelect function:
Repeatedly partition a range of elements in the given array while homing in on the k^{th}k 
th
  element.
In the partition function:
Choose a pivot element. The pivot value will be squared Euclidean distance from the origin to the pivot element and will be compared to the squared Euclidean distance of all other points in the partition.
Start with pointers at the left and right ends of the partition, then while the two pointers have not yet met:
If the value of the element at the left pointer is smaller than the pivot value, increment the left pointer.
Otherwise, swap the elements at the two pointers and decrement the right pointer.
Make sure the left pointer is past the last element whose value is lower than the pivot value.
Return the value of the left pointer as the new pivot index.
Return the first kk elements of the array.
Time: O(n): n+n/2+n/4+....... = 2N
Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();
        while (pivotIndex != k) {
            // Repeatedly partition the vector
            // while narrowing in on the kth element
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    };

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    };

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
    
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};
