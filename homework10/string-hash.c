//
// Created by 14832 on 2022/12/25.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000
#define N 50

typedef struct element{
    char *content;
    struct element *Next;
}Element;

int hash(char *s);
void init(Element *s[]);
void add(Element **s, char content[]);
bool is_in_here(Element *s, char content[]);

int main(){
    int num_str = 0;
    int num_order = 0;
    char str[SIZE] ={0};
    scanf("%d %d",&num_str,&num_order);

    Element *strs[N];
    init(strs);

    for(int i = 0;i<num_str;i++){
        getchar();
        scanf("%s",str);
        int temp_hash = hash(str);

        add(&strs[temp_hash],str);

    }

    for(int i = 0;i<num_order;i++){
        getchar();
        scanf("%s",str);
        int temp_hash = hash(str);

        if (is_in_here(strs[temp_hash], str)) {
            printf("Yes\n");
        }else{
            printf("No\n");
        }


    }



}

int hash(char *s){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1))%N;
    return ret;
}

void add(Element **s, char content[]){
    if(*s == NULL){
        Element *temp= malloc(sizeof(Element));
        char *node = malloc((strlen(content)+1) * sizeof(char ));
        strcpy(node,content);
        temp->content = node;
        temp->Next = NULL;
        *s = temp;
    }else{
        add(&((*s)->Next),content);
    }
}

bool is_in_here(Element *s, char content[]){
    if(s == NULL){
        return false;
    }

    if(!strcmp(s->content,content)){
        return true;
    }else{
        return is_in_here(s->Next,content);
    }


}

void init(Element *s[]){
    for(int i = 0;i<N;i++){
        s[i] = NULL;
    }
}



