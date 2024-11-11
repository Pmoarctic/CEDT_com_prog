#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  std::sort(pos.begin(), pos.end());

  std::vector<bool> to_remove(mSize, false);
  for (size_t idx : pos)
  {
    if (idx < mSize)
    {
      to_remove[idx] = true;
    }
  }

  T *newData = new T[mCap];
  size_t newSize = 0;

  for(size_t i=0;i<mSize;i++)
  {
    if(to_remove[i]==true)continue;
    newData[newSize++] = mData[(mFront+i)%mCap];
  }

  delete[] mData;
  mData = newData;
  mSize = newSize;
  mFront = 0;

  return;
}

#endif
