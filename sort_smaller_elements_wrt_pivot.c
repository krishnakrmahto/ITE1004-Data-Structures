int count_levels=0;
int split(int a[],int lower,int upper)
{
    int i=lower,j=lower+1,pivot=a[lower],temp;
    for(;j<=upper;j++)
    {
        if(a[j]<=pivot)
        {
            temp=a[++i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[lower]=a[i];
    a[i]=pivot;
    return i;
}
void quick_sort(int a[],int lower,int upper)
{
	int i;
	if(lower<upper)
	{
		count_levels++;
		i=split(a,lower,upper);
        quick_sort(a,lower,i-1);
        count_levels--;
        if(count_levels!=0)
		quick_sort(a,i+1,upper);
	}
}
int main()
{
	int a[20],i,n,lower,upper;
	puts("number of int values? ");
	scanf("%d",&n);
	puts("enter a list of numbers: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	lower=0;
	upper=n-1;
	quick_sort(a,lower,upper);
	puts("");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}



