//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "GOST_Unit.h"
#include "Function_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
char *TextIshodnii = 0;
char *TextPosle    = 0;

DWORD Dl_File = 0;
unsigned char TabZamen[8][16] =
{
  {3, 5, 7, 9, 0, 8, 6, 4, 2, 1,15,10,12,14,13,11},
  {1, 3, 5, 7, 9,11,13,15,14,12,10, 8, 6, 4, 2, 0},
  {15,13,11, 9, 7, 5, 3, 1, 0, 2, 4, 6, 8,10,12,14},
  {0, 2, 4, 6, 8,10,12,14,15,13,11, 9, 7, 5, 3, 1},
  {14,12,10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9,11,13,15},
  {0,15, 1,14, 2,13, 3,12, 4,11, 5,10, 6, 9, 7, 8},
  {4,11, 5,10, 6, 9, 7, 8, 0,15, 1,14, 2,13, 3,12},
  {11,14,13,12,10,15, 1, 2, 4, 6, 8, 0, 9, 7, 5, 3}
} ;


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
//   Блок для генерации 32 символьного ключа пользователя
 AnsiString StrUserKey = "";  // Переменная для ключа пользователя
                              // то, что вводит user

 AnsiString StrKey32 = "";    // Переменная для ключа кодирования строковая
 StrUserKey = Key_Edit->Text; // Считываем ключ пользователя из эдита

 int KeyUserDlina;                // Длинна ключа пользователя то, что ввел user
 KeyUserDlina = StrUserKey.Length();  // узнаем длинну ключа пользователя

int Kol_wo_Copy = 0;
 if (KeyUserDlina < 32) Kol_wo_Copy = 32/KeyUserDlina; // Количество копий ключа пользователя
 Kol_wo_Copy++;    // Увеличиваем на 1 для верности (делаем ключ больше 256 сим)

 int i;
 for ( i = 0; i < Kol_wo_Copy; i++)    //  копируем строку ключа Kol_wo_Copy раз
    StrKey32 = StrKey32 + StrUserKey;  // увеличиваем до 32 и более

char * tmp;         // переменная - временный массив символов
tmp = new char[32]; // выделяем память
tmp = StrKey32.c_str(); // в неё заносим 32 символа ключа
tmp[32] = 0;     // обрезка  ДО 32
char * aKey; // переменная - массив символов для ключа 128 байт
 aKey = new char[128]; // выделяем память

 aKey = StrCopy(aKey, tmp); // копируем 32 символа из tmp в aKey - 1 РАЗ к1..к8
 aKey[32] = 0;              // обрезка
 aKey = StrCat(aKey, tmp);  // конкатенация aKey и tmp заносим в aKey - 2 РАЗ к1..к8
 aKey = StrCat(aKey, tmp); // конкатенация aKey и tmp заносим в aKey = 96 символов
                           // - 3 РАЗ к1..к8
 aKey[96] = 0;

for (int i = 7; i >= 0; i--) // цикл для инверсии 32 Симв по 4 символа
{                            // из tmp
/// Высчитываем  tmp[4*i](+1;+2;+3) --- K8 - i=0,
//  96 при i = 0  (+1;+2;+3)            K7 - i=1, и т.д
//  100 при i = 1 и т.д         И заносим символы из tmp

 aKey[96 + (7-i)*4]     = tmp[4*i];
 aKey[96 + (7-i)*4 + 1] = tmp[4*i + 1];
 aKey[96 + (7-i)*4 + 2] = tmp[4*i + 2];
 aKey[96 + (7-i)*4 + 3] = tmp[4*i + 3];
}
// Ключ сформирован



// Удлинитель исходного текста до кратности 64 бита - 8 символов

