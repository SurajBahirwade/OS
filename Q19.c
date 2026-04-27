#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void sort(int a[], int n) {
    int i, j, t;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void display(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
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
        printf("\nParent Process\n");
        sort(arr, n);
        printf("Sorted by Parent: ");
        display(arr, n);
        wait(NULL);
        printf("Child finished\n");
    }
    else if(pid == 0) {
        printf("\nChild Process\n");
        sort(arr, n);
        printf("Sorted by Child: ");
        display(arr, n);
    }
    else {
        printf("Fork failed\n");
    }

    pid_t pid2 = fork();

    if(pid2 > 0) {
        printf("\nZombie Demonstration\n");
        sleep(10);
    }
    else if(pid2 == 0) {
        printf("Child exiting to become zombie\n");
        exit(0);
    }

    pid_t pid3 = fork();

    if(pid3 > 0) {
        printf("\nOrphan Demonstration\n");
        exit(0);
    }
    else if(pid3 == 0) {
        sleep(5);
        printf("Orphan Child New Parent PID: %d\n", getppid());
    }

    return 0;
}
