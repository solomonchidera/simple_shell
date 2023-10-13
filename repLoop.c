#include "solomon.h"

int main(void)
{
    char *command;

    do
    {
        display_prompt1();
        command = display_command();

        if(!command)
        {
            exit(EXIT_SUCCESS);
        }
        if(command[0] == '\0' || _strcomp(command, "\n") == 0)
        {
            free(command);
            continue;
        }
        if(_strcomp(command, "exit\n") == 0)
        {
            free(command);
            break;
        }
        _puts(command);
        free(command);
    } while(1);
    exit(EXIT_SUCCESS);
}

char *display_command(void)
{
    char buffer[1024];
    char *p = NULL;
    char lenpointer = 0;
    int blength;
    char *p2;

    while(fgets(buffer, 1024, stdin))
    {
        blength = strlen(buffer);

        if(!p)
        {
            p = malloc(blength + 1);
        }
        else
        {
            p2 = realloc(p, lenpointer + blength + 1);

            if(p2)
            {
                p = p2;
            }
            else
            {
                free(p);
                p = NULL;
            }
        }
        if(!p)
        {
            _puts("error: failed to alloc buffer");
            return (NULL);
        }
        strcpy(p + lenpointer, buffer);

        if(buffer[blength - 1] == '\n')
        {
            if(blength == 1 || buffer[blength - 2] != '\\')
            {
                return (p);
            }
            p[lenpointer + blength - 2] = '\0';
            blength -= 2;
            display_prompt2();
        }

        lenpointer += blength;
    }
    return (p);
}
