#include <stdio.h>

int main(void)
{
    printf("sizeof(int)  = %d\n",(int)sizeof(int));
    printf("sizeof(long) = %d\n",(int)sizeof(long));
    printf("sizeof(long long) = %d\n",(int)sizeof(long));
    _Bool false = 0;
    _Bool true = 1;
    printf("false = %d\n",false);
    printf("true = %d\n",true);
    return 0;
}
