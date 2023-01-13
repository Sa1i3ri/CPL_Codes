//
// Created by 14832 on 2022/12/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

    char *s;
    struct node* next;
}Node;
typedef struct list{
    Node*head;
    Node*tail;
}List;
List nodes[500005];//



int hash(const char* s,int m){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++) ret=(ret+s[i]*(i+1))%m;
    return ret;
}
void init(List *lst){
    lst->head=NULL;
    lst->tail=NULL;
}
void append(List* node,const char*s){
    char *temp = malloc((strlen(s)+1) * sizeof(char));
    Node* newnode=malloc(sizeof (Node*));
    newnode->next=NULL;
    strcpy(temp,s);
    newnode->s = temp;
    if (node->head==NULL){
        node->head=newnode;

    }else {
        node->tail->next = newnode;

    }
    node->tail=newnode;
}


int main(){
    int m,q,a;
    char *s=malloc(1005*sizeof *s);
    scanf("%d %d",&m,&q);
    for(int i=0;i<m;i++){
        init(&nodes[i]);
    }
    for(int i =0;i<m;i++){
        scanf("%s",s);
        append(&nodes[hash(s,m)],s);

    }
    for(int i=0;i<q;i++){
        scanf("%s",s);
        a=hash(s,m);
        int j=0;
        Node *node=nodes[a].head;
        while(node!=NULL) {
            if (!strcmp(node->s, s)) {
                printf("Yes\n");
                j=1;
                break;
            }
            node = node->next;
        }
        if(j==0)printf("No\n");
    }
    free(s);
    return 0;
}
