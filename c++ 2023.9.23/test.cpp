#include "test1.h"

void test()
{
    // vector<int> vsl = {-1, 0, 3, 4, 7, 4, 3, 0, 1, 8};
    // LockingTree klocls(vsl);
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    map<list<int>::const_iterator, int> m;

    cout << m[l.begin()] << endl;
}

int main()
{
    int time = 9;
    int n = 8;
    time %= (n - 1) * 2;
    int s = time < n ? time + 1 : 1;
    cout << s << endl;
    // test();

    return 0;
}
