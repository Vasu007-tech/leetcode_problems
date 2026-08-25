class Solution {
public:
    long long power(long long base, long long exp) {
        if (exp == 0)
            return 1;

        long long half = power(base, exp / 2);
        long long ans = (half * half) % 1000000007;

        if (exp % 2 == 1)
            ans = (ans * base) % 1000000007;

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % 1000000007;
    }
};