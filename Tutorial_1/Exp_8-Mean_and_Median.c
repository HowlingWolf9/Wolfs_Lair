#include <stdio.h> 
#include <stdlib.h> 

void main() 
{  
	int* ptr; 
	int size,temp;
	float sum=0,median;  
	printf("Enter size of elements:"); 
	scanf("%d", &size); 
	ptr = (int*)malloc(size * sizeof(int));
	if (ptr == NULL) 
	{ 
		printf("Memory not allocated.\n"); 
	} 
	else 
	{ 
		printf("%d bits of Memory successfully allocated using malloc.\n",(size*sizeof(int)));  
		for (int j=0;j<size;++j) 
		{ 
			printf("Enter number %d:",j+1);
			scanf("%d",&ptr[j]); 
		}
		for(int i=0;i<size;++i)
			{
				for (int j=0;j<size;++j)
				{
					if(ptr[i]<=ptr[j])
					{
						temp=ptr[i];
						ptr[i]=ptr[j];
						ptr[j]=temp;	
					}	
				}
			}
		if(size%2==0)
		{
			median=((ptr[size/2]+ptr[(size/2)+1])/2);
		}
		else
		{
			median=ptr[size/2];
		}
		printf("The elements of the array are: "); 
		for (int j=0;j<size;++j)
		{
			sum=sum+ptr[j];
			printf("%d, ", ptr[j]); 
		}
		printf("\nThe mean of the array is %.2f",(sum/size));
		printf("\nThe median of the array is %.2f",median);
	} 
}
