#include <stdio.h>

int main()
{
    char message[11] = "", str[11] = "hello world";
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
    int i = 0,j=-1;
    message[0] = letters[0];
    while (i != 11)
    {
        while (message[i] != str[i]){
            message[i + 1] = '\0';
            message[i] = letters[++j];
            printf("%s\n", message);
        }
        j=0;
        i++;
    }

    return 0;
}
