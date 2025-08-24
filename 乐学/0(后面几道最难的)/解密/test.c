#include<stdio.h>    
#include<string.h>    
struct node    
{    
    unsigned int Offset;    
    unsigned short Size;    
    unsigned char Key;    
    char jiango;     
}pw;    
int main()    
{    
	int n;
    char name[100],jd[20],MsgErr[]="Wrong Key!",MsgSn[]="Serial No.: ",MsgMD9[]="MD9: ",c[5000];    
    scanf("%s%d",name,&n);    
    printf("XH: %02d\nSN: ",n);    
    FILE * kk=fopen(name,"rb");    
    for(int i=0;i<5;i++)    
    {    
        fseek(kk,(n-1)*8+0x210*i,SEEK_SET);    
        fread(&pw,8,1,kk);    
        fseek(kk,pw.Offset,SEEK_SET);    
        fread(jd,10,1,kk);    
        for(int i=0;i<10;i++)jd[i]=(jd[i]+pw.Key)%0x100;    
        if(!strcmp(jd,MsgErr))continue;    
        fseek(kk,pw.Offset,SEEK_SET);    
        fread(c,pw.Size,1,kk);    
        for(int i=0;i<pw.Size;i++)c[i]=(c[i]+pw.Key)%0x100;    
        char *p=strstr(c,MsgSn)+12;    
        for(int i=1;i<=19;i++)printf("%c",*p++);    
        printf("\nM9: ");    
        char *m=strstr(c,MsgMD9)+5;    
        for(int i=1;i<=32;i++)printf("%c",*m++); 
        printf("\n");    
        return 0;    
    }    
}
