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
      TextIshodnii = LoadFromFile(OpenDialog1->FileName.c_str(), &Dl_File); // �������� ������� LoadFromFile (���)
     // � ��� ����� ������� ���������� �����
      DO_Memo->Text = TextIshodnii;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cod_BtnClick(TObject *Sender)
{
//   ���� ��� ��������� 256 ����������� ����� ������������  "�" - � ���������
 AnsiString StrUserKey = ""; // ���������� ��� ����� ������������
                        // ��, ��� ������ user

 AnsiString StrCodeKey = ""; // ���������� ��� ����� ����������� ���������
 StrUserKey = Key_Edit->Text;// ��������� ���� ������������ �� �����

 int KeyUserDlina; // ������ ����� ������������ ��, ��� ���� user
 KeyUserDlina = StrUserKey.Length();  // ������ ������ ����� ������������

 int Kol_wo_Copy = 256/KeyUserDlina; // ���������� ����� ����� ������������
 Kol_wo_Copy++;    // ����������� �� 1 ��� �������� (������ ���� ������ 256 ���)
 int i;
 for ( i = 0; i < Kol_wo_Copy; i++)    //  �������� ������ ����� Kol_wo_Copy ���
    StrCodeKey = StrCodeKey + StrUserKey;  // ����������� �� 256 � �����

char *Code_Key;                // ������� ���� � ���������    �
Code_Key = StrCodeKey.c_str(); // ������� ���� � ������ ��������
Code_Key[256] = 0;             // ������� �� 256 ��������
//   ���� ��� ��������� 256 ����������� ����� ������������ +++ ����� �����

//---------------------------------------------------------------------------
if (TextIshodnii == 0)  // ��������� - ���� �� ����� � ��� ������
    {
     TextIshodnii = DO_Memo->Text.c_str();   // ���� ���, �� ��������� ��� �� ����
     Dl_File = DO_Memo->Text.Length();         // ������ ������
    }
//---------------------------------------------------------------------------

//   ���� ��� ��������� 256 ����������� S - �����,"S" - � ��������� �������

unsigned char SBlok[256]; // ���������� - ������ ����� (���� - �� 0 �� 255 - ��������)
                       // ������� � 256 �����
for (i = 0;i < 256; i++)
   SBlok[i] = i;          // ��������� ������� S - ���� ���������� i � i ������

// ���� ��� ��������� 256 ����������� S - �����,"S" - � ��������� ������� �����

//---------------------------------------------------------------------------
int I, tmp, J = 0;
unsigned char t, K=0;

for (I = 0; I < 256; I++)
    {
     J = (J + SBlok[I] + Code_Key[I]) % 256; // ������������� J ��� ������
    //    ������ ������� SBlok[I] � SBlok[J]
     tmp = SBlok[J];      // ��������� SBlok[J] � tmp  ---|
     SBlok[J] = SBlok[I]; // ������� � SBlok[J] SBlok[I]  |
     SBlok[I] = tmp;      // ������� � SBlok[I]  tmp    <-|
    }

I = 0;
J = 0;
for (i = 0; i < Dl_File; i++) // ���� �� 0 �� ���-�� ��������� ��������
    {
     I++;                 // ����������� I �� 1
     I = I % 256;         // ������� �� ������� �� 256
     J = (J + SBlok[I]) % 256; // ������������� J ��� ������
     t = SBlok[I] + SBlok[J];  // �� �������
     K = SBlok[t];             // �� �������

     //�������� ��������������� ����, ��� ��� �

     TextIshodnii[I-1] = TextIshodnii[I-1] ^ K; // �������� XOR I - �� �������
    // ������ � I mod 256 (������� �� �������) �������� �����
    }

if (OpenDialog1->FileName == "") SaveFile("c:\cod.txt",TextIshodnii , Dl_File);
// ���� ���� �� ������, �� ��������� � "c:\cod.txt"
else SaveFile((OpenDialog1->FileName + "���").c_str(),TextIshodnii , Dl_File);
// ����� ��������� � ���� � �������� ������, ������ � ���������� ��������� "���"
Posle_Memo->Text = TextIshodnii; // ����������� ������������� ������ � ����
OpenDialog1->FileName = "";      // ������ ��� ����� �� ��������� ������
delete(TextIshodnii);            // ������������ ������ ������
TextIshodnii = 0;                // �������� ������ �� �����
}
//---------------------------------------------------------------------------


