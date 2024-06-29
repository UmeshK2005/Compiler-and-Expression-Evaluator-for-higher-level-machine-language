/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symnode.h"

//Write your code below this line

SymNode::SymNode(){
    key=" ";
    height=0;
    par=NULL;
    left=NULL;
    right=NULL;
}

SymNode::SymNode(string k){
    key=k;
    height=0;
    par=NULL;
    left=NULL;
    right=NULL;
}

SymNode* SymNode::LeftLeftRotation(){
  SymNode *p=left;
    SymNode *s=p->par;
    SymNode *q=p->right;
    //cout<<p->key<<endl;
   //if(s->key=="32"){
    //cout<<s->left->key<<endl;}
    p->right=s;
   // cout<<p->left->key<<endl;
    p->par=par;
   // cout<<(p->par==NULL)<<endl;
    //par=p;
   // cout<<p->left->key<<p->right->key<<p->key<<endl;
    s->par=p;
    s->left=q;
    if(q!=NULL){
    q->par=s;}
  //  cout<<s->par->key<<endl;
    if(s->left==NULL and s->right==NULL){s->height=0;}
    else if (s->right==NULL){s->height=1+s->left->height;}
    else if (s->left==NULL){s->height=1+s->right->height;}
    else{//cout<<s->height<<endl;
    s->height=1+max(s->left->height,s->right->height);}
    //cout<<s->height<<endl;
    if(p->left==NULL and p->right==NULL){p->height=0;}
    else if(p->right==NULL){p->height=1+p->left->height;}
    else if(p->left==NULL){p->height=1+p->right->height;}
    else{
    p->height=1+max(p->left->height,p->right->height);}
  //  cout<<p->height<<endl;
    return p;
}

SymNode* SymNode::RightRightRotation(){
   SymNode *p=right;
    SymNode *s=p->par;
    SymNode *q=p->left;
  //  cout<<(right->key)<<endl;
    p->left=s;
   // cout<<p->left->key<<endl;
    p->par=par;
   // cout<<(p->par==NULL)<<endl;
    //par=p;
   // cout<<p->left->key<<p->right->key<<p->key<<endl;
    s->par=p;
    s->right=q;
    if(q!=NULL)
    {q->par=s;}
  //  cout<<s->par->key<<endl;
    if(s->left==NULL and s->right==NULL){s->height=0;}
    else if (s->right==NULL){s->height=1+s->left->height;}
    else if (s->left==NULL){s->height=1+s->right->height;}
    else{
    s->height=1+max(s->left->height,s->right->height);}
  //  cout<<s->height<<endl;
    if(p->left==NULL and p->right==NULL){p->height=0;}
    else if(p->right==NULL){p->height=1+p->left->height;}
    else if(p->left==NULL){p->height=1+p->right->height;}
    else{
    p->height=1+max(p->left->height,p->right->height);}
   // cout<<p->height<<endl;
    return p;
}

SymNode* SymNode::LeftRightRotation(){
       // cout<<"hi"<<endl;
    SymNode *p=left;
    //cout<<p->key<<endl;
  //  SymNode *q=p->right;
    SymNode *s=p->par;
    s->left=s->left->RightRightRotation();
   // cout<<s->left->key<<endl;
    p=s->LeftLeftRotation();
    return p;
}

SymNode* SymNode::RightLeftRotation(){
       // cout<<key<<endl;
    SymNode *p=right;
    SymNode*s= p->par;
   // cout<<p->key<<" "<<p->par->key<<endl;
    s->right=s->right->LeftLeftRotation();
    //cout<<s->par->key<<endl;
    p=s->RightRightRotation();
    //p->par=par;
    //cout<<p->par->key<<endl;
    return p;
}

SymNode::~SymNode(){
       // delete par;
   if(right!=NULL){
    delete right;}
    if (left!=NULL){
    delete left;}
}