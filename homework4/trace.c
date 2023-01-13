
#include "stdio.h"

#define SIZE 55

int main(){
    int n,m,x0,y0,x,y;
    scanf("%d %d %d %d",&n,&m,&x0,&y0);
    x=x0;
    y=y0;
    int count = 0;
    int vis[SIZE][SIZE]={0};
    vis[x0][y0]=1;


    char s[SIZE][SIZE]={0};

    int vectors[4][2] ={{0,1},
                        {0,-1},
                        {1,0},
                        {-1,0}};

    for(int i = 1;i<=n;i++){
        getchar();
        for(int j = 1;j<=m;j++){
            scanf("%c",&s[i][j]);
            if(s[i][j]=='#'){
                count++;
            }
        }
    }


    printf("%d\n",count);
    printf("%d %d\n",x0,y0);

    while (count>0) {
        for (int k = 0; k < 4; k++) {
            int new_i = x + vectors[k][0];
            int new_j = y + vectors[k][1];

            if (s[new_i][new_j] == '#' && vis[new_i][new_j] == 0) {
                vis[new_i][new_j] = 1;
                x = new_i;
                y = new_j;
                printf("%d %d\n", x, y);
                break;
            }

        }
        count--;

    }
}