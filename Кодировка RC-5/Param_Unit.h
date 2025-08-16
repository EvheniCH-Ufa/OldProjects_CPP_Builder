//---------------------------------------------------------------------------

#ifndef Param_UnitH
#define Param_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TParam_Frm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TEdit *EdKey;
        TEdit *EdKolRaunds;
        TLabel *LblSizeBloks;
        TLabel *LblKolRaunds;
        TGroupBox *GroupBox2;
        TUpDown *UpDown1;
        TPanel *Panel1;
        TLabel *Label1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TParam_Frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern       char*             Key;
extern       unsigned int*     L;
extern       unsigned int*     S;
extern       unsigned int      C;
extern       unsigned int      R;

const unsigned int      P                = 0xB7E15163;  // число Пи
const unsigned int      Q                = 0x9E3779B9;  // Экспонента

extern PACKAGE TParam_Frm *Param_Frm;
//---------------------------------------------------------------------------
#endif