if (OpenDialog1->FileName == "")         // если файл не открыт
  {                                      // то
   Dl_File = DO_Memo->Text.Length();     // Смотрим в Мемо длинну текста,
   TextIshodnii = new char[Dl_File + 8]; // выделяем память с запасом
   TextIshodnii = StrCopy(TextIshodnii,DO_Memo->Text.c_str()); // и в TextIshodnii пишем текст из Мемо
  }
int KOL_Dobawki = Dl_File % 8;   // узнаем остаток от деления Dl_File на 8

int j;
if (KOL_Dobawki != 0) //  если остаток не 0
    {
     KOL_Dobawki = 8 - KOL_Dobawki; // узнаем кол-во недостающих символов
     // Добавочные символы - точки и последний - их количество
     char * Dobawka = 0;  // переменная для добавки

     Dobawka = new char[KOL_Dobawki];

     for (j = 0; j < KOL_Dobawki - 1; j++)
        Dobawka[j] = '.';           // делаем строку с точками
                                           // кол-во их = KOL_Dobawki-1
     Dobawka[j] = (j + 49);  // последний символ - само колич-во
     Dobawka[j+1] = 0;

     Dl_File = Dl_File + KOL_Dobawki; // Т.к. длина TextIshodnii изменилась -
                                      // увеличиваем и значение ее длинны

     TextIshodnii = StrCat(TextIshodnii, Dobawka); // добавляем
                                                    // добавку сзади исходного текста
    };
TextPosle = new char[Dl_File + 1];  // выделяем память для обработанного текста


// А теперь - сама кодировка       -УУУУУУУ-УУУУУ-УУУУУ-УУУУ

RL L, R;           //  его левая и правая части
for (i = 0; i < (Dl_File / 8); i++)  // Цикл кодирования по 8 символов (64 бита)
   {
    L.R_char[0] = TextIshodnii[i*8];     // Посимвольное копирование
    L.R_char[1] = TextIshodnii[i*8 + 1]; // 4 символов из ТextIshodnii
    L.R_char[2] = TextIshodnii[i*8 + 2]; // в L
    L.R_char[3] = TextIshodnii[i*8 + 3];

    R.R_char[0] = TextIshodnii[i*8 + 4]; // -//- в R
    R.R_char[1] = TextIshodnii[i*8 + 5];
    R.R_char[2] = TextIshodnii[i*8 + 6];
    R.R_char[3] = TextIshodnii[i*8 + 7];
RL R_tmp;
    for (j = 0; j < 32; j++)  // счетчик итераций шифрования блока в 64 бита
      {
       R_tmp = R;            // сохраняем здесь L для операции XOR;
       RL Key_4;                // объявл пиеременную - ключ из 4 символов

       Key_4.R_char[0] = aKey[j*4];     // Посимвольное копирование
       Key_4.R_char[1] = aKey[j*4 + 1]; // 4 символов из основного ключа
       Key_4.R_char[2] = aKey[j*4 + 2]; // в 4-х символьный ключ
       Key_4.R_char[3] = aKey[j*4 + 3];

       //  Функция сМод - суммирование по mod 32
       R.R_int = R.R_int + Key_4.R_int; // обрезается по mod 2**32
                      // автоматически т.к. тип int и дают число мах 2**32


       // Замена в таблице замен
       unsigned char Bait, AH, AL;
       Bait = R.R_char[3];         // временн перем = 1 Byte
       AH   = Bait / 16;  // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;  // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[1][AH];
       AL = TabZamen[0][AL];

       R.R_char[3] = AH * 16 + AL;
         // 1 байт заменили

       Bait = R.R_char[2];         // временн перем = 1 Byte
       AH   = Bait / 16;  // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;  // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[3][AH];
       AL = TabZamen[2][AL];

       R.R_char[2] = AH * 16 + AL;
         // 2 байт заменили


       Bait = R.R_char[1];   // временн перем = 1 Byte
       AH   = Bait / 16;     // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;     // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[5][AH];
       AL = TabZamen[4][AL];

       R.R_char[1] = AH * 16 + AL;
         // 3 байт заменили


       Bait = R.R_char[0];         // временн перем = 1 Byte
       AH   = Bait / 16;  // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;  // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[7][AH];
       AL = TabZamen[6][AL];

       R.R_char[0] = AH * 16 + AL;
       // 4 байт заменили
       // Замена в таблице замен закончили

       // Сдвиг на 11бит влево
       asm
        {
         rol R.R_int, 11;
        };

       // операция "XOR"
       R.R_int = L.R_int ^ R.R_int;

       // обмен R и L м/у собой
       L     = R_tmp;
      }
    L = R;
    R = R_tmp;

    TextPosle[i*8]     = L.R_char[0]; // Посимвольное копирование
    TextPosle[i*8 + 1] = L.R_char[1]; // 4 символов из L в TextPosle
    TextPosle[i*8 + 2] = L.R_char[2];
    TextPosle[i*8 + 3] = L.R_char[3];

    TextPosle[i*8 + 4] = R.R_char[0]; // Посимвольное копирование
    TextPosle[i*8 + 5] = R.R_char[1]; // 4 символов из R в TextPosle
    TextPosle[i*8 + 6] = R.R_char[2];
    TextPosle[i*8 + 7] = R.R_char[3];

    TextPosle[i*8 + 8] = 0;
   }

