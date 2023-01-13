#include "stdio.h"
#include "math.h"
#define SIZE 100

void change(int s_id[],int num[],int id,int k,int *len);

int main(){
    int s_id[SIZE]={0};
    int num[SIZE]={0};
    for(int i = 0;i<SIZE;i++){
        num[i] = -1;
    }

    int order[SIZE][5]={0};

    int n ,q;
    int len = 1;

    scanf("%d %d",&n,&q);
    getchar();
//这里需要继续写
    for(int i = 1;i<=q;i++){
        scanf("%c",&order[i][0]);
        if(order[i][0]=='A'){
            scanf("%d %d",&order[i][1],&order[i][2]);
        }
        getchar();
    }

    num[1]=n;


    for(int i = 1;i<=q;i++){
        if(order[i][0] == 'Q' && i==1){
            printf("1\n");
            printf("%d ",s_id[1]);
            printf("\n");
        }else if(order[i][0]=='Q' && i>=2){

            printf("%d\n",len);

            for(int j = len;j>=1;j--){
                printf("%d ",s_id[j]);
            }
            printf("\n");

        }else if(order[i][0]=='A'){


            int k = -1;
            for(int j = 0;j<31;j++){
                if( (1<<(j-1)) <order[i][2] && (1<<j) >=order[i][2]){
                    k=j;
                    break;
                }
            }
            change(s_id,num,order[i][1],k,&len);
        }


    }

}

void change(int s_id[],int num[],int id,int k,int *len){

    while (1){
        for(int i = *len;i>=1;i--){
            if(num[i] == k && s_id[i] == 0){
                s_id[i] = id;
                return;
            }
            if(num[i]> k && s_id[i] == 0){
                for(int j = *len+1;j>=i+2;j--){
                    num[j]=num[j-1];
                    s_id[j]=s_id[j-1];
                }


                num[i]=num[i]-1;
                num[i+1] = num[i];
                s_id[i+1]=s_id[i];
                *len = *len+1;
                break;
            }

        }
        //反着分裂
//        for(int i = *len;i>=1;i--){
//            if(num[i]> k && s_id[i] == 0){
//                num[i]=num[i]-1;
//                num[i+1] = num[i];
//                *len = *len+1;
//                break;
//            }
//        }
    }


}

