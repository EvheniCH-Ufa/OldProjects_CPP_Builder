//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RC_4_Unit.h"
#include "Function_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char *TextIshodnii = 0;
DWORD Dl_File = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Open_BtnClick(TObject *Sender)
{
 if (OpenDialog1->Execute())
     {
      TextIshodnii = LoadFromFile(OpenDialog1->FileName.c_str(), &Dl_File); // вызываем функцию LoadFromFile (моя)
     // В исх текст заносим содержимое файла
      DO_Memo->Text = TextIshodnii;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cod_BtnClick(TObject *Sender)
{
//   Блок для генерации 256 символьного ключа пользователя  "К" - в алгоритме
 AnsiString StrUserKey = ""; // Переменная для ключа пользователя
                        // то, что вводит user

 AnsiString StrCodeKey = ""; // Переменная для ключа кодирования строковая
 StrUserKey = Key_Edit->Text;// Считываем ключ пользователя из эдита

 int KeyUserDlina; // Длинна ключа пользователя то, что ввел user
 KeyUserDlina = StrUserKey.Length();  // узнаем длинну ключа пользователя

 int Kol_wo_Copy = 256/KeyUserDlina; // Количество копий ключа пользователя
 Kol_wo_Copy++;    // Увеличиваем на 1 для верности (делаем ключ больше 256 сим)
 int i;
 for ( i = 0; i < Kol_wo_Copy; i++)    //  копируем строку ключа Kol_wo_Copy раз
    StrCodeKey = StrCodeKey + StrUserKey;  // увеличиваем до 256 и более

char *Code_Key;                // Рабочий ключ в алгоритме    К
Code_Key = StrCodeKey.c_str(); // заносим ключ в массив символов
Code_Key[256] = 0;             // обрезка до 256 символов
//   Блок для генерации 256 символьного ключа пользователя +++ конец блока

//---------------------------------------------------------------------------
if (TextIshodnii == 0)  // проверяем - есть ли текст в исх строке
    {
     TextIshodnii = DO_Memo->Text.c_str();   // если нет, то считываем его из мемо
     Dl_File = DO_Memo->Text.Length();         // длинна текста
    }
//---------------------------------------------------------------------------

//   Блок для генерации 256 символьного S - блока,"S" - в алгоритме линейно

unsigned char SBlok[256]; // Переменная - массив чисел (байт - от 0 до 255 - значения)
                       // длинной в 256 ячеек
for (i = 0;i < 256; i++)
   SBlok[i] = i;          // Заполняем линейно S - блок значениями i в i ячейке

// Блок для генерации 256 символьного S - блока,"S" - в алгоритме линейно КОНЕЦ

//---------------------------------------------------------------------------
int I, tmp, J = 0;
unsigned char t, K=0;

for (I = 0; I < 256; I++)
    {
     J = (J + SBlok[I] + Code_Key[I]) % 256; // Инициализация J для замены
    //    Меняем местами SBlok[I] и SBlok[J]
     tmp = SBlok[J];      // сохраняем SBlok[J] в tmp  ---|
     SBlok[J] = SBlok[I]; // заносим в SBlok[J] SBlok[I]  |
     SBlok[I] = tmp;      // заносим в SBlok[I]  tmp    <-|
    }

I = 0;
J = 0;
for (i = 0; i < Dl_File; i++) // Цикл от 0 до кол-ва считанных символов
    {
     I++;                 // УВЕЛИЧИВАЕМ I на 1
     I = I % 256;         // остаток от деления на 256
     J = (J + SBlok[I]) % 256; // Инициализация J для замены
     t = SBlok[I] + SBlok[J];  // по формуле
     K = SBlok[t];             // по формуле

     //ПОЛУЧИЛИ ПСЕВДОСЛУЧАЙНЫЙ БАЙТ, БЛЯ ЭТО К

     TextIshodnii[I-1] = TextIshodnii[I-1] ^ K; // операция XOR I - го символа
    // текста с I mod 256 (остаток от деления) символом ключа
    }

if (OpenDialog1->FileName == "") SaveFile("c:\cod.txt",TextIshodnii , Dl_File);
// если файл не выбран, то сохраняем в "c:\cod.txt"
else SaveFile((OpenDialog1->FileName + "код").c_str(),TextIshodnii , Dl_File);
// иначе сохраняем в файл с исходным именем, только в расширение добавляем "код"
Posle_Memo->Text = TextIshodnii; // отображение обработанного текста в МЕМО
OpenDialog1->FileName = "";      // чистим имя файла от случайной записи
delete(TextIshodnii);            // освобождение памяти текста
TextIshodnii = 0;                // обнуляем ссылку на текст
}
//---------------------------------------------------------------------------


