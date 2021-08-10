// @AndreyQuerino
// Compilação linux g++/i686-w64-mingw32-g++ <filename>.cpp -o <filname>.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
// Compilação windows g++ -std=c++11 a.cpp -o a.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
// Mensagem de boas vindas

#include <stdio.h>
#include <windows.h>

void wellCome(){
    printf("*************************************************************************************************************\n\n");
    printf("Yb        dP       8 .d88b                          8b   d8         .d88b.                  w\n");             
    printf(" Yb  db  dP  .d88b 8 8P    .d8b. 8d8b.d8b. .d88b    8YbmdP8 8d8b    8P  Y8 8   8 .d88b 8d8b w 8d8b. .d8b.\n"); 
    printf("  YbdPYbdP   8.dP' 8 8b    8' .8 8P Y8P Y8 8.dP'    8  v  8 8P      8b wd8 8b d8 8.dP' 8P   8 8P Y8 8' .8\n"); 
    printf("   YP  YP    `Y88P 8 `Y88P `Y8P' 8   8   8 `Y88P    8     8 8       `Y88Pw `Y8P8 `Y88P 8    8 8   8 `Y8P'\n\n");
    printf("*************************************************************************************************************\n\n"); 
}

int main(){
    wellCome();
    system("pause");
    return 0;
}