if (OpenDialog1->FileName == "") SaveFile("c:\cod.txt",TextPosle , Dl_File);
// если файл не выбран, то сохраняем в "c:\cod.txt"
else SaveFile((OpenDialog1->FileName + "код").c_str(), TextPosle , Dl_File);
// иначе сохраняем в файл с исходным именем, только в расширение добавляем "код"

Posle_Memo->Text = TextPosle; // отображение обработанного текста в МЕМО
OpenDialog1->FileName = "";      // чистим имя файла от случайной записи
delete(TextIshodnii);            // освобождение памяти текста исходного
delete(TextPosle);            // освобождение памяти текста полученного
TextIshodnii = 0;                // обнуляем ссылку на текст исходного
TextPosle = 0;                // обнуляем ссылку на текст полученного
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Recod_BtnClick(TObject *Sender)
{
//   Блок для генерации 32 символьного ключа пользователя
 AnsiString StrUserKey = "";  // Переменная для ключа пользователя
                              // то, что вводит user

 AnsiString StrKey32 = "";    // Переменная для ключа кодирования строковая
 StrUserKey = Key_Edit->Text; // Считываем ключ пользователя из эдита

 int KeyUserDlina;                // Длинна ключа пользователя то, что ввел user
 KeyUserDlina = StrUserKey.Length();  // узнаем длинну ключа пользователя

int Kol_wo_Copy = 0;
 if (KeyUserDlina < 32) Kol_wo_Copy = 32/KeyUserDlina; // Количество копий ключа пользователя
 Kol_wo_Copy++;    // Увеличиваем на 1 для верности (делаем ключ больше 256 сим)

 int i;
 for ( i = 0; i < Kol_wo_Copy; i++)    //  копируем строку ключа Kol_wo_Copy раз
    StrKey32 = StrKey32 + StrUserKey;  // увеличиваем до 32 и более

char * tmp;         // переменная - временный массив символов
tmp = new char[32]; // выделяем память
tmp = StrKey32.c_str(); // в неё заносим 32 символа ключа
tmp[32] = 0;     // обрезка  ДО 32
char * aKey; // переменная - массив символов для ключа 128 байт
 aKey = new char[128]; // выделяем память

 aKey = StrCopy(aKey, tmp); // копируем 32 символа из tmp в aKey - 1 РАЗ к1..к8
 aKey[32] = 0;              // обрезка
 aKey = StrCat(aKey, tmp);  // конкатенация aKey и tmp заносим в aKey - 2 РАЗ к1..к8
 aKey = StrCat(aKey, tmp); // конкатенация aKey и tmp заносим в aKey = 96 символов
                           // - 3 РАЗ к1..к8
 aKey[96] = 0;

for (int i = 7; i >= 0; i--) // цикл для инверсии 32 Симв по 4 символа
{                            // из tmp
/// Высчитываем  tmp[4*i](+1;+2;+3) --- K8 - i=0,
//  96 при i = 0  (+1;+2;+3)            K7 - i=1, и т.д
//  100 при i = 1 и т.д         И заносим символы из tmp

 aKey[96 + (7-i)*4]     = tmp[4*i];
 aKey[96 + (7-i)*4 + 1] = tmp[4*i + 1];
 aKey[96 + (7-i)*4 + 2] = tmp[4*i + 2];
 aKey[96 + (7-i)*4 + 3] = tmp[4*i + 3];
} // Ключ сформирован



// Удлинитель исходного текста до кратности 64 бита - 8 символов

if (OpenDialog1->FileName == "")         // если файл не открыт
  {                                      // то
   Dl_File = DO_Memo->Text.Length();     // Смотрим в Мемо длинну текста,
   TextIshodnii = new char[Dl_File + 8]; // выделяем память с запасом
   TextIshodnii = StrCopy(TextIshodnii,DO_Memo->Text.c_str()); // и в TextIshodnii пишем текст из Мемо
  }

int KOL_Dobawki = Dl_File % 8;   // узнаем остаток от деления Dl_File на 8



   // ПРОВЕРЯЕМ НА КРАТНОСТЬ 64 БИТА (ЭТО ТЕКСТ ЗАКОДИРОВАН ИЛИ НЕТ)
if (KOL_Dobawki != 0)
   {
    ShowMessage("Этот файл/текст не был зашифрован, т.к его длина не кратна 8!!!!");
    delete(TextIshodnii);   // освобождение памяти текста исходного
    return;
   }

int j;
if (KOL_Dobawki != 0) //  если остаток не 0
    {
     KOL_Dobawki = 8 - KOL_Dobawki; // узнаем кол-во недостающих символов
     // Добавочные символы - точки и последний - их количество
     char * Dobawka = 0;  // переменная для добавки

     Dobawka = new char[KOL_Dobawki];

     for (j = 0; j < KOL_Dobawki - 1; j++)
        Dobawka[j] = '.';           // делаем строку с точками
                                           // кол-во их = KOL_Dobawki-1
     Dobawka[j] = (j + 48);  // последний символ - само колич-во
     Dobawka[j+1] = 0;

     Dl_File = Dl_File + KOL_Dobawki; // Т.к. длина TextIshodnii изменилась -
                                      // увеличиваем и значение ее длинны

     TextIshodnii = StrCat(TextIshodnii, Dobawka); // добавляем
                                                    // добавку сзади исходного текста
    };
TextPosle = new char[Dl_File + 1];

// А теперь - сама РАСКОДИРОВКА       -УУУУУУУ-УУУУУ-УУУУУ-УУУУ
RL L, R;           //  его левая и правая части
for (i = 0; i < (Dl_File / 8); i++)  // Цикл кодирования по 8 символов (64 бита)
   {
    L.R_char[0] = TextIshodnii[i*8];     // Посимвольное копирование
    L.R_char[1] = TextIshodnii[i*8 + 1]; // 4 символов из ТextIshodnii
    L.R_char[2] = TextIshodnii[i*8 + 2]; // в L
    L.R_char[3] = TextIshodnii[i*8 + 3];

    R.R_char[0] = TextIshodnii[i*8 + 4]; // -//- в R
    R.R_char[1] = TextIshodnii[i*8 + 5];
    R.R_char[2] = TextIshodnii[i*8 + 6];
    R.R_char[3] = TextIshodnii[i*8 + 7];

RL R_tmp ;
    for (j = 0; j < 32; j++)  // счетчик итераций шифрования блока в 64 бита
      {
       R_tmp = R;            // сохраняем здесь R для операции XOR;
       RL Key_4;                // объявл пиеременную - ключ из 4 символов

       Key_4.R_char[0] = aKey[(32-j-1)*4];     // Посимвольное копирование
       Key_4.R_char[1] = aKey[(32-j-1)*4 + 1]; // 4 символов из основного ключа
       Key_4.R_char[2] = aKey[(32-j-1)*4 + 2]; // в 4-х символьный ключ
       Key_4.R_char[3] = aKey[(32-j-1)*4 + 3];

       //  Функция сМод - суммирование по mod 32
       R.R_int = R.R_int + Key_4.R_int; // обрезается по mod 2**32
                      // автоматически т.к. тип int и дают число мах 2**32


       // Замена в таблице замен
       unsigned char Bait, AH, AL;
       Bait = R.R_char[3];         // временн перем = 1 Byte
       AH   = Bait / 16;  // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;  // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[1][AH];
       AL = TabZamen[0][AL];

       R.R_char[3] = AH * 16 + AL;
         // 1 байт заменили

       Bait = R.R_char[2];         // временн перем = 1 Byte
       AH   = Bait / 16;  // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;  // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[3][AH];
       AL = TabZamen[2][AL];

       R.R_char[2] = AH * 16 + AL;
         // 2 байт заменили


       Bait = R.R_char[1];   // временн перем = 1 Byte
       AH   = Bait / 16;     // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;     // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[5][AH];
       AL = TabZamen[4][AL];

       R.R_char[1] = AH * 16 + AL;
         // 3 байт заменили


       Bait = R.R_char[0];         // временн перем = 1 Byte
       AH   = Bait / 16;  // АН - старшая часть от Bait = 4 бита (целочисл деление)
       AL   = Bait % 16;  // АL - младшая часть от Bait = 4 бита (остаток от деления)

       AH = TabZamen[7][AH];
       AL = TabZamen[6][AL];

       R.R_char[0] = AH * 16 + AL;
       // 4 байт заменили
       // Замена в таблице замен закончили

       // Сдвиг на 11бит влево
       asm
        {
         rol R.R_int, 11;
        };

       // операция "XOR"
       R.R_int = R.R_int ^ L.R_int;

       // обмен R и L м/у собой
       L     = R_tmp;
      }
    L = R;
    R = R_tmp;

    TextPosle[i*8]     = L.R_char[0]; // Посимвольное копирование
    TextPosle[i*8 + 1] = L.R_char[1]; // 4 символов из L в TextPosle
    TextPosle[i*8 + 2] = L.R_char[2];
    TextPosle[i*8 + 3] = L.R_char[3];

    TextPosle[i*8 + 4] = R.R_char[0]; // Посимвольное копирование
    TextPosle[i*8 + 5] = R.R_char[1]; // 4 символов из R в TextPosle
    TextPosle[i*8 + 6] = R.R_char[2];
    TextPosle[i*8 + 7] = R.R_char[3];

    TextPosle[i*8 + 8] = 0;
   }

if (OpenDialog1->FileName == "") SaveFile("c:\cod.txt",TextPosle , Dl_File);
// если файл не выбран, то сохраняем в "c:\cod.txt"
else SaveFile((OpenDialog1->FileName + "код").c_str(), TextPosle , Dl_File);
// иначе сохраняем в файл с исходным именем, только в расширение добавляем "код"

Posle_Memo->Text = TextPosle; // отображение обработанного текста в МЕМО
OpenDialog1->FileName = "";      // чистим имя файла от случайной записи
delete(TextIshodnii);            // освобождение памяти текста исходного
delete(TextPosle);            // освобождение памяти текста полученного
TextIshodnii = 0;                // обнуляем ссылку на текст исходного
TextPosle = 0;                // обнуляем ссылку на текст полученного
      
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 DO_Memo->Text = "1234";
}
//---------------------------------------------------------------------------

