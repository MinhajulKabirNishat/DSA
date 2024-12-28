#include <stdio.h>

 void printArray(int arr[], int n) {

     printf("Array: ");
    for (int i = 0 ; i < n; i++) {
        printf( "%d ", arr[i] );
    }
    printf("\n");
}

  void bubbleSort(int arr[], int n)
  {

    for(int i = 0; i < n-1; i++)
        {
        for(int j =0; j< n-i- 1; j++)
         {
            if( arr[j] >arr[j+1])
             {
             int temp = arr[j];
                arr[j] = arr[j+1];

            arr[j+1] = temp;
            }
        }
    }
  }

  void deleteNthOccurrence(int arr[], int *n, int value, int occurrence) {
     int count = 0;
        for(int i = 0; i <*n; i++)
            {
         if( arr[i] == value)
         {
            count++;

            if(count == occurrence)
            {
                for(int j = i; j < *n-1; j++)
                    {
                    arr[j] = arr[j+1];
                }
                *n--;

                printf("Deleted %dth occurrence of value %d\n", occurrence, value);
                return;
            }
        }
    }
      printf("%dth occurrence of value %d not found\n",occurrence,value);
}

  int binarySearch(int arr[], int n, int value)
   {
     int low = 0, high = n-1;
         while(low <=high) {
          int mid = (low + high) / 2;
        if(arr[mid] == value)
            {
            return mid;
        }
        else if(arr[mid] < value)
            {
            low = mid + 1;
        } else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n, choice, pos, new_val, s_val, occurrence, i, flag;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    while(1) {
       err:
       printf("\n1. Print Entire array\n2. Access a specific index\n3. Update the value of a specific index\n4. Linear Search\n5. Insert new value at a specific index\n6. Delete from an index\n7. Delete nth occurrence of a value\n8. Bubble Sort the existing array\n9. Binary Search on the array\n10. Exit");
       printf("\n\nEnter choice: ");
       scanf("%d", &choice);

       if(choice == 1) {
            printArray(arr, n);
       }

       else if(choice == 2) {
            printf("\nEnter the index to access: ");
            scanf("%d", &pos);
            if(pos >= 0 && pos < n) {
                printf("\nThe value at index %d: %d", pos, arr[pos]);
            } else {
                printf("Index out of bounds");
            }
       }

       else if(choice == 3) {
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &new_val);
            if(pos >= 0 && pos < n) {
                arr[pos] = new_val;
                printf("The new value at index %d: %d", pos, arr[pos]);
            } else {
                printf("Index out of bounds");
            }
       }

       else if(choice == 4) {
            printf("\nEnter the value to search: ");
            scanf("%d", &s_val);

            flag = 0;

            for(i = 0; i < n; i++) {
                if(arr[i] == s_val) {
                    printf("Value %d found at index %d", s_val, i);
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                printf("Value %d not found in the array", s_val);
            }
       }

       else if(choice == 5) {
            printf("\nEnter the value to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert: ");
            scanf("%d", &pos);

            if(pos < 0 || pos > n) {
                printf("Invalid position. Insertion failed.");
            } else {
                for(i = n; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                arr[pos] = new_val;
                printf("Value %d inserted at index %d", new_val, pos);
                n++;
            }
       }

       else if(choice == 6) {
            printf("\nEnter the position (index) to delete from: ");
            scanf("%d", &pos);

            if(pos < 0 || pos >= n) {
                printf("Invalid position. Deletion failed.");
            } else {
                for(i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                printf("Value at index %d deleted successfully", pos);
                n--;
            }
       }

       else if(choice == 7) {
            printf("\nEnter the value to delete: ");
            scanf("%d", &new_val);
            printf("\nEnter the occurrence to delete: ");
            scanf("%d", &occurrence);
            deleteNthOccurrence(arr, &n, new_val, occurrence);
       }

       else if(choice == 8) {
            bubbleSort(arr, n);
            printf("Array sorted using bubble sort");
       }

       else if(choice == 9) {
            printf("\nEnter the value to search for: ");
            scanf("%d", &s_val);
            bubbleSort(arr, n);
            int result = binarySearch(arr, n, s_val);
            if(result != -1) {
                printf("Value %d found at index %d", s_val, result);
            } else {
                printf("Value %d not found in array", s_val);
            }
       }

       else if(choice == 10) {
            break;
       }

       else {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
       }
    }
    return 0;
}
