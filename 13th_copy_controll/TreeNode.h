#pragma once
#include "../11th_associative_container/include.h"
using namespace std;

class TreeNode
{
public:
	friend void swapLR(TreeNode &l, TreeNode &r) {
		TreeNode *tmp = &l;
		l = r;
		r = *tmp;
		
	}
	TreeNode() : value(string("")), count(0), left(nullptr), right(nullptr) {}
	TreeNode(int count) : value(string("")), count(count), left(nullptr), right(nullptr) {}
	TreeNode(int count, TreeNode *l, TreeNode* r) : value(string("")), count(count) {
		left = l;
		right = r;
	}
	

	TreeNode(const TreeNode& tree) : value(tree.value), count(tree.count) {
		// ���ԭ�ڵ�����ӽڵ㲻Ϊ�գ��ݹ�ش����µ����ӽڵ�
		if (tree.left)
			left = new TreeNode(*tree.left);
		else left = nullptr;

		// ���ԭ�ڵ�����ӽڵ㲻Ϊ�գ��ݹ�ش����µ����ӽڵ�
		if (tree.right)
			right = new TreeNode(*tree.right);
		else right = nullptr;
	}

private:
	string value;
	int count;
	TreeNode* left;
	TreeNode* right;
};


class BinStrTree {
public:
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree& bst) {
		TreeNode* tmp = bst.root;
		delete root;
		root = tmp;
	}
	
private:
	TreeNode* root;
};
