#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primes[7]={2,3,5,7,11,13,17};

int is_divisible(long long n)
{
	char num[11];
	sprintf(num, "%lld", n);
	int check[10]={0};
	for(int i=0;i<10;i++)
	{
		check[num[i]-'0']++;
		if(check[num[i]-'0']==2)
			return 0;
	}

	int sub[7];
	char word[4];
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<3;j++)
			word[j]=num[i+1+j];
		word[3]=0;
		sub[i]=atoi(word);

		if(sub[i]%primes[i]!=0)
			return 0;
	}
	return 1;
}

int main()
{
	long long sum=0;
	for(long long i=1000000000;i<10000000000;i++)
		if(is_divisible(i))
		{
			printf("%lld - it is divisible!\n",i);
			sum+=i;
		}

	printf("%lld\n",sum);
	return 0;
}
