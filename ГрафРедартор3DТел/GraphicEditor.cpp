//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Basic_Unit.cpp", Basic_Form);
USEFORM("Create_Object_Unit.cpp", Frm_Create_Object);
USEFORM("Points_Unit.cpp", Frm_Points);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "ГИС Курсовая работа \"Графический редактор трёхмерных геометрических объектов\"";
                 Application->CreateForm(__classid(TBasic_Form), &Basic_Form);
                 Application->CreateForm(__classid(TFrm_Create_Object), &Frm_Create_Object);
                 Application->CreateForm(__classid(TFrm_Points), &Frm_Points);
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
