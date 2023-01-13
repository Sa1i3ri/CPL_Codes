//
// Created by 14832 on 2022/12/7.
//

#include <assert.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define SIZE 20000
#define N 100

int number_of_variable = 0;

typedef  enum type{
    SPACE,
    ERROR,
    INT,
    FLOAT,
    OPERATOR,
    VARIABLE,
}Type;

typedef struct token{
    Type type ;
    char str[N];
}Token;

Token token[SIZE];

typedef struct value{
    Type type;

    union {
        int iVal;
        double fVal;
    }val;

}Value;

Value error={
        .type = ERROR,
};

typedef struct assignment{
    char name[N];
    Type type;
    union {
        int iVal;
        double fVal;
    }val;
}Assignment;
Assignment assignment[SIZE];

int detect_types(char s[]);
Value eval(int l,int r);
void printValue(Value v);
Value evalAssign(int l,int r,int *state,int *temp_op);
int check_parentheses(int l,int r);
int find_main_operator(int l,int r);
bool is_in_parentheses(int l,int r,int op);
Value meetValue(Value v1,Value v2,int op);
void skip_space(char des[], char ori[]);

int op_of_space_l = -1;
int op_of_space_r = -1;


int main(){

    Value ans[N];
    int index_ans = 0;

    char copy[SIZE] = {0};



    while (gets(copy) != NULL ) {


        int count = 0;
        int state = -1;
        int temp_op = -1;
        op_of_space_l = -1;
        op_of_space_r = -1;

        for(int i = 0;i<SIZE;i++){
            skip_space(token[i].str,copy);
            op_of_space_l = op_of_space_r;
            count++;


            if(copy[op_of_space_r] == 0 || (copy[op_of_space_r] == ' ' && copy[op_of_space_r+1] == 0)){
                break;
            }
        }



        int temp_judge = 0;

        for (int i = 0; i<count; ++i) {
            token[i].type = detect_types(token[i].str);
            if (token[i].type == ERROR) {
                ans[index_ans].type = ERROR;
                index_ans++;
                temp_judge = 1;
                break;
            }
        }

        if(temp_judge){
            for(int i = 0;i<SIZE;i++){
                copy[i] = 0;
                token[i].type = SPACE;
                for(int j = 0;j<N;j++){
                    token[i].str[j] = 0;
                }
            }
            continue;
        }


        if(evalAssign(0, count - 1,&state,&temp_op).type == ERROR){
            ans[index_ans].type = ERROR;
            index_ans++;
            for(int i = 0;i<SIZE;i++){
                copy[i] = 0;
                token[i].type = SPACE;
                for(int j = 0;j<N;j++){
                    token[i].str[j] = 0;
                }
            }
            continue;
        }

        if(state == 1){
            ans[index_ans].type = assignment[temp_op].type;
            if(assignment[temp_op].type==INT){
                ans[index_ans].val.iVal = assignment[temp_op].val.iVal;
            }else if(assignment[temp_op].type==FLOAT){
                ans[index_ans].val.fVal = assignment[temp_op].val.fVal;
            }
        }else if(state == -1){
            ans[index_ans] = eval(0, count - 1);
        }

        index_ans++;

        for(int i = 0;i<SIZE;i++){
            copy[i] = 0;
            token[i].type = SPACE;
            for(int j = 0;j<N;j++){
                token[i].str[j] = 0;
            }
        }

    }



    for(int i = 0;i<index_ans;i++){
        printValue(ans[i]);
    }





}


