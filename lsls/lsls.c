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
      DIR *nested_directory = opendir(fullpath);
      struct dirent *nested_entries;
      while ((nested_entries = readdir(nested_directory)) != NULL) {
        struct stat buffer;
        char *nested_path = malloc(strlen(fullpath) + strlen(nested_entries->d_name) + 2);
        strcpy(nested_path, path);
        strcat(nested_path, "/");
        strcat(nested_path, nested_entries->d_name);
        stat(nested_path, &buffer);
        if ((buffer.st_mode & S_IFDIR) != 0) {
          printf("%20s    %s\n","<DIR>", nested_entries->d_name);          
        } else {
          printf("%20lld    %s\n", buffer.st_size, nested_entries->d_name);
        }
      }

    } else {
      printf("%10lld    %s\n", buf.st_size, entries->d_name);
    }
  }

  // Close directory
  closedir(directory);
  
  return 0;
}