
// https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=2023819&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// DP35 【模板】二维前缀和

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    vector<vector<int>> arr(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    // 预处理前缀和矩阵
    vector<vector<long long>> dp(n + 1, vector<long long> (m + 1));
    dp[0][0] = 0, dp[0][1] = 0, dp[1][0] = 0;
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    // 使用前缀和矩阵
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] <<
             endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")