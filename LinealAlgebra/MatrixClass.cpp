/*=============================================================================================================
====================================   GRAPHS REPRESENTATIONS        ==========================================
=============================================================================================================*/

#include <iostream>                                                                 //Include Libraries
#include <vector>                                                                   //Include Libraries
#include <stdexcept>                                                                //Include Libraries
#include <algorithm>                                                                //Include Libraries

using namespace std;                                                                //Bad practice, dont do


/*===================================================================
================      MATRIX TEMPLATE CLASS       ===================
===================================================================*/

template <class T>                                                                  //General Class
class Matrix {                                                                      //Class Matrix:

  private:                                                                          //=== Private Stuff ===
    int Rows;                                                                       //Number of Rows
    int Columns;                                                                    //Number of Columns

    vector<T> Data;                                                                 //Not best implementation :(

  public:                                                                           //=== Public Stuff ===
    
    // ================================================
    // =============  CONSTRUCTOR    ==================
    // ================================================

    // == GENERAL-EMPTY CONSTRUCTOR ==
    Matrix(int Rows, int Columns) {                                                 //General Constructor
        if (Rows < 1 || Columns < 1)                                                //If stupid size entered :/
            throw std::invalid_argument("Received Incompatible size Matrices");     //Get the fuck out
        
        this->Rows = Rows;                                                          //Set the Rows size
        this->Columns = Columns;                                                    //Set the Columns size

        Data.resize(Rows * Columns);                                                //Allocate space
    }

    // == POPULATE CONSTRUCTOR ==
    Matrix(int Rows, int Columns, const vector<T> &Data):                           //Delegate Construtor
    Matrix(Rows, Columns) {                                                         //Call this constructor
        Populate(Data);                                                             //Now call this
    }

    // ================================================
    // ========  GENERAL FUNCTIONS  ===================
    // ================================================


    // == GETTERS ==
    int GetRows() const { return Rows; }                                            //Getter for Rows
    int GetColumns() const { return Columns; }                                      //Getter for Columns

    // == POPUTALE THE MATRIX WITH INFO ==
    void Populate (const vector<T> &NewData) {                                         //Populate the Data Matrix
        Data = NewData;
        Data.resize(Rows * Columns);                                                //Allocate space
    }

    // == SHOW THE MATRIX ==
    friend ostream& operator<< (ostream& out, const Matrix<T> &ThatMatrix) {        //Overload << (not member)
        
        for (int i = 0; i < ThatMatrix.GetRows(); ++i) {                            //Foreach Row
            for (int j = 0; j < ThatMatrix.GetColumns(); ++j)                       //Foreach Columns
                out << (ThatMatrix)(i, j) << " ";                                   //Show me
            out << std::endl;
        }

        return out;
    }

    // == SHOW ITEMS INSIDE THE MATRIX ==
    T& operator()(int Row, int Column) {                                            //Call on a T& object
        if (Row < 0 || Column < 0 || Row >= Rows || Column >= Columns)              //If you are out
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        return this->Data[(Row * Columns) + Column];                                //Go, true identity
    }            
    T operator()(int Row, int Column) const {
        if (Row < 0 || Column < 0 || Row >= Rows || Column >= Columns)              //If you are out
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        return this->Data[(Row * Columns) + Column];                                //Go, true identity

    }


    // ========================================================
    // ===============   OPERATIONS   =========================
    // ========================================================

    // ========================================
    // ===============   =     ================
    // ========================================

    // ========= OPERATOR ASSIGNS  ============
    Matrix<T>& operator= (Matrix<T> that) {                                         //Overload the == operator
        if (this != &that) swap(that);                                              //Call my swap function
        return *this;                                                               //return this
    }

    // ========= SWAP  ========================
    void swap(Matrix<T> &A, Matrix<T> &B) {                                         //Swap the functions
        using std::swap;                                                            //Now use std swap :3

        swap(A.Rows, B.Rows);                                                       //Swap the important bits
        swap(A.Columns, B.Columns);                                                 //Swap the important bits
        swap(A.Data, B.Data);                                                       //Swap the important bits
    }
    // ========= SWAP  ========================
    void swap(Matrix<T> &that) {swap(*this, that);}                                 //Other function form


    // ========================================
    // ===============   ==    ================
    // ========================================

