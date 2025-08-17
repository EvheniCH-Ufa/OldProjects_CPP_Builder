//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Basic_Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int Pole[3][3];
Sost *Tree = 0;
Sost *TekSost = 0;
Sost *PredSost = 0;
//int RRR = 1;
int MassPrower[8][3] = {0,1,2,
                        3,4,5,
                        6,7,8,
                        0,3,6,
                        1,4,7,
                        2,5,8,
                        0,4,8,
                        2,4,6};
int MassHodow[9] = {4,0,8,2,6,1,3,5,7};
//int MassHodow[9] = {0,8,2,6,1,3,5,7,4};
int Strateg0[9]  = {4,0,8,2,6,1,3,5,7};
int Strateg1[9]  = {4,1,0,2,6,8,3,5,7};
int HODIgrtoka;
int PlayGame = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit_BtnClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NewGame_BtnClick(TObject *Sender)
{
 for (int i = 0; i < 9; i++)
  MassHodow[i] = Strateg0[i];

 Komp1_Btn->Enabled = 1;
 DrawSetka();
 TekSost = Tree;
 PlayGame = 1;
 HODIgrtoka = 1;
 Label1->Caption = "";
}
//---------------------------------------------------------------------------
void TForm1::DrawSetka()
{
 Image1->Canvas->Rectangle(0,0, 149,149);

 Image1->Canvas->MoveTo(0,   49);
 Image1->Canvas->LineTo(149, 49);
 Image1->Canvas->MoveTo(149, 99);
 Image1->Canvas->LineTo(0, 99);

 Image1->Canvas->MoveTo(49, 0);
 Image1->Canvas->LineTo(49, 149);
 Image1->Canvas->MoveTo(99, 149);
 Image1->Canvas->LineTo(99, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 HODIgrtoka = 1;
 int i,j;
 AnsiString Str = "";

 Image1->Canvas->Pen->Width = 2;
 Image1->Canvas->Pen->Color = clBlack;
 Image1->Canvas->Brush->Color = clWhite;
 Image1->Canvas->Brush->Style = bsSolid;

 Tree = new Sost;
// Tree2 = new Sost;
 TekSost = Tree;

 TekSost->Parent       = 0;
 TekSost->Prawilo      = -1;
 TekSost->CheiHod      = -1;
 TekSost->KolZanat     = 0;
 TekSost->KolPo2_0     = 0;
 TekSost->KolPo2_X     = 0;
 TekSost->KolChild     = 9-TekSost->KolZanat;

 for (i = 0; i < 9; i++)
   TekSost->Pole[i] = 0;


 for (i = 0; i < 9; i++)
  {
   if (TekSost->Pole[i] == 0)  Str += "| ";
   if (TekSost->Pole[i] == -1) Str += "|0";
   if (TekSost->Pole[i] ==  1) Str += "|X";
  }
 Str += "|";

 Zapolnenie(TekSost, 1, TreeView1->Items->Add(0, Str));
// DrawSetka();
 Label1->Caption = "";
 // Label1->Caption = RRR;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Komp1_BtnClick(TObject *Sender)
{
 int Koord;
 Sost *tmp;
 
 Komp1_Btn->Enabled = 0;
 Koord = HodKompa(HODIgrtoka, TekSost);
 if (Koord >=0) tmp = Hod(Koord, HODIgrtoka, TekSost);
  TekSost = tmp;
 HODIgrtoka = abs(HODIgrtoka - 1);

}
//---------------------------------------------------------------------------
Sost *TForm1::WstawkaUsla(int KoordHoda, Sost *Parent, int Hod)
{
 if (!(Parent->Pole[KoordHoda]))
 {
//  RRR ++;
  int i,j, Res1, Res_1;

  Sost *New;
  New = new Sost;
  New->Parent = Parent;
  New->Prawilo = KoordHoda;
  New->CheiHod = Hod;

  for (i = 0; i < 9; i++)
   New->Pole[i] = Parent->Pole[i];

  if (Hod) New->Pole[KoordHoda] =  1; // esli hod krest
  else     New->Pole[KoordHoda] = -1; // esli hod nolik

  New->KolZanat = Parent->KolZanat + 1;
  New->KolChild = 9 - New->KolZanat;

  Cell SostWiigrisha = ProwerkaLines(New);
  New->KolPo2_X = SostWiigrisha.X;
  New->KolPo2_0 = SostWiigrisha.Y;
  if ((New->KolPo2_X > 9) ^ (New->KolPo2_0 > 9))
   New->KolChild = 0; 
  return New;
 }
 else return 0;
}
//---------------------------------------------------------------------------
void TForm1::Zapolnenie(Sost *Parent, int Hod, TTreeNode *Par)
{
 int k,i, j;
 TTreeNode *TempTreeWiew;
 Parent->Child = new Sost*[9];
 AnsiString Str = "";
 Cell SostWiigrisha;
 for (k = 0; k < 9; k++)
 {
  Parent->Child[MassHodow[k]] = WstawkaUsla(MassHodow[k], Parent, Hod);

  if (Parent->Child[MassHodow[k]])
   {
    for (i = 0; i < 9; i++)
    {
     if (Parent->Child[MassHodow[k]]->Pole[i] ==  0) Str += "| ";
     if (Parent->Child[MassHodow[k]]->Pole[i] == -1) Str += "|0";
     if (Parent->Child[MassHodow[k]]->Pole[i] ==  1) Str += "|X";
    }
    Str += "|";
    TempTreeWiew = Par;
//    TempTreeWiew = TreeView1->Items->AddChild(Par, Str);
    if ((Parent->Child[MassHodow[k]]->KolPo2_0 < 10) && (Parent->Child[MassHodow[k]]->KolPo2_X < 10))
     Zapolnenie(Parent->Child[MassHodow[k]], abs(Hod-1), TempTreeWiew);
    Str = "";
    }
 }
}
//---------------------------------------------------------------------------
 Cell TForm1::ProwerkaLines(Sost *TekSos)
{
 int k, i, j;
 Cell Result;
 Result.X = 0;
 Result.Y = 0;

 for (i = 0; i < 8; i++)
 {
  k = TekSos->Pole[MassPrower[i][0]] + TekSos->Pole[MassPrower[i][1]] + TekSos->Pole[MassPrower[i][2]];

  switch (k)
  {
   case -3: Result.Y = 10; // wse 3 po 0(-1)
   break;

   case -2: Result.Y += 1; //     2 po 0(-1), 1 - pusto(0)
   break;

   case  2: Result.X += 1; //     2 po X(1),  1 - pusto(0)
   break;

   case  3: Result.X = 10; // wse 3 po X(1)
   break;
  }
 }
 return Result;
}
//---------------------------------------------------------------------------
Sost *TForm1::Hod(int Koord, int HOD, Sost *Sostoajnie)
{
 if (TekSost->Child[Koord])
 {
  int x = Koord % 3;
  int y = Koord / 3;

  x *= 50;
  y *= 50;

  Image1->Canvas->Pen->Width = 3;
  Image1->Canvas->Pen->Color = clBlack;

  if (HOD)
  {
   Image1->Canvas->MoveTo(x+5,y+5);
   Image1->Canvas->LineTo(x+45,y+45);
   Image1->Canvas->MoveTo(x+45,y+5);
   Image1->Canvas->LineTo(x+5,y+45);
  }
  else
   Image1->Canvas->Ellipse(x+5, y+5, x+45, y+45);
  return TekSost->Child[Koord];
 }
 else return 0;
}
//---------------------------------------------------------------------------
int TForm1::HodKompa(int HOD, Sost *Sostoajnie)
{
 if (Sostoajnie->KolChild == 0) return -1000; // net hodow
 int i;
 Cell MH[9],MHP[9],MHR[9], max, min;  // X - значение Y - позиция хода(координата)

 max.X = -1;
 max.Y = -1;
 for (i = 0; i < 9; i++)
 {
  MH[MassHodow[i]].X = -1;
  MH[MassHodow[i]].Y = -1;
  MHP[MassHodow[i]].X = -1;
  MHP[MassHodow[i]].Y = -1;
  if (Sostoajnie->Child[MassHodow[i]])
  {
   // заполняем массив выгоды хода компьютера
   MH[MassHodow[i]].Y = MassHodow[i];
   if (HOD)
    MH[MassHodow[i]].X = Sostoajnie->Child[MassHodow[i]]->KolPo2_X;
   else
    MH[MassHodow[i]].X = Sostoajnie->Child[MassHodow[i]]->KolPo2_0;
   // заполняем массив выгоды последуещего хода противника
   MHP[MassHodow[i]].X = ProwerkaHoda(abs(HOD-1), Sostoajnie->Child[MassHodow[i]]);
   MHP[MassHodow[i]].Y = MassHodow[i];
   if ((MHP[MassHodow[i]].X > 9) && (MH[MassHodow[i]].X < 10))
    MH[MassHodow[i]].Y = -1;
   if (max.X < MH[MassHodow[i]].X)
   {
    max.X = MH[MassHodow[i]].X;
    max.Y = MassHodow[i];
   }
  }
 }
 if (max.X >= 10) return max.Y;

 /*
 max.X = -100;
 max.Y = -100;
 // ищем в массиве ходов ход с максимальной выгодой
 for (i = 0; i < 9; i++)
  if (MH[MassHodow[i]].Y >= 0)
   if (max.X < MH[MassHodow[i]].X)
   {
    max.X = MH[MassHodow[i]].X;
    max.Y = MH[MassHodow[i]].Y;
   }

 min.X =  100;
 min.Y =  100;
 // ищем в массиве ходов ход с максимальной выгодой
 for (i = 0; i < 9; i++)
  if (MHP[MassHodow[i]].Y >= 0)
   if (min.X > MHP[MassHodow[i]].X)
   {
    min.X = MHP[MassHodow[i]].X;
    min.Y = MHP[MassHodow[i]].Y;
   }
 */
 max.X = -100;
 max.Y = -100;
 for (i = 0; i < 9; i++)
  if (MH[MassHodow[i]].Y >= 0)
  {
   MHR[MassHodow[i]].X = MH[MassHodow[i]].X - MHP[MassHodow[i]].X;
   MHR[MassHodow[i]].Y = MH[MassHodow[i]].Y;

   if (max.X < MH[MassHodow[i]].X)
   {
    max.X = MH[MassHodow[i]].X;
    max.Y = MH[MassHodow[i]].Y;
   }
  }


 if (max.Y > -1) return max.Y;
 else
  for (i = 0; i < 9; i++)
   if (Sostoajnie->Child[MassHodow[i]]) return MassHodow[i];
}
//---------------------------------------------------------------------------
int  TForm1::ProwerkaHoda(int HOD, Sost *Sostoajnie)
{
 if (!(Sostoajnie->KolChild)) return -100;
 int i,tmp, max = -1;
 for (i = 0; i < 9; i++)
 {
  if (Sostoajnie->Child[i])
  {
   if (HOD) tmp = Sostoajnie->Child[i]->KolPo2_X;
   else     tmp = Sostoajnie->Child[i]->KolPo2_0;
   if (max < tmp) max = tmp;
  }
 }
 return max;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (!(PlayGame)) return;


 int Koord, Wiigr;
 Komp1_Btn->Enabled = 0;

 int i;
 int XX = X / 50;
 int YY = Y / 50;

 Sost *tmp = Hod(XX+YY*3, HODIgrtoka, TekSost);
 if (tmp)
  {
   TekSost = tmp;
// Prowerka na wiigrish
   if (HODIgrtoka)
   Wiigr = TekSost->KolPo2_X;
   else
   Wiigr = TekSost->KolPo2_0;
   if (Wiigr > 9)
   {
    Label1->Caption = "Вы выиграли";
    PlayGame = 0;
    return;
   };

   if (TekSost->KolZanat == 3)
   {
    if (HODIgrtoka) i = 1;
    else i = -1;

    if (((TekSost->Pole[0] == i) && (TekSost->Pole[8] == i)) ^
        ((TekSost->Pole[2] == i) && (TekSost->Pole[6] == i)))
     for (i = 0; i < 9; i++)
      MassHodow[i] = Strateg1[i];
   }

   HODIgrtoka = abs(HODIgrtoka - 1);
   Koord = HodKompa(HODIgrtoka, TekSost);
   if (Koord >=0) tmp = Hod(Koord, HODIgrtoka, TekSost);
   TekSost = tmp;

// Prowerka na wiigrish
   if (HODIgrtoka)
   Wiigr = TekSost->KolPo2_X;
   else
   Wiigr = TekSost->KolPo2_0;
   if (Wiigr > 9)
   {
    Label1->Caption = "Вы проиграли";
    PlayGame = 0;
    return;
   };

   HODIgrtoka = abs(HODIgrtoka-1);
  }
 if (TekSost->KolChild == 0)
   {
    Label1->Caption = "Ничья";
    PlayGame = 0;
    return;
   };

}
//---------------------------------------------------------------------------


