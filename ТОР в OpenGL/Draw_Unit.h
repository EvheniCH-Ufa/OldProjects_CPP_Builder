//---------------------------------------------------------------------------
#ifndef Draw_UnitH
#define Draw_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
//---------------------------------------------------------------------------
class TDraw_Frm : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall LoadTextur(AnsiString FileName);

private:	// User declarations
  HGLRC ghRC;
  HDC   ghDC;
  void Draw();

  void Tor(GLint U, GLint V, GLfloat R, GLfloat A, GLenum Type);

public:		// User declarations
        __fastcall TDraw_Frm(TComponent* Owner);
 bool   __fastcall bSetupPixelFormat(HDC hdc);
};
//---------------------------------------------------------------------------
extern PACKAGE TDraw_Frm *Draw_Frm;
//---------------------------------------------------------------------------
#endif
