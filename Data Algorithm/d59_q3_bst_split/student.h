#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<queue>

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;

  node* cur = mRoot;
  node* tmp;
  node* prev;

  while(cur)
  {
    if(cur->data.first < val)cur=cur->right;
    else
    {
      ////disjointing
      tmp = cur->left;

      if(cur==mRoot)
      {
        mRoot = tmp;
        if(cur->left!=NULL)
        {
          cur->left = NULL;
          tmp->parent = NULL;
        }
      }
      else
      {
        child_link(cur->parent, cur->data.first) = tmp;
        if(cur->left!=NULL)
        {
          
          tmp->parent = cur->parent;
          //cur->parent->right = tmp;
          cur->left = NULL;
        }
      }
      /////
      
      /////connecting result tree
      if(result.mRoot == NULL)
      {
        result.mRoot = cur;
        cur->parent = NULL;
      }
      else
      {
        cur->parent = tmp;
        prev->left = cur;
      }

      //check for next left node ,which maybe contain (data >= val)
      prev = cur;
      cur = tmp;
    }
  }

  return result;
}

#endif
