#include <stdio.h>

int main(void){
	int a,b,counter;
	int one,ten,hun,tho;
	while(1){
		scanf("%d%d",&a,&b);
		counter = 0;
		if(!a || !b){
			break;
		}
		else{
			if(!(a / 1000) || !(b / 1000)){
				printf("Error\n");
			}
			else{
				for(; a < b; a++){
					if(a % 2 == 0){
						one = a % 10;
						ten = a % 100 / 10;
						hun = a % 1000 / 100;
						tho = a / 1000;
						if((one != ten) && (one != hun) && (one != tho) && (ten != hun) && (ten != tho) && (hun != tho)){
							printf("%d  ",a);
							counter++;
						}
					}
				}
				printf("\n");
				printf("counter=%d\n",counter);
			}
		}
	}
	return 0;
}
