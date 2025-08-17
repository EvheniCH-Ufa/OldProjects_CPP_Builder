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
 int    KolChild;   // кол-во детей
 Sost **Child;      // массив детей
 Sost  *Parent;     // ссылка на родителя
 int    Prawilo;    // точка, по котор получен
 int    CheiHod;    // кто ходил 0 - нолик, 1 - крестик
 int    Pole[9];    //состояние поля на данный момент -1 - 0; 1- X
 int    KolZanat;   //количество занятых клеток из 9
 int    KolPo2_0;   // кол-во по 2 шт 0 после этого хода не блокированных -1 - победа
 int    KolPo2_X;   // кол-во по 2 шт X после этого хода не блокированных -1 - победа

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
        // Возвращает .X - kol-wo 2 po  1(X) = 10 esli 3 po  1(X)
        // Возвращает .Y - kol-wo 2 po -1(0) = 10 esli 3 po -1(0)
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
