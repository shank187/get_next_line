#include <libc.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt",O_RDONLY);
    // char *s = malloc(11);
    // printf("%p\n",s);
    // read(fd, s, 10);
    // printf("%s\n",s);
    // printf("%p\n",s);
    printf("%s",get_next_line(fd));   
    printf("%s",get_next_line(fd));   
    // printf("%s",get_next_line(fd));   
    // printf("%s",get_next_line(fd)); 

    // printf("%s",get_next_line(fd));   
    // // printf("%s",get_next_line(fd));   
    // // printf("%s",get_next_line(fd));   
}