#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool canWin(const vector<int>& v, int targetSum) {
    int n = v.size();
    vector<bool> dp(targetSum + 1, false);

    for (int i = 1; i <= targetSum; i++) {
        for (int x : v) {
            if (i >= x && !dp[i - x])
                dp[i] = true;
        }
    }

    return dp[targetSum];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numElements, targetSum;
    cin >> numElements >> targetSum;

    vector<int> v(numElements);
    for (int i = 0; i < numElements; i++) {
        cin >> v[i];
    }

    if (canWin(v, targetSum)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
