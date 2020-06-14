/*
A simple matrix class c++ code
*/

#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <iostream>
#include "../include/matrix.hpp"

using namespace std;

#define PAUSE {printf("Press \"Enter\" to continue\n"); fflush(stdin); getchar(); fflush(stdin);}


 // a simple exception class for error msgs
class Exception
{
public:
  const char* msg;
  Exception(const char* arg)
   : msg(arg)
  {
  }
};


  // constructor
  Matrix::Matrix()
  {
    // null object
    mat = NULL;
    rows = 0;
    cols = 0;
  }

  // constructor
  Matrix::Matrix(const int row_count, const int column_count)
  {
    // create a Matrix object with given number of rows and columns
    mat = NULL;

    if (row_count > 0 && column_count > 0)
    {
      rows = row_count;
      cols = column_count;

      mat = new double*[rows];
      for (int r = 0; r < rows; r++)
      {
        mat[r] = new double[cols];

        // initial value filled with zeros
        for (int c = 0; c < cols; c++)
        {
          mat[r][c] = 0;
        }
      }
    }
  }

  // assignment operator
  Matrix::Matrix(const Matrix& a)
  {
    rows = a.rows;
    cols = a.cols;
    mat = new double*[a.rows];
    for (int r = 0; r < a.rows; r++)
    {
      mat[r] = new double[a.cols];

      // copy the values from the matrix a
      for (int c = 0; c < a.cols; c++)
      {
        mat[r][c] = a.mat[r][c];
      }
    }
  }

  // index operator use to get rows and columns from matrix
  double& Matrix::operator()(const int r, const int c)
  {
    if (mat != NULL && r > 0 && r <= rows && c > 0 && c <= cols)
    {
      return mat[r-1][c-1];
    }
    else
    {
      throw Exception("Subscript out of range");
    }
  }

  // index operator used for the class like matrix.get(col, row)
  double Matrix::get(const int r, const int c) const
  {
    if (mat != NULL && r > 0 && r <= rows && c > 0 && c <= cols)
    {
      return mat[r-1][c-1];
    }
    else
    {
      throw Exception("Subscript out of range");
    }
  }

  // assignment operator
  Matrix& Matrix::operator= (const Matrix& a)
  {
    rows = a.rows;
    cols = a.cols;
    mat = new double*[a.rows];
    for (int r = 0; r < a.rows; r++)
    {
      mat[r] = new double[a.cols];

      // copy the values from the matrix a
      for (int c = 0; c < a.cols; c++)
      {
        mat[r][c] = a.mat[r][c];
      }
    }
    return *this;
  }

  // element wise scalar addition
  Matrix& Matrix::Add(const double v)
  {
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        mat[r][c] += v;
      }
    }
     return *this;
  }

  // element wise scalar substraction
  Matrix& Matrix::Subtract(const double v)
  {
    return Add(-v);
  }

  // element wise scalar multiplication
  Matrix& Matrix::Multiply(const double v)
  {
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        mat[r][c] *= v;
      }
    }
     return *this;
  }

  // element wise scalar division
  Matrix& Matrix::Divide(const double v)
  {
     return Multiply(1/v);
  }

  // Matrix Addition
  Matrix operator+(const Matrix& a, const Matrix& b)
  {
    // check if the dimensions match
    if (a.rows == b.rows && a.cols == b.cols)
    {
      Matrix res(a.rows, a.cols);

      for (int r = 0; r < a.rows; r++)
      {
        for (int c = 0; c < a.cols; c++)
        {
          res.mat[r][c] = a.mat[r][c] + b.mat[r][c];
        }
      }
      return res;
    }
    else
    {
      // give an error
      throw Exception("Dimensions does not match");
    }

    // return an empty matrix
    return Matrix();
  }

  // addition of Matrix with double
  Matrix operator+ (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Add(b);
    return res;
  }

  // Matrix Substraction
  Matrix operator- (const Matrix& a, const Matrix& b)
  {
    // check if the dimensions match
    if (a.rows == b.rows && a.cols == b.cols)
    {
      Matrix res(a.rows, a.cols);

      for (int r = 0; r < a.rows; r++)
      {
        for (int c = 0; c < a.cols; c++)
        {
          res.mat[r][c] = a.mat[r][c] - b.mat[r][c];
        }
      }
      return res;
    }
    else
    {
      // give an error
      throw Exception("Dimensions does not match");
    }

    // return an empty matrix
    return Matrix();
  }

  // subtraction of Matrix with double
  Matrix operator- (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Subtract(b);
    return res;
  }

  // operator multiplication
  Matrix operator* (const Matrix& a, const Matrix& b)
  {
    // check if the dimensions match
    if (a.cols == b.rows)
    {
      Matrix res(a.rows, b.cols);

      for (int r = 0; r < a.rows; r++)
      {
        for (int c_res = 0; c_res < b.cols; c_res++)
        {
          for (int c = 0; c < a.cols; c++)
          {
            res.mat[r][c_res] += a.mat[r][c] * b.mat[c][c_res];
          }
        }
      }
      return res;
    }
    else
    {
      // give an error
      throw Exception("Dimensions does not match");
    }

    // return an empty matrix (this never happens but just for safety)
    return Matrix();
  }


  // multiplication of Matrix with double
  Matrix operator* (const Matrix& a, const double b)
  {
    Matrix res = a;
    res.Multiply(b);
    return res;
  }

  //returns the size of the i-th dimension of the matrix
  int Matrix::Size(const int i) const
  {
    if (i == 1)
    {
      return rows;
    }
    else if (i == 2)
    {
      return cols;
    }
    return 0;
  }

  // returns the number of rows
  int Matrix::GetRows() const
  {
    return rows;
  }

  // returns the number of columns
  int Matrix::GetCols() const
  {
    return cols;
  }

  // print the contents of the matrix
  void Matrix::Print() const
  {
    if (mat != NULL)
    {
      cout << "|";
      for (int r = 0; r < rows; r++)
      {
        if (r > 0)
        {
          cout << "";
        }
        for (int c = 0; c < cols-1; c++)
        {
          cout << mat[r][c] << ", ";
        }
        if (r < rows-1)
        {
          cout << mat[r][cols-1]  << "|\n|";
        }
        else
        {
          cout << mat[r][cols-1] << "|\n";
        }
      }
    }
    else
    {
      // matrix is empty
      printf("[ ]\n");
    }
  }

  // destructor
  Matrix::~Matrix()
  {
    // clean memory
    for (int r = 0; r < rows; r++)
    {
      delete mat[r];
    }
    delete mat;
    mat = NULL;
  }


/*
 * for i=1 the function returns the number of rows,
 * and for i=2 the function returns the number of columns
 * else the function returns 0
 */
int Matrix::MatSize(const Matrix& a, const int i)
{
  return a.Size(i);
}
