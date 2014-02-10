#pragma once
#include <string>
#include <vector>

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

class CC4ch2 : public Base
{
public:
  void run();

private:

};