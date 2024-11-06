#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  if(pos == 0)
  {
    push(value);
    return;
  }

  T* newData = new T[mSize + 1];
  long long cnt = pos;
  size_t idx;
  for(int i=mSize;i>=0;i--)
  {
    if(cnt==0)
    {
      newData[i] = value;
    }
    else if(cnt>0)
    {
      newData[i] = mData[i-1];
    }
    else
    {
      newData[i] = mData[i];
    }
    cnt--;
  }
  mSize++;
  mCap = mSize;
  delete[] mData;
  mData = newData;
  return;
}

#endif
