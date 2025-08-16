//---------------------------------------------------------------------------
#ifndef Basic_UnitH
#define Basic_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Matrix_for_lab.h"
#include "Grafics_Unit.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
//---------------------------------------------------------------------------
class TBasic_Form : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GrBx_Param;
        TPanel *Pnl_ElipsParam;
        TLabel *Lbl_Elips_c;
        TLabel *Lbl_Elips_b;
        TLabel *Lbl_Elips_a;
        TComboBox *CmbBx_Figura;
        TGroupBox *GroupBox1;
        TLabel *Lbl_X;
        TLabel *Lbl_Y;
        TLabel *Lbl_Z;
        TLabel *Lbl_U;
        TLabel *Lbl_V;
        TPanel *Pnl_ToroidParam;
        TButton *Button1;
        TEdit *Ed_Tor_R;
        TUpDown *UpDn_Tor_R;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Ed_Tor_a;
        TUpDown *UpDn_Tor_a;
        TEdit *Ed_Elips_a;
        TEdit *Ed_Elips_b;
        TEdit *Ed_Elips_c;
        TEdit *Ed_Segment_U;
        TEdit *Ed_Segment_V;
        TEdit *Ed_Rot_X;
        TEdit *Ed_Rot_Y;
        TEdit *Ed_Rot_Z;
        TUpDown *UpDn_Elips_a;
        TUpDown *UpDn_Elips_b;
        TUpDown *UpDn_Elips_c;
        TUpDown *UpDn_Segment_U;
        TUpDown *UpDn_Segment_V;
        TUpDown *UpDn_Rot_Z;
        TUpDown *UpDn_Rot_X;
        TUpDown *UpDn_Rot_Y;
        TPanel *U_V_Pnl;
        TPanel *Rotate_Pnl;
        TLabel *Label7;
        TPanel *Pnl_PositionLight;
        TLabel *Label8;
        TLabel *Lbl_Light_Z;
        TLabel *Lbl_Light_X;
        TLabel *Lbl_Light_Y;
        TEdit *Ed_Light_X;
        TEdit *Ed_Light_Y;
        TEdit *Ed_Light_Z;
        TUpDown *UpDn_Light_Z;
        TUpDown *UpDn_Light_X;
        TUpDown *UpDn_Light_Y;
        TPanel *Pnl_ColorLight;
        TLabel *Label2;
        TLabel *Lbl_ClrLight_B;
        TLabel *Lbl_ClrLight_R;
        TLabel *Lbl_ClrLight_G;
        TEdit *Ed_ClrLight_R;
        TEdit *Ed_ClrLight_G;
        TEdit *Ed_ClrLight_B;
        TUpDown *UpDn_ClrLight_B;
        TUpDown *UpDn_ClrLight_R;
        TUpDown *UpDn_ClrLight_G;
        TPanel *Pnl_ColorLigth_View;
        TPanel *Pnl_ColorBody;
        TLabel *Label3;
        TLabel *Lbl_ClrBody_B;
        TLabel *Lbl_ClrBody_R;
        TLabel *Lbl_ClrBody_G;
        TEdit *Ed_ClrBody_R;
        TEdit *Ed_ClrBody_G;
        TEdit *Ed_ClrBody_B;
        TUpDown *UpDn_ClrBody_B;
        TUpDown *UpDn_ClrBody_R;
        TUpDown *UpDn_ClrBody_G;
        TPanel *Pnl_ColorBody_View;
        TEdit *Ed_Prozr;
        TEdit *Ed_Kd;
        TEdit *Ed_Kl;
        TEdit *Ed_Ks;
        TUpDown *UpDn_Kd;
        TUpDown *UpDn_Proz;
        TUpDown *UpDn_Ks;
        TUpDown *UpDn_Kl;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TEdit *Ed_N;
        TUpDown *UpDn_N;
        TLabel *Label14;
        TOpenPictureDialog *OpenPictureDialog1;
        TCheckBox *ChBx_Texture;
        TRadioGroup *RadioGroup1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CmbBx_FiguraChange(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall UpDn_ClrLight_RClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall UpDn_ClrBody_RClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall UpDn_Tor_RClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall UpDn_Rot_XClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall UpDn_Light_XClick(TObject *Sender,
          TUDBtnType Button);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);
        void __fastcall ChBx_TextureClick(TObject *Sender);
        void __fastcall UpDn_ProzClick(TObject *Sender, TUDBtnType Button);
private:	// User declarations
public:		// User declarations
        __fastcall TBasic_Form(TComponent* Owner);
        void __fastcall Raschet();
};
//---------------------------------------------------------------------------
extern PACKAGE TBasic_Form *Basic_Form;
//---------------------------------------------------------------------------
#endif
