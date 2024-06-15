
// https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e?tpId=230&tqId=2032484&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196
// DP41 【模板】01背包

// 空间优化
#include <iostream>
#include <string.h>
using namespace std;

const int N = 1010;
int n, V;
int v[N], w[N];
int dp[N];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }

    // 第一问
    // dp[i][j] -- 在前i个位置中选择体积不超过j的最大价值
    // 优化，用上一行的值来推断下一行的值
    for (int i = 1; i <= n; ++i) {
        // for (int j = V; j >= 1; --j) { // 从右往左，防止覆盖
        //     if (j >= v[i]) dp[j] = max(w[i] + dp[j - v[i]], dp[j]);
        // }
        // 优化 --  反正只有一个if语句，还是关于j和v[i]的
        for (int j = V; j >= v[i]; --j) { // 从右往左，防止覆盖
            if (j >= v[i]) dp[j] = max(w[i] + dp[j - v[i]], dp[j]);
        }
    }
    cout << dp[V] << endl;

    // 第二问
    memset(dp, 0, sizeof(dp));
    // 初始化第一行
    for (int j = 1; j <= V; ++j) dp[j] = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = V; j >= v[i]; --j) {
            if ( dp[j - v[i]] != -1)
                dp[j] = max(w[i] + dp[j - v[i]], dp[j]);
        }
    }
    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")


//#include <iostream>
//#include <string.h>
//using namespace std;
//
//const int N = 1010;
//int n, V;
//int v[N], w[N];
//int dp[N][N];
//
//int main() {
//    cin >> n >> V;
//    for (int i = 1; i <= n; ++i) {
//        cin >> v[i] >> w[i];
//    }
//
//    // 第一问
//    // dp[i][j] -- 在前i个位置中选择体积不超过j的最大价值
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= V; ++j) { // 保证1到V都能映射到，当前位置能找到前一个位置的值
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i])
//                dp[i][j] = max(w[i] + dp[i - 1][j - v[i]], dp[i][j]);
//        }
//    }
//    cout << dp[n][V] << endl;
//
//    // 第二问
//    memset(dp, 0, sizeof(dp));
//    // 初始化第一行
//    for (int j = 1; j <= V; ++j) dp[0][j] = -1;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= V; ++j) {
//            dp[i][j] = dp[i - 1][j];
//            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
//                dp[i][j] = max(w[i] + dp[i - 1][j - v[i]], dp[i][j]);
//        }
//    }
//    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
//    return 0;
//}
//// 64 位输出请用 printf("%lld")