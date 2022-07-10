#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef struct treenode {
    struct treenode* lchild;
    struct treenode* rchild;
    int val;
}treenode;
void shellsort(vector<char> & v){//希尔排序
    int h=1;
    while(h<v.size()/3){
        h=h*3+1;
    }
    printf("%d ",h);
    while(h>=1){
        for(int i=h;i<v.size();i++){
            for(int j=i;j>=h && v[j]<v[j-h];j-=h){
                if(v[j]<v[j-h]){
                    int temp=v[j];
                    v[j]=v[j-h];
                    v[j-h]=temp;
                }
                  else break;  
            }
            for(int ll=0;ll<16;ll++){
                printf("%c ",v[ll]);
            }
            cout<<endl;
        }
        h/=3;
    }
}
void getnext(vector<int> & next,string b){//求next数组
    int k=-1;
    int j=0;
    next[0]=-1;
    while(j<b.size()){
        if(k==-1||b[j]==b[k]){
            next[++j]=++k;
        }
        else{
            k=next[k];
        }
    }
}
void matching_process(string a,string b,vector<int> next){//KMP匹配
    int la=0;
    int lb=0;
    while(la<a.size()&&lb<b.size()){
        if(lb==-1||a[la]==b[lb]){
            la++;
            lb++;
        }
        else{
            lb=next[lb];
        }
    }
    if(lb>=b.size()){
        printf("位置是：");
        printf("%d",la-b.size()+1);
    }
    else{
        printf("匹配失败");
    }
}
treenode* insert_(treenode* t,int val1){//根据给定的序列构造二叉搜索树
    if(t==nullptr){
        treenode* root=new treenode();
        root->val=val1;
        root->rchild=nullptr;
        root->lchild=nullptr;
        return root;
    }
    else{
        if(val1>t->val){
            t->rchild=insert_(t->rchild,val1);
        }
        else if(val1<t->val){
            t->lchild=insert_(t->lchild,val1);
        }
        return t;
    }
}
string mid_traverse(treenode* t){
    string s;
    if(t==nullptr){
        return s;
    }
    s=mid_traverse(t->lchild);
    s+=(char)(t->val+48);
    s=s+mid_traverse(t->rchild);
    return s;
}
int main(){
    char s[200];
    int size=200;
    while(cin.getline(s,size)){
    cout<<s<<endl;        
    }


    return 0;
}