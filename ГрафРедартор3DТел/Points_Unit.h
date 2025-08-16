//---------------------------------------------------------------------------

#ifndef Points_UnitH
#define Points_UnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrm_Points : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GrBx_Rasmer;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Ed_PointsZ;
        TEdit *Ed_PointsY;
        TEdit *Ed_PointsX;
        TButton *Btn_Points_Ok;
        TButton *Btn_Points_No;
   TUpDown *UpDown1;
   TUpDown *UpDown2;
   TUpDown *UpDown3;
        void __fastcall Ed_PointsXKeyPress(TObject *Sender, char &Key);
   void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
private:	// User declarations
public:		// User declarations
        __fastcall TFrm_Points(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrm_Points *Frm_Points;
//---------------------------------------------------------------------------
#endif
