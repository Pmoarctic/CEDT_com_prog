#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <algorithm>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  size_t round = (b-a+1)/2;
  size_t l = a;
  size_t r = b;
  while(round--)
  {
    std::swap(mData[(mFront+l)%mCap],mData[(mFront+r)%mCap]);
    l++;
    r--;
  }

  return;
}

#endif
