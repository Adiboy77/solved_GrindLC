/*
Iterative approach:
double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0) {
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
            return ((1/x) * myPow(1/x , -(n+1)));//very important line
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return myPow(x*x , n/2);
        if(n % 2 != 0)
            return (x * myPow(x , n - 1));
        return 0.0;//just for the sake of avoiding compiler error
    }
};
