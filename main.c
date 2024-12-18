#include <libc.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt",O_RDONLY);
    // char *s = malloc(11);
    // // printf("%p\n",s);
    // int i = read(fd, s, 4);
    // printf("|%s| i = %i\n",s, i);
    // i = read(fd, s, 4);
    // printf("|%s| i = %i\n",s, i);
    // i = read(fd, s, 4);
    // printf("|%s| i = %i\n",s, i);
    // i = read(fd, s, 4);
    // printf("|%s| i = %i\n",s, i);
    // i = read(fd, s, 4);
    // printf("|%s| i = %i\n",s, i);

    // int j = write(fd, "hhhh", 4);
    // printf("%i\n",j);
    printf("%s",get_next_line(fd));   
    printf("%s",get_next_line(fd));   
    // printf("%s",get_next_line(fd));   
    // printf("%s",get_next_line(fd)); 
    // printf("%s",get_next_line(fd));   
    // printf("%s",get_next_line(fd));   
    // printf("%s",get_next_line(fd));   
    // // // printf("%s",get_next_line(fd));   
    // // // printf("%s",get_next_line(fd));   
}