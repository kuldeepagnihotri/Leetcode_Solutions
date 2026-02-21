class Solution {
public:

    // Prime check function
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;

        for (int i = left; i <= right; i++) {

            int num = i;
            int setBits = 0;

            // Convert to binary and count 1 bits
            while (num > 0) {
                if (num % 2 == 1)
                    setBits++;
                num = num / 2;
            }

            // Check if number of set bits is prime
            if (isPrime(setBits))
                count++;
        }

        return count;
    }
};