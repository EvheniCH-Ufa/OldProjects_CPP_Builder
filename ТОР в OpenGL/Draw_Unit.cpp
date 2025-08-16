//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Draw_Unit.h"
#include "Basic_Unit.h"
#include "Grafics_Unit.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
TDraw_Frm *Draw_Frm;

GLbyte TexW = 64;
GLbyte TexH = 64;
GLubyte Textura[64][64][3];
bool GenSOn = 1;
Graphics::TBitmap *BMP;
//---------------------------------------------------------------------------
__fastcall TDraw_Frm::TDraw_Frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDraw_Frm::FormCreate(TObject *Sender)
{
 ClientHeight = 500;
 ClientWidth = 500;
 // инициализация OpenGl
   ghDC = GetDC(Handle);
   if (!bSetupPixelFormat(ghDC))
      Close();
   ghRC = wglCreateContext(ghDC);
   wglMakeCurrent(ghDC, ghRC);

    glEnable (GL_BLEND);
    glEnable (GL_CULL_FACE);
     glEnable(GL_TEXTURE_2D);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
  glShadeModel (GL_FLAT);
 glClearColor(0.0, 0.0, 0.0, 0.0);

   FormResize(Sender);

   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_DEPTH_TEST);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_NORMALIZE);

     float p[4]={0,0,250,0};//,
//           d[3]={0,0,-250};
   glLightfv(GL_LIGHT0,GL_POSITION,p);
