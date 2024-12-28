#include<stdio.h>

int main() {
    int n, choice, pos, new_val, s_val, i, flag;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    while(1) {
       err:
       printf("\n1.Print \n2.Update\n3.Search\n4.Insert\n5.Delete (bonus)\n0.EXIT");
       printf("\n\nEnter choice: ");
       scanf("%d", &choice);

       if(choice==1) {
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);
       }

       else if(choice==2) {
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &new_val);
            arr[pos] = new_val;
            printf("The new val at index %d: %d", pos, arr[pos]);
       }

       else if(choice==3) {

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

       else if(choice==4)
       {
            printf("\nEnter the value to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert: ");
            scanf("%d", &pos);


            if(pos < 0 || pos >= n) {
                printf("Invalid position. Insertion failed.");
            }
            else {

                for(i = n - 1; i >= pos; i--) {
                    arr[i + 1] = arr[i];
                }

                arr[pos] = new_val;
                printf("Value %d inserted at index %d", new_val, pos);
                n++;
            }
       }

       else if(choice==5)
            {
            printf("\nEnter the position (index) to delete from: ");
            scanf("%d", &pos);

            if(pos < 0 || pos >= n)
             {
                printf("Invalid position. Deletion failed.");
            }
            else {
                for(i = pos; i < n - 1; i++)
                    {
                    arr[i] = arr[i + 1];
                }
                printf("Value at index %d deleted successfully", pos);
                n--;
            }
       }
       else if(choice==0)
            break;
        else {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
        }

    }
    return 0;
}
