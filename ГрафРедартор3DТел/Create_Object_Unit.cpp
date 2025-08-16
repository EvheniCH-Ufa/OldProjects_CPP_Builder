//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Create_Object_Unit.h"
#include "Points_Unit.h"
#include "Basic_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFrm_Create_Object *Frm_Create_Object;
TRGB_Color CLR;
//---------------------------------------------------------------------------
__fastcall TFrm_Create_Object::TFrm_Create_Object(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrm_Create_Object::Ed_Rasmer1KeyPress(TObject *Sender,
      char &Key)
{
 if ((Key != '0') && (Key != '1') && (Key != '2') && (Key != '3') &&
     (Key != '4') && (Key != '5') && (Key != '6') && (Key != '7') &&
     (Key != '8') && (Key != '9') && (Key != '.') && (Key != ','))
   {
       Abort();
   }
}
//---------------------------------------------------------------------------
void __fastcall TFrm_Create_Object::Btn_CrObj_NoClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TFrm_Create_Object::ChkBxClick(TObject *Sender)
{
 switch (Status)
 {
   case 0:
     {
      if (ChkBx->Checked)
        {
         Label2->Enabled = 0;
         Label3->Enabled = 0;
         Ed_Rasmer2->Enabled = 0;
         Ed_Rasmer3->Enabled = 0;
        }
      else
        {
         Label2->Enabled = 1;
         Label3->Enabled = 1;
         Ed_Rasmer2->Enabled = 1;
         Ed_Rasmer3->Enabled = 1;
        }
     };
   break;
   case 2:
     {
      if (ChkBx->Checked)
        {
         Label2->Enabled = 1;
         Label3->Enabled = 1;
         Ed_Rasmer2->Enabled = 1;
         Ed_Rasmer3->Enabled = 1;
        }
      else
        {
         Label2->Enabled = 1;
         Label3->Enabled = 1;
         Label3->Enabled = 0;
         Ed_Rasmer3->Enabled = 0;
        }
     };
   break;
 }

}
//---------------------------------------------------------------------------
void __fastcall TFrm_Create_Object::Btn_Start_PointsClick(TObject *Sender)
{
 Frm_Points->ShowModal();
}
//---------------------------------------------------------------------------
/*
Status     0 - блок, |  1 - Цилиндр, | 2 - конус,               | 3 - сфера,
Размер1     Длинна   |   Высота      |  Высота                  |  Диаметр
Размер1     Ширина   |   Диаметр     |  Диаметр (ниж для усеч)  |    ---
Размер1     Высота   |     ---       |  --- (Диам верх для усеч)|    ---
*/


void __fastcall TFrm_Create_Object::Panel1Click(TObject *Sender)
{
 if (ColorDialog1->Execute())
   {
//    Panel1->Color = ColorDialog1->Color;
    CLR.Color = ColorDialog1->Color;
    TrBr_R->Position = CLR.RGB.R;
    TrBr_G->Position = CLR.RGB.G;
    TrBr_B->Position = CLR.RGB.B;
    TrBr_RChange(Sender);
   }
}
//---------------------------------------------------------------------------

void __fastcall TFrm_Create_Object::TrBr_RChange(TObject *Sender)
{
 CLR.RGB.R = TrBr_R->Position;
 CLR.RGB.G = TrBr_G->Position;
 CLR.RGB.B = TrBr_B->Position;
 Lbl_VR->Caption = TrBr_R->Position;
 Lbl_VG->Caption = TrBr_G->Position;
 Lbl_VB->Caption = TrBr_B->Position;
 Lbl_VPR->Caption = TrBr_Proz->Position;
 Lbl_VR->Left = TrBr_R->Left + 10 + TrBr_R->Position * 180/255 - Lbl_VR->Width/2;
 Lbl_VG->Left = TrBr_G->Left + 10 + TrBr_G->Position * 180/255 - Lbl_VG->Width/2;
 Lbl_VB->Left = TrBr_B->Left + 10 + TrBr_B->Position * 180/255 - Lbl_VB->Width/2;
 Lbl_VPR->Left = TrBr_Proz->Left + 10 + TrBr_Proz->Position * 180/100 - Lbl_VPR->Width/2;
 Panel1->Color = CLR.Color;
}
//---------------------------------------------------------------------------

void __fastcall TFrm_Create_Object::FormCreate(TObject *Sender)
{
 TrBr_R->Position = 0;
 TrBr_G->Position = 255;
 TrBr_B->Position = 0;
 TrBr_Proz->Position = 100;
 TrBr_RChange(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TFrm_Create_Object::N1Click(TObject *Sender)
{
 int i;
 TTeloCount1 = 0;
 for (i = 0; i < TTeloCount; i++)
 {
  if (i != CmBx_Tela->ItemIndex)
   {
    Tela1[TTeloCount1] = Tela[i];
    TTeloCount1++;
   }
 }

CmBx_Tela->Items->Clear();

 TTeloCount = TTeloCount1;
 for (i = 0; i < TTeloCount1; i++)
 {
  Tela[i] = Tela1[i];
 }
String Str;
 for (int i = 0; i < TTeloCount; i++)
 {
    switch (Tela[i].TypeTelo)
    {
     case 0: Str  = "Блок";
     break;
     case 1: Str  = "Цилиндр";
     break;
     case 2: Str  = "Конус";
     break;
     case 3: Str  = "Сфера";
     break;
    }
    Str += Tela[i].idTelo;
    CmBx_Tela->Items->Add(Str);
 }
 CmBx_Tela->ItemIndex = -1;
 Basic_Form->FormPaint(Basic_Form);


}
//---------------------------------------------------------------------------
void __fastcall TFrm_Create_Object::UpDn_Rot_XClick(TObject *Sender,
      TUDBtnType Button)
{
 Basic_Form->CreateObject(Status, CmBx_Tela->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFrm_Create_Object::CmBx_TelaChange(TObject *Sender)
{
 int i  = CmBx_Tela->ItemIndex;

 TrBr_R->Position = Tela[i].Color.RGB.R;
 TrBr_G->Position = Tela[i].Color.RGB.G;
 TrBr_B->Position = Tela[i].Color.RGB.B;
 TrBr_Proz->Position = Tela[i].Prozrach;
 Ed_Rasmer1->Text = Tela[i].Rasmer1;
 Ed_Rasmer2->Text = Tela[i].Rasmer2;
 Ed_Rasmer3->Text = Tela[i].Rasmer3;
// UpDown1->Position = Tela[i].Rasmer1;
// UpDown2->Position = Tela[i].Rasmer2;
// UpDown3->Position = Tela[i].Rasmer3;
 Ed_Rot_X->Text = Tela[i].AngleX;
 Ed_Rot_Y->Text = Tela[i].AngleY;
 Ed_Rot_Z->Text = Tela[i].AngleZ;
 Frm_Points->Ed_PointsX->Text = -Tela[i].StartPoints.X;
 Frm_Points->Ed_PointsY->Text =  Tela[i].StartPoints.Y;
 Frm_Points->Ed_PointsZ->Text = -Tela[i].StartPoints.Z;
 Basic_Form->UstanowkaCreateObject(Tela[i].TypeTelo);
 Status = Tela[i].TypeTelo;
 TrBr_RChange(Sender);
 Basic_Form->FormPaint(Basic_Form);
 String Str = "Редактирование ";
 Str += CmBx_Tela->Items->Strings[CmBx_Tela->ItemIndex];
 Caption = Str;
}
//---------------------------------------------------------------------------

