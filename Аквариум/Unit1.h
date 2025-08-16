//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
const float Epsilon = 1;
//---------------------------------------------------------------------------
const float KolDeystwiy = 9;
//---------------------------------------------------------------------------
//const float KolFish = 10;
//---------------------------------------------------------------------------
const int OblWid = 100;
//---------------------------------------------------------------------------
struct TEda
{
 int Est;
 int X;
 int Y;
};
//---------------------------------------------------------------------------
struct TGlPoint2d
{
 float X;
 float Y;
};
//---------------------------------------------------------------------------
struct TFish
{
 int          Live;     // 1 - жив, 0 - мертв
 int          Golod;    // 120 - норма, 0 - к смерти
 int          Deistwie; // 0 - виснет, 1 - плывем, 2 - жрать, 3 - маневр 4 - парить мозги соседу, 5 - убегать от того же соседа
 TGlPoint2d   Gabarit;  // razmeri
 int          Obem;  // X*Y/100
 int          Naprawlenie; //0 = -; 1 = +; 2 = top
 float        Speed;
 TGlPoint2d   Step;
 TGlPoint2d   Koord; // текущие координаты
 TGlPoint2d   TochkaNaznach; // Пункт назначения часть 4 с половиной

};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TBasicForm : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TPopupMenu *PopMenu;
        TMenuItem *KormPM;
        TImage *ImageFon;
        TTimer *Timer2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall KormPMClick(TObject *Sender);
        void __fastcall FormConstrainedResize(TObject *Sender,
          int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
        void __fastcall ImageFonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer2Timer(TObject *Sender);
private:	// User declarations
//        void  Draw();
//        void  Grat(int NumFish);
        HRGN  CREATERGNFROMBITMAP(Graphics::TBitmap *rgnBitmap);
 //       void  Pliwem(int NumFish);
 //       void  Manewr(int NumFish);
  //      int   ProwerkaPribitia(int NumFish);
//        int   ProwerkaEdi();
public:		// User declarations
        __fastcall TBasicForm(TComponent* Owner);
};

DWORD WINAPI ThreadFish(LPVOID);
HANDLE ThreadFisher[10];

int        ProwerkaEdiBligaishei(TGlPoint2d IshToshka);
TGlPoint2d GeneratePut();
float      AbsLen(TGlPoint2d T1, TGlPoint2d T2);
TGlPoint2d RaschetStep(TGlPoint2d T1, TGlPoint2d T2, int Speed);
void       Move(int NumFish);

//HANDLE mThreadFisher[10];p
//---------------------------------------------------------------------------
extern PACKAGE TBasicForm *BasicForm;
//---------------------------------------------------------------------------
#endif
