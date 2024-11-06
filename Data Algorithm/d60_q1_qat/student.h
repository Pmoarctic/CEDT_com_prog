#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  // you need to return something
  // return 
  //std::cout << (mFront+mCap+idx)%mCap << "\n";

  return mData[(mFront + (mSize + idx)%mSize + mCap)%mCap];
}

#endif
