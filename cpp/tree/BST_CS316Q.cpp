#include<conio.h>
#include<iostream>
using namespace std;
struct Node 
{      int data;
       Node * left, *right;
};
typedef Node * BST;
void CREATE(BST & T)
{    T=NULL;
}
void CHEN(int x, BST & T)
{    Node * e=new Node;     e->data=x;     e->left=NULL;     e->right=NULL;
     if(T==NULL) T=e;
     else
        if(x>T->data) CHEN(x,T->right);
        else 
        if(x<T->data) CHEN(x,T->left);
        else cout<<"\n Da co "<<x<<" tren cay T nen khong them vao T";
}
void LNR(BST T)
{    if(T!=NULL)
     {   LNR(T->left);         cout<<T->data<<"\t";      LNR(T->right);    }
}
void TAOFILE()
{   int x;char ch;
    FILE * f=fopen("BST.txt","w");
    do{cout<<"\n Nhap x: ";cin>>x;
        fprintf(f,"%d\t",x);
        cout<<"\n Nhan ESC de dung";
        ch=getch();
    }while(ch!=27);
    fclose(f);
    cout<<"\n Da tao xong tap tin BST.txt";
}
int TIM(int x, BST T)
{   if(T==NULL) return 0;
    else
      if(x==T->data) return 1;
      else
         if(x>T->data) return TIM(x,T->right);
         else return TIM(x,T->left);         
}
Node * findmin(BST T)
{     while(T->left!=NULL)
       T=T->left;
     return T;
}
Node * findmax(BST T)
{    while(T->right!=NULL)
       T=T->right;
     return T;
}
BST DELETE(BST T, int x)
{    if(T==NULL)  return NULL;
    else
      if(x>T->data) T->right=DELETE(T->right,x);
      else if(x<T->data) T->left=DELETE(T->left,x);
      else
      {  if(T->left==NULL && T->right==NULL)
          {    Node * e=T; T=NULL;delete(e);
          }
          else
          if(T->left!=NULL && T->right==NULL)
          { Node * e=T; T=T->left;e->left=NULL;delete(e);
          }
          else 
           if(T->left==NULL && T->right!=NULL)
           {Node * e=T;T=T->right;e->right=NULL;delete(e);
           }
           else
           {  Node * temp=findmax(T->left);
               T->data=temp->data;
               T->left=DELETE(T->left,temp->data);
           }       
      }
      return T;      
}
void RUN()
{   BST T;
    CREATE(T);
   // TAOFILE(); 
   int x;
    FILE * f=fopen("BST.txt","r");
    while(!feof(f))
    {  fscanf(f,"%d\t",&x);
       CHEN(x,T);
    }
    cout<<"\n CAY VUA NHAP LA: \n";
    LNR(T);
    cout<<"\n Nhap gia tri can xoa x: "; cin>>x;
    if(TIM(x,T)==1) 
    {
       T=DELETE(T,x);
        cout<<"\n CAY SAU KHI XOA "<<x<<" LA: \n";
        LNR(T);
    }
    else cout<<"\n Khong co "<<x<<" tren cay T";
}
int main()
{   RUN();
    getch();
}
