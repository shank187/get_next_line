#include "get_next_line_bonus.h"


int main(void)
{
    int fd = open("w.text", O_RDONLY);
    // char *s ;
    // read(fd, s, 10);
    // printf("%s\n",s);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
}