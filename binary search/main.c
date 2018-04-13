#include <stdio.h>
void sort(int arr[],int n)
{
	int i,j,c;
	for(i=0;i<n;i++)
	{
		for(j = i+1;j<n;j++)
		{
			if(arr[i] > arr[j]){
				int ch = arr[i];
				arr[i] =arr[j] ;
				arr[j] = ch;
			}
			
		}
	}
}

int main()
{
   int c, first, last, middle, n, search;

   printf("Enter number of elements\n");
   scanf("%d",&n);
	int array[n];
   printf("Enter %d integers\n", n);

   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
      
    sort(array,n);
   printf("Enter value to find\n");
   scanf("%d", &search);

   first = 0;
   last = n - 1;
   middle = (first+last)/2;

   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;
      else if (array[middle] == search) {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d is not present in the list.\n", search);

   return 0;
}
