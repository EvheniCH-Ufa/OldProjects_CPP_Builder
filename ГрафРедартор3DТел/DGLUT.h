//---------------------------------------------------------------------------
#ifndef DGLUTH
#define DGLUTH
//---------------------------------------------------------------------------
#include <ExtCtrls.hpp>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <math.h>
#include "Matrix_for_lab.h"
typedef  GLfloat TGLfloat3v[3];
typedef  int     TInteger3v[3];//---------------------------------------------------------------------------const  GLfloat BoxPoints[6][3] =          {{-1,  0,  0},           { 0,  1,  0},
           { 1,  0,  0},
           { 0, -1,  0},
           { 0,  0,  1},
           { 0,  0, -1}};

const  GLint   BoxFaces[6][4] =          {{0, 1, 2, 3},           {3, 2, 6, 7},
           {7, 6, 5, 4},
           {4, 5, 1, 0},
           {5, 6, 2, 1},
           {7, 4, 0, 3}};

/*
Octahedron data - Данные Восьмигранника :
произведенный восьмигранник центрирован в начале координат и имеет радиус 1.0
*/
const  TGLfloat3v OctData[6] =             {{ 1.0,  0.0,  0.0},              {-1.0,  0.0,  0.0},
              { 0.0,  1.0,  0.0},
              { 0.0, -1.0,  0.0},
              { 0.0,  0.0,  1.0},
              { 0.0,  0.0, -1.0}};

const
  TInteger3v OctIndex[8] =
             {{0, 4, 2},
              {1, 2, 4},
              {0, 3, 4},
              {1, 4, 3},
              {0, 2, 5},
              {1, 5, 2},
              {0, 5, 3},
              {1, 3, 5}};

/*Icosahedron data - Данные Двадцатигранника:Эти числа манипулируемые, чтобы делать двадцатигранник из радиуса 1.0*/const
  float IcoX = 0.525731112119133606;
const
  float IcoZ = 0.850650808352039932;

const
  TGLfloat3v IcoData[12] =
             {{-IcoX,     0,  IcoZ},
              { IcoX,     0,  IcoZ},
              {-IcoX,     0, -IcoZ},
              { IcoX,     0, -IcoZ},
              {    0,  IcoZ,  IcoX},
              {    0,  IcoZ, -IcoX},
              {    0, -IcoZ,  IcoX},
              {    0, -IcoZ, -IcoX},
              { IcoZ,  IcoX,     0},
              {-IcoZ,  IcoX,     0},
              { IcoZ, -IcoX,     0},
              {-IcoZ, -IcoX,     0}};

const
  TInteger3v IcoIndex[20] =
             {{ 0,  4,  1},
              { 0,  9,  4},
              { 9,  5,  4},
              { 4,  5,  8},
              { 4,  8,  1},
              { 8, 10,  1},
              { 8,  3, 10},
              { 5,  3,  8},
              { 5,  2,  3},
              { 2,  7,  3},
              { 7, 10,  3},
              { 7,  6, 10},
              { 7, 11,  6},
              {11,  0,  6},
              { 0,  1,  6},
              { 6,  1, 10},
              { 9,  0, 11},
              { 9, 11,  2},
              { 9,  2,  5},
              { 7,  2, 11}};

  /* Tetrahedron data */
const
  float TetT = 1.73205080756887729;

const
  TGLfloat3v TetData[4] =
             {{ TetT,  TetT,  TetT},
              { TetT, -TetT, -TetT},
              {-TetT,  TetT, -TetT},
              {-TetT, -TetT,  TetT}};

const
  TInteger3v TetIndex[4] =
             {{0, 1, 3},
              {2, 1, 0},
              {3, 2, 0},
              {1, 2, 3}};

// Teapot stuff
/*
   Rim, body, lid, and bottom data must be reflected in x
   and y; handle and spout data across the y axis only.
  Периферия, тело, крышка, и данные основания должна быть
  отражена в x и y; обработайте и данные струи поперек y оси только.
*/

const
  GLint PatchData[10][16] =
        {
//       Rim - Периферия
         {102, 103, 104, 105,   4,   5,   6,   7,
            8,   9,  10,  11,  12,  13,  14,  15},
//         { Body }
         { 12,  13,  14,  15,  16,  17,  18,  19,
           20,  21,  22,  23,  24,  25,  26,  27},
         { 24,  25,  26,  27,  29,  30,  31,  32,
           33,  34,  35,  36,  37,  38,  39,  40},
//          { Lid *}
         { 96,  96,  96,  96,  97,  98,  99, 100,
          101, 101, 101, 101,   0,   1,   2,   3},
         {  0,   1,   2,   3, 106, 107, 108, 109,
          110, 111, 112, 113, 114, 115, 116, 117},
//          { Bottom }
         {118, 118, 118, 118, 124, 122, 119, 121,
          123, 126, 125, 120,  40,  39,  38,  37},
//          { Handle }
         { 41,  42,  43,  44,  45,  46,  47,  48,
           49,  50,  51,  52,  53,  54,  55,  56},
         { 53,  54,  55,  56,  57,  58,  59,  60,
           61,  62,  63,  64,  28,  65,  66,  67},
//          { Spout }
         { 68,  69,  70,  71,  72,  73,  74,  75,
           76,  77,  78,  79,  80,  81,  82,  83},
         { 80,  81,  82,  83,  84,  85,  86,  87,
           88,  89,  90,  91,  92,  93,  94,  95}};

