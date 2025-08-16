//---------------------------------------------------------------------------
#ifndef Grafics_UnitH
#define Grafics_UnitH
#include "Matrix_for_lab.h"
#include "Grafics_Unit.h"
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
const double Pi = 3.1415926535897932384626433832795;
const double Expon = 1;
const unsigned char MaxWidth = 200;
const unsigned char MaxHeigt = 200;
const unsigned int  MaxLength = MaxWidth * MaxHeigt * 2;
//---------------------------------------------------------------------------
extern TColor ColorFill;
extern bool Zalivka;
//---------------------------------------------------------------------------
struct TPloskost
{
 double A;
 double B;
 double C;
 double D;
};
//---------------------------------------------------------------------------
//struct TPoint3D
//{
// double X,Y,Z;
//};
//---------------------------------------------------------------------------
struct TRGB
{
 unsigned char R,G,B,A;
};
//---------------------------------------------------------------------------
 union TRGB_Color
{
 TRGB RGB;
 TColor Color;
};
//---------------------------------------------------------------------------
extern TRGB_Color ColorBody_RGB, ColorLigth_RGB;
//---------------------------------------------------------------------------
struct TRowsCol      //������ TPoint
{
 unsigned int W,H;  // �������� I,J ��� X,Y
};
//---------------------------------------------------------------------------
struct TTreugolnik
{
 TRowsCol  T1,T2,T3; // ������ �����, ��������� �����-�� � ������� ��� �����
 TVector3D Normal;

};
//---------------------------------------------------------------------------
struct TTelo
{
 TVector3D PntsIsh[MaxHeigt][MaxWidth];
 TVector3D PntsTek[MaxHeigt][MaxWidth];
 unsigned int HeigtIsh;
 unsigned int WidthIsh;

 TVector3D WNTochki[MaxHeigt];

 TTreugolnik Prim[MaxLength];
 unsigned int LenPrim;
};
//---------------------------------------------------------------------------
extern TTelo Telo;
//---------------------------------------------------------------------------
void RaschetTela(int Figure, unsigned int Width, unsigned int Heigt,
                 unsigned int R, unsigned int A,
                 unsigned int a, unsigned int b, unsigned int c,
                 TTelo *Telo);
//---------------------------------------------------------------------------
inline boolean RaschetPloskosti(TTreugolnik &Tr, TVector3D &WnT);
//---------------------------------------------------------------------------
void RotateTelo();
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
