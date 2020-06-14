class Vector
{
public:
  Vector();
  Vector(const int data_count);
  Vector(const Vector& a);
  double& operator()(const int data_count);
  double get(const int data_count) const;
  Vector& operator= (const Vector& a);
  Vector& Add(const double v);
  Vector& Subtract(const double v);
  Vector& Multiply(const double v);
  Vector& Divide(const double v);
  int VecSize() const;
  int VecSize(const Vector& a);
  void Print() const;


  // destructor
  ~Vector();


  int data_count;
  double* vec;
};

Vector operator+(const Vector& a, const Vector& b);
Vector operator+ (const Vector& a, const double b);
Vector operator-(const Vector& a, const Vector& b);
Vector operator- (const Vector& a, const double b);
Vector operator* (const Vector& a, const Vector& b);
Vector operator* (const Vector& a, const double b);