const
  GLfloat TeaData[127][3] =
          {{   0.2,       0,     2.7},
           {   0.2,  -0.112,     2.7},
           { 0.112,    -0.2,     2.7},
           {     0,    -0.2,     2.7},
           {1.3375,       0, 2.53125},
           {1.3375,  -0.749, 2.53125},
           { 0.749, -1.3375, 2.53125},
           {     0, -1.3375, 2.53125},
           {1.4375,       0, 2.53125},
           {1.4375,  -0.805, 2.53125},
           { 0.805, -1.4375, 2.53125},
           {     0, -1.4375, 2.53125},
           {   1.5,       0,     2.4},
           {   1.5,   -0.84,     2.4},
           {  0.84,    -1.5,     2.4},
           {     0,    -1.5,     2.4},
           {  1.75,       0,   1.875},
           {  1.75,   -0.98,   1.875},
           {  0.98,   -1.75,   1.875},
           {     0,   -1.75,   1.875},
           {     2,       0,    1.35},
           {     2,   -1.12,    1.35},
           {  1.12,      -2,    1.35},
           {     0,      -2,    1.35},
           {     2,       0,     0.9},
           {     2,   -1.12,     0.9},
           {  1.12,      -2,     0.9},
           {     0,      -2,     0.9},
           {    -2,       0,     0.9},
           {     2,       0,    0.45},
           {     2,   -1.12,    0.45},
           {  1.12,      -2,    0.45},
           {     0,      -2,    0.45},
           {   1.5,       0,   0.225},
           {   1.5,   -0.84,   0.225},
           {  0.84,    -1.5,   0.225},
           {     0,    -1.5,   0.225},
           {   1.5,       0,    0.15},
           {   1.5,   -0.84,    0.15},
           {  0.84,    -1.5,    0.15},
           {     0,    -1.5,    0.15},
           {  -1.6,       0,   2.025},
           {  -1.6,    -0.3,   2.025},
           {  -1.5,    -0.3,    2.25},
           {  -1.5,       0,    2.25},
           {  -2.3,       0,   2.025},
           {  -2.3,    -0.3,   2.025},
           {  -2.5,    -0.3,    2.25},
           {  -2.5,       0,    2.25},
           {  -2.7,       0,   2.025},
           {  -2.7,    -0.3,   2.025},
           {    -3,    -0.3,    2.25},
           {    -3,       0,    2.25},
           {  -2.7,       0,     1.8},
           {  -2.7,    -0.3,     1.8},
           {    -3,    -0.3,     1.8},
           {    -3,       0,     1.8},
           {  -2.7,       0,   1.575},
           {  -2.7,    -0.3,   1.575},
           {    -3,    -0.3,    1.35},
           {    -3,       0,    1.35},
           {  -2.5,       0,   1.125},
           {  -2.5,    -0.3,   1.125},
           { -2.65,    -0.3,  0.9375},
           { -2.65,       0,  0.9375},
           {    -2,    -0.3,     0.9},
           {  -1.9,    -0.3,     0.6},
           {  -1.9,       0,     0.6},
           {   1.7,       0,   1.425},
           {   1.7,   -0.66,   1.425},
           {   1.7,   -0.66,     0.6},
           {   1.7,       0,     0.6},
           {   2.6,       0,   1.425},
           {   2.6,   -0.66,   1.425},
           {   3.1,   -0.66,   0.825},
           {   3.1,       0,   0.825},
           {   2.3,       0,     2.1},
           {   2.3,   -0.25,     2.1},
           {   2.4,   -0.25,   2.025},
           {   2.4,       0,   2.025},
           {   2.7,       0,     2.4},
           {   2.7,   -0.25,     2.4},
           {   3.3,   -0.25,     2.4},
           {   3.3,       0,     2.4},
           {   2.8,       0,   2.475},
           {   2.8,   -0.25,   2.475},
           { 3.525,   -0.25, 2.49375},
           { 3.525,       0, 2.49375},
           {   2.9,       0,   2.475},
           {   2.9,   -0.15,   2.475},
           {  3.45,   -0.15,  2.5125},
           {  3.45,       0,  2.5125},
           {   2.8,       0,     2.4},
           {   2.8,   -0.15,     2.4},
           {   3.2,   -0.15,     2.4},
           {   3.2,       0,     2.4},
           {     0,       0,    3.15},
           {   0.8,       0,    3.15},
           {   0.8,   -0.45,    3.15},
           {  0.45,    -0.8,    3.15},
           {     0,    -0.8,    3.15},
           {     0,       0,    2.85},
           {   1.4,       0,     2.4},
           {   1.4,  -0.784,     2.4},
           { 0.784,    -1.4,     2.4},
           {     0,    -1.4,     2.4},
           {   0.4,       0,    2.55},
           {   0.4,  -0.224,    2.55},
           { 0.224,    -0.4,    2.55},
           {     0,    -0.4,    2.55},
           {   1.3,       0,    2.55},
           {   1.3,  -0.728,    2.55},
           { 0.728,    -1.3,    2.55},
           {     0,    -1.3,    2.55},
           {   1.3,       0,     2.4},
           {   1.3,  -0.728,     2.4},
           { 0.728,    -1.3,     2.4},
           {     0,    -1.3,     2.4},
           {     0,       0,       0},
           { 1.425,  -0.798,       0},
           {   1.5,       0,   0.075},
           { 1.425,       0,       0},
           { 0.798,  -1.425,       0},
           {     0,    -1.5,   0.075},
           {     0,  -1.425,       0},
           {   1.5,   -0.84,   0.075},
           {  0.84,    -1.5,   0.075}};

const
  GLfloat TeaTex[2][2][2] =
          {{{0, 0}, {1, 0}},
           {{0, 1}, {1, 1}}};

const
  GLfloat PI = 3.1415926535897932384626433832795;
//---------------------------------------------------------------------------

  GLfloat dodec[20][3];
  GLUquadricObj *quadObj;

//---------------------------------------------------------------------------//procedure DrawBox(Size : GLfloat; DrawType : GLenum);//---------------------------------------------------------------------------void DrawBox(GLfloat Size, GLenum DrawType){  GLfloat V[8][3];  GLint I;  GLfloat HalfSize = Size / 2;

  V[0][0] = -HalfSize;
  V[1][0] = -HalfSize;
  V[2][0] = -HalfSize;  V[3][0] = -HalfSize;  V[4][0] =  HalfSize;  V[5][0] =  HalfSize;  V[6][0] =  HalfSize;  V[7][0] =  HalfSize;  V[0][1] = -HalfSize;  V[1][1] = -HalfSize;  V[4][1] = -HalfSize;  V[5][1] = -HalfSize;  V[2][1] =  HalfSize;  V[3][1] =  HalfSize;  V[6][1] =  HalfSize;  V[7][1] =  HalfSize;  V[0][2] = -HalfSize;  V[3][2] = -HalfSize;  V[4][2] = -HalfSize;  V[7][2] = -HalfSize;  V[1][2] =  HalfSize;  V[2][2] =  HalfSize;  V[5][2] =  HalfSize;  V[6][2] =  HalfSize;  for (I = 0;I <= 5; I++)  {    glBegin(DrawType);      glNormal3fv(BoxPoints[I]);      glVertex3fv(V[BoxFaces[I][0]]);      glVertex3fv(V[BoxFaces[I][1]]);      glVertex3fv(V[BoxFaces[I][2]]);      glVertex3fv(V[BoxFaces[I][3]]);    glEnd();  }}// DrawBox//---------------------------------------------------------------------------//procedure glutWireCube(Size : GLDouble);//---------------------------------------------------------------------------void glutWireCube(GLfloat Size){  DrawBox(Size, GL_LINE_LOOP);}//glutWireCube//---------------------------------------------------------------------------//procedure glutSolidCube(Size : GLDouble);//---------------------------------------------------------------------------void glutSolidCube(GLfloat Size){  DrawBox(Size, GL_QUADS);}//glutSolidCube/*/---------------------------------------------------------------------------
procedure glutWireSphere(
  Radius : GLdouble;
  Slices : GLint;
  Stacks : GLint);
