#include "test01.h"

void test01()
{
    vector<int> arr = {3, 2, 1};
    Solution s;
    vector<int> v = s.getLeastNumbers(arr, 2);
    for_each(v.begin(), v.end(), printfor());
}
