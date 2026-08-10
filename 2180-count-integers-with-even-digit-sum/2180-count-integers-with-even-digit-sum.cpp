class Solution {
public:
    int countEven(int num) {
        int digitSum = 0, n = num;

        while(n) {
            digitSum+=n%10;
            n/=10;
        }
        return digitSum%2==0 ? num/2: (num-1)/2;
    }
};