*///---------------------------------------------------------------------------
void glutWireSphere(GLfloat Radius, GLint Slices, GLint Stacks)
{  if (quadObj == 0)     quadObj = gluNewQuadric();  gluQuadricDrawStyle(quadObj, GLU_LINE);  gluQuadricNormals(quadObj, GLU_SMOOTH);  gluSphere(quadObj, Radius, Slices, Stacks);}//glutWireSphere
/*/---------------------------------------------------------------------------
procedure glutSolidSphere(
  Radius : GLdouble;
  Slices : GLint;
  Stacks : GLint);
*///---------------------------------------------------------------------------
void glutSolidSphere(GLfloat Radius, GLint Slices, GLint Stacks)
{  if (quadObj == 0)     quadObj = gluNewQuadric();  gluQuadricDrawStyle(quadObj, GLU_FILL);  gluQuadricNormals(quadObj, GLU_SMOOTH);  gluSphere(quadObj, Radius, Slices, Stacks);}//glutSolidSphere
/*/---------------------------------------------------------------------------
procedure glutWireCone(
  Base : GLdouble;
  Height : GLdouble;
  Slices : GLint;
  Stacks : GLint);
*///---------------------------------------------------------------------------
void glutWireCone(GLfloat Base, GLfloat Height, GLint Slices, GLint Stacks)
{  if (quadObj == 0)     quadObj = gluNewQuadric();  gluQuadricDrawStyle(quadObj, GLU_LINE);  gluQuadricNormals(quadObj, GLU_SMOOTH);  gluCylinder(quadObj, Base, 0.0, Height, Slices, Stacks);}//glutWireCone
/*/---------------------------------------------------------------------------
procedure glutSolidCone(
  Base : GLdouble;  Height : GLdouble;
  Slices : GLint;  Stacks : GLint);
*///---------------------------------------------------------------------------
void glutSolidCone(GLfloat Base, GLfloat Height, GLint Slices, GLint Stacks)
{  if (quadObj == 0)     quadObj = gluNewQuadric();  gluQuadricDrawStyle(quadObj, GLU_FILL);  gluQuadricNormals(quadObj, GLU_SMOOTH);  gluCylinder(quadObj, Base, 0.0, Height, Slices, Stacks);}//glutSolidCone
/*/---------------------------------------------------------------------------
procedure Doughnut(
  inr : GLfloat;  outR : GLfloat;  nsides : GLint;  rings : GLint;  DrawType :GLenum);*///---------------------------------------------------------------------------
void Doughnut(GLfloat inr, GLfloat outR, GLint nsides, GLint rings, GLenum DrawType)
{  int i, j;  GLfloat theta, phi, theta1, phi1;  GLfloat p0[3], p1[3], p2[3], p3[3], n0[3], n1[3], n2[3], n3[3];  for (i = 0; i < rings; i++)    {     theta  = i *2.0 * PI / rings;     theta1 = (i + 1) * 2.0 * PI / rings;     for (j = 0; j < nsides; j++)       {        phi  = j *2.0 * PI / nsides;        phi1 = (j + 1) * 2.0 * PI / nsides;
	p0[0] = cos(theta) * (outR + inr * cos(phi));
        p0[1] = -sin(theta) * (outR + inr * cos(phi));        p0[2] = inr * sin(phi);
	p1[0] = cos(theta1) * (outR + inr * cos(phi));
        p1[1] = -sin(theta1) * (outR + inr * cos(phi));        p1[2] = inr * sin(phi);
        p2[0] = cos(theta1) * (outR + inr * cos(phi1));
        p2[1] = -sin(theta1) * (outR + inr * cos(phi1));        p2[2] = inr * sin(phi1);
        p3[0] = cos(theta) * (outR + inr * cos(phi1));        p3[1] = -sin(theta) * (outR + inr * cos(phi1));        p3[2] = inr * sin(phi1);        n0[0] = cos(theta) * (cos(phi));        n0[1] = -sin(theta) * (cos(phi));        n0[2] = sin(phi);        n1[0] = cos(theta1) * (cos(phi));        n1[1] = -sin(theta1) * (cos(phi));        n1[2] = sin(phi);        n2[0] = cos(theta1) * (cos(phi1));        n2[1] = -sin(theta1) * (cos(phi1));        n2[2] = sin(phi1);        n3[0] = cos(theta) * (cos(phi1));        n3[1] = -sin(theta) * (cos(phi1));        n3[2] = sin(phi1);        glBegin(DrawType);          glNormal3fv(n3);          glVertex3fv(p3);          glNormal3fv(n2);          glVertex3fv(p2);          glNormal3fv(n1);          glVertex3fv(p1);          glNormal3fv(n0);          glVertex3fv(p0);        glEnd();       }    }}//Doughnut
/*/---------------------------------------------------------------------------
procedure glutWireTorus(
  innerRadius : GLdouble;  outerRadius :GLdouble;
  nsides : GLint;
  rings : GLint);
*///---------------------------------------------------------------------------
void glutWireTorus(GLfloat innerRadius, GLfloat outerRadius, GLint nsides, GLint rings)
{  Doughnut(innerRadius, outerRadius, nsides, rings, GL_LINE_LOOP);}//glutWireTorus/*/---------------------------------------------------------------------------
procedure glutSolidTorus(
  innerRadius : GLdouble;  outerRadius :GLdouble;
  nsides : GLint;
  rings : GLint);
*///---------------------------------------------------------------------------
void glutSolidTorus(GLfloat innerRadius, GLfloat outerRadius, GLint nsides, GLint rings)
{  Doughnut(innerRadius, outerRadius, nsides, rings, GL_QUADS);}//glutSolidTorus
//Вообще полезный материал
/*/---------------------------------------------------------------------------
procedure Diff3(
  a0, a1, a2, b0, b1, b2 : GLfloat;  var c : array of GLfloat);*///---------------------------------------------------------------------------
void Diff3(GLfloat a0, GLfloat a1, GLfloat a2, GLfloat b0, GLfloat b1, GLfloat b2, TGLfloat3v c)
{  c[0] = a0 - b0;  c[1] = a1 - b1;  c[2] = a2 - b2;}//Diff3
//Вообще полезный материал
/*/---------------------------------------------------------------------------
procedure CrossProd(
  v1, v2 : array of GLfloat;  var prod : array of GLfloat);*///---------------------------------------------------------------------------
void CrossProd(TGLfloat3v v1, TGLfloat3v v2, TGLfloat3v prod)
{  prod[0] = v1[1] * v2[2] - v2[1] * v1[2];  prod[1] = v1[2] * v2[0] - v2[2] * v1[0];
  prod[2] = v1[0] * v2[1] - v2[0] * v1[1];
}//CrossProd

