#include "list_utils.h"

// Process arguments then fills array of strings containing directories passed as args
// If no arguments are passed then the directory is the current working directory
void setDirectoriesPaths(char ***directory, char **argv, int argc) {
    if (argc < 2) {
        *directory = (char **) malloc(1 * sizeof(char *));
        if ((*directory) == NULL) {
            perror("Failed to allocate memory for directory");
            return;
        }

        (*directory)[0] = malloc(2);
        if ((*directory) == NULL) {
            perror("Failed to allocate memory for directory");
            return;
        }
        strcpy((*directory)[0], ".");
    } else {
        *directory = (char **) malloc((argc - 1) * sizeof(char *));
        if (*directory == NULL) {
            perror("Failed to allocate memory for directories");
            return;
        }

        for (int i = 1; i < argc; i++) {
            (*directory)[i - 1] = argv[i];
        }
    }
}

// Helper method to print the file or directory permissions
void printFilePermissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

// Prints time in a formatted way using file status
void printTime(struct tm *time, const struct stat *status) {
    time = localtime(&status->st_mtime);
    char timeBuffer[15];

    strftime(timeBuffer, sizeof(timeBuffer), "%d %b %H:%M", time);
    printf(" %s", timeBuffer);
}

// Prints all file details in one line using file name and status
void printFileDetails(const char *filename, const struct stat *status) {
    struct passwd *passwd = getpwuid(status->st_uid);
    struct group *group = getgrgid(status->st_gid);
    struct tm *time;

    printFilePermissions(status->st_mode);
    printf(" %ld", status->st_nlink);
    printf(" %s", passwd->pw_name);
    printf(" %s", group->gr_name);
    printf(" %ld", status->st_size);
    printTime(time, status);
    printf(" %s\n", filename);
}

// Process each directory then prints the details of each file or folder in the directory
void processDirectory(DIR **dir, struct dirent **entry, struct stat *fileStatus, char **directory) {
    while (((*entry) = readdir(*dir)) != NULL) {
        char path[PATH_MAX];
        if (strcmp((*entry)->d_name, ".") == 0 || strcmp((*entry)->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", *directory, (*entry)->d_name);

        if (stat(path, fileStatus) == -1) {
            perror("stat");
            continue;
        }

        printFileDetails((*entry)->d_name, fileStatus);
    }
    printf("\n");
}

// Lists all directories and files in the directories passed as arguments
void list(char ***directories, const int argc) {
    struct dirent *entry;
    struct stat fileStatus;

    int numOfDirectories = (argc < 2) ? 1 : argc - 1;

    for (int i = 0; i < numOfDirectories; i++) {
        DIR *dir = opendir((*directories)[i]);
        if (dir == NULL) {
            perror("opendir");
            continue;
        }

        if (numOfDirectories > 1) {
            printf("%s:\n", (*directories)[i]);
        }

        processDirectory(&dir, &entry, &fileStatus, &(*directories)[i]);
        closedir(dir);
    }
}
