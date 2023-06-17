//
// Created by Administrator on 2022/4/2 0002.
//

#ifndef ACM_SCNNER_H
#define ACM_SCNNER_H

class Scanner{
private:
    bool blank(char c);
public:
    int readInt();
    long long readLL();
    char readChar();
    void readCStr(char *c);
    string readString();
};

inline int Scanner::readInt(){

    register int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}

inline long long readLL(){

    register long long x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}

inline char Scanner::readChar(){

    return getchar();
}

inline void Scanner::readCStr(char *c){

    char ch = getchar();
    while (blank(ch)) ch = getchar();
    int p = 0;
    for (c[p++] = ch; !blank(ch = getchar()); c[p++] = ch);
    c[p] = '\0';//½áÎ²
}

inline string Scanner::readString(){

    char strBuf[10000];
    readCStr(strBuf);
    string s = strBuf;
    return s;
}

inline bool Scanner::blank(char c){

    return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}


#endif //ACM_SCNNER_H