int detect_types(char s[]){

    if(s[0] == ' ' && strlen(s) == 1){
        return SPACE;
    }

    //operator
    if((s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '(' || s[0] == ')' || s[0] == '=' ) &&
       strlen(s) == 1){
        return OPERATOR;
    }

    //variable
    int m = 0;
    int judge_variable = 1;
    if(s[0]>='0'&& s[0]<='9'){
        judge_variable = 0;
    }else{
        while(s[m]!=0){
            if(!((s[m]>='A' && s[m] <='Z') || (s[m]>='0' && s[m] <='9') || (s[m]>='a' && s[m] <='z') || s[m]=='_')){
                judge_variable = 0;
                break;
            }
            m++;
        }
    }

    if(judge_variable){
        return VARIABLE;
    }

    //否则就是number(int float)
    int count_dian = 0;
    int op_of_dian = -1;
    int index = 0;
    int judge_number = 1;
    while (s[index] != 0){
        if(s[index] == '.'){
            count_dian++;
            op_of_dian = index;
            index++;
            continue;
        }
        if(s[index] < '0' || s[index] > '9'  ){
            judge_number=0;
            break;
        }
        index++;
    }
    if(judge_number){

        if(count_dian == 0){
            //int

            if(s[0] == '0' && strlen(s) == 1){
                return INT;
            }else if(s[0] == '0' && strlen(s)!=1){
                return ERROR;
            }

            return INT;


        }else if(count_dian == 1){
            //float

            int is_there_only_zero = 1;
            for(int j = 0; j < op_of_dian; j++){
                if(s[j] != '0'){
                    is_there_only_zero = 0;
                    break;
                }
            }

            if(op_of_dian == strlen(s)-1 || op_of_dian == 0 || (is_there_only_zero && op_of_dian!=1)){
                return ERROR;
            } else{
                return FLOAT;
            }

        }
    }
    //都不是就是error
    return ERROR;
}

Value eval(int l,int r){

    int check = check_parentheses(l, r);

    if(check == -1){
        return error;
    }

    if(l>r){
        return error;
    }else if(l==r){
        Value temp;
        temp.type = token[l].type;
        if(temp.type == FLOAT){
            temp.val.fVal = atof(token[l].str);
        }else if(temp.type == INT){
            temp.val.iVal = atoi(token[l].str);
        }else if(temp.type == VARIABLE){
            //是个变量 待会写
            for(int i = 0;i<number_of_variable+2;i++){
                int judge = strcmp(token[l].str, assignment[i].name);
                if(!judge){
                    if(assignment[i].type==INT){
                        temp.type = INT;
                        temp.val.iVal = assignment[i].val.iVal;
                    }else if(assignment[i].type== FLOAT){
                        temp.type = FLOAT;
                        temp.val.fVal = assignment[i].val.fVal;
                    }
                    break;
                }

            }

            if(temp.type == VARIABLE){
                temp=error;
            }

        } else{
            temp = error;
        }
        return temp;
    }else if(check == true){
        //check括号
        return eval(l+1,r-1);
    }else if(token[l].str[0] == '-'){
        Value temp;

        int op = find_main_operator(l, r);
        if (op != -1) {
            Value val1 = eval(l, op - 1);
            Value val2 = eval(op + 1, r);
            //合流
            return meetValue(val1, val2, op);
        }

        temp = eval(l+1,r);
        if(temp.type == INT){
            temp.val.iVal = (-1)*temp.val.iVal;
        }else if(temp.type==FLOAT){
            temp.val.fVal = (-1.0)*temp.val.fVal;
        }
        return temp;


    }else{
        int op = find_main_operator(l,r);
        if(op == -1){
            return error;
        }

        Value val1 = eval(l,op-1);
        Value val2 = eval(op+1,r);
        //合流
        return  meetValue(val1,val2,op);
    }

}

Value evalAssign(int l,int r,int *state,int *temp_op){
    //state 默认-1 错误0 有赋值操作1

    int is_there_equal = 0;
    int first_index = -1;
    for(int i = l;i<=r;i++){
        if(token[i].str[0] == '='){
            first_index = i;
            is_there_equal=1;
            *state = 1;
            break;
        }
    }

    int appear_before = 0;
    int op = 0;

    if(is_there_equal){

        for(int i = l;i<=first_index;i++){
            if(token[i].type == OPERATOR && token[i].str[0]!= '='){
                return error;
            }
        }


        if(token[first_index-1].type == VARIABLE){

            for(int i = 0;i<number_of_variable+2;i++){
                if(!strcmp(token[first_index-1].str, assignment[i].name)){
                    appear_before = 1;
                    op = i;
                    break;
                }
            }

            if(!appear_before){

                Value temp = evalAssign(first_index+1,r,state,temp_op);

                strcpy(assignment[number_of_variable].name,token[first_index-1].str);

                assignment[number_of_variable].type =temp.type;

                if(temp.type == INT){
                    assignment[number_of_variable].val.iVal = temp.val.iVal;
                }else if(temp.type == FLOAT){
                    assignment[number_of_variable].val.fVal = temp.val.fVal;
                }

                *temp_op = number_of_variable;
                number_of_variable ++;
                return temp;
            }else{
                Value temp = evalAssign(first_index+1,r,state,temp_op);
                assignment[op].type = temp.type;

                if(temp.type == INT){
                    assignment[op].val.iVal = temp.val.iVal;
                }else if(temp.type == FLOAT){
                    assignment[op].val.fVal = temp.val.fVal;
                }
                *temp_op = op;
                return temp;
            }

        }else{
            return error;
        }



    }else{
        Value v = eval(l,r);
        return v;
    }



}

