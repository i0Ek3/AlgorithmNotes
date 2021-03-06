// 
// big_numbers_operation.cpp
// @ianpasm(kno30826@gmail.com)
// 2018-03-18 09:26:32
// 
 
#include <cstdio>
#include <cstring>

const int maxn = 100000;

struct bign {
    int d[maxn];
    int len;
    bign() {
        memset(d,0,sizeof(d));
        int len = 0;
    }
};

bign reverse(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign add(bign a,bign b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        int sum = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = sum % 10;
        carry = sum / 10;
    }
    if (carry != 0) c.d[c.len++] = carry;
    return c;
}

bign sub(bign a,bign b)
{
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++)
    {
        if (a.d[i] < b.d[i])
        {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;
    }
    return c;
}

bign multi(bign a,int b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++)
    {
        int tmp = a.d[i] * b + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    while (carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bign divide(bign a,int b,int& r)
{
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.d[i];
        if (r < b) c.d[i] = 0;
        else
        {
            c.d[i] = r / b;
            r %= b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;
    }
    return c;
}

void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
    {
        printf("%d",a.d[i]);
    }
}

int main()
{
    char str1[maxn],str2[maxn];
    scanf("%s%s",str1,str2);
    bign a = reverse(str1);
    bign b = reverse(str2);
    printf("The add is :\n");
    print(add(a,b));
    printf("\n");
    printf("The sub is :\n");
    print(sub(a,b));
    printf("\n");
    printf("The multi is :\n");
    print(multi(a,10));
    printf("\n");
    //printf("The divide is :\n");
    //print(divide(a,10));
    return 0;
}





