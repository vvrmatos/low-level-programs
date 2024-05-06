#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

void listFiles(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    printf("Files in '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    listFiles(argv[1]);
    return EXIT_SUCCESS;
}
