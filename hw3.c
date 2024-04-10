#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXN 10

int main(int argc,char *argv[]){
int N,i,j,l,x,y,a=0;
float row,column;
float array[MAXN][MAXN];
float E,max;
float sum_row[MAXN],sum_column[MAXN];
max=0;
l=0;

     if (argc<2 || argc>3){
       printf("\n");
    }else{
         if (strcmp(argv[1],"-check")==0){
                  scanf("%d",&N);
            for(i=0;i<N;i++){
             for (j=0;j<N;j++){
                   scanf("%f",&array[i][j]);}}
                  y=1;
               for (i=0;i<N;i++){
                    row=0;
                for(j=0;j<N;j++){
                    row=row+array[i][j];}
                if (row==1){
                   printf("ROW %d YES\n",i+1);}
                   else{
                   printf("ROW %d NO\n",i+1);
                      y=0;}}
             for (i=0;i<N;i++){
               column=0;
             for (j=0;j<N;j++){
                 column=column+array[j][i];}
             if (column==1){
               printf("COLUMN %d YES\n",i+1);}
              else{
               printf("COLUMN %d NO\n",i+1);
                y=0;}}
             if (y==1){
               printf("MARKOV YES\n");}
             else{
            printf ("MARKOV NO\n");}}
            if (strcmp(argv[1],"-create")==0){
                 srand((unsigned int)time(NULL));
          N=atoi(argv[2]);
          while(l==0){
              a++;
                for (i=0;i<N;i++){
             sum_row[i]=0;
             sum_column[i]=0;
          for(j=0;j<N;j++){
           array[i][j]=0;}}
                 l=1;
                for(i=0;i<N;i++){
                      for(j=0;j<N;j++){
                         if (sum_row[i]>sum_column[j]){
                            max=sum_row[i];}
                          else{
                              max=sum_column[j];}
                        if (max==0){
                           x=rand()%10;
                           E= (float) x;
                            E=E/10;}
                         else if(i==N-1){
                            if (1-sum_column[j]>=0){
                               E=1-sum_column[j];}
                            else{
                                l=0;
                                break;
                            }}
                          else if(j==N-1){
                            if(1-sum_row[i]>=0){
                             E=1-sum_row[i];}
                        else{
                            l=0;
                            break;
                           }
                           }
                          else{
                           E=1-max;
                           y=(int)(E*10);
                           if(y!=0){
                           x=rand()%y;
                           E=(float) x;
                           E=E/10;}
                           else{
                            l=0;
                            break;
                           }}
                          array[i][j]=E;
                          sum_row[i]=sum_row[i]+E;
                          sum_column[j]=sum_column[j]+E;}}
                          for (i=0;i<N;i++){
                           row=0;
                           column=0;
                          for (j=0;j<N;j++){
                            row=row+array[i][j];
                            column=column+array[j][i];}
                          if((row!=1 || column!=1) && (array[i][j]<0)){
                              l=0;}}}
      printf("%d %d\n",N,a-1);
      for(i=0;i<N;i++){
        if(i!=0){
          printf("\n");}
       for (j=0;j<N;j++){
             if(j!=N-1){
                   printf("%.1f ",array[i][j]);}
              else {
                  printf("%.1f",array[i][j]);}}}
            printf("\n");
}}
return 0;
}
