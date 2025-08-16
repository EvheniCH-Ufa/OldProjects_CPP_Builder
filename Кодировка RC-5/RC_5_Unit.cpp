//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RC_5_Unit.h"
#include "Param_Unit.h"
#include "Function_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

      char*             TextIshodnii;
      DWORD             DlinaTexta;
      char*             Key;
      unsigned int*     L;
      unsigned int*     S;
      unsigned int      C;
      unsigned int      R;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenMMClick(TObject *Sender)
{
unsigned long LegnthFileReal;

 if (OpenDialog1->Execute())
     {
     if (TextIshodnii)
        {
         delete(TextIshodnii);
         (TextIshodnii)=0;
        };
       TextIshodnii = LoadFromFile(OpenDialog1->FileName.c_str(), &DlinaTexta);

       if ((DlinaTexta % 8) != 0)
          {
           unsigned int i = 0;
           for (i = 0; i <(8 - (DlinaTexta % 8));i++)
                TextIshodnii[++DlinaTexta]=0;
           DlinaTexta++;
          }

       Memo1->Text = TextIshodnii;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ParamsMMClick(TObject *Sender)
{
Param_Frm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
TextIshodnii = 0;
OpenDialog1->InitialDir = ExtractFileDir(Application->ExeName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AboutMMClick(TObject *Sender)
{
ShellAbout(Handle, "Кодировка алгоритмом RC-5", "Должна работать", 0);
}

//--------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
if (TextIshodnii)
    delete(TextIshodnii);

if  (Key)
    delete(Key);

if  (L)
    delete(L);

if  (S)
    delete(S);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CodingMMClick(TObject *Sender)
{
if (S == NULL)
   {
    ShowMessage("Error");
    Abort();
   }

if (!(TextIshodnii))
   {
    ShowMessage("Ошибка! Отсутствует текст");
    Abort();
   }

unsigned int I = 0;
unsigned int j = 0;
unsigned int tmp = 0;
unsigned char sdwig = 0;


AB* CodeText;
CodeText = (AB*)TextIshodnii;

ProgressBar1->Max = (DlinaTexta-1)/8 + 1;
ProgressBar1->Position = 0;

int Sto = 1;
if (ProgressBar1->Max > 100)Sto = 100;

  for (j = 0; j <= ((DlinaTexta-1) / 8); j ++)
      {
       CodeText[j].A += S[0];
       CodeText[j].B += S[1];

       for (I = 1; I <= R; I++)
           {
            CodeText[j].A = (CodeText[j].A ^ CodeText[j].B);
            sdwig = CodeText[j].B % 32;
            tmp = CodeText[j].A;
            asm
               {
                mov cl,sdwig;
                rol tmp, cl;
               };
            CodeText[j].A = tmp + S[2 * I];
/******************************************************************/
            CodeText[j].B = (CodeText[j].A ^ CodeText[j].B);
            sdwig = CodeText[j].A % 32;
            tmp = CodeText[j].B;
            asm
               {
                mov cl,sdwig;
                rol tmp, cl;
               };
            CodeText[j].B = tmp + S[2*I+1];
           }
           if (!(j%(ProgressBar1->Max /Sto)))
              ProgressBar1->Position = j;
      }
TextIshodnii[j*8]=0;
SaveFile((OpenDialog1->FileName + "cod").c_str(), TextIshodnii, DlinaTexta);
Memo2->Text = TextIshodnii;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RecodingMMClick(TObject *Sender)
{
if (S == NULL)
   {
    ShowMessage("Error");
    Abort();
   }

if (!(TextIshodnii))
   {
    ShowMessage("Ошибка! Отсутствует текст");
    Abort();
   }

unsigned int I = 0;
unsigned int j = 0;
unsigned int tmp = 0;
unsigned char sdwig = 0;

ProgressBar1->Max = (DlinaTexta-1)/8 + 1;
ProgressBar1->Position = 0;

int Sto = 1;
if (ProgressBar1->Max > 100)Sto = 100;

AB* CodeText;
CodeText = (AB*)TextIshodnii;

  for (j = 0; j <= ((DlinaTexta-1) / 8); j ++)
      {
       for (I = R; I > 0; I--)
           {
/******************************************************************/
            CodeText[j].B -= S[2*I+1];

            sdwig = CodeText[j].A % 32;
            tmp = CodeText[j].B;
            asm
               {
                mov cl,sdwig;
                ror tmp, cl;
               };
            CodeText[j].B = tmp ^ CodeText[j].A;
/******************************************************************/
            CodeText[j].A -= S[2 * I];
            sdwig = CodeText[j].B % 32;
            tmp = CodeText[j].A;
            asm
               {
                mov cl,sdwig;
                ror tmp, cl;
               };
            CodeText[j].A = tmp ^ CodeText[j].B;
           }
       CodeText[j].A -= S[0];
       CodeText[j].B -= S[1];
      if (!(j%(ProgressBar1->Max /Sto)))
          ProgressBar1->Position = j;
      }
TextIshodnii[j*8]=0;
Memo2->Text = TextIshodnii;
SaveFile(OpenDialog1->FileName.c_str(), TextIshodnii, DlinaTexta);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitMMClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
Memo4->Text = Param_Frm->EdKey->Text;
}
//---------------------------------------------------------------------------

