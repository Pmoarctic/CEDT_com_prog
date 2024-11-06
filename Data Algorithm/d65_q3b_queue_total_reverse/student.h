#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  mFront = (mFront + (aux?(1 - mSize):(mSize - 1)) + mCap)%mCap;
  aux = (aux+1)%2;
  return;
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  return mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  return mData[(mFront + (aux?(1 - mSize):(mSize - 1)) + mCap)%mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  
  if(mSize+1>mCap)
  {
    T* newData = new T[mSize+1];
    for(size_t i=0;i<mSize;i++)
    {
      newData[i] = mData[(i + (aux?((mFront + mSize - 1)%mCap):mFront))%mCap];
    }
    delete [] mData;
    mCap = mSize+1;
    mData = newData;
    mFront = 0;
  }
  mData[(mFront + (aux?-mSize:mSize) +mCap) % mCap] = element;
  mSize++;
  //
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  mFront = (mFront + (aux?-1:1) + mCap) % mCap;
  mSize--;
}

#endif