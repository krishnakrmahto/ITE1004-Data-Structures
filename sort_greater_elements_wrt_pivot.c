int count=0;
int split(int a[],int lower,int upper)
{
    int i,j,pivot,temp;
    i=lower+1;
    j=lower+2;
    pivot=a[lower+1];
    for(;j<=upper;j++)
    {
        if(a[j]<=pivot)
        {
            temp=a[++i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    if(a[lower]<=pivot)
    {
        a[lower+1]=a[i];
        a[i]=pivot;
        return i;
    }
    else
    {
        temp=a[lower];
        a[lower]=a[i];
        a[i]=temp;
        if(i!=lower+1)
        {
            a[lower+1]=a[i-1];
            a[i-1]=pivot;
        }
        return(i-1);
    }
}
void quick_sort(int a[],int lower,int upper)
{
	int i;
	if(lower<upper)
	{
	    count++;
		i=split(a,lower,upper);
		quick_sort(a,i+1,upper);
        count--;
		if(count!=0)
		quick_sort(a,lower,i-1);
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



