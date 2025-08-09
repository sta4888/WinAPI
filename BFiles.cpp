#include <Windows.h>
#include <string.h>



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	PCWSTR PATH = L"D:/1/test.txt"; //Путь к файлу с которым будем работать

	//Функция открытия файла ASCII(явная)
	/*
	HANDLE WINAPI CreateFileA(
		_In_     LPCSTR               lpFileName, // <- путь к файлу
		_In_     DWORD                 dwDesiredAccess, // <-доступ к файлу. См. ниже
		_In_     DWORD                 dwShareMode, // <- Разрешение на доступ к файлу другому ПО
		_In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes, // <- * на структуру безопасности. Ставим NULL
		_In_     DWORD                 dwCreationDisposition, // <- определяет как открыть файл. См. ниже
		_In_     DWORD                 dwFlagsAndAttributes, // <- атрибут файла. Ставим FILE_ATTRIBUTE_NORMAL
		_In_opt_ HANDLE                hTemplateFile //<- Дескриптор базового файла для наследования атрибутов
	);
	// Доступ: GENERIC_READ - чтение, GENERIC_WRITE - запись. Можно объеденить побитовым ИЛИ
	// Доступ другому ПО:
		// NULL - другие программы не могут даже читать файл
		// FILE_SHARE_READ - разрешает только читать файл
		// FILE_SHARE_WRITE - чтение и запись
		// FILE_SHARE_DELETE - чтение, запись удаление
	//Как открыть файл:
		//CREATE_NEW - пытается создать новый файл. Если файл существует - то функция завершится неудачей
		//CREATE_ALWAYS - всегда создаст новый
		//OPEN_EXISTING - открывает существующий. Иначе - неудача
		//OPEN_ALWAYS - открывает если файл есть, иначе - создаёт новый
		//TRUNCATE_EXISTING - Дописать в конец СУЩЕСТВУЮЩЕГО файла. Файл должен быть открыт на запись
	*/
	//Соответственно для юникода - CreateFileW
	//У CreateFile нет расширенной версии

	HANDLE hFile = CreateFile(
		PATH,
		GENERIC_READ | GENERIC_WRITE,
		NULL, //<- NB!
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	system("pause");

	CloseHandle(hFile); //<- закрывает дескриптор

	return 0;
}