//Вообще полезный материал
/*/---------------------------------------------------------------------------
procedure Normalize(var v : array of GLfloat);
*///---------------------------------------------------------------------------
void Normalize(TGLfloat3v v)
{  GLfloat d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);  d = 1 / d;  v[0] = v[0] * d;
  v[1] = v[1] * d;
  v[2] = v[2] * d;
}//Normalize
/*/---------------------------------------------------------------------------
procedure Pentagon(a, b, c, d, e : integer; shadeType : GLenum);
*///---------------------------------------------------------------------------
void Pentagon(int a, int b, int c, int d, int e, GLenum ShadeType)
{  GLfloat n0[3], d1[3], d2[3];  Diff3(dodec[a][0], dodec[a][1], dodec[1][2],
        dodec[b][0], dodec[b][1], dodec[b][2], d1);
  Diff3(dodec[b][0], dodec[b][1], dodec[b][2],
        dodec[c][0], dodec[c][1], dodec[c][2], d2);
  CrossProd(d1, d2, n0);
  Normalize(n0);

  glBegin(ShadeType);
    glNormal3fv(n0);
    glVertex3fv(dodec[a]);
    glVertex3fv(dodec[b]);
    glVertex3fv(dodec[c]);
    glVertex3fv(dodec[d]);
    glVertex3fv(dodec[e]);
  glEnd();
}//Pentagon

/*/---------------------------------------------------------------------------
procedure Dodecahedron(DrawType : GLenum);
*///---------------------------------------------------------------------------
void Dodecahedron(GLenum DrawType)
{
  Pentagon( 0,  1,  9, 16,  5, DrawType);
  Pentagon( 1,  0,  3, 18,  7, DrawType);
  Pentagon( 1,  7, 11, 10,  9, DrawType);
  Pentagon(11,  7, 18, 19,  6, DrawType);
  Pentagon( 8, 17, 16,  9, 10, DrawType);
  Pentagon( 2, 14, 15,  6, 19, DrawType);
  Pentagon( 2, 13, 12,  4, 14, DrawType);
  Pentagon( 2, 19, 18,  3, 13, DrawType);
  Pentagon( 3,  0,  5, 12, 13, DrawType);
  Pentagon( 6, 15,  8, 10, 11, DrawType);
  Pentagon( 4, 17,  8, 15, 14, DrawType);
  Pentagon( 4, 12,  5, 16, 17, DrawType);
}//Dodecahedron

/*/---------------------------------------------------------------------------
procedure glutWireDodecahedron;
*///---------------------------------------------------------------------------
void glutWireDodecahedron()
{
  Dodecahedron(GL_LINE_LOOP);
}//glutWireDodecahedron

/*/---------------------------------------------------------------------------
procedure glutSolidDodecahedron;
*///---------------------------------------------------------------------------
void glutSolidDodecahedron()
{
  Dodecahedron(GL_TRIANGLE_FAN);
}//glutSolidDodecahedron

/*/---------------------------------------------------------------------------
procedure RecordItem(n1, n2, n3 :  array of GLfloat; ShadeType : GLenum);
*///---------------------------------------------------------------------------
void RecordItem(TGLfloat3v n1, TGLfloat3v n2, TGLfloat3v n3, GLenum ShadeType)
{  TGLfloat3v q0, q1;  Diff3(n1[0], n1[1], n1[2], n2[0], n2[1], n2[2], q0);  Diff3(n2[0], n2[1], n2[2], n3[0], n3[1], n3[2], q1);
  CrossProd(q0, q1, q1);
  Normalize(q1);

  glBegin(ShadeType);
    glNormal3fv(q1);
    glVertex3fv(n1);
    glVertex3fv(n2);
    glVertex3fv(n3);
  glEnd;
}//RecordItem

/*/---------------------------------------------------------------------------
procedure SubDivide(
  v0, v1, v2 : array of GLfloat;
  ShadeType : GLenum);
*///---------------------------------------------------------------------------
void SubDivide(TGLfloat3v v0, TGLfloat3v v1, TGLfloat3v v2, GLenum ShadeType)
{
  int Depth, i, j, k, n;
  TGLfloat3v w0, w1, w2;
  GLfloat l;

  Depth = 1;

  for (i = 0; i < Depth; i++)
  {
    j = 0;

    while (i + j < Depth)
     {
      k = Depth - i - j;

      for (n =0; n < 3; n++)
       {
        w0[n] = (i * v0[n] + j * v1[n] + k * v2[n]) / Depth;
        w1[n] = ((i + 1) * v0[n] + j * v1[n] + (k - 1) * v2[n])/ Depth;
        w2[n] = (i * v0[n] + (j + 1) * v1[n] + (k - 1) * v2[n])/ Depth;
       }

      l = sqrt(w0[0] * w0[0] + w0[1] * w0[1] + w0[2] * w0[2]);
      w0[0] = w0[0] / l;
      w0[1] = w0[1] / l;
      w0[2] = w0[2] / l;

      l = sqrt(w1[0] * w1[0] + w1[1] * w1[1] + w1[2] * w1[2]);
      w1[0] = w1[0] / l;
      w1[1] = w1[1] / l;
      w1[2] = w1[2] / l;

      l = sqrt(w2[0] * w2[0] + w2[1] * w2[1] + w2[2] * w2[2]);
      w2[0] = w2[0] / l;
      w2[1] = w2[1] / l;
      w2[2] = w2[2] / l;

      RecordItem(w1, w0, w2, ShadeType);
      j++;
     }
  }
}//SubDivide

/*/---------------------------------------------------------------------------
procedure DrawTriangle(
  I : Integer;
  Data : Array of TGLfloat3v;
  NDX : Array of TInteger3v;
  ShadeType : GLenum);
*///---------------------------------------------------------------------------
void DrawTriangle(int i, const TGLfloat3v Data[6], const TInteger3v NDX[8], GLenum ShadeType)
{
  TGLfloat3v X0, X1, X2;
//  X0[0] = Data[NDX[i][0]][0];
 // X0[1] = Data[NDX[i][0]][1];
 // X0[2] = Data[NDX[i][0]][2];

  *X0 = *Data[NDX[i][0]];
  *X1 = *Data[NDX[i][1]];
  *X2 = *Data[NDX[i][2]];
  SubDivide(X0, X1, X2, ShadeType);
}//DrawTriangle

/*/---------------------------------------------------------------------------
procedure Octaheadron(ShadeType : GLenum);
*///---------------------------------------------------------------------------
void Octaheadron(GLenum ShadeType)
{
 int I;

 for (I = 0; I < 8; I++)
    DrawTriangle(I, OctData, OctIndex, ShadeType);
}//Octaheadron

/*/---------------------------------------------------------------------------
procedure glutWireOctaheadron;
*///---------------------------------------------------------------------------
void glutWireOctaheadron()
{
  Octaheadron(GL_LINE_LOOP);
}//glutWireOctaheadron

/*/---------------------------------------------------------------------------
procedure glutSolidOctaheadron;
*///---------------------------------------------------------------------------
void glutSolidOctaheadron()
{
  Octaheadron(GL_TRIANGLES);
}//glutSolidOctaheadron

