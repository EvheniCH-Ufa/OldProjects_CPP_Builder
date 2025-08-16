//---------------------------------------------------------------------------
#pragma hdrstop
#include "Function_Unit.h"
#include "RC_5_Unit.h"
//---------------------------------------------------------------------------
char *LoadFromFile(char* FileName, DWORD* DlinaFile)
{
DWORD Length = 0;
HANDLE hFile;
char* Buffer;
       hFile = CreateFile(FileName,
                          GENERIC_READ,
                          FILE_SHARE_READ,
                          NULL,
                          OPEN_ALWAYS,
                          0,
                          NULL);
       Length = GetFileSize(hFile, 0);
       Buffer = new char[Length+7];
       SetFilePointer(hFile, 0, 0, FILE_BEGIN); // ������������� ������ �� ������ �����
       ReadFile(hFile, Buffer, Length, DlinaFile, NULL);
       Buffer[*DlinaFile] = 0;
       CloseHandle(hFile);

return Buffer;
}
//---------------------------------------------------------------------------
void SaveFile(char *FileName, char *str, DWORD &DlinaFaila)
{
  unsigned int sd = 0;
  sd = DlinaFaila;

  while(str[sd++]);
  sd--;
  
  HANDLE        hFile;
  DWORD         dlinaFile; // ������� 32 ���� ����� �����
  unsigned long       DlinaFile; // ������� 32 ���� ����� �����

  hFile   = CreateFile( FileName,         //��������� ���� �� ������
                        GENERIC_WRITE,
                        0,
                        0,
                        OPEN_ALWAYS,    // ���� ��� ��� �� ������ ���
                        0,0);

  WriteFile(hFile, str, sd, &DlinaFile, NULL);  // ���������� � ����� ����� ������

  CloseHandle(hFile);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
