#include <stdio.h>
int main()
{
      int a,b,c,d;
      int l,g;
      scanf("%d %d %d %d",&a,&b,&c,&d);
      if (b==d){
        l= a+c;
        g=b;}
      else {
         l=a*d+c*b;
         g=b*d;}
      if (g){
         printf("%d %d\n",l,g);}
       else{
         printf("\n");}
        return 0;
}
