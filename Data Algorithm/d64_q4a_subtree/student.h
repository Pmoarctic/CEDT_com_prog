#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if(n==NULL)return 0;

  size_t cnt = 0;
  if(n->left!=NULL)cnt+=process(n->left);
  if(n->right!=NULL)cnt+=process(n->right);
  return 1 + cnt;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if (mSize == 0) return std::pair<KeyT,MappedT>();

  left.clear();
  right.clear();

  //left tree
  left.mRoot = this->mRoot->left;
  if(left.mRoot != NULL)
  {
    left.mRoot->parent = NULL;
  }
  //

  //right
  right.mRoot = this->mRoot->right;
  if(right.mRoot != NULL)
  {
    right.mRoot->parent = NULL;
  }
  //

  //clear main
  this->mRoot->left = NULL;
  this->mRoot->right = NULL;
  //

  //fix mSize
  left.mSize = process(left.mRoot);
  right.mSize = this->mSize - left.mSize - 1;
  this->mSize = 1;
  //

  return std::pair<KeyT,MappedT>(this->mRoot->data.first,this->mRoot->data.second);
}

#endif

