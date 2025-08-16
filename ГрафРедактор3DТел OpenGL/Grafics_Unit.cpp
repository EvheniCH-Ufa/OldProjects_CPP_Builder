//---------------------------------------------------------------------------
#pragma hdrstop
#include "Grafics_Unit.h"
#include "Math.h"
#include "Matrix_for_lab.h"
#include "Basic_Unit.h"

TColor ColorLine;
TColor ColorFill;
TTelo Tela[1000], Tela1[1000];
unsigned int TTeloCount = 0;
unsigned int TTeloCount1 = 0;
TRGB_Color ColorBody_RGB, ColorLigth_RGB;
int Count =0;

//---------------------------------------------------------------------------
void RotateTelo()
{
  TMatrix_4X4 RotX;
  TMatrix_4X4 RotY;
  TMatrix_4X4 RotZ;
  TMatrix_4X4 Rot;
  unsigned int i, j;

//  for (unsigned int i = 0; i < Telo.HeigtIsh; i++)
//    for (unsigned int j = 0; j < Telo.WidthIsh; j++)
//      Telo.PntsTek[i][j].Copy(Telo.PntsIsh[i][j]);

//  RotX = Rot.RotateX(Pi * Basic_Form->UpDn_Rot_X->Position/180);
//  RotY = Rot.RotateY(Pi * Basic_Form->UpDn_Rot_Y->Position/180);
//  RotZ = Rot.RotateZ(Pi * Basic_Form->UpDn_Rot_Z->Position/180);

  Rot = RotX.Mull(RotY);
  Rot = RotZ.Mull(Rot);

//  for (i = 0; i < Telo.HeigtIsh; i++)
//    for (j = 0;j < Telo.WidthIsh; j++)
//      Rot.Mull(Telo.PntsTek[i][j]);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
