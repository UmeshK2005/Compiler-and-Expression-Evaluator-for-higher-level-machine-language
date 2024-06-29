/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"

//Write your code below this line

Parser::Parser(){
    SymbolTable *s=new SymbolTable();
    symtable=s;
    last_deleted=0;
}
bool check(string t){
    
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
void Parser::parse(vector<string> code){
     //  cout<<code[0]<<endl;
     vector<ExprTreeNode*>v;
     if(code[0]!="del"){//cout<<"hi"<<endl;
    if(code[0]!="ret"){//cout<<(symtable->root==NULL)<<endl;
     symtable->insert(code[0]);}
    // cout<<"hi"<<endl;
     ExprTreeNode*root= new ExprTreeNode(code[1],0);
    // cout<<root->id<<endl;
     ExprTreeNode *l=new ExprTreeNode(code[0],0);
     root->left=l;
     ExprTreeNode*p=new ExprTreeNode();
     root->right=p;
   //  cout<<root->right->id<<endl;
     vector<string>code1;
   //  code1.push_back("(");
    for(int i=2;i<code.size();i++){
        //cout<<code[i]<<endl;
        code1.push_back(code[i]);
    }
  //  code1.push_back(")");
    int i=0;
    v.push_back(p);
    //cout<<v.size()<<endl;
    //cout<<v[0]->id<<endl;
   // cout<<check(code1[0])<<endl;
    while(i<code1.size()){
        if(code1[i]=="("){
            ExprTreeNode *temp1=new ExprTreeNode();
            ExprTreeNode*temp=v[v.size()-1];
            temp->left=temp1;
            v.push_back(temp1);
            i+=1;
        }
        else if(check(code1[i])){
            ExprTreeNode*temp=v[v.size()-1];
            v.pop_back();
            temp->id=code1[i];
            temp->type="VAL";
            int n =stoi(code1[i]);
            temp->num=n;
            i+=1 ;

        }
        else if(code1[i]=="+" or code1[i]=="-" or code1[i]=="*" or code1[i]=="/"){
             ExprTreeNode*temp=v[v.size()-1];
            v.pop_back();
            string t=code1[i];
             if (t=="+"){temp->type="ADD";}
                else if(t=="-"){temp->type="SUB";}
             else if(t=="*"){temp->type="MUL";}
            else{temp->type="DIV";}
            ExprTreeNode*temp1=new ExprTreeNode();
            temp->right=temp1;
            v.push_back(temp);
            v.push_back(temp1);
            i+=1;
        }
        else if(code1[i]==")"){
            v.pop_back();
            i+=1;
        }
        else{
            ExprTreeNode*temp=v[v.size()-1];
            v.pop_back();
            temp->id=code1[i];
            temp->type="VAR";
            i+=1;
        }




    }
     expr_trees.push_back(root);
     
     
     
     }
     else{//cout<<"hi"<<endl;
        ExprTreeNode*temp1=new ExprTreeNode("del",0);
        ExprTreeNode *temp2=new ExprTreeNode(code[1],0);
        ExprTreeNode *temp3=new ExprTreeNode(code[2],0);
        temp2->right=temp3;
        temp2->left=temp1;
        int x=symtable->search(code[2]);
       // cout<<"hi"<<endl;
        if(x!=-1 and x!=-2){last_deleted=x;}
        
        symtable->remove(code[2]);
        expr_trees.push_back(temp2);


     }
}

Parser::~Parser(){
  delete symtable;
}