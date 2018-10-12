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
    size_t Rows;                                                                       //Number of Rows
    size_t Columns;                                                                    //Number of Columns

    static inline T UNIT;                                                           //What is 0 where
    static inline T ZERO;                                                           //What is 1 where

    vector<T> Data;                                                                 //Not best implementation :(

  public:                                                                           //=== Public Stuff ===
    
    // ================================================
    // =============  CONSTRUCTOR    ==================
    // ================================================

    // == GENERAL-EMPTY CONSTRUCTOR ==
    Matrix(size_t Rows, size_t Columns) {                                                 //General Constructor
        if (Rows < 1 || Columns < 1)                                                //If stupid size entered :/
            throw std::invalid_argument("Received Incompatible size Matrices");     //Get the fuck out
        
        this->Rows = Rows;                                                          //Set the Rows size
        this->Columns = Columns;                                                    //Set the Columns size

        Data.resize(Rows * Columns);                                                //Allocate space
    }

    // == POPULATE CONSTRUCTOR ==
    Matrix(size_t Rows, size_t Columns, const vector<T> &Data):                           //Delegate Construtor
    Matrix(Rows, Columns) {                                                         //Call this constructor
        Populate(Data);                                                             //Now call this
    }

    // == POPULATE LAMDA CONSTRUCTOR ==
    template<typename F>                                                            //F is for Function
    Matrix(size_t Rows, size_t Columns, F&& Function):                                    //Delegate Construtor
    Matrix(Rows, Columns) {                                                         //Call this constructor
        Populate(Function);                                                         //Now call this
    }



    // ================================================
    // ========  GENERAL FUNCTIONS  ===================
    // ================================================


    // == GETTERS ==
    size_t GetRows() const { return Rows; }                                            //Getter for Rows
    size_t GetColumns() const { return Columns; }                                      //Getter for Columns

    static T GetUNIT() { return UNIT; }                                              //Getter for Unit
    static T GetZERO() { return ZERO; }                                              //Getter for Zero

    static void SetUNIT(T Unit) { UNIT = Unit; }                                     //Setter for Unit
    static void SetZERO(T Zero) { ZERO = Zero; }                                     //Setter for Zero

    // == POPUTALE THE MATRIX WITH INFO ==
    void Populate (const vector<T> &NewData) {                                      //Populate the Data Matrix
        if (NewData.size() < (Columns * Rows))                                      //Check the size
            throw std::invalid_argument("Not enough data in vector");               //Get the fuck out

        Data = NewData;
        Data.resize(Rows * Columns);                                                //Allocate space
    }

    // == POPULATE WITH A FUNCTION ==
    template<typename F>                                                            //F is for Function
    void Populate(F&& Function) {                                                   //Populate with a function
        for (size_t i = 0; i < Rows; ++i)                                              //Foreach resultant Row
            for (size_t j = 0; j < Columns; ++j)                                       //Foreach resultant Columns
                (*this)(i, j) = Function(*this, i, j);                              //Call the function to get value
    }

    // == SHOW THE MATRIX ==
    friend ostream& operator<< (ostream& out, const Matrix<T> &ThatMatrix) {        //Overload << (not member)
        
        for (size_t i = 0; i < ThatMatrix.GetRows(); ++i) {                            //Foreach Row
            for (size_t j = 0; j < ThatMatrix.GetColumns(); ++j)                       //Foreach Columns
                out << (ThatMatrix)(i, j) << "\t";                                   //Show me
            out << std::endl;
        }

        return out;
    }

    // == SHOW ITEMS INSIDE THE MATRIX ==
    T& operator()(size_t Row, size_t Column) {                                            //Call on a T& object
        if (Row < 0 || Column < 0 || Row >= Rows || Column >= Columns)              //If you are out
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        return this->Data[(Row * Columns) + Column];                                //Go, true identity
    }            
    T operator()(size_t Row, size_t Column) const {
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

    // ====a===== SWAP  ========================
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

        for (size_t i = 0; i < Rows; ++i) {                                            //Foreach resultant Row
            for (size_t j = 0; j < Columns; ++j)                                       //Foreach resultant Columns
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

        for (size_t i = 0; i < Rows; ++i) {                                            //Foreach Row
            for (size_t j = 0; j < Columns; ++j)                                       //Foreach Columns
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

        for (size_t i = 0; i < Rows; ++i) {                                            //Foreach Row
            for (size_t j = 0; j < Columns; ++j)                                       //Foreach Columns
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

        for (size_t i = 0; i < this->Rows; ++i) {                                      //Foreach resultant Row
            for (size_t j = 0; j < that.Columns; ++j) {                                //Foreach resultant Columns
        
                Result(i, j) = T {};                                                //Ok, let start in 0
                for (size_t k = 0; k < this->Columns; ++k)                             //Travel  0..n or 0..Columns
                    Result(i, j) += ( (*this)(i, k) * (that)(k, j) );               //this place is sum of things

            }
        }

        return Result;                                                              //Return the result matrix
    }


    // ========================================================
    // =============     GENERAL FUNCTIONS   ==================
    // ========================================================
    
    // ========= TRACE  ========
    T Trace() {                                                                     //Trace a Matrix
        if (Rows != Columns) throw std::invalid_argument("Not Square Matrix");      //Get the fuck out
        T Result {};                                                                //Start the Result variable
        for (size_t i = 0; i < Rows; ++i) Result += (*this)(i, i);                     //Sum the diagonals
        return Result;                                                              //return it
    }

    // ========= CREATE A IDENTITY MATRIX  ========
    static Matrix<T> CreateIdentity(size_t Dimension) {                                //Create a Identity
        Matrix<T> Result(Dimension, Dimension);                                     //Create a square matrix
        for (size_t k = 0; k < Dimension; ++k) (Result)(k, k) = UNIT;                  //Matrix(k, k) = Unity
        return Result;                                                              //Return Indentity
    }

    // ========================================================
    // =============     ELEMENTAL OPERATIONS    ==============
    // ========================================================

    // =============================================
    // =============     SWAP       ================
    // =============================================
    void SwapRow(size_t Origin, size_t Destination) {                                     //============ Change Row =====
        
        if (Origin == Destination) return;                                          //If you want to change nothing
        if (Origin < 0 || Destination < 0) throw invalid_argument("Negative Row");  //Get the fuck out
        if (Origin >= Rows || Destination >= Rows)                                  //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (size_t k = 0; k < Columns; ++k)                                           //For each Row
            std::swap((*this)(Origin, k), (*this)(Destination, k));                 //Swap the element of the Row
    }
    void SwapColumn(size_t Origin, size_t Destination) {                                  //========= Change Column =====
        
        if (Origin == Destination) return;                                          //If you want to change nothing
        if (Origin < 0 || Destination < 0)                                          //If we want negative columns
            throw invalid_argument("Negative Column");                              //Get the fuck out
        if (Origin >= Columns || Destination >= Columns)                            //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (size_t k = 0; k < Rows; ++k)                                              //For each Row
            std::swap((*this)(k, Origin), (*this)(k, Destination));                 //Swap the element of the Row
    }

    // =============================================
    // =============     SCALE       ===============
    // =============================================
    void ScaleRow(size_t RowNumber, T Scale) {                                         //============= Scale Row =====
        
        if (RowNumber < 0 || RowNumber >= Rows)                                     //If a something go wrong
            throw std::invalid_argument("Error in Row Number or Scale");            //Get the fuck out

        for (size_t k = 0; k < Columns; ++k)                                           //For each Row
            (*this)(RowNumber, k) = (*this)(RowNumber, k) * Scale;                  //Swap the element of the Row
    }
    void ScaleColumn(size_t ColumnNumber, T Scale) {                                   //============ Scale Column ===
        
        if (ColumnNumber < 0 || ColumnNumber >= Columns)                            //If a something go wrong
            throw std::invalid_argument("Error in Column Number or Scale");         //Get the fuck out

        for (size_t k = 0; k < Rows; ++k)                                              //For each Row
            (*this)(k, ColumnNumber) = (*this)(k, ColumnNumber) * Scale;            //Swap the element of the Row
    }        

    // =============================================
    // =============     PIVOT       ===============
    // =============================================
    void PivotRow(size_t Destination, size_t Reference, T Scale) {                        //============= Pivot Row =====

        if (Destination < 0 || Reference < 0)                                       //If we want negative rows
            throw std::invalid_argument("Negative Row");                            //Get the fuck out
        if (Destination >= Rows || Reference >= Rows)                               //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (size_t k = 0; k < Columns; ++k)                                           //For each Row
            (*this)(Destination, k) += (*this)(Reference, k) * Scale;               //Swap the element of the Row
    }
    void PivotColumn(size_t Destination, size_t Reference, T Scale) {                     //============= Pivot Column ==
        
        if (Destination < 0 || Reference < 0)                                       //If we want negative rows
            throw std::invalid_argument("Negative Row");                            //Get the fuck out
        if (Destination >= Columns || Reference >= Columns)                         //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (size_t k = 0; k < Rows; ++k)                                              //For each Row
            (*this)(k, Destination) += (*this)(k, Reference) * Scale;               //Swap the element of the Row
    }



    // ========================================================
    // =============     GAUSSIAN ELIMINATION    ==============
    // ========================================================
    void GaussianElimination() {                                                    //Gaussian Elimination Algorithm

        for (size_t ActualRow = 0, ActualColumn = 0; ActualRow < Rows; ++ActualRow) {  //For each Row we will do this:

            std::cout << *(this) << endl; 

            if ( abs((*this)(ActualRow, ActualColumn)) <= ZERO)  {                  //If we top element is ZERO D:
                
                bool PivotExistInColumn = false;                                    //Suposse we will never find it
                for (size_t NewRow = 0; NewRow < Rows; NewRow++) {                     //Foreach Row
                    if ( abs((*this)(ActualRow, ActualColumn)) <= ZERO ) continue;  //If this row is the same, pass

                    SwapRow(ActualRow, NewRow);                                     //Swap the rows now
                    PivotExistInColumn = true;                                      //We find the pivot :p
                    break;                                                          //So go the fuck out
                }
                if (PivotExistInColumn == false) {ActualColumn++; continue;}        //If no pivot, go to next row
            }

            ScaleRow(ActualRow, UNIT/((*this)(ActualRow, ActualColumn)) );          //Now put the top element to UNIT

            std::cout << *(this) << endl; 


            for (size_t i = 0; i < Rows; i++) {                                        //Foreach row below
                if (i == ActualColumn) continue;
                PivotRow(i, ActualRow, -UNIT * (*this)(i, ActualColumn));           //Make the column to 0
                std::cout << *(this) << endl; 
            }

            ActualColumn++;                                                         //Next element is one below
        }

        for (T &Element : Data) if (abs(Element) <= ZERO) Element = abs(Element);   //Remove the stupid -0
    } 

};


    













// ================================================
// ============  LITTLE MAIN    ===================
// ================================================
size_t main(void) {

    Matrix<double>::SetUNIT(1);
    Matrix<double>::SetZERO(1e-10);

    Matrix<double> M1(3, 6, {
        1   ,  4    ,  6    , 1  , 0, 0 , 
        -3  , -7    , -8    , 0  , 1, 0 , 
        2   ,  12   , 17    , 0  , 0, 1 , 
    });

    cout << "Before:" << endl << M1 << endl;

    M1.GaussianElimination();

    cout << "After:" << endl << M1 << endl;


    return 0;
}
