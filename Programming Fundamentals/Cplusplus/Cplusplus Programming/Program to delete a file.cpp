#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];

    printf("Enter the filename to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("%s file deleted successfully.\n", filename);
    } else {
        printf("Unable to delete the file.\n");
    }

    return 0;
}
