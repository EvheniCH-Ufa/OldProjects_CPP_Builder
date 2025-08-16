//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Points_Unit.h"
#include "Create_Object_Unit.h"
#include "Basic_Unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrm_Points *Frm_Points;
//---------------------------------------------------------------------------
__fastcall TFrm_Points::TFrm_Points(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrm_Points::Ed_PointsXKeyPress(TObject *Sender, char &Key)
{
 if ((Key != '0') && (Key != '1') && (Key != '2') && (Key != '3') &&
     (Key != '4') && (Key != '5') && (Key != '6') && (Key != '7') &&
     (Key != '8') && (Key != '9') && (Key != '.') && (Key != ',') && (Key != '-'))
   {
       Abort();
   }
}
//---------------------------------------------------------------------------

void __fastcall TFrm_Points::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
{
 Basic_Form->CreateObject(Frm_Create_Object->Status, Frm_Create_Object->CmBx_Tela->ItemIndex);
}
//---------------------------------------------------------------------------

