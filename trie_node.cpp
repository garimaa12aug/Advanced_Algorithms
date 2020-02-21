#include<bits/stdc++.h>

using namespace std;

struct trienode{
map<char, trienode*>children;
bool eow;
};

trienode* new_node()
{
trienode* node = new trienode;
node->eow=false;
return node;
}

void insert(trienode *&root, string str)
{
if(root== NULL)
root = new_node();

int i;
trienode *current = root;
char key;
for(i=0;i<str.length();i++)
{
key = str[i];
if(current->children.find(key) == current->children.end())
current->children[key] = new_node();

current = current->children[key];

}
current->eow = true;
}

bool search(trienode* root, string str)
{
if(root == NULL)
return false;
trienode* current = root;
int i;
char key;
for(i=0;i<str.length();i++)
{
key = str[i];
current = current->children[key];
if(current == NULL)
return false;
}
return current->eow;
}

int main()
{
trienode* head = NULL;
int k;
string s;
string p;

while(1)
{
cout<<"\nchoose operation :\n1.Insertion\n2.Searching\n3.Exit"<<endl;

cin>>k;

switch(k)
{
case 1 : cout<<"enter string to be inserted"<<endl;

cin>>s;
insert(head,s);
cout<<"string inserted successfully in dictionary";
break;
case 2 : cout<<"enter string to be searched";

cin>>p;
bool answer;
answer = search(head , p);
if(answer)
cout<<"string present"<<endl;
else
cout<<"string not present in dictionary"<<endl;
break;
case 3 : exit(0);
}
}
}
