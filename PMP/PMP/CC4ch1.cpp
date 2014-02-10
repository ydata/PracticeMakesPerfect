#pragma once

#include "classdefs.h"
#include <iostream>
#include <set>
#include <map>

void CC4ch1::run() {
  //string str("Armstrong announced the reversal in a staff e-mail Saturday.");
  //cout << isUniqueChars(str) << endl;
  //cout << isUniqueCharsN(str) << endl;
  //char str[] = "Armstrong announced the reversal in a staff e-mail Saturday.";
  //reverseCharString(str);
  //removeDuplicates(str);
  //removeDuplicatesHash(str);
  //cout << str << endl;

  /*
  string s = "anagrams";
  string t = "aaagmnrs";
  cout << isAnagram(s, t) << endl;
  */

  int n = 5;
  vector< vector<int> > mat;
  int m[5][5] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}
  };
  for (int i = 0; i < n; ++i) {
    mat.push_back( vector<int>(m[i], m[i] + n) );
  }
  rotateMatrix(mat);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mat[i][j] << '\t';
    }
    cout << endl;
  }
}

bool CC4ch1::isUniqueChars(string str) {
  set<char> existed;
  for (unsigned i = 0; i < str.length(); ++i) {
    set<char>::const_iterator it = existed.find( str.at(i) );
    if ( it != existed.end() )  return false;
    existed.insert( str.at(i) );
  }
  return true;
}

bool CC4ch1::isUniqueCharsN(string str) {
  for (unsigned i = 0; i < str.length(); ++i) {
    char c1 = str.at(i);
    for (unsigned j = i + 1; j < str.length(); ++j) {
      char c2 = str.at(j);
      if (c1 == c2)   return false;
    }
  }
  return true;
}

void CC4ch1::reverseCharString(char* str) {
  if (str == NULL) return;

  int head = 0;
  int end = strlen(str) - 1;
  while (head < end) {
    char tmp = str[head];
    str[head] = str[end];
    str[end] = tmp;
    head++;
    end--;
  }
}

void CC4ch1::removeDuplicates(char* str) {
  if (str == NULL) return;
  int len = strlen(str);
  if (len < 2)  return;

  int tail = 1;
  for (int i = 1; i < len; ++i) {
    int j = 0;
    while (j < tail) {
      if (str[i] == str[j]) break;
      ++j;
    }
    if (j == tail) {
      str[tail] = str[i];
      ++tail;
    }
  }
  str[tail] = 0;
}

void CC4ch1::removeDuplicatesHash(char* str) {
  if (str == NULL) return;
  int len = strlen(str);
  if (len < 2)  return;

  set<char> exists;
  exists.insert(str[0]);
  int tail = 1;
  for (int i = 1; i < len; ++i) {
    if ( exists.find(str[i]) == exists.end() ) {
      exists.insert(str[i]);
      str[tail] = str[i];
      ++tail;
    }
  }
  str[tail] = 0;
}

bool CC4ch1::isAnagram(string s, string t) {
  unsigned len = s.size();
  if (t.size() != len) return false;

  map<char, int> char_count;
  map<char, int>::iterator it;
  char c;
  for (unsigned i = 0; i < len; ++i) {
    c = s.at(i);
    it = char_count.find(c);
    if ( it == char_count.end() ) {
      char_count[c] = 1;
    } else {
      char_count[c]++;
    }
  }
  for (unsigned i = 0; i < len; ++i) {
    c = t.at(i);
    it = char_count.find( t.at(i) );
    if ( it == char_count.end() ) return false;
    char_count[c]--;
    if (char_count[c] == 0) {
      char_count.erase(c);
      if ( char_count.empty() ) {
        return (i == (len - 1) );
      }
    }
  }
  return false;
}

void CC4ch1::rotateMatrix(vector< vector<int> >& matrix) {
  int n = matrix.size();
  for (int layer = 0; layer < n / 2; ++layer) {
    int first = layer;
    int last = n - 1 - layer;
    for (int i = first; i < last; ++i) {
      int offset = i - first;
      int top = matrix[first][i];
      // left -> top
      matrix[first][i] = matrix[last - offset][first];
      // bottom -> left
      matrix[last - offset][first] = matrix[last][last - offset];
      // right -> bottom
      matrix[last][last - offset] = matrix[i][last];
      // top -> right
      matrix[i][last] = top;
    }
  }
}

