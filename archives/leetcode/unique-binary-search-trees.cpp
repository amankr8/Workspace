class Solution {
private:
    map<int, long long> m;
public:
    int numTrees(int n) {
        m[0] = 1;
        m[1] = 1;
        for(int i=2; i<=n; i++) {
            int sum = 0;
            for(int j=0; j<i; j++) {
                sum += m[j]*m[i-1-j];
            }
            m[i] = sum;
        }
        return m[n];
    }
};