/*/---------------------------------------------------------------------------procedure Icosahedron(ShadeType : GLenum);
*///---------------------------------------------------------------------------
void Icosahedron(GLenum ShadeType){
  int I;

  for (I = 0; I < 20; I++)
    DrawTriangle(I, IcoData, IcoIndex, ShadeType);
}//Icosahedron
/*/---------------------------------------------------------------------------procedure glutWireIcosahedron;
*///---------------------------------------------------------------------------
void glutWireIcosahedron(){  Icosahedron(GL_LINE_LOOP);}//glutWireIcosahedron/*/---------------------------------------------------------------------------procedure glutSolidIcosahedron;
*///---------------------------------------------------------------------------
void glutSolidIcosahedron(){
  Icosahedron(GL_TRIANGLES);
}//glutSolidIcosahedron
/*/---------------------------------------------------------------------------procedure Tetrahedron(ShadeType : GLenum);
*///---------------------------------------------------------------------------
void Tetrahedron(GLenum ShadeType){
  int I;

  for (I = 0; I < 4; I++)
    DrawTriangle(I, TetData, TetIndex, ShadeType);
}//Tetrahedron
/*/---------------------------------------------------------------------------procedure glutWireTetrahedron;
*///---------------------------------------------------------------------------
void glutWireTetrahedron(){  Tetrahedron(GL_LINE_LOOP);}//glutWireTetrahedron
/*/---------------------------------------------------------------------------procedure glutSolidTetrahedron;
*///---------------------------------------------------------------------------
void glutSolidTetrahedron(){  Tetrahedron(GL_TRIANGLES);
}//glutSolidTetrahedron
//         Материал Заварного чайника { Teapot stuff }/*/---------------------------------------------------------------------------procedure Teapot(Grid : GLint; Scale : GLdouble; ShadeType : GLenum);
*///---------------------------------------------------------------------------
void Teapot(GLint Grid, GLdouble Scale, GLenum ShadeType){  GLfloat P[4][4][3], Q[4][4][3], R[4][4][3], S[4][4][3];  GLint I, J, K, L;
  glPushAttrib(GL_ENABLE_BIT | GL_EVAL_BIT);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_MAP2_VERTEX_3);
  glEnable(GL_MAP2_TEXTURE_COORD_2);
  glPushMatrix;
    glRotatef(270.0, 1.0, 0.0, 0.0);
    glScalef(0.5 * Scale, 0.5 * Scale, 0.5 * Scale);
    glTranslatef(0.0, 0.0, -1.5);
    for (I = 0; I < 10; I++)
      {
       for (J = 0; J < 4; J++)
         for (K = 0; K < 4; K++)
           for (L = 0; L < 3; L++)
             {
              P[J][K][L] = TeaData[PatchData[I][J * 4 +      K]][L];
              Q[J][K][L] = TeaData[PatchData[I][J * 4 + (3 - K)]][L];
              if (L == 1)
                Q[J][K][L] = -Q[J][K][L];
              if (I < 6)
                {
                 R[J][K][L] = TeaData[PatchData[I][J * 4 + (3 - K)]][L];
                 if(L == 0)
                   R[J][K][L] = -R[J][K][L];
                 S[J][K][L] = TeaData[PatchData[I][J * 4 + K]][L];
                 if (L == 0)
                   S[J][K][L] = -S[J][K][L];
                 if (L == 1)
                   S[J][K][L] = -S[J][K][L];
                }
             }
      glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2, 0, 1, 4, 2, TeaTex[0][0]);//????????
      glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, P[0][0]);           //????????
      glMapGrid2f(Grid, 0.0, 1.0, Grid, 0.0, 1.0);
      glEvalMesh2(ShadeType, 0, Grid, 0, Grid);
      glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, Q[0][0]);           //????????
      glEvalMesh2(ShadeType, 0, Grid, 0, Grid);
      if (I < 6)
        {
         glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, R[0][0]);        //????????
         glEvalMesh2(ShadeType, 0, Grid, 0, Grid);
         glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, S[0][0]);        //????????
         glEvalMesh2(ShadeType, 0, Grid, 0, Grid);
        }
    }
  glPopMatrix;
  glPopAttrib;
}// Teapot
/*/---------------------------------------------------------------------------procedure glutWireTeapot(Scale : GLdouble);
*///---------------------------------------------------------------------------
void glutWireTeapot(GLdouble Scale){
  Teapot(10, Scale, GL_LINE);
}//glutWireTeapot
/*/---------------------------------------------------------------------------procedure glutSolidTeapot(Scale : GLdouble);
*///---------------------------------------------------------------------------
void glutSolidTeapot(GLdouble Scale){
  Teapot(14, Scale, GL_FILL);
}//glutSolidTeapot
/*/---------------------------------------------------------------------------
procedure initDodecahedron;
*///---------------------------------------------------------------------------
void initDodecahedron()
{
  GLfloat alpha, beta;
  alpha = sqrt(2.0 / (3.0 + sqrt(5.0)));
  beta  = 1.0 + sqrt(6.0 / (3.0 + sqrt(5.0)) - 2.0 + 2.0 * sqrt(2.0 / (3.0 + sqrt(5.0))));

  dodec[ 0][0] = -alpha;  dodec[ 0][1] =      0; dodec[ 0][2] =   beta;
  dodec[ 1][0] =  alpha;  dodec[ 1][1] =      0; dodec[ 1][2] =   beta;
  dodec[ 2][0] =     -1;  dodec[ 2][1] =     -1; dodec[ 2][2] =     -1;
  dodec[ 3][0] =     -1;  dodec[ 3][1] =     -1; dodec[ 3][2] =      1;
  dodec[ 4][0] =     -1;  dodec[ 4][1] =      1; dodec[ 4][2] =     -1;
  dodec[ 5][0] =     -1;  dodec[ 5][1] =      1; dodec[ 5][2] =      1;
  dodec[ 6][0] =      1;  dodec[ 6][1] =     -1; dodec[ 6][2] =     -1;
  dodec[ 7][0] =      1;  dodec[ 7][1] =     -1; dodec[ 7][2] =      1;
  dodec[ 8][0] =      1;  dodec[ 8][1] =      1; dodec[ 8][2] =     -1;
  dodec[ 9][0] =      1;  dodec[ 9][1] =      1; dodec[ 9][2] =      1;
  dodec[10][0] =   beta;  dodec[10][1] =  alpha; dodec[10][2] =      0;
  dodec[11][0] =   beta;  dodec[11][1] = -alpha; dodec[11][2] =      0;
  dodec[12][0] =  -beta;  dodec[12][1] =  alpha; dodec[12][2] =      0;
  dodec[13][0] =  -beta;  dodec[13][1] = -alpha; dodec[13][2] =      0;
  dodec[14][0] = -alpha;  dodec[14][1] =      0; dodec[14][2] =  -beta;
  dodec[15][0] =  alpha;  dodec[15][1] =      0; dodec[15][2] =  -beta;
  dodec[16][0] =      0;  dodec[16][1] =   beta; dodec[16][2] =  alpha;
  dodec[17][0] =      0;  dodec[17][1] =   beta; dodec[17][2] = -alpha;
  dodec[18][0] =      0;  dodec[18][1] =  -beta; dodec[18][2] =  alpha;
  dodec[19][0] =      0;  dodec[19][1] =  -beta; dodec[19][2] = -alpha;
}//initDodecaheadron//---------------------------------------------------------------------------void CreateBlock( float Length, float Width, float Heigth,
                  float AnX, float AnY, float AnZ,
                  TVector3D StartPt, GLenum DrawType)
{
 TGLfloat3v P[8]; // A, B, C, D, A1, B1, C1, D1;
 TGLfloat3v N[6]; // normali

 P[0][0] = 0;
 P[0][1] = 0;
 P[0][2] = 0;

 P[1][0] = 0;
 P[1][1] = 0;
 P[1][2] = Width;

 P[2][0] = 0;
 P[2][1] = Heigth;
 P[2][2] = Width;

 P[3][0] = 0;
 P[3][1] = Heigth;
 P[3][2] = 0;

 P[4][0] = Length;
 P[4][1] = 0;
 P[4][2] = 0;

 P[5][0] = Length;
 P[5][1] = 0;
 P[5][2] = Width;

 P[6][0] = Length;
 P[6][1] = Heigth;
 P[6][2] = Width;

 P[7][0] = Length;
 P[7][1] = Heigth;
 P[7][2] = 0;

 N[0][0] = -1;
 N[0][1] = 0;
 N[0][2] = 0;

 N[1][0] = 0;
 N[1][1] = 1;
 N[1][2] = 0;

 N[2][0] = 1;
 N[2][1] = 0;
 N[2][2] = 0;

 N[3][0] = 0;
 N[3][1] = -1;
 N[3][2] = 0;

 N[4][0] = 0;
 N[4][1] = 0;
 N[4][2] = 1;

 N[0][0] = 0;
 N[0][1] = 0;
 N[0][2] = -1;

  TMatrix_4X4 RotX;
  TMatrix_4X4 RotY;
  TMatrix_4X4 RotZ;
  TMatrix_4X4 Rot;


  RotX = Rot.RotateX(Pi * AnX /180);
  RotY = Rot.RotateY(Pi * AnY /180);
  RotZ = Rot.RotateZ(Pi * AnZ /180);

  Rot = RotX.Mull(RotY);
  Rot = RotZ.Mull(Rot);

  unsigned int i;
  for (i = 0; i < 8; i++)
    {
     Rot.Mull(P[i]);
     P[i][0] += StartPt.X;
     P[i][1] += StartPt.Y;
     P[i][2] += StartPt.Z;
    }

  for (i = 0; i < 6; i++)
     Rot.Mull(N[i]);

  glShadeModel(GL_FLAT);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

  for (i = 0; i < 6; i++)
  {
   glBegin(DrawType);
 //     glNormal3fv(N[i]);
      glVertex3fv(P[BoxFaces[i][0]]);
      glVertex3fv(P[BoxFaces[i][1]]);      glVertex3fv(P[BoxFaces[i][2]]);      glVertex3fv(P[BoxFaces[i][3]]);   glEnd();  }
};

