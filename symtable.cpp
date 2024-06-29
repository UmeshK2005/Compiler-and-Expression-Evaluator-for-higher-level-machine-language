/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
//#include"symnode.h"
//#include<iostream>
using namespace std;
//Write your code below this line

SymbolTable::SymbolTable(){
    size=0;
    root=NULL;
}

void SymbolTable::insert(string k){
      SymNode*s=new SymNode(k);
    if(root==NULL){root=s;//cout<<"mdm"<<endl;
    return;}
    else{
  //    cout<<k<<endl;
    SymNode*temp=root;
    SymNode*x=root->par;
    while(temp!=NULL){//cout<<temp->key<<endl;
        if (k>temp->key){//cout<<"gfkjk"<<endl;
            if(temp->right==NULL){
              temp->right=s;
              s->par=temp;
              temp=temp->right;break;
            }
            else{
           // cout<<temp->key<<endl;
            temp->right->par=temp;
          //  cout<<temp->right->par->key<<endl;
            temp=temp->right;}
        }
        else if(k<temp->key){
            if(temp->left==NULL){
              temp->left=s;
              s->par=temp;
              temp=temp->left;
              break;
            }
            else{temp->left->par=temp;
            temp=temp->left;}
        }
        else{return ;}
    }
   // cout<<temp->key<<" "<<(temp->par->key)<<endl;
   // cout<<temp->par->right->key<<endl;
    temp=temp->par;
    while(temp!=NULL){//cout<<temp->key<<endl;
  //  temp=temp->par;
    int h=0;
    if(temp->right==NULL and temp->left==NULL){temp->height=0;}
    else if(temp->right==NULL){temp->height=1+temp->left->height;h=temp->height;}
    else if(temp->left==NULL){temp->height=1+temp->right->height;h=-temp->height;}
    else{
    temp->height=1+max(temp->right->height,temp->left->height);
      h=temp->left->height-temp->right->height;
    }
  //  cout<<temp->height<<endl;

    //cout<<h<<endl;
    if(h>1){
        
        if(temp->left->key>k){
          
        temp=temp->LeftLeftRotation();
        x=temp;
       // cout<<temp->key<<endl;
        if(temp->par!=NULL){
          if(temp->key>temp->par->key){temp->par->right=temp;}
          else{temp->par->left=temp;}}
        temp=temp->par;
        continue;
          
        }
        else{//cout<<"hi"<<endl;
          temp=temp->LeftRightRotation();x=temp;
       //   cout<<x->key<<endl;
        if(temp->par!=NULL){
          if(temp->key>temp->par->key){temp->par->right=temp;}
         else{ temp->par->left=temp;}}
        temp=temp->par;continue;}

        }
    
    else if(h<-1){
        if(temp->right->key<k){//cout<<"hi"<<endl;
            temp=temp->RightRightRotation();
        //    if(temp->right!=NULL){
        //    cout<<temp->right->key<<endl;}
           x=temp;
            if(temp->par!=NULL){
          if(temp->key>temp->par->key){temp->par->right=temp;}
          else{temp->par->left=temp;}}
            temp=temp->par;
            continue;
        }
        else{//cout<<"hi"<<endl;
            temp=temp->RightLeftRotation();
          //  cout<<temp->key<<endl;
            x=temp;
             if(temp->par!=NULL){
          if(temp->key>temp->par->key){temp->par->right=temp;}
          else{temp->par->left=temp;}}
            temp=temp->par;
            continue;
        }
    }
    else{//cout<<temp->key<<endl;
        //cout<<temp->right->key<<endl;
        x=temp;
        temp=temp->par;
      //  cout<<(temp->par==NULL)<<endl;
        continue;
    }
  //  temp=temp->par;
    }//cout<<temp->key<<endl;
    root=x;
    //cout<<root->key<<endl;
 //   if(root->key=="30"){  cout<<root->right->key<<endl;
   //   }
    return ;
    
    }
    return ;
}

