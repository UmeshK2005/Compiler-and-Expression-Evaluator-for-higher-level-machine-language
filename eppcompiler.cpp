/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "eppcompiler.h"

//Write your code below this line

EPPCompiler::EPPCompiler(){
    memory_size=0;
    output_file="";

}

EPPCompiler::EPPCompiler(string out_file,int mem_limit){
    output_file=out_file;
    memory_size=mem_limit;
    for(int i=0;i<memory_size+2;i++){
        mem_loc.push_back(i);
    }
    std::ofstream semx;
    semx.open(output_file,std::ofstream::out | std::ofstream::trunc);
    semx.close();
}

void EPPCompiler::compile(vector<vector<string>> code){
     int n=code.size();
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
      //  cout<<code[i].size()<<endl;
        targ.parse(code[i]);
       // cout<<"hi"<<endl;
        vector<string>vortsex=generate_targ_commands();
        write_to_file(vortsex);
    }
}
void visit(ExprTreeNode *root,vector<string>&v,Parser &targ){
    if(root->type=="VAL"){string t="PUSH "+root->id;
    v.push_back(t);}
    else if(root->type=="VAR"){
        int addr=targ.symtable->search(root->id);
        

        string t= "PUSH mem["+ to_string(addr) +"]";v.push_back(t);
        

    }
    else{
        v.push_back(root->type);
    }
}
void generator(ExprTreeNode *root,vector<string> &v,Parser &targ){
    if (root->left==NULL and root->right==NULL){//cout<<"hi"<<endl;
     visit(root,v,targ);
     return;
   //  cout<<"hi"<<endl;
   }
   else{
        generator(root->right,v,targ);
        generator(root->left,v,targ);
       // cout<<root->type<<endl;
        visit(root,v,targ);
      
        return;

   }
}
vector<string> EPPCompiler::generate_targ_commands(){
    ExprTreeNode *root=targ.expr_trees[targ.expr_trees.size()-1];
   // cout<<root->left->type<<" "<<root->left->id<<endl;
   
    vector<string>v;
    if(root->left->type!="DEL"){
    generator(root->right,v,targ);}
     // for(int i=0;i<v.size();i++){
      //    cout<<v[i]<<" ";
      //  }
        //cout<<endl;
     if (root->left->type=="VAR"){//cout<<"hi"<<endl;
        if(targ.symtable->search(root->left->id)==-1){
        //  cout<<"hi"<<endl;
        
        string t=root->left->id;
       // cout<<t<<mem_loc[0]<<endl;
         // cout<<targ.symtable->root->key<<endl;
        targ.symtable->assign_address(t,mem_loc[0]);
      //  cout<<targ.symtable->search(root->left->id)<<endl;
        string x="mem["+to_string(mem_loc[0])+"] = POP";
      //  cout<<v.size()<<endl;
        v.push_back(x);
        mem_loc.erase(mem_loc.begin());}
        else if(targ.symtable->search(root->left->id)!=-2){
        //  cout<<"heloo"<<endl;
          int p=targ.symtable->search(root->left->id);
        //  cout<<p<<endl;
          string x="mem["+to_string(p)+"] = POP";
         // cout
          v.push_back(x);
        }
        
    }
    else if(root->left->type=="DEL"){//cout<<"hi"<<endl;
        int k=targ.last_deleted;
       // cout<<k<<endl;
        string x="DEL = mem["+to_string(k)+"]";
        v.push_back(x);
        mem_loc.push_back(k);
    }
    else if(root->left->type=="RET"){
       
        v.push_back("RET = POP");
    }
    else{}
     // for(int i=0;i<v.size();i++){
       //   cout<<v[i]<<endl;
       // }
       // cout<<endl;
    return v;
}

void EPPCompiler::write_to_file(vector<string> commands){
    ofstream sey;
    sey.open(output_file,ios::app);
    for(string & x:commands){
        sey<<x<<endl;
    }
    sey.close();
}

EPPCompiler::~EPPCompiler(){
  
}
/*
int main(){
    int ct = 0;
    
        vector<string> a = {  "a",":=", "(","1","+","2",")"};
        vector<string> b = {  "b",":=", "(","1","+","2",")"};
        vector<string> c = {"del",":=","b"};
        vector<string> d = {  "c",":=", "(","1","+","2",")"};
        
        vector<string> e = {"ret" ,":=", "(","a","+","c",")"};
     //   EPPCompiler* com =  new EPPCompiler("ab.txt",2);
        vector<vector<string>> vec;
//        vector<string> s = {"x",":=","3"};
//        vector<string> b = {"del",":=","x"};
//        v.push_back(s);
//        v.push_back({"y",":=","2"});
//        v.push_back({"z",":=","(","x","-","y",")"});
//        v.push_back(b);
//        v.push_back({"ret",":=","z"});
        vec.push_back({"x",":=","3"});
        vec.push_back({"y",":=","2"});
        vec.push_back({"z",":=","(","x","-","y",")"});
        vec.push_back({"ret",":=","z"});
       // vec.push_back(e);
        EPPCompiler *x=new EPPCompiler("ab.txt",100);
        (x->compile(vec));


     //   com->compile(vec);
       // ct++;
      //  delete com;
    
}
*/