//---------------------------------------------------------------------------
#pragma hdrstop  //
#include "Function_Unit.h"
//---------------------------------------------------------------------------
char *LoadFromFile(char* FileName, DWORD* DlinaFile)
{
DWORD Length = 0;
HANDLE hFile;
char* Buffer;
       hFile = CreateFile(FileName,  // Создаем (открываем) файл с именем FileName
                                     //   и возвращаем его адрес (ссылку)
                          GENERIC_READ,        // для чтения
                          FILE_SHARE_READ,
                          NULL,
                          OPEN_ALWAYS,
                          0,
                          NULL);
       Length = GetFileSize(hFile, 0); // Считываем размер файла
       Buffer = new char[Length + 7];  // Выделяем память под файл (чуть больше)
       SetFilePointer(hFile, 0, 0, FILE_BEGIN); // устанавливаем курсор на НАЧАЛО файла

       ReadFile(hFile,          // Считываем файл всё ++ Ссылка на файл
                Buffer,         // Куда считываем "строка"
                Length,         // Необходимая длинна
                DlinaFile,      // Количество реально считанных символов
                NULL);

       Buffer[*DlinaFile] = 0; //Обнулям после последнего символа 0 - КОНЕЦ СТРОКИ
       CloseHandle(hFile);     //     Закрываем ссылку на файл

return Buffer; // Возвращаем адрес массива символов
}
//---------------------------------------------------------------------------
void SaveFile(char *FileName, char *str, DWORD &DlinaFaila)
{
  unsigned int sd = 0;
  sd = DlinaFaila;

  while(str[sd++]);
  sd--;
  
  HANDLE        hFile;
  DWORD         dlinaFile; // младшие 32 бита длины файла
  unsigned long       DlinaFile; // старшие 32 бита длины файла

  hFile   = CreateFile( FileName,         //открываем фаил на запись
                        GENERIC_WRITE,
                        0,
                        0,
                        OPEN_ALWAYS,    // если его нет то создаём его
                        0,0);

  WriteFile(hFile, str, sd, &DlinaFile, NULL);  // дописываем в конец файла строку

  CloseHandle(hFile);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
