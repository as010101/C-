#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using std::vector;
using std::queue;
const int maxn=30;
int data[maxn];
struct node{
    int data;
    int height;
    node* lchild;
    node* rchild;
};
node* root;
node* newNode(int x){
    node* root=new node;
    root->data=x;
    root->height=1;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}
 
int getHeight(node* root){
    if(root==NULL)
        return 0;
    return root->height;
}
 
void updateHeight(node* root){
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
 
void L(node* &root){
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
 
void R(node* &root){
    node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
 
int getBalanceFactor(node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}
 
void insert_node(node* &root,int v){
    if(root==NULL){
        root=newNode(v);
        return;
    }
    if(v<root->data){
        insert_node(root->lchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->lchild)==1){
                R(root);
            }else if(getBalanceFactor(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert_node(root->rchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->rchild)==-1){
                L(root);
            }else if(getBalanceFactor(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}
 
node* create(int data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert_node(root,data[i]);
    }
    return root;
}
 
int main(){
    int n,;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    root=create(data,n);
    printf("%d\n",root->data);
    system("pause");
    return 0;
}
