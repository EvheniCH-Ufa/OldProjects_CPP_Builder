//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Basic_Unit.h"
#include "Matrix_for_lab.h"
#include "Grafics_Unit.h"
#include "DGLUT.h"
#include <mem.h>
#include "Create_Object_Unit.h"
#include "Points_Unit.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TBasic_Form *Basic_Form;
unsigned char MousKey = 0; // 0 - нет, 1 - левая, 2 - левая + правая
unsigned char RotState = 0; // 0- общий, 1- относ X, 2- относ Y, 3 - относ Z
float StartMousX, StartMousY;
int AnX, AnY, AnZ;
HWND CrsrRotX, CrsrRotY, CrsrRotZ, CrsrRotAll;
GLint VPX1, VPX2, VPY1, VPY2, VPZ1, VPZ2;
bool Zalivka = 1;
typedef float float3v[3];
bool Redaktor = 0;
float Masc = 1.0f;
/*float3v vrX = {1.0, 0.0, 0.0};
float3v vrY = {0.0, 1.0, 0.0};
float3v vrZ = {0.0, 0.0, 1.0};*/
//---------------------------------------------------------------------------
__fastcall TBasic_Form::TBasic_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_ExitClick(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::FormCreate(TObject *Sender)
{
String Dir = ExtractFileDir(Application->ExeName);
SvDlg->InitialDir = Dir;
OpnDlg->InitialDir = Dir;

// ЗАГРУЗКА КУРСОРОВ
CrsrRotAll = LoadImage(0, "CrsrRotAll.cur", IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
if (CrsrRotAll == 0) ShowMessage("Ошибка загрузки курсора! (CrsrRotAll.cur)");
  else Screen->Cursors[100] = CrsrRotAll;

CrsrRotX   = LoadImage(0, "CrsrRotX.cur",   IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
if (CrsrRotX == 0) ShowMessage("Ошибка загрузки курсора! (CrsrRotX.cur)");
  else Screen->Cursors[101] = CrsrRotX;

CrsrRotY   = LoadImage(0, "CrsrRotY.cur",   IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
if (CrsrRotY == 0) ShowMessage("Ошибка загрузки курсора! (CrsrRotY.cur)");
  else Screen->Cursors[102] = CrsrRotY;

CrsrRotZ   = LoadImage(0, "CrsrRotZ.cur",   IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
if (CrsrRotZ == 0) ShowMessage("Ошибка загрузки курсора! (CrsrRotZ.cur)");
  else Screen->Cursors[103] = CrsrRotZ;
// ЗАГРУЗКА КУРСОРОВ

// 100- общий, 101- относ X, 102- относ Y, 103 - относ Z

// обзор
VPX1 = VPY1 = -400;
VPZ1 = -1000;
VPY2 = VPX2 = 400;
VPZ2 = 1000;

// Углы поворота
AnX = AnY = AnZ = 0;

 ClientHeight = 600;
 ClientWidth = 600;
 // инициализация OpenGl
   ghDC = GetDC(Handle);
   if (!SetupPixelFormat(ghDC))
      Close();
   ghRC = wglCreateContext(ghDC);
   wglMakeCurrent(ghDC, ghRC);

   glEnable (GL_BLEND);
   glEnable (GL_CULL_FACE);
   glEnable(GL_TEXTURE_2D);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
   glShadeModel (GL_FLAT);
   glClearColor(0.0, 0.0, 0.0, 0.0);

   FormResize(Sender);

   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_DEPTH_TEST);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_NORMALIZE);

     float p[4]={0,0,250,0};
   glLightfv(GL_LIGHT0,GL_POSITION,p);
 // инициализация OpenGl
}
//---------------------------------------------------------------------------
bool __fastcall TBasic_Form::SetupPixelFormat(HDC hdc)
{
    PIXELFORMATDESCRIPTOR pfd, *ppfd;
    int pixelformat;

    ppfd = &pfd;

    ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
    ppfd->nVersion = 1;
    ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    ppfd->dwLayerMask = PFD_MAIN_PLANE;
    ppfd->iPixelType = PFD_TYPE_RGBA;
    ppfd->cColorBits = 16;
    ppfd->cDepthBits = 16;

    ppfd->cAccumBits = 0;
    ppfd->cStencilBits = 0;

    if ((pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0)
    {
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
        return FALSE;
    }
    if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE)
    {
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
        return FALSE;
    }
    return TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::FormResize(TObject *Sender)
{
 int Port = ClientHeight;
 if (Port > ClientWidth) Port = ClientWidth;

   glViewport((ClientWidth - Port)/2, (ClientHeight - Port)/2, Port, Port);
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
//       левой, правой, нижней, верхней, ближней и дальней плоскостей отсечения
   glOrtho(VPX1, VPX2,   VPY1,   VPY2,      VPZ1,   VPZ2); //масштабы координатных осей

//параметры камеры: первая тройка - её координаты,
//                  вторая - вектор направления,
//                  третья - направление оси Y.
  gluLookAt(0, 0, -150,  0,0,0,  0,1,0);
  glMatrixMode(GL_MODELVIEW);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(ghRC)
  {
    wglMakeCurrent(ghDC,0);
    wglDeleteContext(ghRC);
  }
  if(ghDC)
    ReleaseDC(Handle, ghDC);
}
//---------------------------------------------------------------------------
void TBasic_Form::Draw()
{
/*float3v vrX = {1.0, 0.0, 0.0};
float3v vrY = {0.0, 1.0, 0.0};
float3v vrZ = {0.0, 0.0, 1.0};
    // матрицы для поворота
  TMatrix_4X4 RotX;
  TMatrix_4X4 RotY;
  TMatrix_4X4 RotZ;
  TMatrix_4X4 Rot;

// их инициализация
  RotX = Rot.RotateX(Pi * AnX /180);
  RotY = Rot.RotateY(Pi * AnY /180);
  RotZ = Rot.RotateZ(Pi * AnZ /180);

  Rot = RotX.Mull(RotY);
  Rot = RotZ.Mull(Rot);

  Rot.Mull(vrX);
  Rot.Mull(vrY);
  Rot.Mull(vrZ);    */

 glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
 glEnable(GL_POLYGON_STIPPLE);
 glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

 unsigned int I;
 glPushMatrix();
  glRotatef(AnX, 1,0,0);
  glRotatef(AnY, 0,-1,0);
  glRotatef(AnZ, 0,0,-1);

  float LenLine = Masc * 51.0f;
  glBegin(GL_LINES);
   glColor3f(1,0,0);
   glVertex3f(-Masc, 0, 0);
   glVertex3f(-LenLine, 0, 0);

   glColor3f(0,1,0);
   glVertex3f(0, Masc, 0);
   glVertex3f(0, LenLine, 0);

   glColor3f(0,0,1);
   glVertex3f(0, 0, -Masc);
   glVertex3f(0, 0, -LenLine);
  glEnd();


  for (I = 0; I < TTeloCount; I ++)
   {
    if (Zalivka)
     {
      if (Tela[I].Prozrach < 100)
       {
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
       }
       if (Frm_Create_Object->CmBx_Tela->ItemIndex != Tela[I].idTelo)
        glColor4f(1.0f * Tela[I].Color.RGB.R / 255,
                  1.0f * Tela[I].Color.RGB.G / 255,
                  1.0f * Tela[I].Color.RGB.B / 255,
                  1.0f * Tela[I].Prozrach    / 100);
       else
        glColor3f(1.0f, 0.0f, 0.0f);
     }
    else
      if (Frm_Create_Object->CmBx_Tela->ItemIndex != Tela[I].idTelo)
       glColor4f(1.0f * Tela[I].Color.RGB.R / 255,
                 1.0f * Tela[I].Color.RGB.G / 255,
                 1.0f * Tela[I].Color.RGB.B / 255,
                 1.0f);
      else
       glColor3f(1.0f, 0.0f, 0.0f);

      switch (Tela[I].TypeTelo)
       {
        case 0:
         {
          if (Zalivka)
            MglutSolidBlock(Tela[I].Rasmer1, Tela[I].Rasmer2, Tela[I].Rasmer3,
                            Tela[I].AngleX,  Tela[I].AngleY,  Tela[I].AngleZ,
                            Tela[I].StartPoints);
          else
            MglutWireBlock( Tela[I].Rasmer1, Tela[I].Rasmer2, Tela[I].Rasmer3,
                            Tela[I].AngleX,  Tela[I].AngleY,  Tela[I].AngleZ,
                            Tela[I].StartPoints);
         };
        break;
        case 1:
         {
          if (Zalivka)
            MgluSolidCilindr(Tela[I].Rasmer2/2, Tela[I].Rasmer1,
                             Tela[I].AngleX,  Tela[I].AngleY,  Tela[I].AngleZ,
                             Tela[I].StartPoints);
          else
            MgluWireCilindr(Tela[I].Rasmer2/2, Tela[I].Rasmer1,
                            Tela[I].AngleX,  Tela[I].AngleY,  Tela[I].AngleZ,
                            Tela[I].StartPoints);
         };
        break;
        case 2:
         {
          if (Zalivka)
            MgluSolidConusUsehc(Tela[I].Rasmer2/2, Tela[I].Rasmer3/2, Tela[I].Rasmer1,
                             Tela[I].AngleX,  Tela[I].AngleY,  Tela[I].AngleZ,
                             Tela[I].StartPoints);
          else
            MgluWireConusUsehc(Tela[I].Rasmer2/2, Tela[I].Rasmer3/2, Tela[I].Rasmer1,
                               Tela[I].AngleX,    Tela[I].AngleY,  Tela[I].AngleZ,
                               Tela[I].StartPoints);
         };
        break;
        case 3:
         {
          if (Zalivka)
            MgluSolidSphere(Tela[I].Rasmer1/2,Tela[I].StartPoints);
          else
            MgluWireSphere(Tela[I].Rasmer1/2,Tela[I].StartPoints);
         };
        break;
       }
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);
   }

TVector3D PP;
//MgluSolidSphere(100,PP);
glPopMatrix();
SwapBuffers(ghDC);
}
void __fastcall TBasic_Form::FormPaint(TObject *Sender)
{
 Draw();
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_BlockClick(TObject *Sender)
{
 Frm_Create_Object->Status = 0;
 CreateObjectBegin(0);
}
//---------------------------------------------------------------------------
void TBasic_Form::CreateObjectBegin(unsigned char Status)
{
 UstanowkaCreateObject(Status) ;
Frm_Create_Object->TrBr_R->Position = 0;
Frm_Create_Object->TrBr_G->Position = 255;
Frm_Create_Object->TrBr_B->Position = 0;
Frm_Create_Object->TrBr_Proz->Position = 100;
Frm_Create_Object->TrBr_RChange(Frm_Create_Object);
Frm_Create_Object->ChkBxClick(Frm_Create_Object);

if (Frm_Create_Object->ShowModal() == 1)
 {
  CreateObject(Status, TTeloCount);
  TTeloCount++;
  Draw();
 }
}
// int TypeTelo; // 0 - блок, 1 - цилиндр, 2 - конус, 3 - сфера
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TBasic_Form::CreateObject(unsigned char Status, int Num)
{
 if (Num < 0) return;
 //  unsigned int Num = TTeloCount;

   Tela[Num].idTelo        = Num;
   Tela[Num].StartPoints.X = -StrToFloat(Frm_Points->Ed_PointsX->Text);
   Tela[Num].StartPoints.Y = StrToFloat(Frm_Points->Ed_PointsY->Text);
   Tela[Num].StartPoints.Z = -StrToFloat(Frm_Points->Ed_PointsZ->Text);
   Tela[Num].Rasmer1       = StrToFloat(Frm_Create_Object->Ed_Rasmer1->Text);
   Tela[Num].AngleX        = StrToFloat(Frm_Create_Object->Ed_Rot_X->Text);
   Tela[Num].AngleY        = StrToFloat(Frm_Create_Object->Ed_Rot_Y->Text);
   Tela[Num].AngleZ        = StrToFloat(Frm_Create_Object->Ed_Rot_Z->Text);
   Tela[Num].Color.RGB.R   = Frm_Create_Object->TrBr_R->Position;
   Tela[Num].Color.RGB.G   = Frm_Create_Object->TrBr_G->Position;
   Tela[Num].Color.RGB.B   = Frm_Create_Object->TrBr_B->Position;
   Tela[Num].Color.RGB.A   = 255;
   Tela[Num].Prozrach      = Frm_Create_Object->TrBr_Proz->Position;

   switch (Status)
    {
     case 0:
       {
        Tela[Num].TypeTelo = 0;
        if (Frm_Create_Object->ChkBx->Checked)
          {
           Tela[Num].Rasmer2 = Tela[Num].Rasmer1;
           Tela[Num].Rasmer3 = Tela[Num].Rasmer1;
          }
        else
          {
           Tela[Num].Rasmer2 = StrToFloat(Frm_Create_Object->Ed_Rasmer2->Text);
           Tela[Num].Rasmer3 = StrToFloat(Frm_Create_Object->Ed_Rasmer3->Text);
          }
       };
     break;
     case 1:
       {
        Tela[Num].TypeTelo = 1;
        Tela[Num].Rasmer2 = StrToFloat(Frm_Create_Object->Ed_Rasmer2->Text);
        Tela[Num].Rasmer3 = Tela[Num].Rasmer2;
       };
     break;
     case 2:
       {
        Tela[Num].TypeTelo = 2;
        Tela[Num].Rasmer2 = StrToFloat(Frm_Create_Object->Ed_Rasmer2->Text);
        if (!Frm_Create_Object->ChkBx->Checked)
          {
           Tela[Num].Rasmer3 = 0;
          }
        else
          {
           Tela[Num].Rasmer3 = StrToFloat(Frm_Create_Object->Ed_Rasmer3->Text);
          }
       };
     break;
     case 3:
       {
        Tela[Num].TypeTelo = 3;
        Tela[Num].Rasmer2 = Tela[Num].Rasmer1;
        Tela[Num].Rasmer3 = Tela[Num].Rasmer1;
       };
     break;
   }
//  TTeloCount++;
  Draw();
}
// int TypeTelo; // 0 - блок, 1 - цилиндр, 2 - конус, 3 - сфера
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_CilindrClick(TObject *Sender)
{
 Frm_Create_Object->Status = 1;
 CreateObjectBegin(1);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::MM_KonusClick(TObject *Sender)
{
 Frm_Create_Object->Status = 2;
 CreateObjectBegin(2);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::MM_SphereClick(TObject *Sender)
{
 Frm_Create_Object->Status = 3;
 CreateObjectBegin(3);
}
//---------------------------------------------------------------------------
/*
Status     0 - блок, |  1 - Цилиндр, | 2 - конус,               | 3 - сфера,
Размер1     Длинна   |   Высота      |  Высота                  |  Диаметр
Размер1     Ширина   |   Диаметр     |  Диаметр (ниж для усеч)  |    ---
Размер1     Высота   |     ---       |  --- (Диам верх для усеч)|    ---
*/



void __fastcall TBasic_Form::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MousKey = 0;
    Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
int KK = 50;
 if (Button == mbRight)
   {
    MousKey = 1;
    RotState = 0;
    if (X < KK) RotState = 1;
    if (Y < KK) RotState = 3;
    if (Y > ClientHeight - KK) RotState = 2;
    if (X > ClientWidth - KK) RotState = 1;
// 0- общий, 1- относ X, 2- относ Y, 3 - относ Z

   }
 if ((Button == mbMiddle) || ((Button == mbLeft) && (MousKey == 3)))
   {
    MousKey = 2;
   }

StartMousX = X;
StartMousY = Y;
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
float dX = StartMousX - X;
float dY = StartMousY - Y;


switch (MousKey)
{
  case 0:
   {
    Cursor = crDefault;
   };
  break;
  case 1:
   {
    switch (RotState)
    {
      case 0:
        {
         Cursor =100;
         AnY += dX;
         AnX += dY;
           Draw();
        }  ;
      break;
      case 1:
        {
         AnX += dY;
         Cursor =101;
           Draw();
        }  ;
      break;
      case 2:
        {
         AnY += dX;
         Cursor =102;
           Draw();
        }  ;
      break;
      case 3:
        {
         AnZ += dX;
         Cursor =103;
           Draw();
        }  ;
      break;
    }
// курсор   // 100- общий, 101- относ X, 102- относ Y, 103 - относ Z
// RotState // 0- общий, 1- относ X, 2- относ Y, 3 - относ Z

   };
  break;
  case 2:
   {
    Cursor = crHandPoint;
    VPX1 += dX;
    VPX2 += dX;
    VPY1 -= dY;
    VPY2 -= dY;
    StartMousX = X;
    StartMousY = Y;
    FormResize(Sender);
    Draw();
   };
  break;
 }
    StartMousX = X;
    StartMousY = Y;
}
//---------------------------------------------------------------------------
// unsigned char MousKey = 0;  // 0 - нет,  2 - левая,  1 - правая
// unsigned char RotState = 0; // 0- общий, 1- относ X, 2- относ Y, 3 - относ Z
void __fastcall TBasic_Form::MM_DwigaiClick(TObject *Sender)
{
 MousKey = 3;
 Cursor = crHandPoint;
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_RSKClick(TObject *Sender)
{
 AnX = 0;
 AnY = 0;
 AnZ = 0;
 Draw();
}

//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_PriblizClick(TObject *Sender)
{
 Masc *= 0.9;
 VPX1 *= 0.9;
 VPX2 *= 0.9;
 VPY1 *= 0.9;
 VPY2 *= 0.9;
 FormResize(Sender);
 Draw();

}

//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_OtdalitClick(TObject *Sender)
{
 Masc /= 0.9;
 VPX1 /= 0.9;
 VPX2 /= 0.9;
 VPY1 /= 0.9;
 VPY2 /= 0.9;
 FormResize(Sender);
 Draw();
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
 MM_PriblizClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
 MM_OtdalitClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_FillClick(TObject *Sender)
{
 Zalivka = 1;
 Draw();
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_NotFillClick(TObject *Sender)
{
 Zalivka = 0;
 Draw();
}
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_EditClick(TObject *Sender)
{
String Str;
 Frm_Create_Object->Caption ="Редактирование объекта";
 Frm_Create_Object->Height +=33;
 Frm_Create_Object->Panel2->Top +=33;
 Frm_Create_Object->CmBx_Tela->Visible = 1;


 Frm_Create_Object->CmBx_Tela->Items->Clear();
 Frm_Create_Object->CmBx_Tela->Text = "Выберите объект";
 Frm_Create_Object->CmBx_Tela->ItemIndex = -1;


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
    Frm_Create_Object->CmBx_Tela->Items->Add(Str);
 }

// int TypeTelo; // 0 - блок, 1 - цилиндр, 2 - конус, 3 - сфера
// UstanowkaCreateObject()
 if (Frm_Create_Object->ShowModal() == 1)
     CreateObject(Frm_Create_Object->Status, Frm_Create_Object->CmBx_Tela->ItemIndex);

 Frm_Create_Object->CmBx_Tela->ItemIndex   = -1;
 Draw();

// Frm_Create_Object->Caption ="Редактирование объекта";
 Frm_Create_Object->Height                -=33;
 Frm_Create_Object->Panel2->Top          -=33;
 Frm_Create_Object->CmBx_Tela->Visible     = 0;
// Frm_Create_Object->CmBx_Tela->ItemIndex   = -1;
}
//---------------------------------------------------------------------------

void TBasic_Form::UstanowkaCreateObject(unsigned char Status)
{
 Frm_Create_Object->Label3->Visible =    1;
 Frm_Create_Object->Label3->Enabled = 1;
 Frm_Create_Object->Ed_Rasmer3->Visible =1;
 Frm_Create_Object->Ed_Rasmer3->Enabled = 1;
 Frm_Create_Object->Label2->Visible =      1;
 Frm_Create_Object->Label2->Enabled = 1;
 Frm_Create_Object->Ed_Rasmer2->Visible =    1;
 Frm_Create_Object->Ed_Rasmer2->Enabled = 1;
 switch (Status)
 {
   case 0:
     {
      Frm_Create_Object->Caption = "Создать блок";
      Frm_Create_Object->ChkBx->Caption = "Куб";
      Frm_Create_Object->ChkBx->Checked = 0;
      Frm_Create_Object->ChkBx->Visible = 1;
      Frm_Create_Object->Label1->Caption = "Длинна";
      Frm_Create_Object->Label2->Caption = "Ширина";
      Frm_Create_Object->Label3->Caption = "Высота";
     } ;
   break;
   case 1:
     {
      Frm_Create_Object->Caption = "Создать цилиндр";
      Frm_Create_Object->ChkBx->Visible = 0;
      Frm_Create_Object->Label1->Caption = "Высота";
      Frm_Create_Object->Label2->Caption = "Диаметр";
      Frm_Create_Object->Label3->Caption = "";
      Frm_Create_Object->Label3->Visible = 0;
      Frm_Create_Object->Ed_Rasmer3->Visible = 0;
     } ;
   break;
   case 2:
     {
      Frm_Create_Object->Caption = "Создать конус";
      Frm_Create_Object->ChkBx->Caption = "Усеченный конус";
      Frm_Create_Object->ChkBx->Checked = 0;
      Frm_Create_Object->ChkBx->Visible = 1;

      Frm_Create_Object->Label1->Caption = "Высота";
      Frm_Create_Object->Label2->Caption = "Диаметр ниж. осн-ния";
      Frm_Create_Object->Label2->Visible = 1;
      Frm_Create_Object->Ed_Rasmer2->Visible = 1;
      Frm_Create_Object->Label3->Caption = "Диаметр верх. осн-ния";
     } ;
   break;
   case 3:
     {
      Frm_Create_Object->Caption = "Создать сферу";
      Frm_Create_Object->ChkBx->Visible = 0;

      Frm_Create_Object->Label1->Caption = "Диаметр";
      Frm_Create_Object->Label2->Visible = 0;
      Frm_Create_Object->Ed_Rasmer2->Visible = 0;
      Frm_Create_Object->Label3->Visible = 0;
      Frm_Create_Object->Ed_Rasmer3->Visible = 0;
     } ;
   break;
 }
}
// int TypeTelo; // 0 - блок, 1 - цилиндр, 2 - конус, 3 - сфера



void __fastcall TBasic_Form::MM_OpenClick(TObject *Sender)
{
 if (OpnDlg->Execute())
 {
  SvDlg->FileName = OpnDlg->FileName;
  TIniFile *IniF;
  IniF = new TIniFile(SvDlg->FileName);
  String S;

  TTeloCount = IniF->ReadInteger("KOLTEL", "TEL", 0);
  AnX = IniF->ReadInteger("Angle", "AnX", 0);
  AnY = IniF->ReadInteger("Angle", "AnY", 0);
  AnZ = IniF->ReadInteger("Angle", "AnZ", 0);
  int i;
  for (i = 0; i < TTeloCount; i++)
  {
   S = "Telo" + IntToStr(i);
   Tela[i].idTelo        = i;
   Tela[i].TypeTelo      = IniF->ReadInteger(S, "TypeTelo", 0);
   Tela[i].StartPoints.X = IniF->ReadFloat  (S, "X",        0);
   Tela[i].StartPoints.Y = IniF->ReadFloat  (S, "Y",        0);
   Tela[i].StartPoints.Z = IniF->ReadFloat  (S, "Z",        0);
   Tela[i].Rasmer1       = IniF->ReadFloat  (S, "Rasmer1",  0);
   Tela[i].Rasmer2       = IniF->ReadFloat  (S, "Rasmer2",  0);
   Tela[i].Rasmer3       = IniF->ReadFloat  (S, "Rasmer3",  0);
   Tela[i].AngleX        = IniF->ReadFloat  (S, "AngleX",   0);
   Tela[i].AngleY        = IniF->ReadFloat  (S, "AngleY",   0);
   Tela[i].AngleZ        = IniF->ReadFloat  (S, "AngleZ",   0);
   Tela[i].Color.Color   = IniF->ReadInteger(S, "Color",    0);
   Tela[i].Prozrach      = IniF->ReadInteger(S, "Prozrach", 0);
  }
  if (IniF) delete (IniF);
  Draw();
 }
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::MM_SaveClick(TObject *Sender)
{
 bool Sflag = 0;
 TIniFile *IniF = NULL;

 if (SvDlg->FileName != "")
  Sflag = 1;
 else
  if (SvDlg->Execute())
   Sflag = 1;

 if (!(Sflag))
  return;

 char *str;

 int LenFN = SvDlg->FileName.Length();
 int i = LenFN - 4;
 str = new char[SvDlg->FileName.Length()+5];
 str = StrCopy(str, SvDlg->FileName.c_str());

 if (str[i] != '.')
  {
   char *str1 = ".GGE";
   str = StrCat(str, str1);
   SvDlg->FileName = str;
   delete(str1);
  }

IniF = new TIniFile(SvDlg->FileName);
String S;
int TSAVE = 0;
for (i = 0; i < TTeloCount; i++)
{
 S = "Telo" + IntToStr(TSAVE);
 IniF->WriteInteger(S, "TypeTelo",  Tela[i].TypeTelo);
 IniF->WriteFloat  (S, "X",         Tela[i].StartPoints.X);
 IniF->WriteFloat  (S, "Y",         Tela[i].StartPoints.Y);
 IniF->WriteFloat  (S, "Z",         Tela[i].StartPoints.Z);
 IniF->WriteFloat  (S, "Rasmer1",   Tela[i].Rasmer1);
 IniF->WriteFloat  (S, "Rasmer2",   Tela[i].Rasmer2);
 IniF->WriteFloat  (S, "Rasmer3",   Tela[i].Rasmer3);
 IniF->WriteFloat  (S, "AngleX",    Tela[i].AngleX);
 IniF->WriteFloat  (S, "AngleY",    Tela[i].AngleY);
 IniF->WriteFloat  (S, "AngleZ",    Tela[i].AngleZ);
 IniF->WriteInteger(S, "Color",     Tela[i].Color.Color);
 IniF->WriteInteger(S, "Prozrach",  Tela[i].Prozrach);
 TSAVE++;
}
IniF->WriteInteger("KOLTEL", "TEL", TSAVE);
IniF->WriteInteger("Angle", "AnX", AnX);
IniF->WriteInteger("Angle", "AnY", AnY);
IniF->WriteInteger("Angle", "AnZ", AnZ);

if (IniF) delete (IniF);
 }
//---------------------------------------------------------------------------
void __fastcall TBasic_Form::MM_NewClick(TObject *Sender)
{
 AnX = 0;
 AnY = 0;
 AnZ = 0;

 Masc = 1;
 VPX1 = VPY1 = -400;
 VPZ1 = -1000;
 VPY2 = VPX2 = 400;
 VPZ2 = 1000;
 FormResize(Sender);
 Draw();

 TTeloCount = 0;
 Draw();
}
//---------------------------------------------------------------------------

void __fastcall TBasic_Form::MM_SaveAsClick(TObject *Sender)
{
 SvDlg->FileName = "";
 MM_SaveClick(Sender);
}
//---------------------------------------------------------------------------

