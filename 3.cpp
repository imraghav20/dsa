#include<iostream>
using namespace std;
struct node
{
    int v;
    struct node* l;
    struct node* r;
};
struct node* insert(int val,struct node* root)
{
    if(root==NULL)
    {
        struct node* temp=new node();
        temp->v=val;
        temp->l=temp->r=NULL;
        return temp;
    }
    else if(val<root->v)
    {
        root->l = insert(val,root->l);
    }
    else
    {
        root->r = insert(val,root->r);
    }
    return root;
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->l);
    cout<<root->v<<" ";
    inorder(root->r);
}
struct node* min_val(struct node* n)
{
    struct node* temp=n;
    while (n->l !=NULL)
    {
        n=n->l;
    }
    return temp;  
}
struct node* successor(struct node* root,struct node* n)
{
    if(n->r !=NULL)
    {
        return min_val(n->r);
    }
    else
    {
        struct node* temp=root;
        struct node* succ=NULL;
        while (temp!=NULL)
        {
            if(n->v < temp->v)
            {
                succ=temp;
                temp=temp->l;
            }
            else if(n->v > temp->v)
            {
                temp=temp->r;
            }
            else
            {
                break;
            }
        }
        return succ;
    }
}
struct node* max_val(struct node* n)
{
    struct node* temp=n;
    while (n->r !=NULL)
    {
        n=n->r;
    }
    return temp;  
}
struct node* predecessor(struct node* root,struct node* n)
{
    if(n->l !=NULL)
    {
        return max_val(n->l);
    }
    else
    {
        struct node* temp=root;
        struct node* succ=NULL;
        while (temp!=NULL)
        {
            if(n->v < temp->v)
            {
                temp=temp->l;
            }
            else if(n->v > temp->v)
            {
                succ=temp;
                temp=temp->r;
            }
            else
            {
                break;
            }
        }
        return succ;
    }
}
struct node* bs(struct node* root ,int v)
{
    struct node* temp=root;
    while (temp!=NULL)
    {
        if(v<temp->v)
        {
            temp=temp->l;
        }
        else if(v>temp->v)
        {
            temp=temp->r;
        }
        else
        {
            break;
        }
    }
    return temp;   
}

int main()
{
    struct node* root=NULL;
    int n;
    int v;
    int succ_val;
    int predecessor_val;
    cout<<"size=";
    cin>>n;
    cout<<"\nenter the elements=";
    while (n--)
    {
        cin>>v;
        root=insert(v,root);
    }

    cout<<"\n enorder=";
    inorder(root);

    cout<<"\nenter succ val=";
    cin>>succ_val;
    struct node* temp=successor(root,bs(root,succ_val));
    cout<<"\nsuccessor = "<<temp->v;

    cout<<"\npredecessor_val=";
    cin>>predecessor_val;
    struct node* tem=predecessor(root,bs(root,predecessor_val));
    cout<<"\npredecesoor = "<<tem->v;
    
    return 0;
}