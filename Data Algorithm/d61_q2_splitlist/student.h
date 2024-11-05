void splitList(CP::list<T>& list1, CP::list<T>& list2) {
    // Add your code here
    int n = (size()+1)/2;
    int m = size()-n;
    
    node* itr = mHeader;
    for(int i=0;i<n;i++)itr = itr->next;
    
    node* itr2 = itr->next;

    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    itr->next = list1.mHeader;
    list1.mHeader->prev = itr;

    list2.mHeader->prev->next = itr2;
    itr2->prev = list2.mHeader->prev;
    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;

    mHeader->prev = mHeader;
    mHeader->next = mHeader;

    mSize = 0;
    list1.mSize += n;
    list2.mSize += m;
}