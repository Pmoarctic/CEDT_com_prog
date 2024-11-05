#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>



template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  node* tail = mHeader->prev;
  size_t add=0;
  for(auto i=ls.begin();i!=ls.end();i++)
  {
    add += (*i).size();
    node* newls = (*i).begin().ptr;
    tail->next = newls;
    newls->prev = tail;

    newls = (*i).mHeader;
    tail = newls->prev;

    (*i).mSize = 0;
    newls->next = newls;
    newls->prev = newls;
  }
  tail->next = mHeader;
  mHeader->prev = tail;
  mSize += add;
}
#endif