void SymbolTable::remove(string k){
  //cout<<(root->left==NULL)<<endl;
  if(root==NULL){return ;}
    else{
    SymNode*temp=root;
    SymNode*x=root->par;
    while(temp!=NULL){
        if (k>temp->key){
            if(temp->right==NULL){
                return ;
            }
            else{x=temp;
                temp=temp->right;
            }
        }
        else if(k<temp->key){
            if(temp->left==NULL){
                return ;
            }
            else{x=temp;
                temp=temp->left;
            }
        }
        else{break;}
    }
 //   if(temp->key=="9"){
   // cout<<temp->key<<" "<<"kf"<<endl;}
    if(temp->left==NULL or temp->right==NULL){
      //cout<<"hi"<<endl;
        if (temp->par==NULL){//cout<<"hi"<<endl;
            if(temp->left==NULL and temp->right!=NULL){
             // cout<<"hi"<<endl;
                temp->right->par=NULL;

                root=temp->right;
                temp->right=NULL;
                delete temp;
                //cout<<temp->key<<endl;
               // delete temp;
               // cout<<root->key<<endl;
                return;
            }
            else if(temp->left==NULL and temp->right==NULL){
            //  cout<<"hi"<<endl;
              //  cout<<(temp->key)<<endl;
                //cout<<"hi"<<endl;
              //  delete root;
                root=NULL;
                return ;
            }
            else{
                temp->left->par=NULL;
                root=temp->left;
                temp->left=NULL;
                delete temp;
                return;
            }
            return;
        }
        else {
            if(temp->left==NULL and temp->right==NULL){
             // cout<<"hie"<<endl;
                if(x->right==temp){x->right=NULL;temp->par=NULL;
                delete temp;}
                else if(x->left==temp){//cout<<"hi"<<endl;
                  x->left=NULL;temp->par=NULL;
               //   cout<<x->key<<endl;
                  delete temp;
                }
            }
            else if (temp->left==NULL){//cout<<"hi"<<endl;
                if (x->right==temp){temp->right->par=x;
                x->right=temp->right;
                  temp->right=NULL;
                  temp->par=NULL;
                  delete temp;
                }
                else{temp->right->par=x;
                
                x->left=temp->right;
                  temp->right=NULL;
                  temp->par=NULL;
                  delete temp;
                }
            }
            else{
                if(x->left==temp){
                    temp->left->par=x;
                    x->left=temp->left;
                    temp->left=NULL;
                    temp->par=NULL;
                    delete temp;
                }
                else{
                    temp->left->par=x;
                    x->right=temp->left;
                    temp->left=NULL;
                    temp->par=NULL;
                    delete temp;
                }
            }//cout<<x->key<<endl;
            
            
            temp=x;
           // cout<<(temp->right==NULL)<<endl;
            

            
        }
    }
    else{
        SymNode*temp1=temp->left;
        SymNode*y=temp;;
        while (temp1->right!=NULL){
            y=temp1;
            temp1=temp1->right;
        }
       // cout<<(temp->key)<<"dff"<<endl;
      //  cout<<temp1->key<<endl;
      //  cout<<(y->key)<<endl;
        if(y->right==temp1){//cout<<"hi"<<endl;
        if(temp1->left==NULL){//cout<<"hi"<<endl;
            y->right=NULL;
            temp1->par=NULL;
           
        }
        else{//cout<<temp1->par->key<<endl;
            temp1->left->par=y;
            y->right=temp1->left;
            temp1->left=NULL;
            temp1->par=NULL;
            
        }
        }
        else{//cout<<y->key<<endl;
          if(temp1->left==NULL){
            y->left=NULL;
            temp1->par=NULL;
            
          }
          else{//cout<<temp1->par->key<<endl;
            temp1->left->par=y;
            y->left=temp1->left;
            temp1->left=NULL;
            temp1->par=NULL;
          }
        }
        //cout<<y->key<<endl;
      //  y=temp1->par;
       // cout<<(y==temp)<<endl;
        
        while(y!=temp){//cout<<y->key<<endl;
            int h=0;
            if(y->right==NULL and y->left==NULL){y->height=0;}
            else if(y->right==NULL){//cout<<<<endl;
              y->height=1+y->left->height;h=y->height;}
            else if (y->left==NULL){y->height=1+y->right->height;h=-y->height;}
            else{
                y->height=1+max(y->right->height,y->left->height);
                h=y->left->height-y->right->height;
            }
         // cout<<h<<endl;
        if(h>1){
        
        int w=0;
        if(y->left->right==NULL){w=y->left->height;}
        else if (y->left->left==NULL){w=-y->left->height;}
        else{w=y->left->left->height-y->left->right->height;}
        //cout<<w<<endl;
        if(w>=0){y=y->LeftLeftRotation();}
       // else if()
        else{y=y->LeftRightRotation();}
        x=y;
       // cout<<y->key->right<<endl;
        if(y->par!=NULL){
          if(y->key>y->par->key){y->par->right=y;}
          else{y->par->left=y;}}
        y=y->par;
        continue;
          
        

        }
    
    else if(h<-1){
        //cout<<"hi"<<endl;
         int w=0;
        if(y->right->right==NULL){w=y->right->height;}
        else if (y->right->left==NULL){w=-y->right->height;}
        else{w=y->right->left->height-y->right->right->height;}
        if(w<=0){y=y->RightRightRotation();}
        else{y=y->RightLeftRotation();}
        //    if(temp->right!=NULL){
        //    cout<<temp->right->key<<endl;}
           x=y;
            if(y->par!=NULL){
          if(y->key>y->par->key){y->par->right=y;}
          else{y->par->left=y;}}
            y=y->par;
            continue;
        
    }
    else{//cout<<temp->key<<endl;
        //cout<<temp->right->key<<endl;
       // cout<<y->par->key<<endl;
        x=y;
        y=y->par;
        
      //  cout<<(temp->par==NULL)<<endl;
        continue;
    }
   // y=y->par;
        }
       // cout<<temp1->key<<" "<<temp->key<<endl;
        temp=y;
       // cout<<(temp->left==NULL)<<endl;
        
        temp1->right=temp->right;
       // cout<<temp1->right->key<<endl;
      //  cout<<temp->left->key<<endl;
        temp1->left=temp->left;
        
   // if(temp->key=="27")   { cout<<(temp1->left->key)<<endl;}
        temp1->par=temp->par;
       // cout<<(temp1->par==NULL)<<endl;
        if(temp->right==NULL){temp1->right=NULL;}
        else{temp->right->par=temp1;}
        if(temp->left==NULL){temp1->left=NULL;}
        else{temp->left->par=temp1;}
      //  cout<<(temp1->key)<<temp1->right->key<<(temp1->left->key)<<endl;
      if(temp->par!=NULL){
        if(temp->par->right==temp){temp->par->right=temp1;}
        else{temp->par->left=temp1;}}
        
        //cout<<
       // delete temp;
        temp=temp1;
        //cout<<temp->key<<" "<<temp->right->key<<(temp->left==NULL)<<endl;

        }
      //  if(temp->key=="32"){
   // cout<<(temp->key)<<endl;
      while(temp!=NULL){//cout<<temp->key<<" jh"<<endl;
    //  if(temp->key=="18"){//cout<<temp->right->height<<endl;}
  //  temp=temp->par;
    int h=0;
    if(temp->right==NULL and temp->left==NULL){temp->height=0;}
    else if(temp->right==NULL){temp->height=1+temp->left->height;h=temp->height;}
    else if(temp->left==NULL){temp->height=1+temp->right->height;h=-temp->height;}
    else{//cout<<temp->left->height<<endl;
    temp->height=1+max(temp->right->height,temp->left->height);
      h=temp->left->height-temp->right->height;
    }
  //  cout<<temp->height<<endl;
    
   // cout<<h<<endl;
    if(h>1){//cout<<temp->height<<endl;
        int w=0;
        if(temp->left->right==NULL){//cout<<"hi"<<endl;
          w=temp->left->height;}
        else if(temp->left->left==NULL){w=-temp->left->height;}
        else{w=temp->left->left->height-temp->left->right->height;}
       // cout<<w<<endl;
        if(w>=0){//cout<<temp->height<<endl;
        temp=temp->LeftLeftRotation();
       //   cout<<temp->height<<endl;
        }
        else{temp=temp->LeftRightRotation();}
        x=temp;
       // cout<<temp->height<<endl;
       // if(root->key=="18"){
        //cout<<temp->par->key<<endl;}
        if(temp->par!=NULL){
          if(temp->key>temp->par->key){temp->par->right=temp;}
          else{temp->par->left=temp;}}
        temp=temp->par;
        continue;
          
    }  
    
    else if(h<-1){int w=0;
            if(temp->right->left==NULL){w=-temp->right->height;}
            else if(temp->right->right==NULL){w=temp->right->height;}
            else{
             // if(temp->key=="35"){cout<<temp->right->right->height<<endl;}
              w=temp->right->left->height-temp->right->right->height;}
           // cout<<w<<endl;
            if(w>0){
              temp=temp->RightLeftRotation();
            }
            else{temp=temp->RightRightRotation();}
        //    if(temp->right!=NULL){
           // cout<<temp->par->key<<endl;
           x=temp;
          if(temp->par!=NULL){
          if(temp->key>temp->par->key){temp->par->right=temp;}
          else{temp->par->left=temp;}}
            temp=temp->par;
            continue;
        
    }
    else{//cout<<temp->key<<endl;
        //cout<<temp->right->key<<endl;
        x=temp;
        temp=temp->par;
      //  cout<<(temp->par==NULL)<<endl;
        continue;
    }
  //  temp=temp->par;
    }//cout<<x->key<<endl;
    root=x;
    return ;
    }
    return ;


}

