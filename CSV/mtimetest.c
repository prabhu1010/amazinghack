#include <sys/types.h>
#include <sys/stat.h>

time_t get_mtime(const char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror(path);
    }
    return statbuf.st_mtime;
}

int main() {
get_mtime("file1.csv");




return 1;
}
