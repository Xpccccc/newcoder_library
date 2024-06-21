
// https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc?tpId=230&tqId=2032575&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// DP42 【模板】完全背包

#include <iostream>
#include <strings.h>
using namespace std;

const int N = 1010;
int n, V;
int v[N], w[N];
int dp[N];

// 优化
int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
    // dp[i][j] -- 从前i个位置中选出体积不超过j的最大价值
    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= V ; ++j) {// 这里得从左往右 -- 因为dp[i][j]依赖左边和上边
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V] << endl;
    bzero(dp, sizeof(dp));
    // dp[i][j] -- 从前i个位置中选出体积刚好等于j的最大价值
    // 初始化 -- 不能凑成j的话dp[i][j] == -1;
    for (int j = 1; j <= V; ++j) dp[j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= V ; ++j) { // 这里得从左往右
            if (dp[j - v[i]] != -1)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;
}
// 64 位输出请用 printf("%lld")

// #include <iostream>
//#include <strings.h>
//using namespace std;
//
//const int N = 1010;
//int n, V;
//int v[N], w[N];
//int dp[N][N];
//
//int main() {
//    cin >> n >> V;
//    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];
//    // dp[i][j] -- 从前i个位置中选出体积不超过j的最大价值
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= V; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i])
//                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//    }
//    cout << dp[n][V] << endl;
//    bzero(dp, sizeof(dp));
//    // dp[i][j] -- 从前i个位置中选出体积刚好等于j的最大价值
//    // 初始化 -- 不能凑成j的话dp[i][j] == -1;
//    for (int j = 1; j <= V; ++j) dp[0][j] = -1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j <= V; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i] && dp[i][j - v[i]] != -1)
//                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
//        }
//    }
//    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
//}
//// 64 位输出请用 printf("%lld")