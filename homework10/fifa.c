//
// Created by 14832 on 2022/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct sportsman{
    char name[32];
    int attack;
    int defend;
    int organization;
}Sportsman;

typedef struct nation{
    char name[32];
    Sportsman mumbers[11];
}Nation;

void compare_nations_and_print(Nation nations[],int what_object,int num);
float average_attack(const Nation *nation);
float average_defend(const Nation *nation);
float average_organization(const Nation *nation);
int compare_bigger(const void *a, const void *b);



int main() {
    int num = 0;
    scanf("%d", &num);
    getchar();

    Nation *nations = malloc(num * sizeof(Nation));

    for (int i_nations = 0; i_nations < num; i_nations++) {
        gets(nations[i_nations].name);
        for (int i_sportsman = 0; i_sportsman < 11; i_sportsman++) {
            scanf("%s",nations[i_nations].mumbers[i_sportsman].name);
            int attack = 0;
            int defend = 0;
            int organization = 0;
            scanf("%d %d %d", &attack, &defend, &organization);
            nations[i_nations].mumbers[i_sportsman].attack = attack;
            nations[i_nations].mumbers[i_sportsman].defend = defend;
            nations[i_nations].mumbers[i_sportsman].organization = organization;
            getchar();
        }
    }

    for(int i = 0;i<3;i++){
        compare_nations_and_print(nations,i,num);
        printf("\n");
    }

    free(nations);
}


void compare_nations_and_print(Nation nations[],int what_object,int num){
    typedef struct nation_scores{
        char name[32];
        float scores;
    }Scores;

    Scores *scores = malloc(num * sizeof(*scores));

    for(int i = 0;i<num;i++){
        strcpy(scores[i].name,nations[i].name);
        switch (what_object) {
            case 0:
                scores[i].scores = average_attack(&nations[i]);
                break;
            case 1:
                scores[i].scores = average_defend(&nations[i]);
                break;
            case 2:
                scores[i].scores = average_organization(&nations[i]);
                break;
            default:
                assert(0);
        }
    }

    qsort(scores,num, sizeof(*scores),compare_bigger);

    for (int i = 0; i < num; ++i) {
        printf("%s ",scores[i].name);
    }

    free(scores);
}

int compare_bigger(const void *a, const void *b){
    typedef struct nation_scores{
        char name[32];
        float scores;
    }Scores;
    const Scores *c = a;
    const Scores *d = b;

    float num_c = c->scores;
    float num_d = d->scores;

    if(num_c>num_d){
        return -1;
    } else if(num_c == num_d){
        return 0;
    } else{
        return 1;
    }

}

float average_attack(const Nation *nation){
    float general = 0;
    for(int i = 0;i<11;i++){
        general += nation->mumbers[i].attack;
    }

    return general/11;
}
float average_defend(const Nation *nation){
    float general = 0;
    for(int i = 0;i<11;i++){
        general += nation->mumbers[i].defend;
    }

    return general/11;
}
float average_organization(const Nation *nation){
    float general = 0;
    for(int i = 0;i<11;i++){
        general += nation->mumbers[i].organization;
    }

    return general/11;
}