/*** 
 * Author: zephyr
 * Date: 2020-12-03 10:35:09
 * LastEditors: zephyr
 * LastEditTime: 2020-12-03 10:45:39
 * FilePath: \LeetCodeSolution\tree\103_Binary_Tree_Zigzag_Level_Order_Traversal.cpp
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    while(!q.empty())
    {
        vector<int> levelOrder;
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++)
        {
            auto node = q.front();
            q.pop();
            levelOrder.emplace_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(!(level%2))
        {
            reverse(levelOrder.begin(),levelOrder.end());
            res.emplace_back(levelOrder);
        }
        else
        {
            res.emplace_back(levelOrder);
        }
        level += 1;
        
    }
    return res;
}