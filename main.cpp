#include "src/matrix.cpp"
#include "src/vector.cpp"

Matrix read_matrix(){
  int rows = 0;
  int cols = 0;
  cout << "Enter the number of matrix rows:" << endl;
  cin >> rows;
  cout << "Enter the number of matrix cols:" << endl;
  cin >> cols;
  Matrix A = Matrix(rows, cols);
  cout << "Enter the matrix elements:" << endl;
  // fill in some values in matrix a
  for (int r = 1; r <= rows; r++)
  {
    for (int c = 1; c <= cols; c++)
    {
      cin >> A(r, c);
    }
  }
  return A;
}

Vector read_vector(){
  int vec_size = 0;
  cout << "Enter the vector size:" << endl;
  cin >> vec_size;
  Vector V = Vector(vec_size);
  cout << "Enter the vector elements:" << endl;
  for (int r = 1; r <= vec_size; r++)
  {
    cin >> V(r);
  }
  return V;
}


int main(int argc, char *argv[])
{
    int flag = 0;
    cout << "Welcome to Matrix and Vector Ops" << endl;
    cout << "Enter flag as 1 for matrix and 2 for vector" << endl;
    cin >> flag;

  try{
    if (flag == 1){
      Matrix A = read_matrix();
      Matrix B = read_matrix();

      // print the whole matrix
      cout << "Print Matrix A = \n";
      A.Print();
      cout << endl;

      // print the whole matrix
      cout << "Print Matrix B = \n";
      B.Print();
      cout << endl;


      // Use Matrix class here
      try
      {
        Matrix C = A + B;
        cout << "Matrix Addition (A + B) C = \n";
        C.Print();
        cout << endl;

        Matrix D = A - B;
        cout << "Matrix Substraction (A - B) D = \n";
        D.Print();
        cout << endl;

        Matrix E = A + 2;
        cout << "Scalar addition(A + 2) E = \n";
        E.Print();
        cout << endl;
        
        Matrix F = A * 2;
        cout << "Scalar multiplication (A * 2) F = \n";
        F.Print();
        cout << endl;

        Matrix G = A * B;
        cout << "Matrix multiplication (A * B) G = \n";
        G.Print();
        cout << endl;

        cout << "Matrix A size is: (" << A.Size(1) << ", " << A.Size(2) << ")" << endl;
      }
      catch (Exception err)
      {
        printf("Error: %s\n", err.msg);
      }
    }


    if (flag == 2){
      Vector V1 = read_vector();
      Vector V2 = read_vector();

      // print the whole vector
      cout << "V1 = \n";
      V1.Print();
      cout << endl;

      // print the whole vector
      cout << "V2 = \n";
      V2.Print();
      cout << endl;

      // Use Vector class here
      try
      {
        Vector B_v = V1 + V2;
        cout << "Vector addition (V1 + V2) B_v = \n";
        B_v.Print();
        cout << endl;

        Vector C_v = V1 - V2;
        cout << "Vector substraction (V1 - V2) C_v = \n";
        C_v.Print();
        cout << endl;

        Vector E_v = V1 + 2;
        cout << "Scalar addition E_v (V1 + 2)= \n";
        E_v.Print();
        cout << endl;

        Vector F_v = V1 * 2;
        cout << "Scalar multiplication F_v (V1 * 2) = \n";
        F_v.Print();
        cout << endl;

        Vector G_v = V1 * V2;
        cout << "Vector multiplication G_v (V1 * V2) = \n";
        G_v.Print();
        cout << endl;

        cout << "Vector size of V1 is:" << VecSize(V1) << endl;
      }
      catch (Exception_Vec err)
      {
        printf("Error: %s\n", err.msg);
      }
    }
  }
  catch (...)
  {
    printf("An error occured...\n");
  }
  printf("\n");
  PAUSE;

  return EXIT_SUCCESS;
}


