#include "test1.h"

class Solution121
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> answer;
        for (int i = 0; i < people.size(); i++)
        {
            int ls = 0;
            for (int j = 0; j < flowers.size(); j++)
                if (people[i] >= flowers[j][0] && people[i] <= flowers[j][1])
                    ls++;
            if (!ls)
                answer.push_back(ls);
        }
        return answer;
    }
};
class Solutiond1
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> left, right;
        for (vector<int> ls : flowers)
        {
            left.push_back(ls[0]);
            right.push_back(ls[1]);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        for (int &a : people)
            a = (upper_bound(left.begin(), left.end(), a) - left.begin()) -
                (lower_bound(right.begin(), right.end(), a) - right.begin());
        return people;
    }
};
int main()
{
    Solutiond1 s121;
    vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people = {2, 3, 7, 11};
    vector<int> v = s121.fullBloomFlowers(flowers, people);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    // int time = 9;
    // int n = 8;
    // time %= (n - 1) * 2;
    // int s = time < n ? time + 1 : 1;
    // cout << s << endl;
    // test();

    return 0;
}