//---------------------------------------------------------------------------
void MglutWireBlock( float Length, float Width, float Heigth,
                    float AnX, float AnY, float AnZ,
                    TVector3D StartPt)
{ CreateBlock(Length, Width, Heigth,             AnX, AnY, AnZ,
             StartPt, GL_LINE_LOOP);
}//glutWireBlock//---------------------------------------------------------------------------
void MglutSolidBlock( float Length, float Width, float Heigth,
                     float AnX, float AnY, float AnZ,
                     TVector3D StartPt)
{ CreateBlock(Length, Width, Heigth,             AnX, AnY, AnZ,
             StartPt, GL_QUADS);
}//glutWireBlock//---------------------------------------------------------------------------
void CreateCilindrAll(float RBttm,       // Радиус нижнего основания
                      float RTop,        // Радиус верхнего основания
                      float Heigth,      // Высота
                      float AnX,         // Базовый угол поворота Х
                      float AnY,         // Базовый угол поворота Y
                      float AnZ,         // Базовый угол поворота Z
                      float AnYws,       // Вспомогательный угол поворота Y
                      int PartyCount,    // Кол-во вершин разбиения
                      TVector3D StartPt, // Стартовая точка - центр нижнего основания
                      GLenum DrawType)   // Тип прорисовки
{
 int I, TopPrtCnt;
 if (RTop == 0)
  {
   TopPrtCnt = 1;   // если конус не усеч - то одна вершина сверху и вывод треугольниками
   if (DrawType == GL_QUADS) DrawType = GL_TRIANGLES;
  }
 else
   TopPrtCnt = PartyCount; // иначе - квадраты и кол-во вершин сверху = снизу

 TGLfloat3v *Bbs = 0;  // массив нижних точек
 TGLfloat3v *Tbs = 0;  // массив верхних точек
 TGLfloat3v *Norm = 0; // массив нормалей
 Bbs  = new TGLfloat3v[PartyCount];
 Norm = new TGLfloat3v[PartyCount];
 Tbs  = new TGLfloat3v[TopPrtCnt];

 float Tetta, Tetta1;

 // расчет нормали Y - составляющей
 Tetta = RBttm - RTop;
 Tetta /= Heigth;
 Tetta = atan(Tetta);
 float NrmY, NrmY_XZ;
 if (Tetta == 0)
  {
   NrmY = 0;     // расчет нормали Y - составляющей
   NrmY_XZ = -1;  // коррекция для X,Z от Y
  }
 else
  {
   NrmY = sin(Pi - Tetta);     // расчет нормали Y - составляющей
   NrmY_XZ = cos(Pi - Tetta);  // коррекция для X,Z от Y
  }
// нормаль к нижнему  верхнему основаниям
 TGLfloat3v  BttNrm,  TopNrm;
//           нижний  верхний центра
 TGLfloat3v  BCntr, TCntr;
 BttNrm[0] =  0.0f;
 BttNrm[1] = 1.0f;
 BttNrm[2] =  0.0f;

 TopNrm[0] = 0.0f;
 TopNrm[1] = -1.0f;
 TopNrm[2] = 0.0f;

// расчет точек нижнего основания и нормалей к боковым граням
 for (I = 0; I < PartyCount; I++)
  {
   Tetta  = I * 2.0f * PI/PartyCount;
   Tetta1 = (0.5f + I) * 2.0f * PI/PartyCount;

   Bbs[I][0]   = cos(Tetta) * RBttm;
   Bbs[I][1]   = 0.0f;
   Bbs[I][2]   = sin(Tetta) * RBttm;

   Norm[I][0]  = cos(Tetta1) * NrmY_XZ;
   Norm[I][1]  = NrmY;
   Norm[I][2]  = sin(Tetta1) * NrmY_XZ;
  }

// если радиуса снизу и сверху не равны, то расчитываем верхние точки
 if (RTop != RBttm)
  for (I = 0; I < TopPrtCnt; I++)
   {
    Tetta  = I * 2.0f * PI/PartyCount;

    Tbs[I][0]   = cos(Tetta) * RTop;
    Tbs[I][1]   = Heigth;
    Tbs[I][2]   = sin(Tetta) * RTop;
   }
 else   // иначе, их просто копируем снизу, но с коррекцией высоты
  for (I = 0; I < TopPrtCnt; I++)
   {
    Tbs[I][0]   = Bbs[I][0];
    Tbs[I][1]   = Heigth;
    Tbs[I][2]   = Bbs[I][2];
   }

// матрицы для поворота
  TMatrix_4X4 RotX;
  TMatrix_4X4 RotY;
  TMatrix_4X4 RotZ;
  TMatrix_4X4 Rot;

// их инициализация с учетом дополнительного поворота по Y
  RotX = Rot.RotateX(Pi * AnX /180);
  RotY = Rot.RotateY(Pi * (AnY + AnYws) /180);
  RotZ = Rot.RotateZ(Pi * AnZ /180);

  Rot = RotX.Mull(RotY);
  Rot = RotZ.Mull(Rot);

// поворачиваем нижние точки и нормали к бокам на углы
 for (I = 0; I < PartyCount; I++)
  {
   Rot.Mull(Bbs[I]);
   Rot.Mull(Norm[I]);

// и смещаем их относительно стартовой точки
   Bbs[I][0] += StartPt.X;
   Bbs[I][1] += StartPt.Y;
   Bbs[I][2] += StartPt.Z;
  }

// поворачиваем верхние точки на углы
 for (I = 0; I < TopPrtCnt; I++)
  {
   Rot.Mull(Tbs[I]);

// и смещаем их относительно стартовой точки
   Tbs[I][0] += StartPt.X;
   Tbs[I][1] += StartPt.Y;
   Tbs[I][2] += StartPt.Z;
  }

// нижний центр BottomCenter
BCntr[0] = StartPt.X;
BCntr[1] = StartPt.Y;
BCntr[2] = StartPt.Z;

// верхний центр TopCenter
TCntr[0] = StartPt.X;
TCntr[1] = StartPt.Y + Heigth;
TCntr[2] = StartPt.Z;
// и поворачиваем его
Rot.Mull(TCntr);

// поворачиваем нижнюю и верхнюю нормали
Rot.Mull(BttNrm);
Rot.Mull(TopNrm);



//вывод стенок
 int II;
 if (TopPrtCnt != 1)  // Если нормальный цилиндр или усеч конус
  {
   for (I = 0; I < PartyCount; I++)
   {
    II = I + 1;
    if (II == PartyCount) II = 0;
    glBegin(DrawType);
     glNormal3fv(Norm[I]);
     glVertex3fv(Bbs[I]);
     glVertex3fv(Tbs[I]);
     glVertex3fv(Tbs[II]);
     glVertex3fv(Bbs[II]);
    glEnd();
   }
  }
 else
  {
   for (I = 0; I < PartyCount; I++)
   {
    II = I + 1;
    if (II == PartyCount) II = 0;
    glBegin(DrawType);
     glNormal3fv(Norm[I]);
     glVertex3fv(Bbs[I]);
     glVertex3fv(Tbs[0]);
     glVertex3fv(Bbs[II]);
    glEnd();
   }
  }

if (DrawType != GL_LINE_STRIP) DrawType = GL_TRIANGLES;

// выводим нижнее основание
for (I = 0; I < PartyCount; I++)
 {
  II = I + 1;
  if (II == PartyCount) II = 0;
   glBegin(DrawType);
     glNormal3fv(BttNrm);
     glVertex3fv(Bbs[I]);
     glVertex3fv(Bbs[II]);
     glVertex3fv(BCntr);
    glEnd();
   }

// выводим верхнее основание
if (RTop != 0)
 for (I = 0; I < TopPrtCnt; I++)
  {
   II = I + 1;
   if (II == TopPrtCnt) II = 0;
    glBegin(DrawType);
     glNormal3fv(TopNrm);
     glVertex3fv(Tbs[I]);
     glVertex3fv(TCntr);
     glVertex3fv(Tbs[II]);
    glEnd();
  }

delete(Bbs);
delete(Norm);
delete(Tbs);
}

