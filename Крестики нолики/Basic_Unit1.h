//---------------------------------------------------------------------------

#ifndef Basic_Unit1H
#define Basic_Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
struct Cell
{
 int X;
 int Y;
};
//---------------------------------------------------------------------------
struct Sost
{
 int    KolChild;   // ���-�� �����
 Sost **Child;      // ������ �����
 Sost  *Parent;     // ������ �� ��������
 int    Prawilo;    // �����, �� ����� �������
 int    CheiHod;    // ��� ����� 0 - �����, 1 - �������
 int    Pole[9];    //��������� ���� �� ������ ������ -1 - 0; 1- X
 int    KolZanat;   //���������� ������� ������ �� 9
 int    KolPo2_0;   // ���-�� �� 2 �� 0 ����� ����� ���� �� ������������� -1 - ������
 int    KolPo2_X;   // ���-�� �� 2 �� X ����� ����� ���� �� ������������� -1 - ������

};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *NewGame_Btn;
        TButton *Komp1_Btn;
        TButton *Exit_Btn;
        TTreeView *TreeView1;
        TLabel *Label1;
        void __fastcall Exit_BtnClick(TObject *Sender);
        void __fastcall NewGame_BtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Komp1_BtnClick(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
        void DrawSetka();
        Sost *WstawkaUsla(int KoordHoda, Sost *Parent, int Hod);
        Cell  ProwerkaNa2(Cell KoordHoda, Sost *Parent, int Hod);
        void  Zapolnenie(Sost *Parent, int Hod, TTreeNode *Par);
        Cell  ProwerkaLines(Sost *TekSos);
        // ���������� .X - kol-wo 2 po  1(X) = 10 esli 3 po  1(X)
        // ���������� .Y - kol-wo 2 po -1(0) = 10 esli 3 po -1(0)
        Sost *Hod(int Koord, int HOD, Sost *Sostoajnie);
        int  HodKompa(int HOD, Sost *Sostoajnie);
        int  ProwerkaHoda(int HOD, Sost *Sostoajnie);
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
