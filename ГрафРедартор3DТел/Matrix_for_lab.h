//---------------------------------------------------------------------------
#ifndef Matrix_for_labH
#define Matrix_for_labH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
typedef float Tfloatv[3];
//---------------------------------------------------------------------------
class TVector3D
{
 public:

 double X, Y, Z, P;
        TVector3D();                                   //��������� 0 ������
inline  TVector3D(double Value);                       //��������� ������ c X,Y,Z = Value
        TVector3D(double vX, double vY, double vZ, double vP); //��������� �������� ������
inline  TVector3D(const TVector3D &Vector)            // ��������� ������, ���������� � �������
          {
           X = Vector.X;
           Y = Vector.Y;
           Z = Vector.Z;
           P = Vector.P;
          };

        void      Copy(const TVector3D &Vector);            // ������ ���������� � �������
inline  TVector3D Add(const TVector3D &Vector);        // ����� ��������
        TVector3D Minus();                             // ������������� ������
        TVector3D Deduction(const TVector3D &Vector);  // �������� ��������
        double    MullSc(const TVector3D &Vector);        // ��������� ���������� ��������
        TVector3D Del(const TVector3D &Vector);// ????   ������� ��������
TVector3D Mull(double Value)                  //���������� ������� �� �����
 {
 TVector3D Res;
  Res.X = X * Value;
  Res.Y = Y * Value;
  Res.Z = Z * Value;
  Res.P = P * Value;
  return Res;
 };

        void      OneV();                              //���������� � ����������
        TVector3D Del(double Value);                   //������� ������� �� �����
        double    Length();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TMatrix_4X4
{
public:

double Table[4][4];
       TMatrix_4X4();                                  // �������� 0 �������
inline TMatrix_4X4(double value);                      // �������� ������� � value �� ��������� � 3-3 = 1
inline TMatrix_4X4(const TMatrix_4X4 &Matr);           // �������� ������� - ����� ������� Matr
inline TMatrix_4X4 Add(const TMatrix_4X4 &Matr);       // ��������
inline TMatrix_4X4 Deduction(const TMatrix_4X4 &Matr); // ���������
       TMatrix_4X4 Mull(const TMatrix_4X4 &Matr);      // ���������
       void   Mull(TVector3D &Vector);                 // ��������� �� ������
       void   Mull(Tfloatv P);                         // ��������� �� ������ �� 3 � �������
inline TMatrix_4X4 Mull(const double value);           // ��������� �� �����
inline TMatrix_4X4 Del(const double value);            // ������� �� �����
       TMatrix_4X4 RotateX(double angle);              // ������� �� ���� �����-�� ��� ��
       TMatrix_4X4 RotateY(double angle);              // ������� �� ���� �����-�� ��� �Y
       TMatrix_4X4 RotateZ(double angle);              // ������� �� ���� �����-�� ��� �Z
inline TMatrix_4X4 Scale(double X, double Y, double Z);// ����������, ������
inline TMatrix_4X4 MirrorXOY();                        // ������� �����-�� ��Y
inline TMatrix_4X4 MirrorYOZ();                        // ������� �����-�� YOZ
inline TMatrix_4X4 MirrorZOX();                        // ������� �����-�� ZOX
inline TMatrix_4X4 Carry(TVector3D &Vector);           // ������� �� ������
inline TMatrix_4X4 Return();                           // ��������
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
/*    ���������� ����������
 TVector3D & operator *= (const TVector3D &Vec)  ;
 TVector3D & operator /= (const TVector3D &Vec)   ;
 TVector3D & operator *= (double F)                ;
 TVector3D & operator /= (double F);*/


