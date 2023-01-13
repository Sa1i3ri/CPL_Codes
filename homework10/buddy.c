//
// Created by 14832 on 2022/12/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct space{
    int id;
    int memory_size;
    struct space *Next;
}Space;

Space *init(int max_memory);
void question(Space *Head);
int question_general(Space *Head, int count);
void question_print_each_one(Space *Head);
void assign(Space *Head, Space *present,int id, int ask_memory);
void generate(Space *pre_memory);
int bit_process(int num);

int main(){
    int max_memory = 0;
    int num_operation = 0;
    char order;
    int id;
    int ask_memory;

    scanf("%d %d", &max_memory, &num_operation);
    Space *Head = init(max_memory);

    for(int i = 0;i<num_operation;i++){
        getchar();
        scanf("%c",&order);
        if(order == 'Q'){
            question(Head);
        }else if(order == 'A'){
            scanf("%d %d",&id,&ask_memory);
            assign(Head,Head ,id, bit_process(ask_memory));
        }
    }


}

Space *init(int max_memory){
    Space *node = malloc(sizeof(*node));
    node->id=0;
    node->Next = NULL;
    node->memory_size = max_memory;
    return node;
}

void question(Space *Head){
    printf("%d\n", question_general(Head,0));
    question_print_each_one(Head);
    printf("\n");
}

int question_general(Space *Head, int count){
    if(Head == NULL){
        return count;
    }
    count++;
    return question_general(Head->Next,count);
}

void question_print_each_one(Space *Head){
    if(Head == NULL){
        return;
    }
    printf("%d ",Head->id);
    question_print_each_one(Head->Next);

}

void assign(Space *Head,Space *present, int id, int ask_memory){
    if(present == NULL)return;

    if(present->id == 0 && present->memory_size == ask_memory){
        present->id = id;
        return;
    }else if(present->id == 0 && present->memory_size > ask_memory){
        generate(present);
        assign(Head,present,id,ask_memory);
    }else{
        assign(Head,present->Next,id,ask_memory);
    }

}

void generate(Space *pre_memory){

    if(pre_memory->memory_size <=0){
        return;
    }

    Space *node = malloc(sizeof(*node));
    node->id=0;
    node->memory_size = pre_memory->memory_size -1;
    node->Next = pre_memory->Next;
    pre_memory->memory_size--;
    pre_memory->Next = node;
}

int bit_process(int num){
    for(int i = 0;i<31;i++){
        if(pow(2,i-1)<num && pow(2,i)>=num){
            return i;
        }
    }

    return -1;
}
