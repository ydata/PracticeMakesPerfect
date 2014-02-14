#pragma once

#include "classdefs.h"
#include <algorithm>
#include <iostream>

using namespace std;

struct AnagramComparator
{
  bool operator()(const string& lhs, const string& rhs) {
    string lhs_copy = lhs;
    string rhs_copy = rhs;
    sort( lhs_copy.begin(), lhs_copy.end() );
    sort( rhs_copy.begin(), rhs_copy.end() );
    return lhs_copy.compare(rhs_copy) < 0;
  }
};

struct CircusPerson
{
  int ht;
  int wt;

  CircusPerson(int h, int w) : ht(h), wt(w) {};
};

struct CircusPersonComparator
{
  bool operator()(const CircusPerson& lhs, const CircusPerson& rhs) {
    if (lhs.ht == rhs.ht) {
      return lhs.wt < rhs.wt;
    } else {
      return lhs.ht < rhs.ht;
    }
  }
};

void CC4ch9::run() {
  vector<string> str_arr;
  sort( str_arr.begin(), str_arr.end(), AnagramComparator() );

  vector<CircusPerson> persons;
  persons.push_back( CircusPerson(60,100) );
  persons.push_back( CircusPerson(70,150) );
  persons.push_back( CircusPerson(56,90) );
  persons.push_back( CircusPerson(75,190) );
  persons.push_back( CircusPerson(60,95) );
  persons.push_back( CircusPerson(68,110) );

  sort( persons.begin(), persons.end(), CircusPersonComparator() );

  for (unsigned i = 0; i < persons.size(); ++i) {
    cout << persons[i].ht << "," << persons[i].wt << endl;
  }
}

int CC4ch9::search(vector<int> arr, int x) {
  int lower = 0;
  int upper = arr.size() - 1;
  while (lower <= upper) {
    int m = (lower + upper) / 2;
    if (x == arr[m])  return m;

    if (arr[lower] <= arr[m]) {
      if (x > arr[m]) {
        lower = m + 1;
      } else if (x >= arr[lower]) {
        upper = m - 1;
      } else {
        lower = m + 1;
      }
    } else {
      if (x < arr[m]) {
        upper = m - 1;
      } else if (x <= arr[upper]) {
        lower = m + 1;
      } else {
        upper = m - 1;
      }
    }
  }
  return -1;
}

