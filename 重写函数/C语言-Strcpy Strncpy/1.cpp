#include <bits/stdc++.h>

using namespace std;

void mstrcpy(char *pDst, const char *pSrc)
{
    /* 检测是否为空指针 */
    assert(pDst != NULL);
    assert(pSrc != NULL);

    /* 字符拷贝 */
    int idx = 0;
    while(pSrc[idx] != '\0')
    {
        pDst[idx] = pSrc[idx];
        idx++;
    }

    /* 输出处理 */
    pDst[idx] = '\0';
}

void mstrncpy(char *pDst, const char *pSrc, size_t n)
{
    /* 检测是否为空指针 */
    assert(pDst != NULL);
    assert(pSrc != NULL);

    int len = strlen(pSrc);
    if(n > len)
    {
        n = len;
    }

    /* 字符拷贝 */
    int idx = 0;
    while(pSrc[idx] != '\0' && idx < n)
    {
        pDst[idx] = pSrc[idx];
        idx++;
    }

    /* 输出处理 */
    pDst[idx] = '\0';
}

int main() 
{
    char src[5] = "abcd";
    char dst[5];
    mstrncpy(dst, src, 3);
    printf("src=%s dst=%s\n", src, dst); 

    return 0;
}


