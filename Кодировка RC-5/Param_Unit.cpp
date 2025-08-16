//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Param_Unit.h"
#include "RC_5_Unit.h"
#include "Function_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TParam_Frm *Param_Frm;
String StrKey;
//---------------------------------------------------------------------------
__fastcall TParam_Frm::TParam_Frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TParam_Frm::Button1Click(TObject *Sender)
{
  int DlinaKey = 0;
  StrKey = EdKey->Text;         // Сохраняем для отображения ключ в строку
  Form1->Memo4->Text = StrKey;
  String Str = EdKey->Text;         // Списываем ключ в строку
  Key = Str.c_str();        // ССылка на ключ

  while (Key[DlinaKey] != 0) // Узнаем длину ключа
        DlinaKey++;

  C = DlinaKey / 4 + 1;      // Кол-во 32 - битных блоков в ключе
  L = (unsigned int*)Key;    // Инициализируем массив L КЛЮЧОМ в 32 битных числах
  R = UpDown1->Position;     // Инициализируем R - кол-во раундов

  if (S)                     // обнуляем S - блоки, если что
     delete(S);

  S = new unsigned int[2*(R+1)]; // Новая память под S - блоки
  S[0] = P;                        // Инициализируем 1 - й блок

  unsigned int i = 0, j = 0, A = 0, B = 0, n = 0, ciklS = 0;

  for (i=1; i < (2*(R + 1)-1);i++)  // Первоначальная инициализация
       S[i] = (S[i-1] + Q);         // S - блоков

  n = 2*(R + 1);                    //
  if (C > n)                        // n = большее из |2*(R + 1)| и |С|
      n = C;

  i = 0;
  for (ciklS = 0; ciklS < 3*n; ciklS++)
  {
   // -------------  A = Si = ( Si + A + B ) <<< 3    ---------------------
   A += S[i] + B;   // инициализация S - блоков
   asm
      {
       rol A, 3;      // Циклический сдвиг влево S - блока на 3 бита
      };
   S[i] = A;

   // -------------  A = Si = ( Si + A + B ) <<< 3    ---------------------

   /**********************************************************************/

   // -------------  B = Lj = ( Lj + A + B ) <<< (A + B)  -----------------
  unsigned char sdwig = 0;
   sdwig  = (A + B) % 32;
   B += L[j] + A;

   asm
      {
       mov cl, sdwig;
       rol B, cl;
      };

   L[j] = B;          // Переинициализация Lj

   // -------------  B = Lj = ( Lj + A + B ) <<< (A + B)  -----------------

   i    = (i + 1) % (2 * (R + 1));    // i = ( i  +  1 ) mod 2(r+1),
   j    = (j + 1) % C;                // j = ( j  +  1 ) mod c
  }
}
//---------------------------------------------------------------------------


void __fastcall TParam_Frm::FormCreate(TObject *Sender)
{
Button1Click(Param_Frm);
}
//---------------------------------------------------------------------------

void __fastcall TParam_Frm::Button2Click(TObject *Sender)
{
EdKey->Text = StrKey;
UpDown1->Position = R;
Close();
}
//---------------------------------------------------------------------------


