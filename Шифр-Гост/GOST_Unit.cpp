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
      TextIshodnii = LoadFromFile(OpenDialog1->FileName.c_str(), &Dl_File); // �������� ������� LoadFromFile (���)
     // � ��� ����� ������� ���������� �����
      DO_Memo->Text = TextIshodnii;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cod_BtnClick(TObject *Sender)
{
//   ���� ��� ��������� 32 ����������� ����� ������������
 AnsiString StrUserKey = "";  // ���������� ��� ����� ������������
                              // ��, ��� ������ user

 AnsiString StrKey32 = "";    // ���������� ��� ����� ����������� ���������
 StrUserKey = Key_Edit->Text; // ��������� ���� ������������ �� �����

 int KeyUserDlina;                // ������ ����� ������������ ��, ��� ���� user
 KeyUserDlina = StrUserKey.Length();  // ������ ������ ����� ������������

int Kol_wo_Copy = 0;
 if (KeyUserDlina < 32) Kol_wo_Copy = 32/KeyUserDlina; // ���������� ����� ����� ������������
 Kol_wo_Copy++;    // ����������� �� 1 ��� �������� (������ ���� ������ 256 ���)

 int i;
 for ( i = 0; i < Kol_wo_Copy; i++)    //  �������� ������ ����� Kol_wo_Copy ���
    StrKey32 = StrKey32 + StrUserKey;  // ����������� �� 32 � �����

char * tmp;         // ���������� - ��������� ������ ��������
tmp = new char[32]; // �������� ������
tmp = StrKey32.c_str(); // � �� ������� 32 ������� �����
tmp[32] = 0;     // �������  �� 32
char * aKey; // ���������� - ������ �������� ��� ����� 128 ����
 aKey = new char[128]; // �������� ������

 aKey = StrCopy(aKey, tmp); // �������� 32 ������� �� tmp � aKey - 1 ��� �1..�8
 aKey[32] = 0;              // �������
 aKey = StrCat(aKey, tmp);  // ������������ aKey � tmp ������� � aKey - 2 ��� �1..�8
 aKey = StrCat(aKey, tmp); // ������������ aKey � tmp ������� � aKey = 96 ��������
                           // - 3 ��� �1..�8
 aKey[96] = 0;

for (int i = 7; i >= 0; i--) // ���� ��� �������� 32 ���� �� 4 �������
{                            // �� tmp
/// �����������  tmp[4*i](+1;+2;+3) --- K8 - i=0,
//  96 ��� i = 0  (+1;+2;+3)            K7 - i=1, � �.�
//  100 ��� i = 1 � �.�         � ������� ������� �� tmp

 aKey[96 + (7-i)*4]     = tmp[4*i];
 aKey[96 + (7-i)*4 + 1] = tmp[4*i + 1];
 aKey[96 + (7-i)*4 + 2] = tmp[4*i + 2];
 aKey[96 + (7-i)*4 + 3] = tmp[4*i + 3];
}
// ���� �����������



// ���������� ��������� ������ �� ��������� 64 ���� - 8 ��������

if (OpenDialog1->FileName == "")         // ���� ���� �� ������
  {                                      // ��
   Dl_File = DO_Memo->Text.Length();     // ������� � ���� ������ ������,
   TextIshodnii = new char[Dl_File + 8]; // �������� ������ � �������
   TextIshodnii = StrCopy(TextIshodnii,DO_Memo->Text.c_str()); // � � TextIshodnii ����� ����� �� ����
  }
int KOL_Dobawki = Dl_File % 8;   // ������ ������� �� ������� Dl_File �� 8

int j;
if (KOL_Dobawki != 0) //  ���� ������� �� 0
    {
     KOL_Dobawki = 8 - KOL_Dobawki; // ������ ���-�� ����������� ��������
     // ���������� ������� - ����� � ��������� - �� ����������
     char * Dobawka = 0;  // ���������� ��� �������

     Dobawka = new char[KOL_Dobawki];

     for (j = 0; j < KOL_Dobawki - 1; j++)
        Dobawka[j] = '.';           // ������ ������ � �������
                                           // ���-�� �� = KOL_Dobawki-1
     Dobawka[j] = (j + 49);  // ��������� ������ - ���� �����-��
     Dobawka[j+1] = 0;

     Dl_File = Dl_File + KOL_Dobawki; // �.�. ����� TextIshodnii ���������� -
                                      // ����������� � �������� �� ������

     TextIshodnii = StrCat(TextIshodnii, Dobawka); // ���������
                                                    // ������� ����� ��������� ������
    };
TextPosle = new char[Dl_File + 1];  // �������� ������ ��� ������������� ������


// � ������ - ���� ���������       -�������-�����-�����-����

RL L, R;           //  ��� ����� � ������ �����
for (i = 0; i < (Dl_File / 8); i++)  // ���� ����������� �� 8 �������� (64 ����)
   {
    L.R_char[0] = TextIshodnii[i*8];     // ������������ �����������
    L.R_char[1] = TextIshodnii[i*8 + 1]; // 4 �������� �� �extIshodnii
    L.R_char[2] = TextIshodnii[i*8 + 2]; // � L
    L.R_char[3] = TextIshodnii[i*8 + 3];

    R.R_char[0] = TextIshodnii[i*8 + 4]; // -//- � R
    R.R_char[1] = TextIshodnii[i*8 + 5];
    R.R_char[2] = TextIshodnii[i*8 + 6];
    R.R_char[3] = TextIshodnii[i*8 + 7];
RL R_tmp;
    for (j = 0; j < 32; j++)  // ������� �������� ���������� ����� � 64 ����
      {
       R_tmp = R;            // ��������� ����� L ��� �������� XOR;
       RL Key_4;                // ������ ����������� - ���� �� 4 ��������

       Key_4.R_char[0] = aKey[j*4];     // ������������ �����������
       Key_4.R_char[1] = aKey[j*4 + 1]; // 4 �������� �� ��������� �����
       Key_4.R_char[2] = aKey[j*4 + 2]; // � 4-� ���������� ����
       Key_4.R_char[3] = aKey[j*4 + 3];

       //  ������� ���� - ������������ �� mod 32
       R.R_int = R.R_int + Key_4.R_int; // ���������� �� mod 2**32
                      // ������������� �.�. ��� int � ���� ����� ��� 2**32


       // ������ � ������� �����
       unsigned char Bait, AH, AL;
       Bait = R.R_char[3];         // ������� ����� = 1 Byte
       AH   = Bait / 16;  // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;  // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[1][AH];
       AL = TabZamen[0][AL];

       R.R_char[3] = AH * 16 + AL;
         // 1 ���� ��������

       Bait = R.R_char[2];         // ������� ����� = 1 Byte
       AH   = Bait / 16;  // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;  // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[3][AH];
       AL = TabZamen[2][AL];

       R.R_char[2] = AH * 16 + AL;
         // 2 ���� ��������


       Bait = R.R_char[1];   // ������� ����� = 1 Byte
       AH   = Bait / 16;     // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;     // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[5][AH];
       AL = TabZamen[4][AL];

       R.R_char[1] = AH * 16 + AL;
         // 3 ���� ��������


       Bait = R.R_char[0];         // ������� ����� = 1 Byte
       AH   = Bait / 16;  // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;  // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[7][AH];
       AL = TabZamen[6][AL];

       R.R_char[0] = AH * 16 + AL;
       // 4 ���� ��������
       // ������ � ������� ����� ���������

       // ����� �� 11��� �����
       asm
        {
         rol R.R_int, 11;
        };

       // �������� "XOR"
       R.R_int = L.R_int ^ R.R_int;

       // ����� R � L �/� �����
       L     = R_tmp;
      }
    L = R;
    R = R_tmp;

    TextPosle[i*8]     = L.R_char[0]; // ������������ �����������
    TextPosle[i*8 + 1] = L.R_char[1]; // 4 �������� �� L � TextPosle
    TextPosle[i*8 + 2] = L.R_char[2];
    TextPosle[i*8 + 3] = L.R_char[3];

    TextPosle[i*8 + 4] = R.R_char[0]; // ������������ �����������
    TextPosle[i*8 + 5] = R.R_char[1]; // 4 �������� �� R � TextPosle
    TextPosle[i*8 + 6] = R.R_char[2];
    TextPosle[i*8 + 7] = R.R_char[3];

    TextPosle[i*8 + 8] = 0;
   }

if (OpenDialog1->FileName == "") SaveFile("c:\cod.txt",TextPosle , Dl_File);
// ���� ���� �� ������, �� ��������� � "c:\cod.txt"
else SaveFile((OpenDialog1->FileName + "���").c_str(), TextPosle , Dl_File);
// ����� ��������� � ���� � �������� ������, ������ � ���������� ��������� "���"

Posle_Memo->Text = TextPosle; // ����������� ������������� ������ � ����
OpenDialog1->FileName = "";      // ������ ��� ����� �� ��������� ������
delete(TextIshodnii);            // ������������ ������ ������ ���������
delete(TextPosle);            // ������������ ������ ������ �����������
TextIshodnii = 0;                // �������� ������ �� ����� ���������
TextPosle = 0;                // �������� ������ �� ����� �����������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Recod_BtnClick(TObject *Sender)
{
//   ���� ��� ��������� 32 ����������� ����� ������������
 AnsiString StrUserKey = "";  // ���������� ��� ����� ������������
                              // ��, ��� ������ user

 AnsiString StrKey32 = "";    // ���������� ��� ����� ����������� ���������
 StrUserKey = Key_Edit->Text; // ��������� ���� ������������ �� �����

 int KeyUserDlina;                // ������ ����� ������������ ��, ��� ���� user
 KeyUserDlina = StrUserKey.Length();  // ������ ������ ����� ������������

int Kol_wo_Copy = 0;
 if (KeyUserDlina < 32) Kol_wo_Copy = 32/KeyUserDlina; // ���������� ����� ����� ������������
 Kol_wo_Copy++;    // ����������� �� 1 ��� �������� (������ ���� ������ 256 ���)

 int i;
 for ( i = 0; i < Kol_wo_Copy; i++)    //  �������� ������ ����� Kol_wo_Copy ���
    StrKey32 = StrKey32 + StrUserKey;  // ����������� �� 32 � �����

char * tmp;         // ���������� - ��������� ������ ��������
tmp = new char[32]; // �������� ������
tmp = StrKey32.c_str(); // � �� ������� 32 ������� �����
tmp[32] = 0;     // �������  �� 32
char * aKey; // ���������� - ������ �������� ��� ����� 128 ����
 aKey = new char[128]; // �������� ������

 aKey = StrCopy(aKey, tmp); // �������� 32 ������� �� tmp � aKey - 1 ��� �1..�8
 aKey[32] = 0;              // �������
 aKey = StrCat(aKey, tmp);  // ������������ aKey � tmp ������� � aKey - 2 ��� �1..�8
 aKey = StrCat(aKey, tmp); // ������������ aKey � tmp ������� � aKey = 96 ��������
                           // - 3 ��� �1..�8
 aKey[96] = 0;

for (int i = 7; i >= 0; i--) // ���� ��� �������� 32 ���� �� 4 �������
{                            // �� tmp
/// �����������  tmp[4*i](+1;+2;+3) --- K8 - i=0,
//  96 ��� i = 0  (+1;+2;+3)            K7 - i=1, � �.�
//  100 ��� i = 1 � �.�         � ������� ������� �� tmp

 aKey[96 + (7-i)*4]     = tmp[4*i];
 aKey[96 + (7-i)*4 + 1] = tmp[4*i + 1];
 aKey[96 + (7-i)*4 + 2] = tmp[4*i + 2];
 aKey[96 + (7-i)*4 + 3] = tmp[4*i + 3];
} // ���� �����������



// ���������� ��������� ������ �� ��������� 64 ���� - 8 ��������

if (OpenDialog1->FileName == "")         // ���� ���� �� ������
  {                                      // ��
   Dl_File = DO_Memo->Text.Length();     // ������� � ���� ������ ������,
   TextIshodnii = new char[Dl_File + 8]; // �������� ������ � �������
   TextIshodnii = StrCopy(TextIshodnii,DO_Memo->Text.c_str()); // � � TextIshodnii ����� ����� �� ����
  }

int KOL_Dobawki = Dl_File % 8;   // ������ ������� �� ������� Dl_File �� 8



   // ��������� �� ��������� 64 ���� (��� ����� ����������� ��� ���)
if (KOL_Dobawki != 0)
   {
    ShowMessage("���� ����/����� �� ��� ����������, �.� ��� ����� �� ������ 8!!!!");
    delete(TextIshodnii);   // ������������ ������ ������ ���������
    return;
   }

int j;
if (KOL_Dobawki != 0) //  ���� ������� �� 0
    {
     KOL_Dobawki = 8 - KOL_Dobawki; // ������ ���-�� ����������� ��������
     // ���������� ������� - ����� � ��������� - �� ����������
     char * Dobawka = 0;  // ���������� ��� �������

     Dobawka = new char[KOL_Dobawki];

     for (j = 0; j < KOL_Dobawki - 1; j++)
        Dobawka[j] = '.';           // ������ ������ � �������
                                           // ���-�� �� = KOL_Dobawki-1
     Dobawka[j] = (j + 48);  // ��������� ������ - ���� �����-��
     Dobawka[j+1] = 0;

     Dl_File = Dl_File + KOL_Dobawki; // �.�. ����� TextIshodnii ���������� -
                                      // ����������� � �������� �� ������

     TextIshodnii = StrCat(TextIshodnii, Dobawka); // ���������
                                                    // ������� ����� ��������� ������
    };
TextPosle = new char[Dl_File + 1];

// � ������ - ���� ������������       -�������-�����-�����-����
RL L, R;           //  ��� ����� � ������ �����
for (i = 0; i < (Dl_File / 8); i++)  // ���� ����������� �� 8 �������� (64 ����)
   {
    L.R_char[0] = TextIshodnii[i*8];     // ������������ �����������
    L.R_char[1] = TextIshodnii[i*8 + 1]; // 4 �������� �� �extIshodnii
    L.R_char[2] = TextIshodnii[i*8 + 2]; // � L
    L.R_char[3] = TextIshodnii[i*8 + 3];

    R.R_char[0] = TextIshodnii[i*8 + 4]; // -//- � R
    R.R_char[1] = TextIshodnii[i*8 + 5];
    R.R_char[2] = TextIshodnii[i*8 + 6];
    R.R_char[3] = TextIshodnii[i*8 + 7];

RL R_tmp ;
    for (j = 0; j < 32; j++)  // ������� �������� ���������� ����� � 64 ����
      {
       R_tmp = R;            // ��������� ����� R ��� �������� XOR;
       RL Key_4;                // ������ ����������� - ���� �� 4 ��������

       Key_4.R_char[0] = aKey[(32-j-1)*4];     // ������������ �����������
       Key_4.R_char[1] = aKey[(32-j-1)*4 + 1]; // 4 �������� �� ��������� �����
       Key_4.R_char[2] = aKey[(32-j-1)*4 + 2]; // � 4-� ���������� ����
       Key_4.R_char[3] = aKey[(32-j-1)*4 + 3];

       //  ������� ���� - ������������ �� mod 32
       R.R_int = R.R_int + Key_4.R_int; // ���������� �� mod 2**32
                      // ������������� �.�. ��� int � ���� ����� ��� 2**32


       // ������ � ������� �����
       unsigned char Bait, AH, AL;
       Bait = R.R_char[3];         // ������� ����� = 1 Byte
       AH   = Bait / 16;  // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;  // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[1][AH];
       AL = TabZamen[0][AL];

       R.R_char[3] = AH * 16 + AL;
         // 1 ���� ��������

       Bait = R.R_char[2];         // ������� ����� = 1 Byte
       AH   = Bait / 16;  // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;  // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[3][AH];
       AL = TabZamen[2][AL];

       R.R_char[2] = AH * 16 + AL;
         // 2 ���� ��������


       Bait = R.R_char[1];   // ������� ����� = 1 Byte
       AH   = Bait / 16;     // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;     // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[5][AH];
       AL = TabZamen[4][AL];

       R.R_char[1] = AH * 16 + AL;
         // 3 ���� ��������


       Bait = R.R_char[0];         // ������� ����� = 1 Byte
       AH   = Bait / 16;  // �� - ������� ����� �� Bait = 4 ���� (�������� �������)
       AL   = Bait % 16;  // �L - ������� ����� �� Bait = 4 ���� (������� �� �������)

       AH = TabZamen[7][AH];
       AL = TabZamen[6][AL];

       R.R_char[0] = AH * 16 + AL;
       // 4 ���� ��������
       // ������ � ������� ����� ���������

       // ����� �� 11��� �����
       asm
        {
         rol R.R_int, 11;
        };

       // �������� "XOR"
       R.R_int = R.R_int ^ L.R_int;

       // ����� R � L �/� �����
       L     = R_tmp;
      }
    L = R;
    R = R_tmp;

    TextPosle[i*8]     = L.R_char[0]; // ������������ �����������
    TextPosle[i*8 + 1] = L.R_char[1]; // 4 �������� �� L � TextPosle
    TextPosle[i*8 + 2] = L.R_char[2];
    TextPosle[i*8 + 3] = L.R_char[3];

    TextPosle[i*8 + 4] = R.R_char[0]; // ������������ �����������
    TextPosle[i*8 + 5] = R.R_char[1]; // 4 �������� �� R � TextPosle
    TextPosle[i*8 + 6] = R.R_char[2];
    TextPosle[i*8 + 7] = R.R_char[3];

    TextPosle[i*8 + 8] = 0;
   }

if (OpenDialog1->FileName == "") SaveFile("c:\cod.txt",TextPosle , Dl_File);
// ���� ���� �� ������, �� ��������� � "c:\cod.txt"
else SaveFile((OpenDialog1->FileName + "���").c_str(), TextPosle , Dl_File);
// ����� ��������� � ���� � �������� ������, ������ � ���������� ��������� "���"

Posle_Memo->Text = TextPosle; // ����������� ������������� ������ � ����
OpenDialog1->FileName = "";      // ������ ��� ����� �� ��������� ������
delete(TextIshodnii);            // ������������ ������ ������ ���������
delete(TextPosle);            // ������������ ������ ������ �����������
TextIshodnii = 0;                // �������� ������ �� ����� ���������
TextPosle = 0;                // �������� ������ �� ����� �����������
      
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 DO_Memo->Text = "1234";
}
//---------------------------------------------------------------------------

