#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <list>

class LRUCache
{
public:
    map<int, int> m;
    list<int> l;
    int n;
    LRUCache(int capacity)
    {
        n = capacity;
    }
    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;

        for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
        {
            if (*it == key)
            {
                l.erase(it);
                break;
            }
        }
        l.push_front(key);
        return m[key];
    }
    void put(int key, int value)
    {
        if (m.find(key) == m.end())
        {
            m.insert(pair<int, int>(key, value));
            l.push_front(key);
            if (m.size() > n)
            {
                m.erase(l.back());
                l.pop_back();
            }
        }
        else
        {
            m[key] = value;
            for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
            {
                if (*it == key)
                {
                    l.erase(it);
                    break;
                }
            }
            l.push_front(key);
        }
    }
};
// class LockingTree
// {
// public:
//     vector<int> locker;
//     vector<int> parent;
//     vector<vector<int>> children;
//     LockingTree(vector<int> &parent)
//     {
//         int n = parent.size();
//         this->parent = parent;

//         locker.resize(n, 0);
//         children.resize(n);
//         for (int i = 1; i < n; i++)
//             children[parent[i]].emplace_back(i);
//     }

//     bool lock(int num, int user)
//     {
//         if (!locker[num])
//         {
//             locker[num] = user;
//             return true;
//         }
//         return false;
//     }

//     bool unlock(int num, int user)
//     {
//         if (locker[num] == user)
//         {
//             locker[num] = 0;
//             return true;
//         }
//         return false;
//     }

//     bool upgrade(int num, int user)
//     {
//         if (!locker[num] && traversalFather(num) && traversalDescendant(num))
//         {
//             locker[num] = user;
//             return true;
//         }
//         return false;
//     }
//     bool traversalFather(int num)
//     {
//         if (parent[num] == -1)
//             return locker[num] > 0 ? false : true;
//         if (!locker[num])
//             return traversalFather(parent[num]);
//         return false;
//     }
//     bool traversalDescendant(int num)
//     {
//         bool tr = false;
//         for (int ls : children[num])
//         {
//             tr = tr || locker[ls] > 0;
//             locker[ls] = 0;
//             tr = tr || traversalDescendant(ls);
//         }
//         return tr;
//     }
// };
