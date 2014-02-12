#pragma once

#include "classdefs.h"
#include <iostream>
#include <stack>

class StackWithMin : public stack<int>
{
public:
  void push(int n);
  int pop();
  int min();

private:
  stack<int> m_mins;
};

void CC4ch3::run() {
  /*
  StackWithMin min_stack;

  cout << min_stack.min() << endl;
  for (int i = 0; i < 10; ++i) {
    min_stack.push(rand() % 101 - 50);
    cout << min_stack.top() << "\t" << min_stack.min() << endl;
  }

  cout << "Popping..." << endl;
  while ( !min_stack.empty() ) {
    cout << min_stack.top() << "\t" << min_stack.min() << endl;
    min_stack.pop();
  }
  */

  stack<int> s;
  for (int i = 0; i < 10; ++i) {
    s.push(rand() % 101 - 50);
    cout << s.top() << "\t";
  }
  cout << endl;
  stack<int> t = sortStack(s);
  while ( !t.empty() ) {
    cout << t.top() << "\t";
    t.pop();
  }
  cout << endl;
}

void StackWithMin::push(int n) {
  if ( n < min() ) {
    m_mins.push(n);
  }
  stack<int>::push(n);
}

int StackWithMin::pop() {
  int n = stack<int>::top();
  if ( n == min() ) {
    m_mins.pop();
  }
  stack<int>::pop();
  return n;
}

int StackWithMin::min() {
  if ( m_mins.empty() ) {
    return numeric_limits<int>::max();
  } else {
    return m_mins.top();
  }
}

stack<int> CC4ch3::sortStack(stack<int>& s) {
  stack<int> t;
  while( !s.empty() ) {
    int val = s.top();
    s.pop();
    while ( ( !t.empty() ) && (t.top() > val) ) {
      s.push( t.top() );
      t.pop();
    }
    t.push(val);
  }
  return t;
}

