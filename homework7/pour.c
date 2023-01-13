//
// Created by 14832 on 2022/11/21.
//

#include "stdio.h"



int change(int *judge,int k,int va,int vb,int vc,int a,int b,int c,int a0,int b0,int c0);
void pour_s_t(int m[],int vt,int s,int t,int index_s,int index_t);

int main(){
    int k,va,vb,vc,a,b,c,a0,b0,c0;
    scanf("%d %d %d %d %d %d %d %d %d %d",&k,&va,&vb,&vc,&a,&b,&c,&a0,&b0,&c0);

    int judge = 0;
    int q = change(&judge,k,va,vb,vc,a,b,c,a0,b0,c0);
    if(q){
        printf("Yes");
    }else{
        printf("No");
    }


}

int change(int *judge,int k,int va,int vb,int vc,int a,int b,int c,int a0,int b0,int c0){
    if(a == a0 && b==b0 && c==c0){
        return 1;
    }


    if(k==0){
        return 0;
    }

    int section_1 [3] = {a,b,c};
    int section_2 [3] = {a,b,c};
    int section_3 [3] = {a,b,c};
    int section_4 [3] = {a,b,c};
    int section_5 [3] = {a,b,c};
    int section_6 [3] = {a,b,c};


    //a->b
    pour_s_t(section_1,vb,a,b,0,1);

    if(section_1[0]==a0 && section_1[1]==b0 && section_1[2]==c0){
        *judge = 1;
    }else{
        change(judge,k-1,va,vb,vc,section_1[0],section_1[1],section_1[2],a0,b0,c0);
    }


    //b->c
    pour_s_t(section_2,vc,b,c,1,2);

    if(section_2[0]==a0 && section_2[1]==b0 && section_2[2]==c0){
        *judge = 1;
    }else{
        change(judge,k-1,va,vb,vc,section_2[0],section_2[1],section_2[2],a0,b0,c0);
    }

    //c->a
    pour_s_t(section_3,va,c,a,2,0);

    if(section_3[0]==a0 && section_3[1]==b0 && section_3[2]==c0){
        *judge = 1;
    }else{
        change(judge,k-1,va,vb,vc,section_3[0],section_3[1],section_3[2],a0,b0,c0);
    }

    //b->a
    pour_s_t(section_4,va,b,a,1,0);

    if(section_4[0]==a0 && section_4[1]==b0 && section_4[2]==c0){
        *judge = 1;
    }else{
        change(judge,k-1,va,vb,vc,section_4[0],section_4[1],section_4[2],a0,b0,c0);
    }

    //c->b
    pour_s_t(section_5,vb,c,b,2,1);

    if(section_5[0]==a0 && section_5[1]==b0 && section_5[2]==c0){
        *judge = 1;
    }else{
        change(judge,k-1,va,vb,vc,section_5[0],section_5[1],section_5[2],a0,b0,c0);
    }

    //a->c
    pour_s_t(section_6,vc,a,c,0,2);

    if(section_6[0]==a0 && section_6[1]==b0 && section_6[2]==c0){
        *judge = 1;
    }else{
        change(judge,k-1,va,vb,vc,section_6[0],section_6[1],section_6[2],a0,b0,c0);
    }

    return *judge;


}

void pour_s_t(int m[],int vt,int s,int t,int index_s,int index_t){
    if(s+t>=vt){
        m[index_s]=0;
        m[index_t]=vt;
    }else{
        m[index_s] = 0;
        m[index_t]=s+t;
    }
}


