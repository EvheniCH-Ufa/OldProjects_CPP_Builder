//---------------------------------------------------------------------------

#ifndef Create_Object_UnitH
#define Create_Object_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFrm_Create_Object : public TForm
{
__published:	// IDE-managed Components
        TButton *Btn_CrObj_Ok;
        TButton *Btn_CrObj_No;
        TPageControl *PageControl1;
        TTabSheet *TbSht_param;
        TTabSheet *TbSht_color;
        TGroupBox *GrBx_Rasmer;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TCheckBox *ChkBx;
        TEdit *Ed_Rasmer3;
        TEdit *Ed_Rasmer2;
        TEdit *Ed_Rasmer1;
        TComboBox *CmBx_Tela;
        TGroupBox *GrBx_Rotate;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Ed_Rot_X;
        TEdit *Ed_Rot_Z;
        TButton *Btn_Start_Points;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Lbl_VG;
        TLabel *Lbl_VB;
        TLabel *Lbl_VPR;
        TLabel *Lbl_VR;
        TLabel *Label13;
        TLabel *Label14;
        TTrackBar *TrBr_R;
        TTrackBar *TrBr_G;
        TTrackBar *TrBr_B;
        TTrackBar *TrBr_Proz;
        TPanel *Panel1;
        TColorDialog *ColorDialog1;
        TPanel *Panel2;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
   TUpDown *UpDn_Rot_X;
   TUpDown *UpDn_Rot_Z;
   TEdit *Ed_Rot_Y;
   TUpDown *UpDn_Rot_Y;
   TUpDown *UpDown1;
   TUpDown *UpDown2;
   TUpDown *UpDown3;

        void __fastcall Ed_Rasmer1KeyPress(TObject *Sender, char &Key);
        void __fastcall Btn_CrObj_NoClick(TObject *Sender);
        void __fastcall ChkBxClick(TObject *Sender);
        void __fastcall Btn_Start_PointsClick(TObject *Sender);
        void __fastcall Panel1Click(TObject *Sender);
        void __fastcall TrBr_RChange(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
   void __fastcall UpDn_Rot_XClick(TObject *Sender, TUDBtnType Button);
   void __fastcall CmBx_TelaChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrm_Create_Object(TComponent* Owner);
        unsigned char Status; // 0 - блок, 1 - Цилиндр, 2 - конус, 3 - сфера,

};
//---------------------------------------------------------------------------
extern PACKAGE TFrm_Create_Object *Frm_Create_Object;
//---------------------------------------------------------------------------
#endif
