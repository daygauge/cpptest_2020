#include "test01.h"

void test01()
{
    // vector<int> arr = {3, 2, 1};
    // Solution s;
    // vector<int> v = s.getLeastNumbers(arr, 2);
    // for_each(v.begin(), v.end(), printfor());
    test02();
}
void test02()
{
    // Solution9141 s;
    // vector<int> v = {0, 1, 3};
    // cout << s.missingNumber(v) << endl;
    // vector<int> v1 = {110, 120, 130};
    // vector<int> v2 = {210, 220, 230};
    // auto f = [](int a, int b) -> int
    // { return a + b + 10; };
    // cout << f(1, 9) << endl;
    // Solution913 S;
    // vector<int> v = {10, 2};
    // cout << S.minNumber(v) << endl;
    test03();
}
void test03()
{
    // vector<int> v = {14, 15, 16, 22, 53, 60};
    // Solution9161 sls;
    // vector<int> ls = sls.twoSum(v, 76);
    // cout << ls[0] << ls[1] << endl;
    test04();
}
void test04()
{
    // Solution9193 ls;
    // vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // ls.spiralOrder(v);

    // Solution9192 sls;
    // cout << sls.add(3, 5) << endl;

    // Solution9191 s;
    // vector<int> v = {3, 4, 3, 3};
    // cout << s.singleNumber(v) << endl;
    Solution0001 s;
    vector<int> v1 = {1, 0, 0, 0, 0, 1};
    vector<vector<int>> v2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << s.collectTheCoins(v1, v2) << endl;
}
