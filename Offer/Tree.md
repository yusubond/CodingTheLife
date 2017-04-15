## 树结构

### 1. 树的子结构

题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构)

题解：

Step1：在树A中找到与B根结点值一样的结点R  
Step2：判断A中以R为根节点的子树是否包含和树B一样的结构  

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL) {
            if(pRoot1->val == pRoot2->val)
                result = HaveTree(pRoot1, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;

    }
    bool HaveTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
    	if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return HaveTree(pRoot1->left, pRoot2->left) && HaveTree(pRoot1->right, pRoot2->right);
    }
};
```

### 2. 二叉树的镜像

题目：

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return ;
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        if(pRoot->left != NULL)
            Mirror(pRoot->left);
        if(pRoot->right != NULL)
            Mirror(pRoot->right);
    }
};
```
