#include<conio.h>
#include<iostream>
using namespace std;
struct Node
{      int data;
       Node *left,*right;
};
typedef Node * TREE;
Node * CREATENODE(int x, TREE L, TREE R)
{    Node * e=new Node; e->data=x;
     e->left=L; e->right=R; return e;
}
void CREATETREE(TREE & T)
{     TREE hbay,bba,bbay,ntam,ssau;
     bbay=CREATENODE(77,NULL,NULL);
     hbay=CREATENODE(27,NULL,bbay);
     ssau=CREATENODE(66,NULL,NULL);
     ntam=CREATENODE(58,NULL,ssau);
     bba=CREATENODE(43,NULL,ntam);
     T=CREATENODE(18,hbay,bba);
}
void NLR(TREE T)
{    if(T!=NULL)
     { cout<<T->data<<"\t";    NLR(T->left);   NLR(T->right);   }
}
void NRL(TREE T)
{ if(T!=NULL)
     { cout<<T->data<<"\t"; NRL(T->right);NRL(T->left);}
     
}
void LNR(TREE T)
{    if(T!=NULL)
     {  LNR(T->left);
        cout<<T->data<<"\t";
        LNR(T->right);
     }
}
void RNL(TREE T)
{  if(T!=NULL)
   {  RNL(T->right);
      cout<<T->data<<"\t";
      RNL(T->left);
   }
}
void LRN(TREE T)
{    if(T!=NULL)
     {  LRN(T->left);
        LRN(T->right);
        cout<<T->data<<"\t";
     }
}
void RLN(TREE T)
{    if(T!=NULL)
     {  RLN(T->right);
        RLN(T->left);
        cout<<T->data<<"\t";
     }
}
int DEMLA(TREE T)
{   if(T==NULL) return 0;
    else
      if(T->left==NULL && T->right==NULL) return 1;
      else  return DEMLA(T->left)+DEMLA(T->right);
}
int DEMBAC1(TREE T)
{ int t=0;
  if(T==NULL) return 0;
  else 
  if((T->left!=NULL && T->right==NULL) ||(T->left==NULL && T->right!=NULL))
     t=1;
  return t+DEMBAC1(T->left)+DEMBAC1(T->right);
}
int DEMBAC2(TREE T)
{ int t=0;
  if(T==NULL) return 0;
  else if(T->left!=NULL && T->right!=NULL)     t=1;
  return t+DEMBAC2(T->left)+DEMBAC2(T->right);
}
// Tinh chieu cao cua cay
int MAX(int x, int y)
{   if(x>y) return x;
    else return y;
}
int CHIEUCAO(TREE T)
{   if(T==NULL) return 0;
    else  return 1+MAX(CHIEUCAO(T->left),CHIEUCAO(T->right));
}
int main()
{   TREE T; CREATETREE(T);
    cout<<"\n Duyet cay theo LRN:\n";
    LRN(T);
    cout<<"\n Duyet cay theo RLN:\n";
    RLN(T);
    cout<<"\n Tren cay co "<<DEMLA(T)<<" nut la";
     cout<<"\n Tren cay co "<<DEMBAC1(T)<<" nut bac 1";
     cout<<"\n Tren cay co "<<DEMBAC2(T)<<" nut bac 2";
     cout<<"\n Chieu cao cua cay T la: "<<CHIEUCAO(T);
    getch();
}
