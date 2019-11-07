#include<stdio.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#define N 10
struct student
{
	char name[5];
	int sorc[6];
	int all;
	double ave;
	int rank;
};
void Printf(struct student *c)
{
	printf("name\tgrade1\tgrade2\tgrade3\tgrade4\tgrade5\tgrade6\tall\taverage\trank\n");
	for(int i=0;i<N;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%3.3lf\t%d\n",c[i].name,c[i].sorc[0],c[i].sorc[1],c[i].sorc[2],c[i].sorc[3],c[i].sorc[4],c[i].sorc[5],c[i].all,c[i].ave,c[i].rank);
	}
}
void rank(struct student*c)
{
	int n=1;
	for(int i=0;i<N;i++)
	{
		c[i].rank=n;
		n++;
	}
}
void change(struct student *a,struct student *b)
{
	struct student *x;
	*x=*a;
	*a=*b;
	*b=*x;
}
void sort(struct student *c)
{
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-1-i;j++)
		{
			if(c[j].all<c[j+1].all)
			{
				change(&c[j],&c[j+1]);
			}
		}
	}
}
int main()
{
	int i,j;
	int num=0;
	srand(time(NULL));
	struct student s[N];
	for(i=0;i<N;i++)
	{
		int a;
		for(j=0;j<5;j++)
		{
			a=rand()%26+97;
			s[i].name[j]=(char)a;
		}
		s[i].name[j]='\0';
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<6;j++)
		{
			s[i].sorc[j]=rand()%51+50;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<6;j++)
		{
			num+=s[i].sorc[j];
		}
		s[i].all=num;
		s[i].ave=(double)num/6;
		num=0;
	}
	sort(s);
	rank(s);
	Printf(s);
}