//   glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,d);
 // инициализация OpenGl

 // эффект прилипания
 Top =Basic_Form->Top;
 Left = Basic_Form->Left - Width;

 // вызываем расчет тела
 Basic_Form->Raschet();

 BMP = new Graphics::TBitmap;
}
//---------------------------------------------------------------------------
bool __fastcall TDraw_Frm::bSetupPixelFormat(HDC hdc)
{
    PIXELFORMATDESCRIPTOR pfd, *ppfd;
    int pixelformat;

    ppfd = &pfd;

    ppfd->nSize = sizeof(PIXELFORMATDESCRIPTOR);
    ppfd->nVersion = 1;
    ppfd->dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    ppfd->dwLayerMask = PFD_MAIN_PLANE;
    ppfd->iPixelType = PFD_TYPE_RGBA;
    ppfd->cColorBits = 16;
    ppfd->cDepthBits = 16;

    ppfd->cAccumBits = 0;
    ppfd->cStencilBits = 0;

    if ((pixelformat = ChoosePixelFormat(hdc, ppfd)) == 0)
    {
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
        return FALSE;
    }
    if (SetPixelFormat(hdc, pixelformat, ppfd) == FALSE)
    {
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
        return FALSE;
    }
    return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TDraw_Frm::FormResize(TObject *Sender)
{
glViewport( 0, 0, ClientWidth, ClientHeight );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
//       левой, правой, нижней, верхней, ближней и дальней плоскостей отсечения
   glOrtho(-301, 301,    -301,   301,      -301,    301); //масштабы координатных осей

//параметры камеры: первая тройка - её координаты,
//                  вторая - вектор направления,
//                  третья - направление оси Y.
  gluLookAt(0,-0,-50,  0,0,0,  0,1,0);
  glMatrixMode( GL_MODELVIEW );
}
//---------------------------------------------------------------------------

void __fastcall TDraw_Frm::FormClose(TObject *Sender, TCloseAction &Action)
{
if(ghRC)
  {
    wglMakeCurrent(ghDC,0);
    wglDeleteContext(ghRC);
  }
  if(ghDC)
    ReleaseDC(Handle, ghDC);
}
//---------------------------------------------------------------------------
void TDraw_Frm::Draw()
{
glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  glEnable(GL_POLYGON_STIPPLE);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

 glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

GLfloat PosL_Z, PosL_Y, PosL_X ;

PosL_X = Basic_Form->UpDn_Light_X->Position;
PosL_Y = Basic_Form->UpDn_Light_Y->Position;
PosL_Z = Basic_Form->UpDn_Light_Z->Position;

GLfloat poz[4]={ PosL_X,  PosL_Y,  PosL_Z, 1.0};
//GLfloat dir[3]={-PosL_X, -PosL_Y, -PosL_Z};

//GLfloat Dif_L[4] = {0, 0,0,0};

GLfloat BlickL[4] = {1.0f * ColorLigth_RGB.RGB.R/255,
                     1.0f * ColorLigth_RGB.RGB.G/255,
                     1.0f * ColorLigth_RGB.RGB.B/255,
                     0.0};
//*/GLfloat BlickL[4] = {0, 1.0, 0,1.0};

GLfloat Dif_M[4] = {1.0f * ColorBody_RGB.RGB.R/255,
                    1.0f * ColorBody_RGB.RGB.G/255,
                    1.0f * ColorBody_RGB.RGB.B/255,
                    Basic_Form->UpDn_Proz->Position / 100.0f};

//GLfloat an_l[4] = {90,90,90,0};

//glLightfv(GL_LIGHT0, GL_SPECULAR, BlickL);
//glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, Dif_L);
//glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, an_l);

glMaterialfv(GL_FRONT, GL_SPECULAR, BlickL);
glMaterialfv(GL_FRONT, GL_EMISSION, Dif_M);
glMaterialfv(GL_FRONT, GL_DIFFUSE, Dif_M);
glMaterialfv(GL_FRONT, GL_AMBIENT, Dif_M);
glMaterialf( GL_FRONT, GL_SHININESS, Basic_Form->UpDn_N->Position);


if (Basic_Form->ChBx_Texture->Checked) glEnable(GL_TEXTURE_2D);
else glDisable(GL_TEXTURE_2D);

bool FullTex = 1;
if (Basic_Form->RadioGroup1->ItemIndex == 1) FullTex = 0;

glColor4f(0.0f * ColorBody_RGB.RGB.R/255,
          0.0f * ColorBody_RGB.RGB.G/255,
          0.0f * ColorBody_RGB.RGB.B/255,
          1.0f * Basic_Form->UpDn_Proz->Position/100);



GLfloat S,T;
unsigned int I, J, ii, jj;
for (I = 0; I < Telo.HeigtIsh; I++)
  {
   ii = I + 1;
   if (ii == Telo.HeigtIsh) ii = 0;

   for (J = 0; J < Telo.WidthIsh; J++)
     {
      jj = J + 1;
      if (jj == Telo.WidthIsh) jj = 0;

      glBegin(GL_TRIANGLE_STRIP);

        if (FullTex)
          {
           T = 1.0f * I/Telo.WidthIsh;
           S = 1.0f * J/Telo.HeigtIsh;
           glTexCoord2d (S, T);
          }
        else glTexCoord2d (0.0, 0.0);

        glVertex3f(Telo.PntsTek[I ][J].X,
                   Telo.PntsTek[I ][J].Y,
                   Telo.PntsTek[I ][J].Z);

        if (FullTex)
          {
           T = 1.0f * I/Telo.WidthIsh;
           S = 1.0f * (J+1)/Telo.HeigtIsh;
           glTexCoord2d (S, T);
          }
        else glTexCoord2d (0.0, 1.0);
        glVertex3f(Telo.PntsTek[I ][jj].X,
                   Telo.PntsTek[I ][jj].Y,
                   Telo.PntsTek[I ][jj].Z);


        if (FullTex)
          {
           T = 1.0f * (I+1)/Telo.WidthIsh;
           S = 1.0f * J/Telo.HeigtIsh;
           glTexCoord2d (S, T);
          }
        else glTexCoord2d (1.0, 0.0);

        glVertex3f(Telo.PntsTek[ii][J ].X,
                   Telo.PntsTek[ii][J ].Y,
                   Telo.PntsTek[ii][J ].Z);

        if (FullTex)
          {
           T = 1.0f * (I+1)/Telo.WidthIsh;
           S = 1.0f * (J+1)/Telo.HeigtIsh;
           glTexCoord2d (S, T);
          }
        else glTexCoord2d (1.0, 1.0);

        glVertex3f(Telo.PntsTek[ii][jj].X,
                   Telo.PntsTek[ii][jj].Y,
                   Telo.PntsTek[ii][jj].Z);
      glEnd();
    }
  }

  glLightfv(GL_LIGHT0, GL_POSITION, poz);
//  glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,dir);


 SwapBuffers(ghDC);

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TDraw_Frm::Timer1Timer(TObject *Sender)
{
 Draw();
}
//---------------------------------------------------------------------------
void __fastcall TDraw_Frm::FormPaint(TObject *Sender)
{
 Draw();
}
//---------------------------------------------------------------------------
void TDraw_Frm::Tor(GLint U, GLint V, GLfloat R, GLfloat A, GLenum TypeDraw)
{
  int i, j;
  GLfloat tetta, phi, tetta1, phi1;

  GLfloat p0[3],
          p1[3],
          p2[3],
          p3[3],
          n0[3],
          n1[3],
          n2[3],
          n3[3];

  for (i = 0; i < V; i++)
    {
     tetta  =    i    * 2.0 * Pi/V;
     tetta1 = (i + 1) * 2.0 * Pi/V;

     for (j = 0; j < U; j++)
       {
        phi  =    j    * 2.0 * Pi/U;
        phi1 = (j + 1) * 2.0 * Pi/U;

        p0[0] =  cos(tetta)* (R + A * cos(phi));
        p0[1] = sin(tetta)* (R + A * cos(phi));
        p0[2] = A * sin(phi);

        p1[0] =  cos(tetta1)* (R + A * cos(phi));
        p1[1] = sin(tetta1)* (R + A * cos(phi));
        p1[2] = A * sin(phi);

        p2[0] = cos(tetta1)* (R + A * cos(phi1));
        p2[1] = sin(tetta1)* (R + A * cos(phi1));
        p2[2] = A * sin(phi1);

        p0[0] =  cos(tetta)* (R + A * cos(phi1));
        p0[1] = sin(tetta)* (R + A * cos(phi1));
        p0[2] = A * sin(phi1);

        n0[0] =  cos(tetta)* cos(phi);
        n0[1] = -sin(tetta)* cos(phi);
        n0[2] = sin(phi);

        n1[0] =  cos(tetta1)* cos(phi);
        n1[1] = -sin(tetta1)* cos(phi);
        n1[2] = sin(phi);

        n2[0] =  cos(tetta1)* cos(phi1);
        n2[1] = -sin(tetta1)* cos(phi1);
        n2[2] = sin(phi1);

        n3[0] =  cos(tetta)* cos(phi1);
        n3[1] = -sin(tetta)* cos(phi1);
        n3[2] = sin(phi1);

        glBegin(TypeDraw);
//          glNormal3fv(n0);
          glVertex3fv(p0);

 //         glNormal3fv(n1);
          glVertex3fv(p1);


 //         glNormal3fv(n2);
          glVertex3fv(p2);

  //        glNormal3fv(n3);
          glVertex3fv(p3);



        glEnd();
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TDraw_Frm::Button1Click(TObject *Sender)
{
Draw();
}
//---------------------------------------------------------------------------
void __fastcall TDraw_Frm::LoadTextur(AnsiString FileName)
{
 GLubyte i,j;
 TRGB_Color Pix;

 BMP->LoadFromFile(FileName);
 TexW = BMP->Width;
 TexH = BMP->Height;

 for (i =0; i < 64 ;i++)
   for (j =0; j < 64 ;j++)
     {
      Pix.Color = BMP->Canvas->Pixels[i][j];
      Textura[i][j][0] = Pix.RGB.R;
      Textura[i][j][1] = Pix.RGB.G;
      Textura[i][j][2] = Pix.RGB.B;
     }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 64, 64,     // здесь задается размер текстуры
                 0, GL_RGB, GL_UNSIGNED_BYTE, &Textura);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glEnable(GL_TEXTURE_2D);

    Draw();

}
//---------------------------------------------------------------------------


