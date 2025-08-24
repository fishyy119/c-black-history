#include <stdio.h>
#include <stdlib.h>
#define N 99
typedef struct student
{
	unsigned int ID;
	char name[9];
	unsigned char km1;
	unsigned char km2;
	unsigned char km3;
	char sex;
}id;
int main()
{
	FILE *fp;
	id stu[N+10],temp;
	unsigned char temp2;
	int sum[N+1];
	unsigned int count=0;//count��¼����ѧ������ 
	register int i,j,k;
	char filename[20]={0};
	gets(filename);
	if((fp=fopen(filename,"rb"))==NULL)//�ȶ���99λѧ������ 
	{
		printf("file open error!\n");
		exit(0);
	} 
	for(i=0;i<N;i++,count++)
	{
		fread(&stu[i],16,1,fp);
		sum[i]=stu[i].km1+stu[i].km2+stu[i].km3;
		stu[i].sex=stu[i].name[8];
		stu[i].name[8]='\0';
	}
	for(i=0;i<N;i++)//����99��ѧ���ɼ����дӴ�Сѡ������ 
	{
		k=i;
		for(j=i+1;j<N;j++)
	    if(sum[k]<sum[j])k=j;
	    if(k!=i)
	    {
	    	temp=stu[k];
	    	stu[k]=stu[i];
	    	stu[i]=temp;
	    	temp2=sum[k];
	    	sum[k]=temp2;
	    	sum[j]=temp2;
	    }
	}
	while(!feof(fp))//��������ѧ�����ݲ��뷨�������� 
	{
		int flag=0;//�жϸ����Ƿ����ǰ99 
	    fread(&temp,16,1,fp);	
	    temp.sex=temp.name[8];
	    temp.name[8]='\0';
	    sum[N]=temp.km1+temp.km2+temp.km3;
	    for(i=0;i<N;i++)
	    if(sum[N]>sum[i])
		{
			flag=1;
		    break;//�ҵ�����λ��
		}
		for(j=N-1;j>i;j--)//���������ѧ������һ��λ��
		{ 
		    stu[j]=stu[j-1]; 
		    sum[j]=sum[j-1];
    	}
		if(flag)
		{
		   stu[i]=temp;	
		   sum[i]=sum[N];
		}
		count++;
	}
	printf("+-----------------------------------------------------+\n");
	printf("|                   TOP 99 of %5u                   |\n",count);
	printf("+-----+--------+----------+---+-----+-----+-----+-----+\n");
	printf("| TOP |   ID   |   Name   |Sex| SUM | KM1 | KM2 | KM3 |\n");
	printf("+-----+--------+----------+---+-----+-----+-----+-----+\n");
	for(i=0;i<N;i++)
	{
		printf("| %2d  | %06u | %8s | %c | %d | %3u | %3u | %3u |\n",i,stu[i].ID,stu[i].name,stu[i].sex,sum[i],stu[i].km1,stu[i].km2,stu[i].km3);
	}
	fclose(fp);
	return 0;
}
