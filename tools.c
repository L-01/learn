#include <stdio.h>
#include "tools.h"
#include <stdlib.h>
#include <getch.h>

void show_msg(const char* msg)
{
    printf("%s",msg);
    fflush(stdout);
    sleep(3);
//  usleep(sec*1000000);
}

void anykey_continue(void)
{
    stdin->_IO_read_ptr = stdin->_IO_read_end;
    puts("任意键继续...");
    getch();
}

