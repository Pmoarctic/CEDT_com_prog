#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  //you may write additional code here
  size_t cnt=0;
  if(ptr == NULL)return 0;
  if(ptr->left!=NULL ^ ptr->right!=NULL)cnt++;

  cnt += process(ptr->left);
  cnt += process(ptr->right);
  return cnt;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
  return 0;
}

#endif
