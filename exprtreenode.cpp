/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "exprtreenode.h"

//Write your code below this line

ExprTreeNode::ExprTreeNode(){

    type=" ";
    id=" ";
    num=0;
    left =NULL;
    right=NULL;

}
bool checknum(string t){
    
    int n=t.size();
    if (n==1 and t[0]=='-'){return false;}
    int c=0;
    for (int i=0;i<n;i++){
      if (c==2){return false;}
        if(t[i]=='-'){c+=1;continue;}
        if (isdigit(t[i])){continue;}
        else{return false;}
    }
    return true;
}
ExprTreeNode::ExprTreeNode(string t,int v){
    num=v;
  if (t=="+"){type="ADD";}
  else if(t=="-"){type="SUB";}
  else if(t=="*"){type="MUL";}
  else if(t=="/"){type="DIV";}
  else if(t=="ret"){type="RET";}
  else if(t=="del"){type="DEL";}
  else if(t==":="){type="Equal";}
  else if (checknum(t)==true){
    type="VAL";
    id=t;
    int n=stoi(t);
    num=n;

  }
  else{
    type="VAR";
    id=t;
  }
 // num=v;
  left=NULL;
  right=NULL;
}

ExprTreeNode::~ExprTreeNode(){
    delete left;
    delete right;
}

