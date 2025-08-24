#include<stdio.h>
int main()
{
	freopen("test.txt", "r", stdin);
	
	char a[10][6]={0};
	int num,i,b[51]={0},j,k=0,t;
	scanf("%d",&num);
	for(i=0;i<11;i++)
	{
		
		for(j=0;j<6;j++)
		{
			scanf("%c",&a[i][j]);
			if(a[i][j]=='+')
			{
				if(i==0&&j==5)
				{
					b[k]=51;
				}
				else
				{
					b[k]=10*(j-1)+i;
				}
				k++;
			}
		}
		printf("%c%c%c%c%c%c",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
	}
	for(i=0;i<51;i++)
	{
//		printf("%d",i);
		for(j=i+1;j<51;j++)
		{
			if(b[j]<b[i])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	if(k!=0){
	printf("%02d\n",b[0]);}
	else
	{
		printf("**\n");
	}
}
