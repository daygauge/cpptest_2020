#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// 剑指 Offer 07
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = preorder;
        for (int i = 0; i < preorder.size(); i++) // 将中序与其对应索引值记录
            dic[inorder[i]] = i;
        return rebuild(0, 0, inorder.size() - 1); // 调用递归函数，参数为： 当前节点索引 ， 左边界索引 ， 右边界索引
    }
    vector<int> preorder;        // 使前序能够被全局访问
    unordered_map<int, int> dic; // 记录中序以及其对应的索引值
    TreeNode *rebuild(int root, int left, int right)
    {
        if (left > right) // 当越界时则返回空
            return NULL;

        TreeNode *ls = new TreeNode(preorder[root]); // 根据前序遍历创建当前节点值
        int i = dic[preorder[root]];                 // 记录当前节点的中序遍历的索引，用于之后创建新节点时跳过合适位置

        // 往左边创建节点： root前序遍历索引+1 ， 左边界保持不动，将记录的右边界i值-1（移动右边界可详见中序与前序遍历数据位置）
        ls->left = rebuild(root + 1, left, i - 1);

        // 往右边创建节点：由于root值存储的为之前的原值，所以除了+1以外还需要加上 i-left(取得已经过的位置，i为当前中序遍历的位置，left则是当前左边界的位置)。左边界则为当前右边界i值+1，右边界保持为当前right值
        ls->right = rebuild(root + i - left + 1, i + 1, right);

        return ls;
    }
};
/*
         3
    9        20
          15      7
*/
void printup(TreeNode *a)
{
    if (!a)
        return;
    cout << a->val << " ";
    printup(a->left);
    printup(a->right);
}
void test01()
{
    vector<int> v1 = {3, 9, 20, 15, 7};
    vector<int> v2 = {9, 3, 15, 20, 7};
    Solution s;
    printup(s.buildTree(v1, v2));
}

int main()
{
    // test01();
    int b = -5;
    b = -b;
    cout << b << endl;

    return 0;
}
