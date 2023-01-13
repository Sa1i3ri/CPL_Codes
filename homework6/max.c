//
// Created by 14832 on 2022/11/6.
//

#include "stdio.h"


int s[1000]={0};
int ans[1000][2]={0};

int max_index(const int p[] , int start ,int final);
void find(const int p[] , int start , int final);

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 1;i<=n;i++){
        scanf("%d",&s[i]);
    }

    find(s,1,n);

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }

}

int max_index(const int p[] , int start ,int final){
    int max = 0;
    int index = -1;
    for(int i = start ; i<=final;i++){
        if(p[i]>max){
            max = p[i];
            index = i;
        }
    }
    return index;
}

void find(const int p[], int start, int final) {
    if (start > final) {
        return;
    }


    ans[max_index(p, start, final)][0] = start;
    ans[max_index(p, start, final)][1] = final;
    find(p, start, max_index(p, start, final) - 1);
    find(p, max_index(p, start, final) + 1, final);




}

