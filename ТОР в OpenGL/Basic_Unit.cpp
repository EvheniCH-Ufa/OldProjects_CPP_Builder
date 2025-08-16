//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Basic_Unit.h"
#include "math.h"
#include "Matrix_for_lab.h"
#include "Grafics_Unit.h"
#include <mem.h>
#include "Draw_Unit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBasic_Form *Basic_Form;

bool  Textur = 0;
//---------------------------------------------------------------------------
__fastcall TBasic_Form::TBasic_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::FormCreate(TObject *Sender)
{
Telo.WidthIsh = 0;
Telo.HeigtIsh = 0;
ClientHeight = 500;
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::CmbBx_FiguraChange(TObject *Sender)
{
 if (CmbBx_Figura->ItemIndex)
    {
     Pnl_ToroidParam->Visible = 0;
     Pnl_ElipsParam->Visible  = 1;
    }
 else
   {
     Pnl_ToroidParam->Visible = 1;
     Pnl_ElipsParam->Visible  = 0;
   }
   Raschet();
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::Raschet()
{
  RaschetTela(CmbBx_Figura->ItemIndex,
              UpDn_Segment_U->Position,
              UpDn_Segment_V->Position,
              UpDn_Tor_R->Position, UpDn_Tor_a->Position,
              UpDn_Elips_a->Position, UpDn_Elips_b->Position,
              UpDn_Elips_c->Position, &Telo);
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::FormShow(TObject *Sender)
{
Draw_Frm->Show();
ColorLigth_RGB.RGB.R = UpDn_ClrLight_R->Position;
ColorLigth_RGB.RGB.G = UpDn_ClrLight_G->Position;
ColorLigth_RGB.RGB.B = UpDn_ClrLight_B->Position;

ColorBody_RGB.RGB.R = UpDn_ClrBody_R->Position;
ColorBody_RGB.RGB.G = UpDn_ClrBody_G->Position;
ColorBody_RGB.RGB.B = UpDn_ClrBody_B->Position;
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::UpDn_ClrLight_RClick(TObject *Sender,
      TUDBtnType Button)
{
   ColorLigth_RGB.RGB.A = 0;
   ColorLigth_RGB.RGB.R = UpDn_ClrLight_R->Position;
   ColorLigth_RGB.RGB.G = UpDn_ClrLight_G->Position;
   ColorLigth_RGB.RGB.B = UpDn_ClrLight_B->Position;
   Pnl_ColorLigth_View->Color = ColorLigth_RGB.Color;

   Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::UpDn_ClrBody_RClick(TObject *Sender,
      TUDBtnType Button)
{
   ColorBody_RGB.RGB.A = 0;
   ColorBody_RGB.RGB.R = UpDn_ClrBody_R->Position;
   ColorBody_RGB.RGB.G = UpDn_ClrBody_G->Position;
   ColorBody_RGB.RGB.B = UpDn_ClrBody_B->Position;
   Pnl_ColorBody_View->Color = ColorBody_RGB.Color;

   Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
 // эффект прилипания
 Draw_Frm->Top = Top;
 Draw_Frm->Left = Left - Draw_Frm->Width;
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::Button1Click(TObject *Sender)
{
 if (OpenPictureDialog1->Execute())
   Draw_Frm->LoadTextur(OpenPictureDialog1->FileName);


// Draw_Frm->Timer1->Enabled = !Draw_Frm->Timer1->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::UpDn_Tor_RClick(TObject *Sender,
      TUDBtnType Button)
{
 Raschet();
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::UpDn_Rot_XClick(TObject *Sender,
      TUDBtnType Button)
{
 RotateTelo();
 Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::UpDn_Light_XClick(TObject *Sender,
      TUDBtnType Button)
{
 Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::Panel1Click(TObject *Sender)
{
 if (OpenPictureDialog1->Execute())
   Draw_Frm->LoadTextur(OpenPictureDialog1->FileName);

}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::RadioGroup1Click(TObject *Sender)
{
 Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::ChBx_TextureClick(TObject *Sender)
{
 Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::UpDn_ProzClick(TObject *Sender,
      TUDBtnType Button)
{
 Draw_Frm->FormPaint(Draw_Frm);
}
//---------------------------------------------------------------------------

