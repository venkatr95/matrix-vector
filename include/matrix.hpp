class Matrix
{
public:
  Matrix();
  Matrix(const int row_count, const int column_count);
  Matrix(const Matrix& a);
  double& operator()(const int r, const int c);
  double get(const int r, const int c) const;
  Matrix& operator= (const Matrix& a);
  Matrix& Add(const double v);
  Matrix& Subtract(const double v);
  Matrix& Multiply(const double v);
  Matrix& Divide(const double v);
  int Size(const int i) const;
  int MatSize(const Matrix& a, const int i);
  int GetRows() const;
  int GetCols() const;
  void Print() const;


  // destructor
  ~Matrix();

  int rows;
  int cols;
  double** mat;
};

Matrix operator+ (const Matrix& a, const double b);
Matrix operator+ (const Matrix& a, const double b);
Matrix operator-(const Matrix& a, const Matrix& b);
Matrix operator- (const Matrix& a, const double b);
Matrix operator* (const Matrix& a, const Matrix& b);
Matrix operator* (const Matrix& a, const double b);