//---------------------------------------------------------------------------

#ifndef GOST_UnitH
#define GOST_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TMemo *DO_Memo;
        TSplitter *Splitter1;
        TMemo *Posle_Memo;
        TEdit *Key_Edit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TOpenDialog *OpenDialog1;
        TButton *Open_Btn;
        TButton *Cod_Btn;
        TButton *Recod_Btn;
        void __fastcall Open_BtnClick(TObject *Sender);
        void __fastcall Cod_BtnClick(TObject *Sender);
        void __fastcall Recod_BtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
