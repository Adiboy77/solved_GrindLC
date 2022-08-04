"""
May be explore this as well C++ coding ninjas: https://www.codingninjas.com/codestudio/problems/alien-dictionary_630423
https://www.youtube.com/watch?v=6kTZYvNNyps
Notes: 
We're given an already sorted input, so we can use this to our advantage
Here words are sorted on the basis of the first ie most significant different character
We would make graph on the basis of taking strings pairwise & appending the first different characters relation in it.
And if the final graph contains any cycle, then that is a contradiction, so we return ""
And say if our final graph has multiple components, ie multiple topo sorts, then we say that we have multiple solutions & can return any one of them
We cannot directly use DFS, because say for the case: abbc, ac : from a if we jump onto c, then we don't cover the entire nodes, thus we will use 
POST ORDER DFS here, ie pushing the node in the result at last after hitting the base case(which is when the node has no more unvisited adjacent nodes, 
then we add it in our result and backtrack).
So indirectly, we traversed from leaves back on the root
Thus we need to reverse our final string at last, as we used the postorder DFS.
#And we would check for the loop in between as well
#We would use visited to mark the visited nodes till now
#And path, for marking the nodes that have been included in the path
#Time: O(x) : x is the number of different characters including in all the input words
#Postorder DFS would give the same final result irrespective of us starting the DFS from any node
"""
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        adj = {char: set() for word in words for char in word}

        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            minLen = min(len(w1), len(w2))
            if len(w1) > len(w2) and w1[:minLen] == w2[:minLen]:
                return ""
            for j in range(minLen):
                if w1[j] != w2[j]:
                    print(w1[j], w2[j])
                    adj[w1[j]].add(w2[j])
                    break

        visited = {}  # {char: bool} False visited, True current path
        res = []

        def dfs(char):
            if char in visited:
                return visited[char]

            visited[char] = True

            for neighChar in adj[char]:
                if dfs(neighChar):
                    return True

            visited[char] = False
            res.append(char)

        for char in adj:
            if dfs(char):
                return ""

        res.reverse()
        return "".join(res)
