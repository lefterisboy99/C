#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    char line1[1000],line2[1000];
    int flag,i,j,l,k;
    int histogram1[256];
    int histogram2[256];
    FILE *f2;
    FILE *f1;


      f2=fopen(argv[2],"r");
      f1=fopen(argv[1],"r");
                         if(f1==(FILE*)NULL || f2==(FILE*)NULL){
                            printf("error 404\n");
                            fclose(f1);
                            fclose(f2);
                            exit(-1);}




                                 for(i=0;i<256;i++){
                                                   histogram1[i]=0;
                                                      histogram2[i]=0;}

           while(fgets(line1,1000,f1) && fgets(line2,1000,f2)){
flag=1;

                            if(strcmp(line1,line2)==0){
                                   printf("TRUE\n");}
                              else{
                                 for(j=0;j<=strlen(line1);j++){
                                    if(line1[j]!=' ' || line1[j]!='\n' || line1[j]!='\0'){
                                             histogram1[toupper(line1[j])]++;}}
                                 for(l=0;l<=strlen(line2);l++){
                                    if(line2[l]!=' ' || line2[l]!='\n' || line2[l]!='\0'){
                                           histogram2[toupper(line2[l])]++;}}
                   for(k=0;k<256;k++){
                     if(histogram1[k]!=histogram2[k]){
                         flag=0;}}
                if(flag){
                    printf("TRUE\n");}
                  else{
                      printf("FALSE\n");}
              for(k=0;k<256;k++){
                  histogram1[k]=0;
                  histogram2[k]=0;}

}}
fgets(line2,1000,f2);
              if(!feof(f1)&& feof(f2)){
                printf("TRAILING LINES IN %s\n",argv[1]);}
               if(!feof(f2) && feof(f1)){
                 printf("TRAILING LINES IN %s\n",argv[2]);}
fclose(f1);
fclose(f2);
return 0;
}
