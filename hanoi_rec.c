#include<stdio.h>
void hanoi(int,char,char,char);
int main()
{
	char source='S',tar='T',aux='A';
	int n;
	puts("Enter the number of disks: ");
	scanf("%d",&n);
	hanoi(n,source,tar,aux);
}
void hanoi(int n,char source,char tar,char aux)
{
	if(n==1)
	printf("Move %d disc from %c to %c\n",n,source,tar);
	else
	{
		hanoi(n-1,source,aux,tar);
		printf("Move %d disc from %c to %c\n",n,source,tar);
		hanoi(n-1,aux,tar,source);
	}
}
