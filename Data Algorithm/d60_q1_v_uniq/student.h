#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <set>
//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  
  std::set<T> U,S;
  for(int i=0;i<mSize;i++)
  {
    U.insert(mData[i]);
  }

  int n = U.size();
  T* newData = new T[n];

  int idx = 0;
  for(int i=0;i<mSize;i++)
  {
    if(S.find(mData[i]) == S.end())
    {
      newData[idx++] = mData[i];
      S.insert(mData[i]);
    }
  }

  mCap = n;
  mSize = n;
  delete [] mData;
  mData = newData;
}

#endif
