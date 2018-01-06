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
    void Populate (const vector<T> &NewData) {                                      //Populate the Data Matrix
        if (NewData.size() < (Columns * Rows))                                      //Check the size
            throw std::invalid_argument("Not enough data in vector");               //Get the fuck out

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

    // == CREATE IDENTITY ==
    static Matrix<T> CreateIdentity(int Dimension, T Unit) {                        //Create a Identity
        Matrix<T> Result(Dimension, Dimension);                                     //Create a square matrix
        for (int k = 0; k < Dimension; ++k) (Result)(k, k) = Unit;                  //Matrix(k, k) = Unity
        return Result;                                                              //Return Indentity
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


    // ========================================================
    // =============     GENERAL FUNCTIONS   ==================
    // ========================================================
    T Trace() {                                                                     //Trace a Matrix
        if (Rows != Columns) throw std::invalid_argument("Not Square Matrix");      //Get the fuck out
        T Result {};                                                                //Start the Result variable
        for (int i = 0; i < Rows; ++i) Result += (*this)(i, i);                     //Sum the diagonals
        return Result;                                                              //return it
    }


    // ========================================================
    // =============     GAUSS JORDAN        ==================
    // ========================================================

    // =============================================
    // =============     SWAP       ================
    // =============================================
    void SwapRow(int Origin, int Destination) {                                     //============= Change Row =====
        
        if (Origin == Destination) return;                                          //If you want to change nothing
        if (Origin < 0 || Destination < 0) throw invalid_argument("Negative Row");  //Get the fuck out
        if (Origin >= Rows || Destination >= Rows)                                  //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < Rows; ++k)                                              //For each Row
            std::swap((*this)(Origin, k), (*this)(Destination, k));                 //Swap the element of the Row
    }
    void SwapColumn(int Origin, int Destination) {                                  //========== Change Column =====
        
        if (Origin == Destination) return;                                          //If you want to change nothing
        if (Origin < 0 || Destination < 0)                                          //If we want negative columns
            throw invalid_argument("Negative Column");                              //Get the fuck out
        if (Origin >= Columns || Destination >= Columns)                            //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < Columns; ++k)                                           //For each Row
            std::swap((*this)(k, Origin), (*this)(k, Destination));                 //Swap the element of the Row
    }

    // =============================================
    // =============     SCALE       ===============
    // =============================================
    void ScaleRow(int RowNumber, int Scale) {                                       //============= Scale Row =====
        
        if (RowNumber < 0 || Scale == 0 || RowNumber >= Rows)                       //If a something go wrong
            throw std::invalid_argument("Error in Row Number or Scale");            //Get the fuck out

        for (int k = 0; k < Rows; ++k)                                              //For each Row
            (*this)(RowNumber, k) = (*this)(RowNumber, k) * Scale;                  //Swap the element of the Row
    }
    void ScaleColumn(int ColumnNumber, int Scale) {                                 //============= Scale Column ===
        
        if (ColumnNumber < 0 || Scale == 0 || ColumnNumber >= Columns)              //If a something go wrong
            throw std::invalid_argument("Error in Column Number or Scale");         //Get the fuck out

        for (int k = 0; k < Columns; ++k)                                           //For each Row
            (*this)(k, ColumnNumber) = (*this)(k, ColumnNumber) * Scale;            //Swap the element of the Row
    }        

    // =============================================
    // =============     PIVOT       ===============
    // =============================================
    void PivotRow(int Destination, int Reference, int Scale) {                      //============= Pivot Row =====
        
        if (Destination < 0 || Reference < 0)                                       //If we want negative rows
            throw std::invalid_argument("Negative Row");                            //Get the fuck out
        if (Destination >= Rows || Reference >= Rows)                               //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < Rows; ++k)                                              //For each Row
            (*this)(Destination, k) += (*this)(Reference, k) * Scale;                //Swap the element of the Row
    }
    void PivotColumn(int Destination, int Reference, int Scale) {                   //============= Pivot Column ==
        
        if (Destination < 0 || Reference < 0)                                       //If we want negative rows
            throw std::invalid_argument("Negative Row");                            //Get the fuck out
        if (Destination >= Columns || Reference >= Columns)                         //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < Columns; ++k)                                           //For each Row
            (*this)(k, Destination) += (*this)(k, Reference) * Scale;               //Swap the element of the Row
    }

};





// ================================================
// ============  LITTLE MAIN    ===================
// ================================================
int main(void) {

    Matrix<int> M1(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    Matrix<int> NewM1(M1);

    cout << "Before:" << endl << M1 << endl;
    M1.PivotColumn(1, 2, 2);
    cout << "After:" << endl << M1 << endl;

    cout << "Before:" << endl << NewM1 << endl;
    
    auto Identity = Matrix<int>::CreateIdentity(3, 1);
    Identity(2, 1) = 2;

    NewM1 = NewM1 * Identity;
    cout << "After:" << endl << NewM1 << endl;

    if (M1 == NewM1) cout << endl << "Que bonito n.n" << endl;

    return 0;
}


