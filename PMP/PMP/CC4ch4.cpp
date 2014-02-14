#pragma once

#include "classdefs.h"
#include <vector>
#include <queue>
#include <iostream>

void CC4ch4::run() {
}

enum GraphNodeState { UNVISITED, VISITING, VISITED };

struct GraphNode
{
  int node_id;
  vector<GraphNode*> adj_nodes;
  GraphNodeState state;
};

struct Graph
{
  vector<GraphNode*> nodes;
};

bool CC4ch4::searchRoute(Graph* g, GraphNode* start, GraphNode* end) {
  queue<GraphNode*> q;
  for (unsigned i = 0; i < g->nodes.size(); ++i) {
    g->nodes[i]->state = UNVISITED;
  }
  start->state = VISITING;
  q.push(start);
  GraphNode* node = NULL;
  while ( !q.empty() ) {
    node = q.front();
    q.pop();
    for (unsigned i = 0; i < node->adj_nodes.size(); ++i) {
      if (node->adj_nodes[i]->state == UNVISITED) {
        if (node->adj_nodes[i]->node_id == end->node_id)  return true;
        node->adj_nodes[i]->state = VISITING;
        q.push(node->adj_nodes[i]);
      }
    }
    node->state = VISITED;
  }
  return false;
}

struct TreeNode
{
  int data;
  TreeNode* left;
  TreeNode* right;

  TreeNode* parent;

  TreeNode(int val) : data(val), left(NULL), right(NULL) {};
};

TreeNode* CC4ch4::addToTree(vector<int>& arr, int start, int end) {
  if (end < start)  return NULL;

  int mid = (start + end) / 2;
  TreeNode* node = new TreeNode(arr[mid]);
  node->left = addToTree(arr, start, mid - 1);
  node->right = addToTree(arr, mid + 1, end);
  
  return node;
}

TreeNode* CC4ch4::createMinBST(vector<int>& arr) {
  return addToTree(arr, 0, arr.size() - 1);
}

vector< vector<TreeNode*> > CC4ch4::bstToLevelArrays(TreeNode* root) {
  int level = 0;
  vector< vector<TreeNode*> > result;
  vector<TreeNode*> one_level;
  one_level.push_back(root);
  result.push_back(one_level);
  while (true) {
    vector<TreeNode*> one_level;
    for (unsigned i = 0; i < result[level].size(); ++i) {
      if (result[level][i]->left != NULL) one_level.push_back(result[level][i]->left);
      if (result[level][i]->right != NULL) one_level.push_back(result[level][i]->right);
    }
    if ( !one_level.empty() ) {
      result.push_back(one_level);
    } else {
      break;
    }
    ++level;
  }
  return result;
}

TreeNode* CC4ch4::inorderSucc(TreeNode* node) {
  if (node == NULL) return NULL;

  if (node->right != NULL) {
    return leftMostChild(node->right);
  }

  TreeNode* parent = node->parent;
  while (parent != NULL) {
    if (parent->left == node) break;
    node = parent;
    parent = node->parent;
  }

  return parent;
}

TreeNode* CC4ch4::leftMostChild(TreeNode* node) {
  if (node == NULL) return NULL;

  while (node->left != NULL)  node = node->left;
  return node;
}

void CC4ch4::findSum(TreeNode* head, int sum, vector<int> buffer, int level) {
  if (head == NULL) return;
  int tmp = 0;
  buffer.push_back(head->data);
  for (int i = level; i > -1; --i) {
    tmp += buffer[i];
    if (tmp == sum) {
      for (int j = i; j <= level; ++j)  cout << buffer[j] << "";
    }
  }
  vector<int> b1 = buffer;
  vector<int> b2 = buffer;
  findSum(head->left, sum, b1, level + 1);
  findSum(head->right, sum, b2, level + 1);
}

