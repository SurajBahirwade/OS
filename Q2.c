#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if(pid > 0) {
        
        printf("\n--- Parent Process ---\n");
        printf("PID: %d\n", getpid());

        sort(arr, n);

        printf("Sorted array by Parent: ");
        display(arr, n);

      
        wait(NULL);

        printf("Child process finished.\n");
    }
    else if(pid == 0) {
        
        printf("\n--- Child Process ---\n");
        printf("PID: %d, Parent PID: %d\n", getpid(), getppid());

        sort(arr, n);

        printf("Sorted array by Child: ");
        display(arr, n);

    }
    else {
        printf("Fork failed!\n");
    }

    return 0;
}
