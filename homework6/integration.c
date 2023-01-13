//
// Created by 14832 on 2022/11/6.
//

#include "stdio.h"
#include "math.h"

int po[100]={0};

double f(const int p[],int p_max_index,int main_p,double num);
double s(const int p[],int p_max_index,int main_p,double a,double b);
double find(const int p[],int p_max_index,int main_p,double l,double r,double e);

int main(){
    int  p_max_index , main_p ;
    double a ,b;
    double e =0.0000000001;
    scanf("%d %d",&p_max_index ,&main_p);
    getchar();
    for(int i = 0;i<=p_max_index;i++){
        scanf("%d",&po[i]);
    }
    getchar();
    scanf("%lf %lf",&a ,&b);

    double ans = find(po,p_max_index,main_p,a,b,e);

    printf("%f",ans);

}



double f(const int p[],int p_max_index,int main_p,double num){
    double ans = 0;
    if(num == 0){
        return 0;
    }

    for(int i = 0;i<= p_max_index;i++){
        ans += p[i] * pow(num , i);
    }

    ans = pow(ans,main_p);
    return ans;

}


double s(const int p[],int p_max_index,int main_p,double a,double b){


    return (b-a)*( 4* f(p,p_max_index,main_p,(a+b)/2) + f(p,p_max_index,main_p,a) + f(p,p_max_index,main_p,b))/6;


}

double find(const int p[],int p_max_index,int main_p,double l,double r,double e){
    double mid = (l+r)/2;
    double SL = s(p,p_max_index,main_p,l,mid);
    double SR = s(p,p_max_index,main_p,mid,r);
    double S = s(p,p_max_index,main_p,l,r);

    if(fabs( SL + SR - S ) <= 15*e ){
        return  SL + SR + (SL + SR - S)/15;
    }else{
        return  find(p, p_max_index,main_p, l, mid,e/2) + find(p, p_max_index,main_p, mid, r,e/2);
    }
}


