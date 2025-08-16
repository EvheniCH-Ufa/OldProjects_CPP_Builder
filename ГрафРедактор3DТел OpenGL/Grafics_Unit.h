//---------------------------------------------------------------------------
#ifndef Grafics_UnitH
#define Grafics_UnitH
#include "Matrix_for_lab.h"
#include "Grafics_Unit.h"
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
const double Pi = 3.1415926535897932384626433832795;
//const unsigned char MaxWidth = 200;
//const unsigned char MaxHeigt = 200;
//const unsigned int  MaxLength = MaxWidth * MaxHeigt * 2;
//---------------------------------------------------------------------------
/*extern TColor ColorFill;
extern bool Zalivka;*/
//---------------------------------------------------------------------------
/*struct TPloskost
{
 double A;
 double B;
 double C;
 double D;
};*/
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
//struct TRowsCol      //Взамен TPoint
//{
// unsigned int W,H;  // аналогия I,J или X,Y
//};
//---------------------------------------------------------------------------
/*struct TTreugolnik
{
 TRowsCol  T1,T2,T3; // адреса точек, принадлеж треуг-ку в массиве тек точек
 TVector3D Normal;
};*/
//---------------------------------------------------------------------------
struct TTelo
{
 int TypeTelo; // 0 - блок, 1 - цилиндр, 2 - конус, 3 - сфера
 int idTelo;
 TVector3D StartPoints;
 float Rasmer1, Rasmer2, Rasmer3;
 float AngleX, AngleY, AngleZ;
 TRGB_Color Color;
 unsigned char Prozrach; // 0 - 100
// bool Visible;
};
//---------------------------------------------------------------------------
extern TTelo Tela[1000];
//---------------------------------------------------------------------------
extern TTelo Tela1[1000];
//---------------------------------------------------------------------------
extern unsigned int TTeloCount, TTeloCount1;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
/*void RaschetTela(int Figure, unsigned int Width, unsigned int Heigt,
                 unsigned int R, unsigned int A,
                 unsigned int a, unsigned int b, unsigned int c,
                 TTelo *Telo);*/
//---------------------------------------------------------------------------
//inline boolean RaschetPloskosti(TTreugolnik &Tr, TVector3D &WnT);
//---------------------------------------------------------------------------
void RotateTelo();
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
