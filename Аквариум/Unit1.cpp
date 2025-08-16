//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const KolFish = 10;
const KolEda  = 20;
const Golod   = 1000;
const PishewajaCennostEdi   = Golod/5;

TBasicForm *BasicForm;
TFish Fisher[KolFish];
int NumFisher[10] = {0,1,2,3,4,5,6,7,8,9};
int SmeshFisher[10] = {34,22,29,27,20,24,22,19,19,17};
TPanel **MasPanFishL, **MasPanFishR, **MasPanFishW, **MasPanEda;
TImage **MasIzoFishL, **MasIzoFishR, **MasIzoFishW, **MasIzoEda;
//---------------------------------------------------------------------------
unsigned __int64 time(void)
{
  asm{ rdtsc;}
}
//---------------------------------------------------------------------------
int Random(int X)
{
  int K = time() % X;
  return K;
}

//---------------------------------------------------------------------------
__fastcall TBasicForm::TBasicForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::FormCreate(TObject *Sender)
{
 HRGN windowRgn;

 ImageFon->Cursor = crHandPoint;                  // меняем курсор
 ImageFon->Picture->LoadFromFile("Pic/Фон.bmp");  // Грузим фон
 MasPanFishL  = new TPanel*[KolFish];             // Создаем массив панелей для рыб, плывущих влево
 MasPanFishR  = new TPanel*[KolFish];             // Создаем массив панелей для рыб, плывущих вправо
 MasPanFishW  = new TPanel*[KolFish];             // Создаем массив панелей для рыб, дохлых
 MasIzoFishL  = new TImage*[KolFish];             // Создаем массив имиджей для рыб, плывущих влево
 MasIzoFishR  = new TImage*[KolFish];             // Создаем массив имиджей для рыб, плывущих вправо
 MasIzoFishW  = new TImage*[KolFish];             // Создаем массив имиджей для рыб, дохлых
 MasPanEda    = new TPanel*[KolEda];              // Создаем массив панелей для еды
 MasIzoEda    = new TImage*[KolEda];              // Создаем массив имиджей для еды

 int i;
 for (i = 0; i < KolFish; i++)
 {
// присваиваем различные свойства панелям и имиджам для левых рыб
  MasPanFishL[i]          = new TPanel(BasicForm);
  MasPanFishL[i]->Parent  = BasicForm;
  MasPanFishL[i]->Visible = 1;
  MasPanFishL[i]->Color   = clBlack;
  MasPanFishL[i]->FullRepaint = 0;

  MasIzoFishL[i]          = new TImage(MasPanFishL[i]);
  MasIzoFishL[i]->Parent  = MasPanFishL[i];
  MasIzoFishL[i]->Visible = 1;
  MasIzoFishL[i]->Align   = alClient;
  MasIzoFishL[i]->Picture->LoadFromFile("Pic/Рыба " + IntToStr(i) + ".bmp");
  MasIzoFishL[i]->Stretch = 1;
  MasIzoFishL[i]->Cursor = crNone;

  MasPanFishL[i]->Height  = MasIzoFishL[i]->Picture->Bitmap->Height+2;
  MasPanFishL[i]->Width   = MasIzoFishL[i]->Picture->Bitmap->Width+2;

// создаем регион по рыбе и обрезаем по нему панели
  windowRgn = CREATERGNFROMBITMAP(MasIzoFishL[i]->Picture->Bitmap);
  SetWindowRgn(MasPanFishL[i]->Handle, windowRgn, True);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// присваиваем различные свойства панелям и имиджам для правых рыб
  MasPanFishR[i]          = new TPanel(BasicForm);
  MasPanFishR[i]->Parent  = BasicForm;
  MasPanFishR[i]->Visible = 0;
  MasPanFishR[i]->FullRepaint = 0;

  MasIzoFishR[i]          = new TImage(MasPanFishR[i]);
  MasIzoFishR[i]->Parent  = MasPanFishR[i];
  MasIzoFishR[i]->Visible = 1;
  MasIzoFishR[i]->Align   = alClient;
  MasIzoFishR[i]->Picture->LoadFromFile("Pic/РыбаR " + IntToStr(i) + ".bmp");
  MasIzoFishR[i]->Stretch = 1;
  MasIzoFishR[i]->Cursor = crNone;

  MasPanFishR[i]->Height  = MasIzoFishR[i]->Picture->Bitmap->Height+2;
  MasPanFishR[i]->Width   = MasIzoFishR[i]->Picture->Bitmap->Width+2;

// создаем регион по рыбе и обрезаем по нему панели
  windowRgn = CREATERGNFROMBITMAP(MasIzoFishR[i]->Picture->Bitmap);
  SetWindowRgn(MasPanFishR[i]->Handle, windowRgn, True);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// присваиваем различные свойства панелям и имиджам для дохлых рыб
  MasPanFishW[i]          = new TPanel(BasicForm);
  MasPanFishW[i]->Parent  = BasicForm;
  MasPanFishW[i]->Visible = 0;
  MasPanFishW[i]->FullRepaint = 0;

  MasIzoFishW[i]          = new TImage(MasPanFishW[i]);
  MasIzoFishW[i]->Parent  = MasPanFishW[i];
  MasIzoFishW[i]->Visible = 1;
  MasIzoFishW[i]->Align   = alClient;
  MasIzoFishW[i]->Picture->LoadFromFile("Pic/РыбаW " + IntToStr(i) + ".bmp");
  MasIzoFishW[i]->Stretch = 1;
  MasIzoFishW[i]->Cursor = crNone;

  MasPanFishW[i]->Height  = MasIzoFishW[i]->Picture->Bitmap->Height+2;
  MasPanFishW[i]->Width   = MasIzoFishW[i]->Picture->Bitmap->Width+2;

// создаем регион по рыбе и обрезаем по нему панели
  windowRgn = CREATERGNFROMBITMAP(MasIzoFishW[i]->Picture->Bitmap);
  SetWindowRgn(MasPanFishW[i]->Handle, windowRgn, True);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// задаем начальные свойства рыбам
  Fisher[i].Live  = 1;
  Fisher[i].Golod = Golod;
  Fisher[i].Deistwie = 1;
  Fisher[i].Speed = 1;
  Fisher[i].Gabarit.X = MasPanFishL[i]->Width;
  Fisher[i].Gabarit.Y = MasPanFishL[i]->Height;
  Fisher[i].Obem = (Fisher[i].Gabarit.X * Fisher[i].Gabarit.Y)/100;
  Fisher[i].Koord.X = Random(BasicForm->ClientWidth);
  Fisher[i].Koord.Y = Random(BasicForm->ClientHeight);
  Fisher[i].TochkaNaznach.X = Fisher[i].Koord.X;
  Fisher[i].TochkaNaznach.Y = Fisher[i].Koord.Y;
  Fisher[i].Naprawlenie = 0;
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 }

 for (i = 0; i < KolEda; i++)
 {
// присваиваем различные свойства панелям и имиджам для еды
  MasPanEda[i]          = new TPanel(BasicForm);
  MasPanEda[i]->Parent  = BasicForm;
  MasPanEda[i]->Visible = 0;
  MasPanEda[i]->Color   = clBlue;
  MasPanEda[i]->FullRepaint = 0;

  MasIzoEda[i]          = new TImage(MasPanEda[i]);
  MasIzoEda[i]->Parent  = MasPanEda[i];
  MasIzoEda[i]->Visible = 1;
  MasIzoEda[i]->Align   = alClient;
  MasIzoEda[i]->Picture->LoadFromFile("Pic/Еда.bmp");
  MasIzoEda[i]->Stretch = 1;
  MasIzoEda[i]->Cursor = crNone;

  MasPanEda[i]->Height  = MasIzoEda[i]->Picture->Bitmap->Height + 2;
  MasPanEda[i]->Width   = MasIzoEda[i]->Picture->Bitmap->Width  + 2;
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// создаем регион по еде и обрезаем по нему панели
  windowRgn = CREATERGNFROMBITMAP(MasIzoEda[i]->Picture->Bitmap);
  SetWindowRgn(MasPanEda[i]->Handle, windowRgn, True);
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 }

 for (i = 0; i < KolFish; i++)
 {
  ThreadFisher[i] = CreateThread(NULL, 0, ThreadFish, &NumFisher[i], 0, NULL);
 }
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::Timer1Timer(TObject *Sender)
{
 int i;
 // оседание еды на дно
 for (i = 0; i < KolEda; i++)
  if (MasPanEda[i]->Visible)
  {
   MasPanEda[i]->Top++;
   if (MasPanEda[i]->Top >= ImageFon->Height - 50)
    {
     MasPanEda[i]->Visible = 0;
//     Timer2Timer(Sender);
    }
  }
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
//---------------------------------------------------------------------------
/*------              процедура движения рыбы            ---------------------*/
void Move(int NumFish)
{
   // направление - вправо или влево и делаем видимой вправую или левую панель
   switch (Fisher[NumFish].Naprawlenie)
   {
     case 0:
     {
      MasPanFishL[NumFish]->Visible = 0;
      MasPanFishR[NumFish]->Visible = 1;
     };
     break;
     case 1:
     {
      MasPanFishL[NumFish]->Visible = 1;
      MasPanFishR[NumFish]->Visible = 0;
     };
     break;
     case 2:
     {
      MasPanFishL[NumFish]->Visible = 0;
      MasPanFishR[NumFish]->Visible = 0;
      MasPanFishW[NumFish]->Visible = 1;
     };
     break;
   }
  // Ход
  if (AbsLen(Fisher[NumFish].TochkaNaznach, Fisher[NumFish].Koord) >= Fisher[NumFish].Speed)
  {
   Fisher[NumFish].Koord.X += Fisher[NumFish].Step.X;
   Fisher[NumFish].Koord.Y += Fisher[NumFish].Step.Y;
  }
  else
   Fisher[NumFish].Koord = Fisher[NumFish].TochkaNaznach;

/*  MasPanFishL[NumFish]->Left = Fisher[NumFish].Koord.X - Fisher[NumFish].Gabarit.X/2;
  MasPanFishL[NumFish]->Top  = Fisher[NumFish].Koord.Y - SmeshFisher[NumFish] - 1;
  MasPanFishR[NumFish]->Left = Fisher[NumFish].Koord.X - Fisher[NumFish].Gabarit.X/2;
  MasPanFishR[NumFish]->Top  = Fisher[NumFish].Koord.Y - SmeshFisher[NumFish] -1 ;
  MasPanFishW[NumFish]->Left = Fisher[NumFish].Koord.X - Fisher[NumFish].Gabarit.X/2;
  MasPanFishW[NumFish]->Top  = Fisher[NumFish].Koord.Y - Fisher[NumFish].Gabarit.Y/2;
  */
  
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::KormPMClick(TObject *Sender)
{
 if (KormPM->Checked)
  ImageFon->Cursor = crHourGlass; // переключаем курсор на кормежку
 else
  ImageFon->Cursor = crHandPoint; // переключаем курсор на руку
}
//---------------------------------------------------------------------------
HRGN TBasicForm::CREATERGNFROMBITMAP(Graphics::TBitmap *rgnBitmap)
{
 TColor TransColor;
 int i,j,  i_width, i_heigt, i_left, i_right;
 HRGN rectRgn, Result;

 Result = 0;
 i_width = rgnBitmap->Width;
 i_heigt = rgnBitmap->Height;
 TransColor = clWhite;

 for (i = 0; i < i_heigt; i++)
 {
  i_left = -1;

  for (j = 0; j <= i_width; j++)
  {
   if (i_left < 0)
   {
    if (rgnBitmap->Canvas->Pixels[j][i] != TransColor) i_left = j;
   }
   else
    if (rgnBitmap->Canvas->Pixels[j][i] == TransColor)
    {
     i_right = j;
     rectRgn = CreateRectRgn(i_left+1, i+1, i_right+1, i+2);
     if (Result == 0) Result = rectRgn;
     else
     {
      CombineRgn(Result, Result, rectRgn, RGN_OR);
     }
     i_left = -1;
    }
  }
  if (i_left >= 0)
  {
   rectRgn = CreateRectRgn(i_left+1, i+1, i_width+1, i+2);
   if (Result == 0) Result = rectRgn;
   else
   {
    CombineRgn(Result, Result, rectRgn, RGN_OR);
   }
  }
 }
 return Result;
};
//---------------------------------------------------------------------------
void __fastcall TBasicForm::FormConstrainedResize(TObject *Sender,
      int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight)
{
// MaxWidth = 1032;
// MinWidth = 1032;
// MaxHeight = 802;
// MinHeight = 802;
}
//---------------------------------------------------------------------------
void __fastcall TBasicForm::ImageFonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 int i;

 // если кормим и нажата левая кнопка
 if ((KormPM->Checked) && (Button == mbLeft))
  for (i = 0; i < KolEda; i++)
   if (!MasPanEda[i]->Visible)
   {
    MasPanEda[i]->Visible = 1;
    MasPanEda[i]->Left = X;
    MasPanEda[i]->Top  = Y;
    break;
   }
}
/*/---------------------------------------------------------------------------
void TBasicForm::Grat(int NumFish)
{
 float Smeshenie , L,k,dX,dY, min = 1000000;

 int i, j, BligEda = -1;
 TGlPoint2d KoorEda;

  for (j = 0; j < KolEda; j++)
   if (MasPanEda[j]->Visible)
   {
    KoorEda.X = MasPanEda[j]->Left;
    KoorEda.Y = MasPanEda[j]->Top;
    L = AbsLen(Fisher[NumFish].Koord, KoorEda);
    if (min > L)
    {
     min = L;
     BligEda = j;
    }
   };
 dX = Fisher[NumFish].TochkaNaznach.X - Fisher[NumFish].Koord.X;
 Smeshenie = 0;
 if (dX > 0) Smeshenie = MasIzoFishL[NumFish]->Width;
 Fisher[NumFish].TochkaNaznach.X = MasPanEda[BligEda]->Left - Smeshenie;
 Fisher[NumFish].TochkaNaznach.Y = MasPanEda[BligEda]->Top - MasIzoFishL[NumFish]->Height/2 + 3;
}
*///---------------------------------------------------------------------------
float AbsLen(TGlPoint2d T1, TGlPoint2d T2)
{
 float L = sqrt((T2.X - T1.X)*(T2.X - T1.X) + (T2.Y - T1.Y)*(T2.Y - T1.Y));
 return L;
}
//---------------------------------------------------------------------------
TGlPoint2d RaschetStep(TGlPoint2d T1, TGlPoint2d T2, int Speed)
{
 TGlPoint2d Result;
 // Расстояние до цели по Х
 float dX = T2.X - T1.X;
 // Расстояние до цели по У
 float dY = T2.Y - T1.Y;
 // Длина пути
 float L = AbsLen(T2, T1);
 // Количество шагов до цели
 float KolStep =  float(L/Speed);
   // Расстояние шага по координатам
 Result.X = dX / KolStep;
 Result.Y = dY / KolStep;

 return Result;
}
/*/---------------------------------------------------------------------------
void  TBasicForm::Pliwem(int NumFish)
{
 // Расстояние до цели по Х
 float tmp = abs(Fisher[NumFish].Koord.X - Fisher[NumFish].TochkaNaznach.X);

 Fisher[NumFish].Speed = 1;
 if (tmp <= Epsilon) // если меньше или = 1, то
  {                  // генерируем новую цель
   Fisher[NumFish].TochkaNaznach.X = Random(BasicForm->ClientWidth  - Fisher[NumFish].Gabarit.X*2)+Fisher[NumFish].Gabarit.X;
   Fisher[NumFish].TochkaNaznach.Y = Random(BasicForm->ClientHeight - Fisher[NumFish].Gabarit.Y*2)+Fisher[NumFish].Gabarit.Y;
//   RaschetStep(NumFish);
  }
 Move(NumFish);
}
//---------------------------------------------------------------------------
void  TBasicForm::Manewr(int NumFish)
{
 // Расстояние до цели по Х
 float tmp = Fisher[NumFish].TochkaNaznach.X - Fisher[NumFish].Koord.X;

 if ((tmp >= 0) && (tmp < MasPanFishL[NumFish]->Width + 3))
 {
  Fisher[NumFish].TochkaNaznach.X -= MasPanFishL[NumFish]->Width;
  Fisher[NumFish].Speed = 3;
 }
}
*///---------------------------------------------------------------------------
void __fastcall TBasicForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 for (int i = 0; i < KolFish; i ++)
  TerminateThread(ThreadFisher[i], NULL);
}
/*/---------------------------------------------------------------------------
int   TBasicForm::ProwerkaPribitia(int NumFish)
{
 int Result = 0;
 float l = AbsLen(Fisher[NumFish].Koord, Fisher[NumFish].TochkaNaznach);
 if (l < Epsilon) Result = 1;
 return Result;
}
*///---------------------------------------------------------------------------
int ProwerkaEdi(TGlPoint2d IshToshka)
{
 int Result = 0;

 TGlPoint2d EdaTochka;

 float Ltmp, L = 1000000;

 for (int i = 0; i < KolEda; i++)
  if (MasPanEda[i]->Visible)
  {
   EdaTochka.X = MasPanEda[i]->Left + 3;
   EdaTochka.Y = MasPanEda[i]->Top  + 3;

   Ltmp = AbsLen(IshToshka, EdaTochka);

   if (L > Ltmp)
   {
    L = Ltmp;
    Result = i + 1;
   }
  }

 return Result;
}
//---------------------------------------------------------------------------
TGlPoint2d   GeneratePut()
{
 TGlPoint2d Result;
 Result.X = Random(BasicForm->ImageFon->Width - 60) + 30;
 Result.Y = Random(BasicForm->ImageFon->Height - 30)+ 15 ;
 return Result;
}
//---------------------------------------------------------------------------
TGlPoint2d GeneratePutNaEdu(TGlPoint2d TekKoord, TGlPoint2d Gabarit, int NumEda)
{
 TGlPoint2d Result;
 Result.X = MasPanEda[NumEda]->Left + 3;
 Result.Y = MasPanEda[NumEda]->Top  + 3;// - Gabarit.Y /2;

 float dX = Result.X - TekKoord.X;

 if (dX > 0) Result.X -= Gabarit.X/2;
 else        Result.X += Gabarit.X/2;

 return Result;
}
//---------------------------------------------------------------------------
int Naprawlenie(float X1, float X2)
{
 int Result = -1;
 float dX = X2 - X1;

 if (dX > 0) Result = 0;
 if (dX < 0) Result = 1;

 return Result;
}
//---------------------------------------------------------------------------
DWORD WINAPI ThreadFish(LPVOID Nom)
{
 DWORD Result = 0;
 int *Tmp;
 Tmp = (int*)Nom;

 int NumFish = *Tmp;
 TFish *Fish = &Fisher[NumFish];

 while (true)
 {
  // если рыба сдохла, то выходим из цикла
  if (!Fish->Live)
  {
   Fish->TochkaNaznach.X = Fish->Koord.X;
   Fish->TochkaNaznach.Y = 0;
   Fish->Deistwie = 6;
   Fish->Naprawlenie = 2;
   Fish->Speed = 6;
   Fish->Step = RaschetStep(Fish->Koord, Fish->TochkaNaznach, Fish->Speed);
   Move(NumFish);
  }
  if ((!Fish->Live) && (Fish->Koord.Y <= 0))
  {
   MasPanFishL[NumFish]->Visible = 0;
   MasPanFishR[NumFish]->Visible = 0;
   MasPanFishW[NumFish]->Visible = 0;
   break;
  }
 // проверяем есть ли еда
  int Eda = ProwerkaEdi(Fish->Koord);
  // если она есть, рыба хочет жрать, то плывем туда
  switch (Fish->Deistwie)
  {
    case 0:{} ;
    break;
    // pliwem.
    case 1:
    {
     if ((Eda) && (Fish->Golod < Golod))
     {
      Fish->Deistwie = 2;
      Fish->Speed    = 3;
     }
     else
      {
       if (AbsLen(Fish->Koord, Fish->TochkaNaznach) < 0.01)
        Fish->TochkaNaznach = GeneratePut();
      }
    };
    break;
    case 2:
    {
     if ((Eda) && (Fish->Golod < Golod))
     {
      Fish->Deistwie = 2;
      Fish->Speed    = 3;
     }
     else
     {
      Fish->Speed = 1;
      Fish->Deistwie = 1;
      Fish->TochkaNaznach = GeneratePut();
     }
    };
    break;
    case 3:{} ;
    break;
    case 4:{} ;
    break;
    case 5:{} ;
    break;
    case 6:{} ;
    break;
  }

       asm{ rdtsc;}


  switch (Fish->Deistwie)
  {
    case 0:{} ;
    break;
    // pliwem
    case 1:
    {
     Fish->Step = RaschetStep(Fish->Koord, Fish->TochkaNaznach, Fish->Speed);
     Fish->Naprawlenie = Naprawlenie(Fish->Koord.X, Fish->TochkaNaznach.X);
     Move(NumFish);
    };
    break;
    case 2:
    {
     Fish->TochkaNaznach = GeneratePutNaEdu(Fish->Koord, Fish->Gabarit, Eda-1);
     Fish->Step = RaschetStep(Fish->Koord, Fish->TochkaNaznach, Fish->Speed);
     Fish->Naprawlenie = Naprawlenie(Fish->Koord.X, MasPanEda[Eda - 1]->Left + 3);
     if (AbsLen(Fish->Koord, Fish->TochkaNaznach) < 0.01)
      {
       MasPanEda[Eda - 1]->Visible = 0;
       Fish->Golod += PishewajaCennostEdi;
      }
     Move(NumFish);
    } ;
    break;
    case 3:{} ;
    break;
    case 4:{} ;
    break;
    case 5:{} ;
    break;
    // wsplitie
    case 6:
    {
    };
    break;
  }

  Fish->Golod--;
  if ((Fish->Golod < Golod/5) && (MasPanFishL[NumFish]->Visible))
  {
   MasPanFishL[NumFish]->Visible = 0;
   MasPanFishL[NumFish]->Visible = 1;
  }
  if ((Fish->Golod < Golod/5) && (MasPanFishR[NumFish]->Visible))
  {
   MasPanFishR[NumFish]->Visible = 0;
   MasPanFishR[NumFish]->Visible = 1;
  }
  if (Fish->Golod <= 0) Fish->Live = 0;
  Sleep(100);
 }
 return Result;
}
//---------------------------------------------------------------------------

void __fastcall TBasicForm::Timer2Timer(TObject *Sender)
{
 for (int NumFish = 0; NumFish < KolFish; NumFish++)
 {
  MasPanFishL[NumFish]->Left = Fisher[NumFish].Koord.X - Fisher[NumFish].Gabarit.X/2;
  MasPanFishL[NumFish]->Top  = Fisher[NumFish].Koord.Y - SmeshFisher[NumFish] - 1;
  MasPanFishR[NumFish]->Left = Fisher[NumFish].Koord.X - Fisher[NumFish].Gabarit.X/2;
  MasPanFishR[NumFish]->Top  = Fisher[NumFish].Koord.Y - SmeshFisher[NumFish] -1 ;
  MasPanFishW[NumFish]->Left = Fisher[NumFish].Koord.X - Fisher[NumFish].Gabarit.X/2;
  MasPanFishW[NumFish]->Top  = Fisher[NumFish].Koord.Y - Fisher[NumFish].Gabarit.Y/2;
 }


}
//---------------------------------------------------------------------------

