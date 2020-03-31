#include <stdio.h> /*dsdadsa*/

int findMin(void) {
  int min, countOfElements, index;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &countOfElements);

  int array[countOfElements];

  //printf("Enter the array: ");
  for(int i = 0; i < countOfElements; i++){
    scanf("%d", &array[i]);
  }

  min = array[0];
  index = 0;
  for(int j = 0; j < countOfElements; j++){
    if(array[j] < min){
      min = array[j];
      index = j;
    }
  }

  printf("The smallest array element: %d, is in position %d", min, index); 

  return 0;
}
