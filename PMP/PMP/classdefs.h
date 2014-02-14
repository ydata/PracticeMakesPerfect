#pragma once
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Base 
{
public:
  virtual void run() = 0;
};

class CC4ch1 : public Base
{
public:
  void run();

private:
  bool isUniqueChars(string str);
  bool isUniqueCharsN(string str);

  void reverseCharString(char* str);

  void removeDuplicates(char* str);
  void removeDuplicatesHash(char* str);

  bool isAnagram(string s, string t);

  void rotateMatrix(vector< vector<int> >& matrix);
};

struct LinkedListNode;

class CC4ch2 : public Base
{
public:
  void run();

private:
  void deleteDups(LinkedListNode* head);
  void deleteDups2(LinkedListNode* head);

  LinkedListNode* nthToLast(LinkedListNode* head, int n);

  LinkedListNode* addLists(LinkedListNode* l1, LinkedListNode* l2, int carry);

  void destroyLinkedList(LinkedListNode** head);
};

class CC4ch3 : public Base
{
public:
  void run();

private:
  stack<int> sortStack(stack<int>& s);
};

struct Graph;
struct GraphNode;
struct TreeNode;

class CC4ch4 : public Base
{
public:
  void run();

private:
  bool searchRoute(Graph* g, GraphNode* start, GraphNode* end);

  TreeNode* addToTree(vector<int>& arr, int start, int end);
  TreeNode* createMinBST(vector<int>& arr);

  vector< vector<TreeNode*> > bstToLevelArrays(TreeNode* root);

  TreeNode* inorderSucc(TreeNode* node);
  TreeNode* leftMostChild(TreeNode* node);

  void findSum(TreeNode* head, int sum, vector<int> buffer, int level);
};

class CC4ch8 : public Base
{
public:
  void run();

private:
  int fibo(int n);
  int fiboIterative(int);

  vector<string> getPerms(string s);
  string insertCharAt(string word, char c, int i);

  void printPar(int l, int r, string str, int index);

  int makeChange(int n, int denom);
};

class CC4ch9 : public Base
{
public:
  void run();

private:
  int search(vector<int> arr, int x);
};

class CC4ch20 : public Base
{
public:
  void run();

private:
};