int check_parentheses(int l,int r){
    int t = 0;

    if(token[l].str[0] != '(' || token[r].str[0] != ')'){
        return false;
    }

    for(int i = l;i<=r;i++){
        if(token[i].str[0] == '('){
            t++;
        }else if(token[i].str[0] == ')'){
            t--;
        }

        if((t < 0 && i<r)  || (t !=0 && i==r)){
            //表达式括号不合法
            return -1;
        }else if(t == 0 && i<r){
            return false;
        }
    }

    return true;

}

int find_main_operator(int l,int r){
    int op = -1;

    for (int i = r; i >= l; i--) {
        if ((token[i].str[0] == '+' || token[i].str[0] == '-') && is_in_parentheses(l, r, i) == false) {

            if (token[i].str[0] == '-' && (token[i - 1].str[0] == '+' || token[i - 1].str[0] == '-'
                                           || token[i - 1].str[0] == '*' || token[i - 1].str[0] == '/' || i == l)) {
                continue;
            }

            op = i;
            return op;
        }
    }

    for(int i = r;i>l;i--){
        if((token[i].str[0] == '*' || token[i].str[0] == '/') && is_in_parentheses(l,r,i) == false){
            op = i;
            return op;
        }
    }

    return op;

}

bool is_in_parentheses(int l,int r,int op){
    int s = 0;
    for(int i = l;i<=op;i++){
        if(token[i].str[0] == '('){
            s++;
        }else if(token[i].str[0] == ')'){
            s--;
        }
    }

    if(s>0){
        return true;
    } else{
        return false;
    }

}

Value meetValue(Value v1,Value v2,int op){
    if(v1.type == ERROR || v2.type == ERROR){
        return error;
    }

    if(v1.type != v2.type){
        if(v1.type == INT){
            v1.type = FLOAT;
            v1.val.fVal = (double)v1.val.iVal;
            v1.val.iVal = 0;
        }else if(v2.type == INT){
            v2.type = FLOAT;
            v2.val.fVal = (double)v2.val.iVal;
            v2.val.iVal = 0;
        }
    }

    Value temp = v1;

    if(temp.type == INT){
        switch (token[op].str[0]) {
            case '+': temp.val.iVal = temp.val.iVal + v2.val.iVal;
                return temp;
            case '-': temp.val.iVal = temp.val.iVal - v2.val.iVal;
                return temp;
            case '*': temp.val.iVal = temp.val.iVal * v2.val.iVal;
                return temp;
            case '/': temp.val.iVal = temp.val.iVal / v2.val.iVal;
                return temp;
        }
    }else if(temp.type == FLOAT){
        switch (token[op].str[0]) {
            case '+': temp.val.fVal = temp.val.fVal + v2.val.fVal;
                return temp;
            case '-': temp.val.fVal = temp.val.fVal - v2.val.fVal;
                return temp;
            case '*': temp.val.fVal = temp.val.fVal * v2.val.fVal;
                return temp;
            case '/': temp.val.fVal = temp.val.fVal / v2.val.fVal;
                return temp;
        }
    }


}

void printValue(Value v){
    if(v.type == INT){
        printf("%d\n",v.val.iVal);
    } else if(v.type==FLOAT){
        printf("%.6f\n",v.val.fVal);
    }else if(v.type == ERROR){
        printf("Error\n");
    }
}

void skip_space(char des[], char ori[]){


    for (int i = op_of_space_l+1; i < SIZE; i++) {
        if (ori[i] == ' ' || ori[i] == 0 || ori[i] == '\0' || ori[i] == '\n') {
            op_of_space_r = i;
            break;
        }
    }

    for(int i = 0;i<=op_of_space_r - op_of_space_l - 2;i++){
        des[i] = ori[i+op_of_space_l+1];
    }




}


