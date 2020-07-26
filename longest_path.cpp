#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct tree {
  int value;
  vector<tree> children;
};

int longest_path(const tree &root) {
  /* Implement me */
  int childNum =(root.children).size();
  if(childNum ==0){
    return 1;
  }
  int maxSequenceWith = 0;
  int maxSequenceWithout = 0;
  bool isSeq = false;
  vector<int> childSeqVec (childNum);
  for (int i = 0; i < childNum; i++){
    childSeqVec[i] = longest_path((root.children)[i]);
    if ((root.value)+1 == ((root.children)[i]).value){
      isSeq = true;
      maxSequenceWith = childSeqVec[i] > maxSequenceWith ? childSeqVec[i] : maxSequenceWith;
    }
    else{
      maxSequenceWithout = childSeqVec[i] > maxSequenceWithout ? childSeqVec[i] : maxSequenceWithout;
    }
  }
  int retvalueWith = isSeq == true ? maxSequenceWith+1 : 1;
  int retValue = retvalueWith > maxSequenceWithout ? retvalueWith : maxSequenceWithout;
  return retValue;
}
