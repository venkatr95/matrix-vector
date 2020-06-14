#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <iostream>
#include "../include/vector.hpp"

using namespace std;

#define PAUSE {printf("Press \"Enter\" to continue\n"); fflush(stdin); getchar(); fflush(stdin);}

// Declarations
class Vector;

 // a simple exception class for error msgs
class Exception_Vec
{
public:
  const char* msg;
  Exception_Vec(const char* arg)
   : msg(arg)
  {
  }
};

  // constructor
  Vector::Vector()
  {
    // null object
    vec = NULL;
    data_count = 0;
  }

  // constructor
  Vector::Vector(const int element_count)
  {
    // create a Vector object with given number of data_count and columns
    vec = NULL;

    if (element_count > 0)
    {
      data_count = element_count;

      vec = new double[data_count];
      for (int v = 0; v < data_count; v++)
      {
          vec[v]= 0;
      }
    }
  }

  // assignment operator
  Vector::Vector(const Vector& a)
  {
    data_count = a.data_count;

    vec = new double[a.data_count];
    for (int v = 0; v < a.data_count; v++)
    {
      vec[v] = a.vec[v];
    }
  }

  // index operator use to get data_count and columns from Vector
  double& Vector::operator()(const int element_count)
  {
    if (vec != NULL && element_count > 0 && element_count <= data_count)
    {
      return vec[element_count-1];
    }
    else
    {
      throw Exception_Vec("Subscript out of range");
    }
  }

  // index operator used for the class like vector.get(element_count)
  double Vector::get(const int element_count) const
  {
    if (vec != NULL && element_count > 0 && element_count <= data_count)
    {
      return vec[element_count-1];
    }
    else
    {
      throw Exception_Vec("Subscript out of range");
    }
  }

  // assignment operator
  Vector& Vector::operator= (const Vector& a)
  {
    data_count = a.data_count;
    vec = new double[a.data_count];
    for (int v = 0; v < a.data_count; v++)
    {
      vec[v] = a.vec[v];
    }
    return *this;
  }

  // element wise scalar addition
  Vector& Vector::Add(const double val)
  {
    for (int v = 0; v < data_count; v++)
    {
        vec[v] += val;
    }
     return *this;
  }

  // element wise scalar substraction
  Vector& Vector::Subtract(const double val)
  {
    return Add(-val);
  }

  // element wise scalar multiplication
  Vector& Vector::Multiply(const double val)
  {
    for (int v = 0; v < data_count; v++)
    {
      vec[v] *= val;
    }
     return *this;
  }

  // Vector Addition
  Vector operator+(const Vector& a, const Vector& b)
  {
    // check if the dimensions match
    if (a.data_count == b.data_count)
    {
      Vector res(a.data_count);

      for (int v = 0; v < a.data_count; v++)
      {
        res.vec[v] = a.vec[v] + b.vec[v];

      }
      return res;
    }
    else
    {
      // give an error
      throw Exception_Vec("Dimensions does not match");
    }

    // return an empty Vector
    return Vector();
  }

  // addition of Vector with double
  Vector operator+ (const Vector& a, const double b)
  {
    Vector res = a;
    res.Add(b);
    return res;
  }

  // Vector Substraction
  Vector operator- (const Vector& a, const Vector& b)
  {
    // check if the dimensions match
    if (a.data_count == b.data_count)
    {
      Vector res(a.data_count);
      for (int r = 0; r < a.data_count; r++)
      {
          res.vec[r] = a.vec[r] - b.vec[r];
      }
      return res;
    }
    else
    {
      // give an error
      throw Exception_Vec("Dimensions does not match");
    }
    // return an empty Vector
    return Vector();
  }

  // subtraction of Vector with double
  Vector operator- (const Vector& a, const double b)
  {
    Vector res = a;
    res.Subtract(b);
    return res;
  }

  // multiplication of Vector with double
  Vector operator* (const Vector& a, const double b)
  {
    Vector res = a;
    res.Multiply(b);
    return res;
  }

  // multiplication of Vector with Vector
  Vector operator* (const Vector& a, const Vector& b)
  {
    // check if the dimensions match
    if (a.data_count == b.data_count)
    {
      Vector res(a.data_count);
      
      for (int v = 0; v < a.data_count; v++)
      {
        res.vec[v] = a.vec[v] * b.vec[v];

      }
      return res;
    }
    else
    {
      // give an error
      throw Exception_Vec("Dimensions does not match");
    }

    // return an empty matrix (this never happens but just for safety)
    return Vector();
  }

  //returns the size of the i-th dimension of the Vector
  int Vector::VecSize() const
  {
    return data_count;
  }


  // print the contents of the Vector
  void Vector::Print() const
  {
    if (vec != NULL)
    {
      cout << "|";
      for (int r = 0; r < data_count; r++)
      {
        if (r > 0)
        {
          cout << " ";
        }
        cout << vec[r];
      }
      cout << "|";
    }
    else
    {
      // Vector is empty
      printf("| |\n");
    }
  }

  // destructor
  Vector::~Vector()
  {
    // clean memory
    delete vec;
    vec = NULL;
  }


/*
Returns vector size
 */
int VecSize(const Vector& a)
{
  return a.VecSize();
}
