//---------------------------------------------------------------------------

#ifndef RC_5_UnitH
#define RC_5_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Windows.hpp>
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TMemo *Memo1;
        TSplitter *Splitter1;
        TMemo *Memo2;
        TMainMenu *MainMenu1;
        TMenuItem *FileMM;
        TMenuItem *OpenMM;
        TMenuItem *ExitMM;
        TLabel *Label1;
        TLabel *Label3;
        TMemo *Memo4;
        TOpenDialog *OpenDialog1;
        TProgressBar *ProgressBar1;
        TMenuItem *CodMM;
        TMenuItem *CodingMM;
        TMenuItem *RecodingMM;
        TMenuItem *ParamsMM;
        TMenuItem *AboutMM;
        TLabel *Label2;
        void __fastcall OpenMMClick(TObject *Sender);
        void __fastcall ParamsMMClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall AboutMMClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall CodingMMClick(TObject *Sender);
        void __fastcall RecodingMMClick(TObject *Sender);
        void __fastcall ExitMMClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations


public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
