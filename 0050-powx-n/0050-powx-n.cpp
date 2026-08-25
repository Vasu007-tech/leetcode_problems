class Solution {
public:
    double pow(double x,long long n){
        if(n==0) return 1;
       double half=  pow( x , n/2);
        double result=half*half;
        if(n%2==1){
            result = result*x;
        }
        return result;
    }
    double myPow(double x, int n) {
        long long N=n;
          if (N < 0) {
            return 1 / pow(x, -N);
        }
        return pow(x,n);
    }
};