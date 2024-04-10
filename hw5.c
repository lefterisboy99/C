#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct x{
int data;
char name[25];
int year;
float money;
struct x *next;
};
typedef struct x node_T;
node_T *root=NULL;




void bubbleSort(node_T *start)
{
                 int temp;
                int hate;
		int l,j;
                float monopoly;
                char tempmovie[25];
		char movieA[25],movieB[25];

    int swapped, i;
    node_T *ptr1;
    node_T *lptr = NULL;


    if (ptr1 == NULL)
        return ;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
		strcpy(movieA,ptr1->name);
		strcpy(movieB,ptr1->next->name);
		for(l=0;l<25;l++){
			if(movieA[i]>movieB[i]){
				j=1;
				break;
			}else{
				j=0;
				}}
            if (j)
            {
		 temp = ptr1->data;
                hate=ptr1->year;
                monopoly=ptr1->money;
                 strcpy(tempmovie,ptr1->name);
                 strcpy(ptr1->name,ptr1->next->name);
                ptr1->data=ptr1->next->data;
                ptr1->year=ptr1->next->year;
                ptr1->money=ptr1->next->money;
                ptr1->next->year=hate;
                ptr1->next->money=monopoly;
                strcpy(ptr1->next->name,tempmovie);
                 ptr1->next->data = temp;
                swapped =1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}






node_T *list_remove_node(node_T *list, node_T *node)
    {
            if( list == NULL) {
            return NULL;
                }
		if(node==NULL){
			return NULL;
			}
            if( list == node) {
                       list = list->next;
		       free(node);
                       return list;
                    }
              list ->next = list_remove_node(list->next, node);
              return list;
    }



int main(int argc,char *argv[]){
    char moviedel[25];
int c,l,a,y,x;
 int chr;
    char name[25],moviename[25];
    int year;
    float income,g,gf;
    int i=1;
    char k,m;
	node_T *head;
	node_T *current;
	node_T *node;
	node_T *freethisshit;
	node_T *swampert;
	node_T *swamp;
					FILE *f;
	   				f=fopen("movies.dat","rb");
				if(f==(FILE *)NULL){
					printf("error 404\n");
					exit(-1);
 				}else{

                root=(node_T*)malloc(sizeof(node_T));
			head=root;
            while(fread(&chr,sizeof(int),1,f)!=0)
                    {
                            if(!i){
                                head->next=(node_T*)malloc(sizeof(node_T));
                                head=head->next;
                                    }
                        fread(name,sizeof(char)*chr,1,f);
                        fread(&year,sizeof(int),1,f);
                        fread(&income,sizeof(float),1,f);
                        head->data=chr;
                        head->year=year;
                        strcpy(head->name,name);
                        head->money=income;
                        head->next=NULL;
                        i=0;
                    } }
				if(strcmp(argv[1],"--reset")==0){
					f=fopen("movies.dat","wb");
					}
				if(strcmp(argv[1],"--insert")==0){
		                    c=atoi(argv[3]);
                		    g=atof(argv[4]);
                            node = (node_T *)malloc(sizeof(node_T));
                            node->year=c;
                            node->money=g;
                            strcpy(node->name,argv[2]);
                            strcpy(moviedel,node->name);
                            l=strlen(moviedel);
                            node->data=l+1;
                            node->next = root;
					head=node;
					f=fopen("movies.dat","wb");
		        	while(head!=NULL){
                      fwrite(&(head->data),sizeof(int),1,f);
                      fwrite(head->name,sizeof(char)*(head->data),1,f);
				      fwrite(&(head->year),sizeof(int),1,f);
				      fwrite(&(head->money),sizeof(float),1,f);
					 head=head->next;}
					}
				if(strcmp(argv[1],"--delete")==0){
					strcpy(moviedel,argv[2]);
					current=root;
					while(current!=NULL && strcmp(current->name,moviedel)!=0){
        			                current=current->next;
					}
					root= list_remove_node(root,current);
					head=root;
 						f=fopen("movies.dat","wb");
						if(current!=NULL){
						while(head!=NULL){
							 fwrite(&(head->data),sizeof(int),1,f);
			                                      fwrite(head->name,sizeof(char)*(head->data),1,f);
                        	            		      fwrite(&(head->year),sizeof(int),1,f);
                                			       fwrite(&(head->money),sizeof(float),1,f);
                                			        head=head->next;}}}
					if(strcmp(argv[1],"--list-all")==0){
							head=root;
							while(head!=NULL){
								x=head->year;
								if(x){
								printf("%s %d %f\n",head->name,head->year,head->money);}
								head=head->next;}}
					if(strcmp(argv[1],"--list-after")==0){
							c=atoi(argv[2]);
							 head=root;
                            while(head!=NULL){
                                    a=head->year;
								if(a>=c){
                                        printf("%s %d %f\n",head->name,head->year,head->money);
                                            }
                                            head=head->next;
                           		 if(head==NULL){
                               			 break;
                           		 }
                          		  }}
                if(strcmp(argv[1],"--add")==0){
						gf=atof(argv[3]);
						strcpy(moviedel,argv[2]);
						head=root;
						f=fopen("movies.dat","wb");
                      while(head!=NULL){
                            strcpy(moviename,head->name);
							if(strcmp(moviename,moviedel)!=0){
                                        fwrite(&(head->data),sizeof(int),1,f);
                                        fwrite(head->name,sizeof(char)*(head->data),1,f);
                                        fwrite(&(head->year),sizeof(int),1,f);
                                        fwrite(&(head->money),sizeof(float),1,f);
                                        head=head->next;
							}else{
				head->money=head->money+gf;
				fwrite(&(head->data),sizeof(int),1,f);
                                fwrite(head->name,sizeof(char)*(head->data),1,f);
                                fwrite(&(head->year),sizeof(int),1,f);
                                fwrite(&(head->money),sizeof(float),1,f);
                                    head=head->next;
                                    }}}
		if(strcmp(argv[1],"--sort")==0){
					bubbleSort(root);
					head=root;
					f=fopen("movies.dat","wb");
				while(head!=NULL){
					fwrite(&(head->data),sizeof(int),1,f);
                                        fwrite(head->name,sizeof(char)*(head->data),1,f);
                                        fwrite(&(head->year),sizeof(int),1,f);
                                        fwrite(&(head->money),sizeof(float),1,f);
					head=head->next;
						}
					}

							fclose(f);
							freethisshit=root;
					while(freethisshit!=NULL){
						free(freethisshit);
						freethisshit=freethisshit->next;
						}
							return 0;
}

