#include <bits/stdc++.h>
using namespace std;

void handle_io() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// Calculate the GCD of two numbers
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b); 
}

vector<int> func(int fatherPos, int martinPos, int velFather, int steps) {
    if(martinPos == fatherPos) return {steps, velFather};

    int velMartin = fatherPos - martinPos;
    int lcm = (velFather * velMartin) / gcd(velFather, velMartin);
    int lastStep = steps * velFather;
    int lastPos = fatherPos + lastStep;
    int commonSteps = lastStep / lcm + 1;

    if(commonSteps == 1) velMartin = lastPos - martinPos;

    return {commonSteps, velMartin};
}

void solve() {
    int x, y, z, q;
    cin >> x >> y >> z >> q;
    vector<int> ans = func(x, y, z, q);

    cout << ans[0] << " " << ans[1] << endl;
}

int main() {
    handle_io();
    solve();
    return 0;
}