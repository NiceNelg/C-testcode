#include <stdio.h>
#include <stdint.h>

#define ngx_align(d,a) ((d + (a-1)) & ~(a - 1))
#define ngx_align_ptr(p, a) \
    (unsigned char *)((uintptr_t)(p) + ((uintptr_t)(a) - 1) & \
                ~((uintptr_t)(a) - 1))

struct st {
    char a;
    int  b;
    char c;
};

int main(int argc, char *argv[])
{
    struct st sl = {'a', 1234, 'c'};
    printf("%d, %d\n", sizeof(struct st), sizeof(int) + sizeof(char) * 2);
    
    printf("%x, %x, %x, %x\n", &sl, &(sl.a), &(sl.b), &(sl.c));
    
    printf("%d\n", (int)ngx_align(73, 8));
    
    printf("%x, %x, %x\n",ngx_align_ptr(&(sl.a), 4), 
                ngx_align_ptr(&(sl.a) + 1, 4), &(sl.b));

    return 0;
}
