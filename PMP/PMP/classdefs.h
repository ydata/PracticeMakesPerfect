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
};

class CC4ch3 : public Base
{
public:
  void run();

private:
  stack<int> sortStack(stack<int>& s);
};

class CC4ch4 : public Base
{
public:
  void run();

private:

};
