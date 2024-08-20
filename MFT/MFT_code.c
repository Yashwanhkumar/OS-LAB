#include <stdio.h>

int main() {
    int ms, bs, nob, n, mp[10], i, p = 0, tif = 0;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bs);

    nob = ms / bs; // Number of blocks
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNo. of Blocks available in memory: %d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    for (i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);
        if (mp[i] > bs) {
            printf("\t\tNO\t\t---");
        } else {
            printf("\t\tYES\t%d", bs - mp[i]);
            tif += bs - mp[i];
            p++;
        }
    }

    if (i < n) {
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");
    }
    printf("\n\nTotal Internal Fragmentation is: %d", tif);

    return 0;
}