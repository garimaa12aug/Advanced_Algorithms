#include<bits/stdc++.h>

using namespace std;

struct tree{
    int key;
    tree *lc;
    tree *rc;
    tree *parent;
    int siz;
    int height;
};

int e =0;

struct tree *head;

struct tree* create(int data)
{
struct tree *r= (struct tree*) malloc(sizeof(struct tree));
r->key=data;
r->lc=NULL;
r->rc=NULL;
r->height=0;
return r;
}
void display(struct tree *r) 
{
if(r != NULL)
{
cout<<r->key;
display(r->lc);
display(r->rc);
}
}
int find(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int heightt(struct tree *r)
{
  if(r==NULL)
    return 0;
  else
    return r->height;
}

int checkbalance(struct tree *r)
{
if (r == NULL)
  return 0;
  return (heightt(r->lc)-heightt(r->rc));
}

struct tree* rightrotate(struct tree* r)
{
struct tree *a =r->lc;
struct tree *b=a->rc;
a->rc = r;
r->lc= b;
a->height = find(heightt(a->lc),heightt(r->rc))+1;
r->height= find(heightt(r->lc),heightt(a->rc))+1 ;
return a;
}
int size(tree *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int s =0;
    if(root->lc !=NULL)
    {
        s = size(root->lc);
    }
    if(root->rc !=NULL)
    {
        s += size(root->rc);
    }
    root->siz = s+1;
    return (root->siz);
}

struct tree *leftrotate(struct tree *x)
{
struct tree *y = x->rc;
struct tree *l = y->lc;
y->lc = x;
x->rc = l;
x->height = find(heightt(x->lc), heightt(x->rc))+1;
y->height = find(heightt(y->lc), heightt(y->rc))+1;
return y;
}



struct tree* insertion(struct tree* node,int key)
{
if(node==NULL)
return (create(key));
if(key < node->key)
node->lc = insertion(node->lc,key);
else if (key > node->key)
node->rc = insertion(node->rc,key);
else 
return node;
node->height = find(heightt(node->lc),heightt(node->rc))+1;
int b = checkbalance(node);
if (b > 1 && key < node->lc->key)    
return rightrotate(node);
if (b < -1 && key > node->rc->key)  
return leftrotate(node);
if (b > 1 && key > node->lc->key)  
{
node->lc =  leftrotate(node->lc);
return rightrotate(node);
}
if (b < -1 && key < node->rc->key) 
{
node->rc = rightrotate(node->rc);
return leftrotate(node);
}
node->siz = size(node);
return node;
}



int iton(struct tree *root,int i)
{
    if(root==NULL)
      {
       cout<<"error";
       return 0;
       
      }
int value;
    if(root->lc)
    value = root->lc->siz+1;
else
value = 1;
    //cout<<value;
    if(value == i)
    return root->key;
    
    else if(value <i)
    {
        iton((root->rc) , i-value);
    }
    else if(value>i)
    {
        iton((root->lc) , i);
    }
}

int ntoi(struct tree *root,int n , int r)
{
    if(root==NULL)
      {
       cout<<"error";
       return 0;
       
      }
if(!root->lc)
{
if(root->key == n)
return r+1;
}
    if(root->key == n)
	return (r+root->lc->siz+1);
    if(root->key >n)
	return (ntoi(root->lc,n,r));
    if(root->key <n)
	return(ntoi(root->rc,n,(r+root->lc->siz+1)));
}

int main()
{
    struct tree* root = NULL;
    int n,i,r;
    cout<<"\nEnter the number of nodes to be inserted :\n ";
        cin>>n;
        for(i=0;i<n;i++)
	{

	cout<<"\nEnter new node data ";
	cin>>r;
	root = insertion(root,r);
        }
    
    cout<<"enter the value of i";
    
    cin>>i;
    int x = iton(root , i);
    //cout<<x;
    cout << i<<" order static is " <<x; 
cout<<endl;
cout<<"enter the value of n";
    
    cin>>n;
     x = ntoi(root , n,e);
cout << n<<" is order static  " <<x; 
    return 0;
//nodes 7 values : 26,21,41,47,14,17,30 
}