//-------------------------------------------------------------------------
void MgluSolidCilindr(float R,       // Радиус основания
                      float Heigth,      // Высота
                      float AnX,         // Базовый угол поворота Х
                      float AnY,         // Базовый угол поворота Y
                      float AnZ,         // Базовый угол поворота Z
                      TVector3D StartPt) // Стартовая точка - центр нижнего основания
{
 float PC = 2 * Pi * R;
 int PCount = PC;
 if (PCount > 150) PCount = 150;

 CreateCilindrAll(R,        // Радиус нижнего основания
                  R,        // Радиус верхнего основания
                  Heigth,   // Высота
                  AnX,      // Базовый угол поворота Х
                  AnY,      // Базовый угол поворота Y
                  AnZ,      // Базовый угол поворота Z
                  0,        // Вспомогательный угол поворота Y
                  PCount,   // Кол-во вершин разбиения
                  StartPt,  // Стартовая точка - центр нижнего основания
                  GL_QUADS);// Тип прорисовки

}

//-------------------------------------------------------------------------
void MgluWireCilindr(float R,       // Радиус основания
                     float Heigth,      // Высота
                     float AnX,         // Базовый угол поворота Х
                     float AnY,         // Базовый угол поворота Y
                     float AnZ,         // Базовый угол поворота Z
                     TVector3D StartPt) // Стартовая точка - центр нижнего основания
{
 int PCount = R/2;
 if (PCount < 10) PCount = 10;


 CreateCilindrAll(R,        // Радиус нижнего основания
                  R,        // Радиус верхнего основания
                  Heigth,   // Высота
                  AnX,      // Базовый угол поворота Х
                  AnY,      // Базовый угол поворота Y
                  AnZ,      // Базовый угол поворота Z
                  0,        // Вспомогательный угол поворота Y
                  PCount,   // Кол-во вершин разбиения
                  StartPt,  // Стартовая точка - центр нижнего основания
                  GL_LINE_STRIP);// Тип прорисовки

}
//-------------------------------------------------------------------------
void MgluWireConus(float R,            // Радиус нижнего основания
                   float Heigth,      // Высота
                   float AnX,         // Базовый угол поворота Х
                   float AnY,         // Базовый угол поворота Y
                   float AnZ,         // Базовый угол поворота Z
                   TVector3D StartPt) // Стартовая точка - центр нижнего основания
{
 int PCount = R/2;
 if (PCount < 10) PCount = 10;

 CreateCilindrAll(R,        // Радиус нижнего основания
                  0,        // Радиус верхнего основания
                  Heigth,   // Высота
                  AnX,      // Базовый угол поворота Х
                  AnY,      // Базовый угол поворота Y
                  AnZ,      // Базовый угол поворота Z
                  0,        // Вспомогательный угол поворота Y
                  PCount,   // Кол-во вершин разбиения
                  StartPt,  // Стартовая точка - центр нижнего основания
                  GL_LINE_STRIP);// Тип прорисовки
}
//-------------------------------------------------------------------------
void MgluSolidConus(float R,           // Радиус основания
                    float Heigth,      // Высота
                    float AnX,         // Базовый угол поворота Х
                    float AnY,         // Базовый угол поворота Y
                    float AnZ,         // Базовый угол поворота Z
                    TVector3D StartPt) // Стартовая точка - центр нижнего основания
{
 float PC = 2 * Pi * R;
 int PCount = PC;
 if (PCount > 150) PCount = 150;


 CreateCilindrAll(R,        // Радиус нижнего основания
                  0,        // Радиус верхнего основания
                  Heigth,   // Высота
                  AnX,      // Базовый угол поворота Х
                  AnY,      // Базовый угол поворота Y
                  AnZ,      // Базовый угол поворота Z
                  0,        // Вспомогательный угол поворота Y
                  PCount,   // Кол-во вершин разбиения
                  StartPt,  // Стартовая точка - центр нижнего основания
                  GL_QUADS);// Тип прорисовки

}

