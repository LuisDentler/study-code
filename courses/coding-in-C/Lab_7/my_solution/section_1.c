#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int N = 0;
 int *p_single_value = NULL;
 int *p_array = NULL;
 int *p_resized_array = NULL;


 printf("Enter a integer N: ");
 if(scanf("%d", &N) !=1,N<=0)
 {
    printf("Invalid input.\n");
    return 1;
 }
 
 p_single_value = (int*)malloc(sizeof(int));

 if (p_single_value == NULL)
 {
    printf("Memory allocation failed.\n");
    return 1;
 }
 
 *p_single_value = N ;
 printf("Value stored using malloc: %d\n", *p_single_value);
 
 p_array = (int *)calloc(N, sizeof(int));

 if (p_array == NULL)
 {
     printf("Memory allocation failed (calloc).\n");
     free(p_single_value);
     return 1;
 }
 for (int i = 0; i < N; i++)
 {
     p_array[i] = i * i;
 }
 
 p_resized_array = (int *)realloc(p_array, 2 * N * sizeof(int));
 if (p_resized_array == NULL)
    {
        printf("Memory reallocation failed (realloc).\n");
        free(p_array);
        free(p_single_value);
        return 1;
    }
    p_array = p_resized_array;
    for (int i = N; i < 2 * N; i++)
    {
        p_array[i] = i * i;
    }

    printf("Array values:\n");
    for (int i = 0; i < 2 * N; i++)
    {
        printf("arr[%d] = %d\n", i, p_array[i]);
    }

    
    free(p_array);
    free(p_single_value);

    p_array = NULL;
    p_single_value = NULL;

    return 0;
}