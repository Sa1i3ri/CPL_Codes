#include <string.h>
#include "stdio.h"
#include "stdlib.h"

#define SIZE 5000
int main_judge = 1;
int count = 0;

void process(const char *s,char *ans);
void print(char *ans);

int main(){
    char *s = malloc(SIZE * sizeof(*s));
    char *t = malloc(SIZE * sizeof(char));
    char *ans = malloc(SIZE*20 * sizeof(char));

    while(scanf("%s", s) != EOF){
        if(*s == ';'){
            process(s,ans);
            continue;
        }


        char *position = strchr(s,';');

        if(position == NULL){
            process(s,ans);
        }else{
            strncpy(t,s,position-s);
            *(t+(int)(position-s))=0;
            process(t,ans);

            *t=';';
            process(t,ans);

            strcpy(t,position+1);
         //   *(t+(int)(position-s))=0;
            process(t,ans);
        }

    }

    print(ans);


    free(s);
    free(t);
    free(ans);
}





void process(const char *s, char *ans){
    main_judge = 0;

    if(*s == ';'){
        *(ans + count) = 'h';
        count++;
        main_judge =1;
        return;
    }else if(*s == ' ' || *s ==0){
        return;
    }


    //reserved
    if (!strcmp(s, "const") || !strcmp(s, "int") ||
        !strcmp(s, "float") || !strcmp(s, "double") ||
        !strcmp(s, "long") || !strcmp(s, "static") ||
        !strcmp(s, "void") || !strcmp(s, "char") ||
        !strcmp(s, "extern") || !strcmp(s, "return") ||
        !strcmp(s, "break") || !strcmp(s, "enum") ||
        !strcmp(s, "struct") || !strcmp(s, "typedef") ||
        !strcmp(s, "union") || !strcmp(s, "goto")) {
        main_judge = 1;
        *(ans + count) = 'r';
        count++;
        goto finish;
    }


    //integer float
    int count_dian = 0;
    int i = 0;
    int judge_number = 1;
    while (*(s+i)!=0){
        if(*(s+i)=='.'){
            count_dian++;
            i++;
            continue;
        }
        if(*(s+i) < 48 || *(s+i) > 57  ){
            judge_number=0;
            break;
        }
        i++;
    }
    if(judge_number){
        if(count_dian == 0){
            main_judge = 1;
            *(ans + count) = 'i';
            count++;
        }else if(count_dian == 1){
            main_judge = 1;
            *(ans + count) = 'f';
            count++;
        }
        goto finish;
    }




    //operator

    if(!strcmp(s, "+") || !strcmp(s, "-") || !strcmp(s, "*") || !strcmp(s, "/") || !strcmp(s, "=") ||
       !strcmp(s,"==") || !strcmp(s,"!=") || !strcmp(s,">=") || !strcmp(s,"<=") || !strcmp(s,">") || !strcmp(s,"<") ){
        main_judge=1;
        *(ans + count) = 'o';
        count++;
        goto finish;
    }

    //variable

    int m = 0;
    int judge_variable = 1;
    if(*s>=48 && *s<=57){
        goto finish;
    }
    while(*(s+m)!=0){
        if(!((*(s+m)>=65 && *(s+m) <=90) || (*(s+m)>=48 && *(s+m) <=57) || (*(s+m)>=97 && *(s+m) <=122) || *(s+m)=='_')){
            judge_variable = 0;
            break;
        }
        m++;
    }

    if(judge_variable){
        main_judge=1;
        *(ans + count) = 'v';
        count++;
        goto finish;
    }

    finish:
    if(main_judge==0){
        *(ans + count) = 'c';
        count++;
    }

}

void print(char *ans){
    for(int i = 0;i<count;i++){
        if(*(ans + i) == 'c' || (*(ans+i+1) =='h' && *(ans+i) =='h') || *ans =='h'){
            printf("Compile Error");
            return;
        }
    }


    for(int i = 0;i<count;i++){


        if(*(ans + i) == 'r'){
            printf("reserved ");
        }else if(*(ans + i)=='i'){
            printf("integer ");
        }else if(*(ans + i)=='f'){
            printf("float ");
        }else if(*(ans + i)=='o'){
            printf("operator ");
        }else if(*(ans + i)=='v'){
            printf("variable ");
        }else if(*(ans+i)=='h'){
            if(i == count-1){
                break;
            }
            printf("\n");
        }
    }


}

