#include <iostream>

using namespace std;
 
class Solution {
public:
    // complexity: O(log(A)+log(B)) time, O(1) space
    // precondition: 0 <= A, B <= 100,000,000
    int zip(int A, int B) {
        if (A < 0 || A > 100000000) return -1;
        if (B < 0 || B > 100000000) return -1;
 
        int rA = reverse(A);
        int rB = reverse(B);
 
        int zipped = 0;
        // complexity: O(log(A)+log(B))
        do {
            if (A > 0) {
                zipped = zipped*10 + rA%10;
                rA /= 10;
                A /= 10;
            }
 
            if (B > 0) {
                zipped = zipped*10 + rB%10;
                rB /= 10;
                B /= 10;
            }
        } while (A > 0 || B > 0);
 
        if (zipped > 100000000) return -1;
 
        return zipped;
    }
 
private:
    // complexity: O(log(n)) time, O(1) space
    // precondition: n >= 0
    int reverse(int n) {
        int reversed = 0;
        while(n > 0) {
            reversed = reversed*10 + n%10;
            n /= 10;
        }
 
        return reversed;
    }
};
 
int main() {
    Solution sol;
    cout << (1526 == sol.zip(12, 56)) << endl;
    cout << (5162 == sol.zip(56, 12)) << endl;
    cout << (16273845 == sol.zip(12345, 678)) << endl;
    cout << (16273890 == sol.zip(123, 67890)) << endl;
    cout << (11020300 == sol.zip(10000, 123)) << endl;
    cout << (11020345 == sol.zip(100, 12345)) << endl;
    cout << (12000000 == sol.zip(100, 20000)) << endl;
    cout << (12000000 == sol.zip(10000, 200)) << endl;
    cout << (-1 == sol.zip(1000, 10000)) << endl;
 	cin.get();
    return 0;
}
