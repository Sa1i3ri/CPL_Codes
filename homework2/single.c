//
// Created by 14832 on 2022/10/10.
//

#include "stdio.h"

int main(){
    int n;
    scanf("%d",&n);
    int a[100]={0};
    int b[1000]={0};
    for(int i = 0;i<2*n-1;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<2*n-1;i++){
        b[a[i]] = b[a[i]]+1;
    }
    for(int i = 0;i<=2*n-1;i++){
        if(b[a[i]]==1){
            printf("%d",a[i]);
        }
    }
}

//int main() {
//    int a[1000000] = {0};
//    int n = 0;
//    int x = 0;
//    scanf("%d ", &n);
//    for (int i = 1; i <= 2 * n - 1; ++i) {
//        scanf("%d", &x);
//        a[x]++;//根据CSDN-算法之桶排序
//    }
//    for (int i = 0; i <= 10 * n; ++i) {
//        if (a[i] == 1) {
//            printf("%d", i);
//        }
//    }
//
//    return 0;
//}


