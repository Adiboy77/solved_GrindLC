/* 
Follow up:
Pruning ??:
The word “prune” means to reduce something by removing things that are not necessary. So, Prune-and-Search is an excellent algorithmic paradigm for solving various optimization problems. This approach was first suggested by Nimrod Megiddo in 1983. This approach always consists of several iterations. At each iteration, it discards a fraction, say f, of input data and then invokes the same algorithm recursively on the remaining data to solve the problem.

The main idea of this approach is to reduce the search space by pruning a fraction of the input elements and recurse on the remaining valid input elements. After some iterations, the size of input data will become so small that it can be solved by the brute-force method in constant time c’. 
Ex.: Binary search, quick select, etc.

2 very important STL functions used:
find_last_not_of: It searches the string for the first character, from the end of the string, that does not match any of the characters specified in its arguments. 

find_first_not_of function:It searches the string for the first character that does not match any of the characters specified in its arguments. Here we will describe all syntaxes it holds.
Return value : Index of first unmatched character when successful or string::npos if no such character found.
 


Brute DFS: accepted:
bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';//changing that char so that it cannot be used
    string s = word.substr(1);//updating word to be searched
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
    board[i][j] = c;//putting back the value of board for the next iteration or the next call on the dfs by exist function(backtracking)
    return ret;
}
*/

//Optimal DFS with pruning:
class Solution {
 bool dfs(vector<vector<char>> &arr, string word, int k, int r, int c)
    {
        
        if(r>=arr.size()||r<0||c>=arr[0].size()||c<0||arr[r][c] != word[k])
            return false;

            k++;
            if(k==word.size())
                return true;
            arr[r][c]='.';
            bool res =  dfs(arr,word,k,r+1,c) || 
						dfs(arr,word,k,r-1,c) || 
						dfs(arr,word,k,r,c+1) ||
						dfs(arr,word,k,r,c-1);
            
            arr[r][c]=word[k-1];
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& arr, string& word) {
        int R = arr.size(), C = arr[0].size(), N = word.size();

        // Prune #1: the arr cannot contain the word.
        if (N > R * C) return false;

        // Prune #2: the arr does not contain all occurrences of the chars in the word.
        unordered_map<char, int> occ;
        for (auto& row : arr) for (auto& c : row) ++occ[c];
        for (auto& c : word) if(--occ[c] < 0) return false;

        // Prune #3: Find the longest prefix/suffix of the same character. If the longest
        // suffix is longer than the longest prefix, swap the strigns (so we are less
        // likely to have a long prefix with a lot of the same character).??why this pruning
        //And i think above explanation is wrong, it should be if longest prefix is longer than longest suffix, then we reverse the strings.
        /*
        Because doing the below STL operations on the below 2 random strings:
    string word = "aaaaabcdefggggggg";
    string word2 = "aaaaabcdefgg";
    Gave output as:-
    aaaaabcdefggggggg
    ggfedcbaaaaa
        */
        int left = word.find_first_not_of(word[0]);
        int right = N - word.find_last_not_of(word[N - 1]);
        if (left > right) reverse(begin(word), end(word));//reversing only

        for(int i=0;i<arr.size();i++)
            for(int j=0;j<arr[0].size();++j)
                if(dfs(arr,word,0,i,j))
                    return true;
        return false;
    }
    
};
