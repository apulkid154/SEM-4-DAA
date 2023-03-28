#include <stdio.h>
#include <time.h>
void main()
{
  int p[7],s[10];
int a[2][2],b[2][2],c[2][2];
clock_t start,end;
printf("Enter the values in matrix a\n");
for(int i=0;i<2;i++){
for(int j=0;j<2;j++){

scanf("%d",&a[i][j]);
}
}
printf("Enter the values in matrix b\n");
for(int i=0;i<2;i++){
for(int j=0;j<2;j++){

scanf("%d",&b[i][j]);
}
}

s[0]=b[0][1]-b[1][1];
s[1]=a[0][0]+a[0][1];
s[2]=a[1][0]+a[1][1];
s[3]=b[1][0]-b[0][0];
s[4]=a[0][0]+a[1][1];
s[5]=b[0][0]+b[1][1];
s[6]=a[0][1]-a[1][1];
s[7]=b[1][0]+b[1][1];
s[8]=a[0][0]-a[1][0];
s[9]=a[1][1]-a[2][1];
s[10]=b[1][1]+b[1][2];
printf("\n");
for(int i=0;i<10;i++)
{
printf("\nS%d = %d",(i+1),s[i]);
}
p[0]=s[0]*a[0][0];
p[1]=s[1]*b[1][1];
p[2]=s[2]*b[0][0];
p[3]=s[3]*a[1][1];
p[4]=s[4]*s[5];
p[5]=s[6]*s[7];
p[6]=s[8]*s[9];

for(int i=0;i<7;i++)
{
printf("\nP%d = %d",(i+1),p[i]);
}

c[0][0]=p[4]+p[3]-p[1]+p[5];
c[0][1]=p[0]+p[1];
c[1][0]=p[2]+p[3];
c[1][1]=p[4]+p[0]-p[2]-p[6];
printf("\n\nMatrix A =");
for(int i=0;i<2;i++)
{
printf("\n");
for(int j=0;j<2;j++)
{
printf("%d \t",a[i][j]);
}
}
printf("\n\nMatrix B");
for(int i=0;i<2;i++)
{
printf("\n");
for(int j=0;j<2;j++)
{
printf("%d \t",b[i][j]);
}
}
printf("\n\nMatrix c");
for(int i=0;i<2;i++)
{
printf("\n");
for(int j=0;j<2;j++)
{
printf("%d \t",c[i][j]);
}
}
printf("\n");
end=clock();
printf("Time taken = %lf",(double)(end-start)/CLOCKS_PER_SEC);

}



	

