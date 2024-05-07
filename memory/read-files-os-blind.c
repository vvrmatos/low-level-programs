/**
 * File: read-files-os-blind.c
 * Author: Victor Kolis
 * Date: 05/06/2024
 * Description: Implements functions that take terminal arguments
 *                          in order to list files in a given dir
 *                          e.g.: (such as) ls in bash scripting
 *                          ./read-files-os-blind ~, lists files in home.
 *                          This code is an upgrade of read-files
 *                          in terms of OS handling.
 * License: The unlicensed
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <errno.h>
#include <string.h>
#endif

void listFiles(const char *path) {
#ifdef _WIN32
    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    DWORD dwError = 0;

    // Append \* to the directory path to list everything in the directory
    char spec[MAX_PATH];
    snprintf(spec, MAX_PATH, "%s\\*", path);

    hFind = FindFirstFile(spec, &ffd);
    if (INVALID_HANDLE_VALUE == hFind) {
        fprintf(stderr, "FindFirstFile failed (%lu)\n", GetLastError());
        return;
    }

    printf("Files in '%s':\n", path);
    do {
        printf("%s\n", ffd.cFileName);
    } while (FindNextFile(hFind, &ffd) != 0);

    dwError = GetLastError();
    if (dwError != ERROR_NO_MORE_FILES) {
        fprintf(stderr, "FindNextFile failed (%lu)\n", dwError);
    }

    FindClose(hFind);
#else
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", strerror(errno));
        return;
    }

    printf("Files in '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
#endif
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    listFiles(argv[1]);
    return EXIT_SUCCESS;
}