    // ========= OPERATOR EQUAL  ==============
    bool operator== (const Matrix<T> &that) {                                       //Overload the == operator

        if (this->Rows != that.Rows || this->Columns != that.Columns) return false; //If different sizes

        for (int i = 0; i < Rows; ++i) {                                            //Foreach resultant Row
            for (int j = 0; j < Columns; ++j)                                       //Foreach resultant Columns
                if ((*this)(i, j) != (that)(i, j)) return false;                    //If info is different run!
        }
        return true;                                                                //Return the result matrix
    }

    // ========= OPERATOR NOT EQUAL  ==============
    bool operator!= (const Matrix<T> &that) {return !(this->operator==(that));}     //Overload matrix


    // ========================================
    // ===============   +    =================
    // ========================================

    // ========= OPERATOR SUM +  ==============
    Matrix<T> operator+ (const Matrix<T> &that) {                                   //Overload the + operator
        Matrix<T> NewMatrix(*this);                                                 //Create a copy of me
        NewMatrix += that;                                                          //Add and assign
        return NewMatrix;                                                           //return modified copy
    }

    // ========= OPERATOR SUM +=  ==============
    Matrix<T> operator+= (const Matrix<T> &that) {                                  //Overload the += operator
        if (this->Rows != that.Rows || this->Columns != that.Columns)               //If different sizes
            throw std::invalid_argument("Received Different size Matrices");        //Get the fuck out

        for (int i = 0; i < Rows; ++i) {                                            //Foreach Row
            for (int j = 0; j < Columns; ++j)                                       //Foreach Columns
               (*this)(i, j) += (that)(i, j);                                       //Add to this
        }

        return *this;
    }


    // ========================================
    // ===============   -    =================
    // ========================================

    // ========= OPERATOR REST -  ==============
    Matrix<T> operator- (const Matrix<T> &that) {                                   //Overload the - operator
        Matrix<T> NewMatrix(*this);                                                 //Create a copy of me
        NewMatrix -= that;                                                          //Add and assign
        return NewMatrix;                                                           //return modified copy
    }

    // ========= OPERATOR REST -=  ==============
    Matrix<T> operator-= (const Matrix<T> &that) {                                  //Overload the -= operator
        if (this->Rows != that.Rows || this->Columns != that.Columns)               //If different sizes
            throw std::invalid_argument("Received Different size Matrices");        //Get the fuck out

        for (int i = 0; i < Rows; ++i) {                                            //Foreach Row
            for (int j = 0; j < Columns; ++j)                                       //Foreach Columns
               (*this)(i, j) -= (that)(i, j);                                       //Add to this
        }

        return *this;
    }


    // ========================================
    // ===============   *    =================
    // ========================================

    // ========= OPERATOR MULTIPLICATE *  ========
    Matrix<T> operator* (const Matrix<T> &that) {                                   //Overload the * operator

        if (this->Columns != that.Rows)                                             //If A:mxn & B:nxp then C:mxp
            throw std::invalid_argument("Received Incompatible size Matrices");     //Get the fuck out

        Matrix<T> Result(this->Rows, that.Columns);                                 //Create result matrix

        for (int i = 0; i < this->Rows; ++i) {                                      //Foreach resultant Row
            for (int j = 0; j < that.Columns; ++j) {                                //Foreach resultant Columns
                
                Result(i, j) = 0;                                                   //Ok, let start in 0
                for (int k = 0; k < this->Columns; ++k)                             //Travel  0..n or 0..Columns
                    Result(i, j) += ( (*this)(i, k) * (that)(k, j) );               //this place is sum of things

            }
        }

        return Result;                                                              //Return the result matrix
    }



};





// ================================================
// ============  LITTLE MAIN    ===================
// ================================================
int main(void) {

    Matrix<int> M1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    
    cout << "Original M1" << endl << M1 << endl;

    Matrix<int> M2(3, 1, {10, 11, 12, 13, 14, 15});

    cout << "Original M2" << endl << M2 << endl;

    cout << "M1 * M2" << endl << M1 * M2 << endl;

    M1 += M1;

    cout << "M1 += M1" << endl << M1 << endl;

    cout << "M2 - M2" << endl << M2 - M2 << endl;

    if (M1 != M2)
        cout << "M1 != M2" << endl;

    if (M2 == M2)
        cout << "M2 == M2" << endl;

    M1 = M2;

    cout << "M1 = M2" << endl << M1 << endl << M2 << endl;

    M1(1, 0) = 5;
    M1(0, 0) = M1(1, 0);
    cout << "M1(1,0) = " << M1(1, 0) << endl;
    cout << "New M1" << M1 << endl;

    return 0;
}


