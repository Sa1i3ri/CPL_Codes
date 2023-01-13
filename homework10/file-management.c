//
// Created by 14832 on 2022/12/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE_ORDER 20
#define SIZE_FILE 20

typedef struct file{
    char name[SIZE_FILE];
    struct file *pre_fire;
    struct file *son_file1;
    struct file *son_file2;
}File;

File *add_Head_file(char name[]);
File *search(char name[], File *Head);
void append(File *pre_file,char append_file_name[]);
void analyze_order(char order[], char file_name[],File *Head);
void Remove(File *file);
int Query(File *file,int count);
void Free_file(File *Head);


int main(){
    int num_files = 0;
    int num_orders = 0;
    char file_name[SIZE_FILE]={0};
    char order[SIZE_ORDER] = {0};
    char file_name1[SIZE_FILE] = {0};
    char file_name2[SIZE_FILE] = {0};
    scanf("%d %d",&num_files,&num_orders);
    getchar();

    scanf("%s %s",file_name1,file_name2);
    File *Head = add_Head_file(file_name1);

    for(int i = 0;i<num_files-1;i++){
        getchar();
        scanf("%s %s",file_name1,file_name2);
        append(search(file_name2,Head),file_name1);
    }


    for(int i = 0;i<num_orders;i++){
        getchar();
        scanf("%s %s",order,file_name);
        analyze_order(order,file_name,Head);
    }


   // Free_file(Head);
    return 0;
}

File *add_Head_file(char name[]){
    File *file = malloc(sizeof(File));
    strcpy(file->name,name);
    file->pre_fire=NULL;
    file->son_file1=NULL;
    file->son_file2=NULL;
    return file;
}

File *search(char name[], File *Head){
    if(Head == NULL || !strcmp(name,Head->name)){
        return Head;
    }
    File *temp1 = search(name,Head->son_file1);
    File *temp2 = search(name,Head->son_file2);

    if(temp1 == NULL && temp2 == NULL){
        return NULL;
    }else if(temp1==NULL){
        return temp2;
    }else if(temp2 == NULL){
        return temp1;
    }else{
        assert(0);
    }

}

void append(File *pre_file, char append_file_name[]) {
    File *new_file = malloc(sizeof(File));
    strcpy(new_file->name, append_file_name);
    new_file->son_file1 = NULL;
    new_file->son_file2 = NULL;
    new_file->pre_fire = pre_file;

    if(pre_file->son_file1 == NULL){
        pre_file->son_file1 = new_file;
    }else if(pre_file->son_file2 == NULL){
        pre_file->son_file2 = new_file;
    }else{
        assert(0);
    }

}

void analyze_order(char order[], char file_name[],File *Head){
    if(!strcmp(order,"remove")){
        Remove(search(file_name,Head));
    }else if(!strcmp(order,"query")){
        int count = 0;
        count = Query(search(file_name,Head),0);
        printf("%d\n",count);
    }else{
        assert(0);
    }
}

void Remove(File *file){
    if(file == NULL){
        return;
    }
    //为头文件
    if(file->pre_fire == NULL){
        Remove(file->pre_fire->son_file1);
        Remove(file->pre_fire->son_file2);
        free(file);
        return;
    }

    //remove的不是头文件，把上一个文件的son指针搞定
    if(file->pre_fire->son_file1 == file){
        file->pre_fire->son_file1 = NULL;
    }else if(file->pre_fire->son_file2 == file){
        file->pre_fire->son_file2 = NULL;
    }


    Remove(file->son_file1);
    Remove(file->son_file2);

    if(file->son_file1 == NULL && file->son_file2==NULL){
        free(file);
        return;
    }


}

int Query(File *file,int count){
    if(file->son_file1 == NULL && file->son_file2 == NULL){
        return count+1;
    }
    //文件本身
    count++;
    //子文件们
    if(file->son_file1!=NULL){
        count = Query(file->son_file1,count);
    }
    if(file->son_file2!=NULL){
        count = Query(file->son_file2,count);
    }

    return count;
}

void Free_file(File *Head){
    Remove(Head);
}