int SymbolTable::search(string k){
    //SymNode*s=new SymNode(k);
    SymNode *temp=root;
    while(temp!=NULL){
        if (temp->key>k){
            temp=temp->left;
        }
        else if (temp->key<k){
            temp=temp->right;
        }
        else{
            return temp->address;
        }
      //  temp=temp->right;
    }
    return -2;
}

void SymbolTable::assign_address(string k,int idx){
    SymNode *temp=root;
    while(temp!=NULL){
        if (temp->key>k){
            temp=temp->left;
        }
        else if (temp->key<k){
            temp=temp->right;
        }
        else{
            break;
        }
       // temp=temp->right;
    }
    if(temp!=NULL){
        temp->address=idx;
        return;
    }
    return;
}
int s(SymNode*root){
    if (root==NULL){return 0;}
    else{
        return 1+s(root->right)+s(root->left);
    }
    return 0;
}
int SymbolTable::get_size(){
    SymNode*temp=root;
    int p=s(temp);
    return p;
    
}

SymNode* SymbolTable::get_root(){
    return root;
}

SymbolTable::~SymbolTable(){
    delete root;
}/*
void preOrder(SymNode *root)  
{  
    if(root != NULL)  
    {  
        std::cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
  */
/*
int main()  
{  
    SymbolTable t ;  
    
    t.insert("10");  
    t.insert("20");  
    t.insert("30");  
    t.insert("40");  
    t.insert("50");  
    t.insert("25");  
      
    /* The constructed AVL Tree would be  
            30  
            / \  
            20 40  
            / \ \  
            10 25 50  
    */
   /*
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(t.root);  
      
    return 0;  
} */
