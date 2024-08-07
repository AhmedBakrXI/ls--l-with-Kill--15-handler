#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>


void setDirectoriesPaths(char ***directory, char **argv, int argc);

void printFilePermissions(mode_t mode);

void printTime(struct tm *time, const struct stat *status);

void printFileDetails(const char *filename, const struct stat *status);

void processDirectory(DIR **dir, char **directoryName);

void list(char ***directories, const int argc);

#endif // _LIST_H_
