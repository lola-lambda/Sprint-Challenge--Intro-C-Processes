#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  // Open directory
  char *path = argv[1];
  struct dirent *entries;
  DIR *directory;

  directory = opendir(path);

  // Read directory
  while ((entries = readdir(directory)) != NULL) {
    struct stat buf;
    char *fullpath = malloc(strlen(path) + strlen(entries->d_name) + 2);
    strcpy(fullpath, path);
    strcat(fullpath, "/");
    strcat(fullpath, entries->d_name);
    stat(fullpath, &buf);
    if ((buf.st_mode & S_IFDIR) != 0) {
      printf("%10s    %s\n","<DIR>", entries->d_name);
    } else {
      printf("%10lld    %s\n", buf.st_size, entries->d_name);
    }
  }

  // Close directory
  closedir(directory);
  
  return 0;
}