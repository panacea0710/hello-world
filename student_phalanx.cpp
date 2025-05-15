#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// 检查坐标是否在矩阵范围内
int ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
int main() {
    int n, m;
    char comma;
    scanf("%d%c%d", &n, &comma, &m);  // 读取矩阵的行数和列数
 
    int g[100][100] = {0};  // 初始化矩阵，假设最大100x100
    char line[1000];
 
    // 读取矩阵数据
    for (int i = 0; i < n; ++i) {
        scanf("%s", line);
        char* token = strtok(line, ",");    // strtok函数返回被分解的第一个子字符串，若无可检索的字符串，则返回空指针
        for (int j = 0; j < m; ++j) {
            if (strcmp(token, "M") == 0) {
                g[i][j] = 1;  // 'M' 表示男生，用1来表示
            }
            token = strtok(NULL, ",");  // 传入的参数应该为NULL，使得strtok函数默认使用上一次未分割完的字符串继续分割 
        }
    }
 
    // 四个方向的位移：水平、垂直、对角线、反对角线
    int d[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int mx = 0;  // 用于存储最长相连男生的数量
 
    // 遍历矩阵的每一个元素
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!g[i][j]) continue;  // 如果当前坐标不是男生，则跳过
            for (int k = 0; k < 4; ++k) {
                int di = i - d[k][0], dj = j - d[k][1];
                if (ok(di, dj, n, m) &&
                        g[di][dj]) continue;  // 如果前一个坐标在范围内且是男生，则跳过
                int c = 1;  // 初始化当前方向相连男生的数量
                di = i + d[k][0], dj = j + d[k][1];
                while (ok(di, dj, n, m) && g[di][dj]) {
                    c++;  // 累加相连男生的数量
                    di += d[k][0], dj += d[k][1];  // 继续移动到下一个坐标
                }
                if (c > mx) mx = c;  // 更新最大相连男生的数量
            }
        }
    }
 
    printf("%d\n", mx);  // 输出结果
    system("pause");
    return 0;
}
#else

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
 
// 检查坐标是否在矩阵范围内
bool ok(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
int main() {
    int n, m;
    char comma;
    cin >> n >> comma >> m;  // 读取矩阵的行数和列数
 
    vector<vector<int>> g(n, vector<int>(m, 0));  // 初始化矩阵
    string line;
    getline(cin, line);  // 读取剩余的换行符
 
    // 读取矩阵数据
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string cell;
        for (int j = 0; j < m; ++j) {
            getline(ss, cell, ',');
            if (cell == "M") {
                g[i][j] = 1;  // 'M' 表示男生，用1来表示
            }
        }
    }
 
    // 四个方向的位移：水平、垂直、对角线、反对角线
    int d[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int mx = 0;  // 用于存储最长相连男生的数量
 
    // 遍历矩阵的每一个元素
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!g[i][j]) continue;  // 如果当前坐标不是男生，则跳过
            for (int k = 0; k < 4; ++k) {
                int di = i - d[k][0], dj = j - d[k][1];
                if (ok(di, dj, n, m) &&
                        g[di][dj]) continue;  // 如果前一个坐标在范围内且是男生，则跳过
                int c = 1;  // 初始化当前方向相连男生的数量
                di = i + d[k][0], dj = j + d[k][1];
                while (ok(di, dj, n, m) && g[di][dj]) {
                    c++;  // 累加相连男生的数量
                    di += d[k][0], dj += d[k][1];  // 继续移动到下一个坐标
                }
                mx = max(mx, c);  // 更新最大相连男生的数量
            }
        }
    }
 
    cout << mx << endl;  // 输出结果
    return 0;
}

#endif