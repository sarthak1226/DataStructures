#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head;

struct node *push(int val,struct node* start)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));

    if (start== NULL)
    {
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(start->data<val) start->right=push(val,start->right);
    if(start->data>val) start->left=push(val,start->left);
return start;
}

struct node* pop(int val)
{
    struct node *cur;
    struct node *parent;
    cur=head;
    while(cur!=NULL && val!=cur->data){
        
        if(cur->data>val)cur=cur->left;
        else cur=cur->right;
    }

    if(cur->left!=NULL&& cur->right!=NULL){
        struct node *temp=cur->left;
        struct node *tempParent=cur;
        while(temp->right!=NULL&&temp!=NULL){
            tempParent=temp;
            temp=temp->right;  
        }
        cur->data=temp->data;
        tempParent->right=NULL;
       if(tempParent == cur)
    tempParent->left = temp->left;
else
    tempParent->right = temp->left;
        free(temp);

    }


}
















void travers(struct node* cur)
{
    if(cur == NULL)
        return;

        if(cur->left!=NULL)travers(cur->left);
    printf("%d ", cur->data);

    if(cur->right!=NULL)travers(cur->right);
    

}


int search(int val){
    struct node* temp=head;
    while(temp!=NULL){
        if(temp->data==val) return 1;
        if(temp->data>val){
  temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return -1;
}








int main()
{
    head=push(10,head);
    head=push(5,head);
    head=push(3,head);
    head=push(18,head);
    head=push(6,head);
    head=push(19,head);
    head=push(15,head);
    head=push(16,head);
    head=push(11,head);
    head=push(14,head);
    travers(head);
}
