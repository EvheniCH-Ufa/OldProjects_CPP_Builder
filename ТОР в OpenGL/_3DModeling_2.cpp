//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Basic_Unit.cpp", Basic_Form);
USEFORM("Draw_Unit.cpp", Draw_Frm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "ГИС Лабораторная работа №1";
                 Application->CreateForm(__classid(TBasic_Form), &Basic_Form);
                 Application->CreateForm(__classid(TDraw_Frm), &Draw_Frm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
