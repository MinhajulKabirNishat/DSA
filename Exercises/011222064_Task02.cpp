
#include <iostream>
#include <vector>
using namespace std;

bool canCreateHamper(const vector<int>& prices, int S) {
    int n = prices.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(S + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            if (prices[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - prices[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][S];
}

int main() {
    int n, S;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the budget: ";
    cin >> S;


    vector<int> prices(n);
    cout << "Enter the prices of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }



    if (canCreateHamper(prices, S)) {
        cout << "Yes, a gift hamper can be created with the exact budget." << endl;
    } else {
        cout << "No, a gift hamper cannot be created with the exact budget." << endl;
    }

    return 0;
}
