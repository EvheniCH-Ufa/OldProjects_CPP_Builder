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
        TVector3D();                                   //—оздаетс€ 0 вектор
inline  TVector3D(double Value);                       //—оздаетс€ вектор c X,Y,Z = Value
        TVector3D(double vX, double vY, double vZ, double vP); //—оздаетс€ заданный вектор
inline  TVector3D(const TVector3D &Vector)            // —оздаетс€ вектор, копируютс€ с другого
          {
           X = Vector.X;
           Y = Vector.Y;
           Z = Vector.Z;
           P = Vector.P;
          };

        void      Copy(const TVector3D &Vector);            // вектор копируютс€ с другого
inline  TVector3D Add(const TVector3D &Vector);        // сумма векторов
        TVector3D Minus();                             // отрицательный вектор
        TVector3D Deduction(const TVector3D &Vector);  // –азность векторов
        double    MullSc(const TVector3D &Vector);        // —кал€рное умножениие векторов
        TVector3D Del(const TVector3D &Vector);// ????   деление векторов
TVector3D Mull(double Value)                  //умножениие вектора на число
 {
 TVector3D Res;
  Res.X = X * Value;
  Res.Y = Y * Value;
  Res.Z = Z * Value;
  Res.P = P * Value;
  return Res;
 };

        void      OneV();                              //привидение к еденичному
        TVector3D Del(double Value);                   //деление вектора на число
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
       TMatrix_4X4();                                  // создание 0 матрицы
inline TMatrix_4X4(double value);                      // создание матрицы с value по диагонали и 3-3 = 1
inline TMatrix_4X4(const TMatrix_4X4 &Matr);           // создание матрицы - копии матрицы Matr
inline TMatrix_4X4 Add(const TMatrix_4X4 &Matr);       // сложение
inline TMatrix_4X4 Deduction(const TMatrix_4X4 &Matr); // вычитание
       TMatrix_4X4 Mull(const TMatrix_4X4 &Matr);      // умножение
       void   Mull(TVector3D &Vector);                 // умножение на вектор
       void   Mull(Tfloatv P);                         // умножение на массив из 3 с плавающ
inline TMatrix_4X4 Mull(const double value);           // умножение на число
inline TMatrix_4X4 Del(const double value);            // деление на число
       TMatrix_4X4 RotateX(double angle);              // поворот на угол относ-но оси ќ’
       TMatrix_4X4 RotateY(double angle);              // поворот на угол относ-но оси ќY
       TMatrix_4X4 RotateZ(double angle);              // поворот на угол относ-но оси ќZ
inline TMatrix_4X4 Scale(double X, double Y, double Z);// раст€жение, сжатие
inline TMatrix_4X4 MirrorXOY();                        // зеркало относ-но ’ќY
inline TMatrix_4X4 MirrorYOZ();                        // зеркало относ-но YOZ
inline TMatrix_4X4 MirrorZOX();                        // зеркало относ-но ZOX
inline TMatrix_4X4 Carry(TVector3D &Vector);           // перенос на вектор
inline TMatrix_4X4 Return();                           // обратна€
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#endif
/*    ѕерегрузка операторов
 TVector3D & operator *= (const TVector3D &Vec)  ;
 TVector3D & operator /= (const TVector3D &Vec)   ;
 TVector3D & operator *= (double F)                ;
 TVector3D & operator /= (double F);*/


