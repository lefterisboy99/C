#include <stdio.h>
#include <stdlib.h>

int **world;
int **new_world;
int row, col;

void load_world_from_file(char *filename){
    int i, k;
    char x;
    FILE *fp;
    fp = fopen(filename,"r");
    fscanf(fp,"%d %d\n",&row, &col);
       new_world=(int**)malloc(row*sizeof(int));
        world=(int**)malloc(row*sizeof(int));
    for(i=0; i<row; i++){
        world[i]=(int*)malloc(col*sizeof(int));
        new_world[i]=(int*)malloc(col*sizeof(int));
    }
    i=0;
    k=0;
    while(1){
        x=getc(fp);
        if(x!=EOF){
            if(x!='|'&& x!='\n' && x!='\0'){
                        if(x=='*'){
				world[i][k]=1;
			}else{
				world[i][k]=0;}
                    k++;
                    if(k==col){
                        i++;
                        k=0;
                    }
            }
        }else break;
    }
}

void save_world_to_file(char *filename){
    int i, k;
    char c;
    FILE *f1;
    f1 = fopen(filename,"w");
    fprintf(f1,"%d %d\n", row, col);
    for(i=0; i<row; i++){
        for(k=0; k<col; k++){
            fprintf(f1,"|");
		if(world[i][k]){
			c='*';
		}else {
			c=' ';}
            fprintf(f1,"%c",c);
        }
        fprintf(f1,"|");
        fprintf(f1,"\n");
    }
    fclose(f1);
}





int num_neighbors(int i,int j){
	int N=0;
N=world[i-1][j-1]+world[i-1][j]+world[i-1][j+1]+world[i][j-1]+world[i][j+1]+world[i+1][j-1]+world[i+1][j]+world[i+1][j+1];
return N;
}


int get_next_state(int i,int j){
int num;
num=num_neighbors(i,j);
if ((world[i][j]==1)&&(num<2 || num>3)) return 0;
if((world[i][j]==0)&&(num==3)) return 1;
}



void next_generation(){
	int i,j,num;
for(i=0;i<row;i++){
for(j=0;j<col;j++){
	new_world[i][j]=0;}}
for(i=1;i<row-1;i++){
for(j=1;j<col-1;j++){
       num=get_next_state(i,j);
	new_world[i][j]=num;
}}
for(i=0;i<row;i++){
for(j=0;j<col;j++){
       world[i][j]=new_world[i][j];}}}



int main(){
	int i;
load_world_from_file("input.txt");
for(i=0;i<50;i++){
	next_generation();
}
save_world_to_file("output.txt");
return 0;
}
