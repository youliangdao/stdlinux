#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE* f);

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        do_cat(stdin);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            FILE* fp;
            fp = fopen(argv[i], "r");
            if (!fp)
            {
                perror(argv[i]);
                exit(1);
            }
            do_cat(fp);
            fclose(fp);
        }
        
    }

    exit(0);
}

static void do_cat(FILE* f)
{
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        if (putchar(c) < 0) exit(1);
    }
}