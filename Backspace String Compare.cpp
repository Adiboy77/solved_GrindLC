/*Java 2 pointer solution: Iterating from back as we then know the amount of chars to skip
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S.charAt(i) == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T.charAt(j) == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j))
                return false;
            // If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        return true;
    }
*/
//Own solution:
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ns = s.length(), nt = t.length();
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '#')
            {
                if(i>0)
                {
                    s.erase(i-1,1);//removes char before #
                    s.erase(i-1,1);//removes #
                    i-=2;//indexing also reduced by 2 as size gets reduced by 2
                }
                  else
                  {
                    s.erase(0,1);//just removing the # as it doesn't contains any char before it
                    i--;//indexing also reduced by 1 as size gets reduced by 1
                  }
            }
        }
         for(int i=0;i<t.length();i++)
        {
            if(t[i] == '#')
            {
                 if(i>0)
                {
                     t.erase(i-1,1);
                    t.erase(i-1,1);
                    i-=2;
                }
                  else
                  {
                    t.erase(0,1);
                      i--;
                  }
            }
        }
     //  cout<<s<<" "<<t<<endl;
        return s == t;
    }
};