//-------------------------------------------------------------------------
void MgluWireConusUsehc(float RBttm,     // Радиус нижнего основания
                        float RTop,        // Радиус верхнего основания
                        float Heigth,      // Высота
                        float AnX,         // Базовый угол поворота Х
                        float AnY,         // Базовый угол поворота Y
                        float AnZ,         // Базовый угол поворота Z
                        TVector3D StartPt) // Стартовая точка - центр нижнего основания
{
 int PCount = RTop/2;
 if (PCount < 10) PCount = 10;

 CreateCilindrAll(RBttm,        // Радиус нижнего основания
                  RTop,        // Радиус верхнего основания
                  Heigth,   // Высота
                  AnX,      // Базовый угол поворота Х
                  AnY,      // Базовый угол поворота Y
                  AnZ,      // Базовый угол поворота Z
                  0,        // Вспомогательный угол поворота Y
                  PCount,   // Кол-во вершин разбиения
                  StartPt,  // Стартовая точка - центр нижнего основания
                  GL_LINE_STRIP);// Тип прорисовки
}
//-------------------------------------------------------------------------
void MgluSolidConusUsehc(float RBttm,     // Радиус нижнего основания
                         float RTop,        // Радиус верхнего основания
                         float Heigth,      // Высота
                         float AnX,         // Базовый угол поворота Х
                         float AnY,         // Базовый угол поворота Y
                         float AnZ,         // Базовый угол поворота Z
                         TVector3D StartPt) // Стартовая точка - центр нижнего основания
{
 float PC = RBttm;
 if (PC < RTop) PC = RTop ;

 PC *= 2 * Pi;
 int PCount = PC;
 if (PCount > 150) PCount = 150;

 CreateCilindrAll(RBttm,        // Радиус нижнего основания
                  RTop,        // Радиус верхнего основания
                  Heigth,   // Высота
                  AnX,      // Базовый угол поворота Х
                  AnY,      // Базовый угол поворота Y
                  AnZ,      // Базовый угол поворота Z
                  0,        // Вспомогательный угол поворота Y
                  PCount,   // Кол-во вершин разбиения
                  StartPt,  // Стартовая точка - центр нижнего основания
                  GL_QUADS);// Тип прорисовки
}
//-------------------------------------------------------------------------
void MgluSphere(float R, int U, TVector3D StartPt, GLenum DrawType)
{
 TGLfloat3v **P, **N;
 int I,J;
 float Tetta, Tetta1, Alpha, Alpha1;

 P = new TGLfloat3v*[U];
 N = new TGLfloat3v*[U];

 for (I = 0; I < U; I++)
  {
   P[I] = new TGLfloat3v[U];
   N[I] = new TGLfloat3v[U];
  }

 for (I = 0; I < U; I++)
  {
   Tetta = I * 2.0f * Pi / U;
   Alpha = (0.5f + I) * 2.0f * Pi / U;

   for (J = 0; J < U; J++)
    {
     Tetta1 = J * 2 * Pi /U;
     Alpha1 = (0.5f + J) * 2.0f * Pi / U;

     P[I][J][0] = R * cos(Tetta1)*cos(Tetta);
     P[I][J][1] = R * sin(Tetta1)*cos(Tetta);
     P[I][J][2] = R * sin(Tetta);

     N[I][J][0] = cos(Alpha1)*cos(Alpha);
     N[I][J][1] = sin(Alpha1)*cos(Alpha);
     N[I][J][2] = -sin(Alpha);
    };
  }

 for (I = 0; I < U; I++)
   for (J = 0; J < U; J++)
    {
     P[I][J][0] += StartPt.X;
     P[I][J][1] += StartPt.Y;
     P[I][J][2] += StartPt.Z;
    };
int II, JJ;

 for (I = 0; I < U; I++)
  {
   II = I + 1;
   if (II == U) II = 0;

   for (J = 0; J < U; J++)
    {
     JJ = J + 1;
     if (JJ == U) JJ = 0;

     glBegin(DrawType);
      glNormal3fv(N[I][J]);

      glVertex3fv(P[I ][J ]);
      glVertex3fv(P[I ][JJ]);
      glVertex3fv(P[II][JJ]);
      glVertex3fv(P[II][J ]);
     glEnd();
    };
  };

 for (I = 0; I < U; I++)
  {
   delete(P[I]);
   delete(N[I]);
  }
 delete(P);
 delete(N);


}
//-------------------------------------------------------------------------
void MgluSolidSphere(float R, TVector3D StartPt)
{
 float PC = R;

 PC *= 2 * Pi;
 int PCount = PC;
 if (PCount > 150) PCount = 150;

// glEnable(GLU_SMOOTH);

 MgluSphere(R, PCount, StartPt, GL_QUADS);
}
//-------------------------------------------------------------------------
void MgluWireSphere(float R, TVector3D StartPt)
{
 int PCount = R/2;
 if (PCount < 10) PCount = 10;
 MgluSphere(R, PCount, StartPt, GL_LINE_STRIP);
}

//initialization
  //initDodecahedron;

#endif