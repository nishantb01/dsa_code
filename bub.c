#include<stdio.h>

void bubble(int stud[], int n){
    int pass = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(stud[j]>stud[j+1]){
                int temp = stud[j];
                stud[j] = stud[j+1];
                stud[j+1] = temp;
                pass++;
            }

        }
    }

    printf("\nsorted array using bubble sort.\n");
    for(int i = 0;i<n;i++){
        printf("%d ",stud[i]);
    }
    printf("\n%d",pass);
}

void select(int stud[],int n){
    int min;
    for(int i = 0 ; i<n ;i++){
        min = i;
        for(int j = i+1 ; j<n ;j++){
            if(stud[j]<stud[min]){
                min = j;
            }

            int temp = stud[min];
            stud[min]= stud[i];
            stud[i]= temp;
        }
    }

    printf("\nsorted array using selection sort.\n");
    for(int i = 0;i<n;i++){
        printf("%d ",stud[i]);
    }
}

int main(){
    int n;
    printf("Enter the Size of array :");
    scanf("%d",&n);

    int stud[n];
    printf("Enter the Elements of Array:\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&stud[i]);
    }
    
    for(int i = 0;i<n;i++){
        printf("%d ",stud[i]);
    }

    int ch ;
    printf("\n1.Bubble Sort\n2.Selection Sort");
    printf("\nEnter the choice : ");
    scanf("%d",&ch);
    if(ch == 1){
        bubble(stud,n);
    }else if(ch == 2){
        select(stud,n);
    }else{
        printf("Invalid choice");
    }
    
    
    return 0;
}
