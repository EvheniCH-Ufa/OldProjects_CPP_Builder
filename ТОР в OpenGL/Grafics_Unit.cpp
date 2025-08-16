//---------------------------------------------------------------------------
#pragma hdrstop
#include "Grafics_Unit.h"
#include "Math.h"
#include "Matrix_for_lab.h"
#include "Draw_Unit.h"
#include "Basic_Unit.h"

TColor ColorLine;
TColor ColorFill;
bool Zalivka;
TTelo Telo;
TRGB_Color ColorBody_RGB, ColorLigth_RGB;
int Count =0;

//---------------------------------------------------------------------------
void RaschetTela(int Figure, unsigned int Width, unsigned int Heigt,
                 unsigned int R, unsigned int A,
                 unsigned int a, unsigned int b, unsigned int c,
                 TTelo *Telo)
{
 unsigned int i,j;
 double X,Y,Z, u, tetta;

 Telo->WidthIsh = Width;
 Telo->HeigtIsh = Heigt;
                      
 switch (Figure)
 {   case 0:     // TOROID
     {
      for (i = 0; i < Telo->HeigtIsh; i++)
        {
         tetta = i * (2 * Pi/Telo->HeigtIsh);

         for (j = 0; j < Telo->WidthIsh; j++)
           {
            u = j * 2 * Pi/Telo->WidthIsh;

            Telo->PntsIsh[i][j].X = (R + A * cos(u))*cos(tetta);
            Telo->PntsIsh[i][j].Y = -(R + A * cos(u))*sin(tetta);
            Telo->PntsIsh[i][j].Z = (A * sin(u));
           };
        }
     };
     break;
   case 1:   // ELIPSOID
     {
      for (i = 0; i < Telo->HeigtIsh; i++)
        {
         tetta = i * (2 * Pi/Telo->HeigtIsh);
         for (j = 0;j < Telo->WidthIsh; j++)
           {
            u = j*2 * Pi/Telo->WidthIsh;

            Telo->PntsIsh[i][j].X = a * cos(u)*cos(tetta);
            Telo->PntsIsh[i][j].Y = b * sin(u)*cos(tetta);
            Telo->PntsIsh[i][j].Z = c * sin(tetta);
           };
        }
     };
     break;
  }

Telo->LenPrim = Telo->HeigtIsh * 2 * Telo->WidthIsh;
unsigned int jj, ii;
unsigned int Numb = 0;

TVector3D WnTochka;
// Разбивка подтел
for (i = 0; i < Telo->HeigtIsh; i++)
  {
   WnTochka.X = 0;
   WnTochka.Y = 0;
   WnTochka.Z = 0;

   for (j = 0; j < Telo->WidthIsh; j++)
     {
      ii = i + 1;
      if (ii == Telo->HeigtIsh) ii = 0;
        WnTochka.X += Telo->PntsIsh[i][j].X + Telo->PntsIsh[ii][j].X;
        WnTochka.Y += Telo->PntsIsh[i][j].Y + Telo->PntsIsh[ii][j].Y;
        WnTochka.Z += Telo->PntsIsh[i][j].Z + Telo->PntsIsh[ii][j].Z;
     }
   Telo->WNTochki[i] = WnTochka.Del(Telo->WidthIsh * 2);
   Telo->WNTochki[i].P =1;// Telo.WNTochki[i].Length();
  }

// Разбивка треугольников...................................................
for (i = 0; i < Telo->HeigtIsh; i++)
  for (j = 0; j < Telo->WidthIsh; j++)
  {
   ii = i + 1;
   if (ii == Telo->HeigtIsh) ii = 0;

   jj = j + 1;
   if (jj == Telo->WidthIsh) jj = 0;

  // Задаем "ссылки на точки"
   Telo->Prim[Numb].T1.W = i;
   Telo->Prim[Numb].T1.H = j;
   Telo->Prim[Numb].T2.W = i;
   Telo->Prim[Numb].T2.H = jj;
   Telo->Prim[Numb].T3.W = ii;
   Telo->Prim[Numb].T3.H = j;

   /*  расчет плоскостей и нормалей*/
   RaschetPloskosti(Telo->Prim[Numb], Telo->WNTochki[i]);
   Telo->Prim[Numb].Normal.OneV();
  /*+++++++++++++*/
 /**/ Numb++; /**/
/*+++++++++++++*/
// Задаем "ссылки на точки"
   Telo->Prim[Numb].T1.W = ii;
   Telo->Prim[Numb].T1.H = jj;
   Telo->Prim[Numb].T2.W = ii;
   Telo->Prim[Numb].T2.H = j;
   Telo->Prim[Numb].T3.W = i;
   Telo->Prim[Numb].T3.H = jj;

   /*  расчет плоскостей и нормалей*/
   RaschetPloskosti(Telo->Prim[Numb], Telo->WNTochki[i]);
   Telo->Prim[Numb].Normal.OneV();
  /*+++++++++++++*/
 /**/ Numb++; /**/
/*+++++++++++++*/
  };
   RotateTelo();
Draw_Frm->FormPaint(Draw_Frm);
};
//---------------------------------------------------------------------------
boolean RaschetPloskosti(TTreugolnik &Tr, TVector3D &WnT)
{
  /*========================================================================*\
 /                        Ax + By + Cz + D = 0                                \
<        Коэффиценты A, B и C равны параметрам x, y и z вектора нормали.       >
 \  Коэффицент D численно равен расстоянию от плоскости до начала координат.  /
  \*========================================================================*/
//                  Telo.PsTek[Tr.T1.W][Tr.T1.H].Y
 Tr.Normal.X = (Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Y - Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Y)*
               (Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Z + Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Z) +
               (Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Y - Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Y)*
               (Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Z + Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Z) +
               (Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Y - Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Y)*
               (Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Z + Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Z);

 Tr.Normal.Y = (Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Z - Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Z)*
               (Telo.PntsIsh[Tr.T1.W][Tr.T1.H].X + Telo.PntsIsh[Tr.T2.W][Tr.T2.H].X) +
               (Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Z - Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Z)*
               (Telo.PntsIsh[Tr.T2.W][Tr.T2.H].X + Telo.PntsIsh[Tr.T3.W][Tr.T3.H].X) +
               (Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Z - Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Z)*
               (Telo.PntsIsh[Tr.T3.W][Tr.T3.H].X + Telo.PntsIsh[Tr.T1.W][Tr.T1.H].X);

 Tr.Normal.Z = (Telo.PntsIsh[Tr.T1.W][Tr.T1.H].X - Telo.PntsIsh[Tr.T2.W][Tr.T2.H].X)*
               (Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Y + Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Y) +
               (Telo.PntsIsh[Tr.T2.W][Tr.T2.H].X - Telo.PntsIsh[Tr.T3.W][Tr.T3.H].X)*
               (Telo.PntsIsh[Tr.T2.W][Tr.T2.H].Y + Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Y) +
               (Telo.PntsIsh[Tr.T3.W][Tr.T3.H].X - Telo.PntsIsh[Tr.T1.W][Tr.T1.H].X)*
               (Telo.PntsIsh[Tr.T3.W][Tr.T3.H].Y + Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Y);

 Tr.Normal.P = -(Tr.Normal.X * Telo.PntsIsh[Tr.T1.W][Tr.T1.H].X +
                 Tr.Normal.Y * Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Y +
                 Tr.Normal.Z * Telo.PntsIsh[Tr.T1.W][Tr.T1.H].Z);

double c = Tr.Normal.MullSc(WnT);

if (c < 0) Tr.Normal = Tr.Normal.Minus();

if (Tr.Normal.Z < 0)
    return 0  ;
else
 return 1;
}
//---------------------------------------------------------------------------
void RotateTelo()
{
  TMatrix_4X4 RotX;
  TMatrix_4X4 RotY;
  TMatrix_4X4 RotZ;
  TMatrix_4X4 Rot;
  unsigned int i, j;

  for (unsigned int i = 0; i < Telo.HeigtIsh; i++)
    for (unsigned int j = 0; j < Telo.WidthIsh; j++)
      Telo.PntsTek[i][j].Copy(Telo.PntsIsh[i][j]);

  RotX = Rot.RotateX(Pi * Basic_Form->UpDn_Rot_X->Position/180);
  RotY = Rot.RotateY(Pi * Basic_Form->UpDn_Rot_Y->Position/180);
  RotZ = Rot.RotateZ(Pi * Basic_Form->UpDn_Rot_Z->Position/180);

  Rot = RotX.Mull(RotY);
  Rot = RotZ.Mull(Rot);

  for (i = 0; i < Telo.HeigtIsh; i++)
    for (j = 0;j < Telo.WidthIsh; j++)
      Rot.Mull(Telo.PntsTek[i][j]);
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
