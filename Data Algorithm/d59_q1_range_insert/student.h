#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
    int len = mSize+(last-first);
    int idx = position - this->begin();
    T* newData = new T[len];

    int i=0;
    auto itr = this->begin();
    while(i<len)
    {
        if(i==idx)
        {
            while(first != last)
            {
                newData[i] = *first;
                
                first++;
                i++;
            }
            continue;
        }
        newData[i] = *itr;
        itr++;
        i++;
    }
    mCap = len+1;
    mSize = len;
    delete [] mData;
    mData = newData;
}



#endif