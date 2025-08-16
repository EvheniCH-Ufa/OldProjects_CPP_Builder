//---------------------------------------------------------------------------
#ifndef Basic_UnitH
#define Basic_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <IniFiles.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>

#include "Matrix_for_lab.h"
#include "Grafics_Unit.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
//---------------------------------------------------------------------------
class TBasic_Form : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *MM_File;
        TMenuItem *MM_Open;
        TMenuItem *MM_Save;
        TMenuItem *MM_Exit;
        TMenuItem *MM_Insert;
        TMenuItem *MM_El_Postr;
        TMenuItem *MM_Op_EL;
        TMenuItem *MM_Block;
        TMenuItem *MM_Cilindr;
        TMenuItem *MM_Sphere;
        TMenuItem *MM_Konus;
        TMenuItem *MM_Obedin;
        TMenuItem *MM_Wichitanie;
        TMenuItem *Peresech;
        TMenuItem *MM_New;
        TMenuItem *MM_View;
        TMenuItem *MM_Pribliz;
        TMenuItem *MM_Otdalit;
        TMenuItem *MM_Dwigai;
        TMenuItem *MM_RSK;
        TMenuItem *MM_Fill;
        TMenuItem *MM_NotFill;
        TMenuItem *MM_Edit;
        TSaveDialog *SvDlg;
        TOpenDialog *OpnDlg;
        TMenuItem *MM_SaveAs;
        void __fastcall MM_ExitClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall MM_BlockClick(TObject *Sender);
        void __fastcall MM_CilindrClick(TObject *Sender);
        void __fastcall MM_KonusClick(TObject *Sender);
        void __fastcall MM_SphereClick(TObject *Sender);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall MM_DwigaiClick(TObject *Sender);
        void __fastcall MM_RSKClick(TObject *Sender);
        void __fastcall MM_PriblizClick(TObject *Sender);
        void __fastcall MM_OtdalitClick(TObject *Sender);
        void __fastcall FormMouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall MM_FillClick(TObject *Sender);
        void __fastcall MM_NotFillClick(TObject *Sender);
        void __fastcall MM_EditClick(TObject *Sender);
        void __fastcall MM_OpenClick(TObject *Sender);
        void __fastcall MM_SaveClick(TObject *Sender);
        void __fastcall MM_NewClick(TObject *Sender);
        void __fastcall MM_SaveAsClick(TObject *Sender);
private:	// User declarations
  HGLRC ghRC;
  HDC   ghDC;
  void Draw();
  void CreateObjectBegin(unsigned char Status);
public:		// User declarations
        __fastcall TBasic_Form(TComponent* Owner);
 bool   __fastcall SetupPixelFormat(HDC hdc);
  void UstanowkaCreateObject(unsigned char Status);
  void CreateObject(unsigned char Status, int Num);
};
//---------------------------------------------------------------------------
extern PACKAGE TBasic_Form *Basic_Form;
//---------------------------------------------------------------------------
#endif
