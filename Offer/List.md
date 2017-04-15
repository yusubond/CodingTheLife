## 链表

主要的解题思路：

1）对于单链表，当使用链表中节点个数的时候，应想到运用 **两个指针** 间隔来解决。

### 1. 从尾到头打印链表

题目：输入一个链表，从尾到头打印链表每个节点的值。

题解：

```
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p = head;
        vector<int> v;
        while(p != NULL) {
            v.push_back(p->val);
            p = p->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
```

### 2.反转链表

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pReverseHead = NULL;
        ListNode *pNode = pHead;
        ListNode *pPre = NULL;
        while(pNode != NULL) {
            ListNode *pNext = pNode->next;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        pReverseHead = pPre;
        return pReverseHead;

    }
};
```

### 3. 合并两个有序的链表

题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode *pNode1 = pHead1;
        ListNode *pNode2 = pHead2;
        ListNode *pHead = NULL;
        if(pHead1->val <= pHead2->val) {
            pHead = pHead1;
            pNode1 = pNode1->next;
        } else {
            pHead = pHead2;
            pNode2 = pNode2->next;
        }
        ListNode *pList = pHead;
        while(pNode1 != NULL && pNode2 != NULL) {
            if(pNode1->val <= pNode2->val) {
                pList->next = pNode1;
            	pNode1 = pNode1->next;
            } else {
                pList->next = pNode2;
                pNode2 = pNode2->next;
            }
            pList = pList->next;
        }
        while(pNode1 != NULL) {
            pList->next = pNode1;
            pNode1 = pNode1->next;
        }
        while(pNode2 != NULL) {
            pList->next = pNode2;
            pNode2 = pNode2->next;
        }
        return pHead;
    }
};
```

### 4. 输出链表中倒数第k个节点

题目：输入一个链表，输出该链表中倒数第k个结点。

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k <= 0) return NULL;
        ListNode *pFirst = pListHead;
        ListNode *pSecond = NULL;
        unsigned int i = 1;
        while(pFirst != NULL) {
            if(i < k) {
                i++;
                pFirst = pFirst->next;
            } else {
                if(i == k)
                    pSecond = pListHead;
                else
                    pSecond = pSecond->next;
                pFirst = pFirst->next;
                i++;
            }
        }
        return pSecond;

    }
};
```

### 5. 重建二叉树

题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

```
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		int n = pre.size() - 1;
        if(n == 0)
            return NULL;
        return PreIn(pre, vin, 0, 0, n);
    }
private:
    TreeNode* PreIn(vector<int> pre, vector<int> in, int preroot, int instart, int inend) {
        if(instart > inend)
            return NULL;
        TreeNode* root = new TreeNode(pre[preroot]);
        int i = instart;
        while(i < inend && in[i] != pre[preroot]) i++;
        root->left = PreIn(pre, in, preroot + 1, instart, i - 1);
        root->right = PreIn(pre, in, preroot + 1 + i - instart, i + 1, inend);
        return root;
    }
};
```

### 6. 二叉树的深度

题目：输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

题解：

1）只有一个结点，深度为1；  
2）只有左子树，深度为左子树深度+1；同理，右子树也是这样；  
3）既有左子树也有右子树，则深度为左右子树深度的最大值+1；  

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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return left > right ? left + 1 : right + 1;
    }
};
```
