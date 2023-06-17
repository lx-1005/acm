#include<bits/stdc++.h>

using namespace std;

char* mystrcpy(char* dest, const char* src) { // ��Leetcode������dest
    if(!dest || !src) return NULL;
    if (src == dest) return dest;

    char* d = dest;
    int len = strlen(src);

    if (d > src && src + len > d) { // ����
        d = d + len - 1;
        src = src + len - 1;
        while (len--) *d-- = *src--;
    }
    else while (len--) *d++ = *src++; // ����

    return dest;
}

void mystrncpy(char* dest, const char* src, size_t len) { // ��Leetcode��len���ַ�������dest
    if(!src || !dest || !len) return;
    size_t slen = strlen(src);
    if (slen < len) return;

    char *d = dest;
    while (len--) *d++ = *src++;
    *d = '\0';
}

int mystrlen(char* s1) { // �ҵ���һ��'\0'
    if (!s1) return 0;

    int cnt = 0;
    while (*s1++ != '\0') ++cnt;
    return cnt;
}

void mystrcat(char* s1,  const char* s2) { // ��s2��s1����
    if (!s1 || !s2) return;

    size_t s1len = strlen(s1), s2len = strlen(s2);
    s1 += s1len;
    while (s2len--) *s1++ = *s2++;
}

char* mystrncat(char* s1, const char* s2, size_t len) { // ��s2��len���ַ���s1����
    if (!s1 || !s2 || !len) return NULL;

    size_t s1len = strlen(s1), s2len = strlen(s2);
    if (s2len < len) return NULL;
    char* p = s1 + s1len;
    while (len--) *p++ = *s2++;
    *p = '\0';
    return s1;
}

int myatoi(char* str) { // �ַ���תint
    if(!str) {
        cout<<"invalid input"<<endl;
        return -1;
    }

    bool ispos = true;
    while (*str != '\0') {
        char c = *str;
        if (c == ' ') continue; // ȥ����ͷ�Ŀո�
        
        if (c == '+') {
            str++;
            if (*str != '\0' && !isdigit(*str)) return -1; // ��Ч
        }
        else if (c == '-') {
            str++;
            if (*str != '\0' && !isdigit(*str)) return -1; // ��Ч
        } 

        const int maxVal = 214748364;
        int num = 0;
        while (*str != '\0') {
            if (!isdigit(*str)) return num;

            if (ispos) {
                if (num > maxVal || (num == maxVal && *str > '7')) break;
                num = num * 10 + (*str - '0');
            }
            else {
                if (num < -maxVal || (num == -maxVal && *str > '8')) break;
                num = num * 10 - (*str - '0');
            }
            str++;
        }

        return num;
    }
}

void* mymemcopy(void* dest, const void* src, size_t n) { // memcpy����Ĳ��������뱣֤�����������ص�
    if (!dest || !src) return NULL;
    if (!n || dest == src) return dest;

    if (src <= dest && src + n > dest || dest <= src && dest + n > src) cout << "mem overlap" << endl;

    char* d = (char*) dest;
    const char* s = (const char*)src;
    while (n--) *d++ = *s++;

    return dest;
}

void* mymemmove(void* dest, const void* src, size_t n) {// memmove����Ĳ�����������������ص�
    if (!dest || !src) return NULL;
    if (!n ||dest == src) return dest;

    char* d = (char*)dest;
    const char *s = (const char*)src;
    int dlen = strlen(d), slen = strlen(s);
    if (dest > src && src + slen > dest) { // ����
        d = d + dlen;
        s = s + slen;
        while (n--) *d-- = *s--;
    }
    else {
        while (n--) *d++ = *s++;
    }

    return dest;
}

void* mymemeset(void* dest, int val, size_t n) { // ��dest��n���ֽ���val
    if(!dest) return NULL;
    if (!n) return dest;

    char* d = (char*)dest;
    while (n--) *d++ = val;

    return dest;
}

bool mystrcmp(char* s1, char* s2) { // �Ƚ������ַ���
    size_t s1len = strlen(s1), s2len = strlen(s2);
    if (s1len != s2len) return false;
    if (!s1len) return true;

    for (int i = 0; i < s1len; i++) {
        if (s1[i] != s2[i]) return false;
    }

    return true;
}