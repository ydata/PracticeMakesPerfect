#pragma once

#include "classdefs.h"
#include <iostream>
#include <set>

struct LinkedListNode
{
  LinkedListNode(int d) { data = d; next = NULL; }

  LinkedListNode* next;
  int data;
};


void CC4ch2::run() {
  /*
  LinkedListNode* head = new LinkedListNode(rand() % 21);
  LinkedListNode* curr = head;
  cout << curr->data;
  for (int i = 0; i < 15; ++i) {
    curr->next = new LinkedListNode(rand() % 21);
    curr = curr->next;
    cout << "\t" << curr->data;
  }
  cout << endl;

  deleteDups2(head);

  curr = head;
  while(curr != NULL) {
    cout << curr->data << "\t";
    curr = curr->next;
  }
  cout << endl;

  LinkedListNode* nth_to_last = nthToLast(head, 3);
  if (nth_to_last) {
    cout << nth_to_last->data << endl;
  }
  */

  LinkedListNode* l1 = new LinkedListNode(3);
  LinkedListNode* curr = l1;
  cout << curr->data;
  for (int i = 0; i < 5; ++i) {
    curr->next = new LinkedListNode(rand() % 10);
    curr = curr->next;
    cout << "\t" << curr->data;
  }
  cout << endl;

  LinkedListNode* l2 = new LinkedListNode(5);
  curr = l2;
  cout << curr->data;
  for (int i = 0; i < 5; ++i) {
    curr->next = new LinkedListNode(rand() % 10);
    curr = curr->next;
    cout << "\t" << curr->data;
  }
  cout << endl;

  LinkedListNode* sum = addLists(l1, l2, 0);
  curr = sum;
  while(curr != NULL) {
    cout << curr->data << "\t";
    curr = curr->next;
  }
  cout << endl;
}

void CC4ch2::deleteDups(LinkedListNode* head) {
  if (head == NULL) return;

  set<int> exists;
  exists.insert(head->data);

  LinkedListNode* prev = head;
  LinkedListNode* curr = head->next;
  while(curr != NULL) {
    if ( exists.find(curr->data) != exists.end() ) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    } else {
      exists.insert(curr->data);
      prev = curr;
      curr = curr->next;
    }
  }
}

void CC4ch2::deleteDups2(LinkedListNode* head) {
  if (head == NULL) return;

  LinkedListNode* prev = head;
  LinkedListNode* curr = head->next;
  while (curr != NULL) {
    LinkedListNode* runner = head;
    while (runner != curr) {
      if (runner->data == curr->data) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
        break;
      }
      runner = runner->next;
    }
    if (runner == curr) {
      prev = curr;
      curr = curr->next;
    }
  }
}

LinkedListNode* CC4ch2::nthToLast(LinkedListNode* head, int n) {
  if (head == NULL || n < 1)  return NULL;

  LinkedListNode* p1 = head;
  LinkedListNode* p2 = head;
  for (int i = 0; i < n - 1; ++i) {
    p2 = p2->next;
    if (p2 == NULL) return NULL;
  }
  while (p2->next != NULL) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}

LinkedListNode* CC4ch2::addLists(LinkedListNode* l1, LinkedListNode* l2, int carry) {
  if ( (l1 == NULL) && (l2 == NULL) && (carry == 0)) {
      return NULL;
  }

  LinkedListNode* result = new LinkedListNode(0);
  int value = carry;
  if (l1 != NULL) {
    value += l1->data;
  }
  if (l2 != NULL) {
    value += l2->data;
  }
  result->data = value % 10;
  LinkedListNode* more = addLists(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, value > 10 ? 1 : 0);
  result->next = more;
  return result;
}
