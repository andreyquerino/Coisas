// @AndreyQuerino
//
// Compilação linux g++/i686-w64-mingw32-g++ <filename>.cpp -o <filname>.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
// Compilação windows g++ <filename>.cpp -o <filname>.exe
//
// Simples criptografia xor

#include<bits/stdc++.h>

void Decrypter(char* Encrypt_Decrypt) { 
    char Chave[2] = {4, 4}; //Coloque quantas chaves quiser
    for (int i = 0; i < (strlen(Encrypt_Decrypt)); i++){ 
        Encrypt_Decrypt[i] = Encrypt_Decrypt[i] ^ Chave[i % (sizeof(Chave) / sizeof(char))]; 
        printf("%c",Encrypt_Decrypt[i]); 
    } 
} 

int main() { 
    char Run[] = "www.github.com/andreyquerino"; //Texto
    printf("Encriptado: "); 
    Decrypter(Run); 
    printf("\nDecripitado: "); 
    Decrypter(Run);
}

// Saída
// Encripitado: sss*cmplqf*gki+ej`va}uqavmjk
// Decripitado: www.github.com/andreyquerino
