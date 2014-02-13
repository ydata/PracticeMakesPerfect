#pragma once

#include "classdefs.h"
#include <iostream>

void CC4ch8::run() {
  vector<string> perms = getPerms("abcd");
  for (unsigned i = 0; i < perms.size(); ++i) {
    cout << perms[i] << endl;
  }
}

int CC4ch8::fibo(int n) {
  if (n < 0) {
    cout << "Error!\n";
  }
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibo(n - 2) + fibo(n - 1);
}

int CC4ch8::fiboIterative(int n) {
  if (n < 0) {
    cout << "Error!\n";
  }
  if (n == 0) return 0;

  int a = 1;
  int b = 1;
  for (int i = 3; i <= n; ++i) {
    int c = a + b;
    a = b;
    b = c;
  }
  return b;
}

vector<string> CC4ch8::getPerms(string s) {
  vector<string> permutations;
  if (s.length() == 0)  return permutations;
  if (s.length() == 1) {
    permutations.push_back(s);
    return permutations;
  }

  char first = s[0];
  string remainder = s.substr(1);
  vector<string> words = getPerms(remainder);
  for (unsigned i = 0; i < words.size(); ++i) {
    for (unsigned j = 0; j <= words[i].length(); ++j) {
      permutations.push_back( insertCharAt(words[i], first, j) );
    }
  }
  return permutations;
}

string CC4ch8::insertCharAt(string word, char c, int i) {
  string start = word.substr(0, i);
  string end = word.substr(i);
  return start + c + end;
}
