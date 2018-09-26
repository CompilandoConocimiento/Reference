
    // ========================================================
    // =============     GENERAL FUNCTIONS   ==================
    // ========================================================
    
    // ========= TRACE  ========
    T Trace() {                                                                     //Trace a Matrix
        if (rows != columns) throw std::invalid_argument("Not Square Matrix");      //Get the fuck out
        T Result {};                                                                //Start the Result variable
        for (int i = 0; i < rows; ++i) Result += (*this)(i, i);                     //Sum the diagonals
        return Result;                                                              //return it
    }

    // ========= CREATE A IDENTITY MATRIX  ========
    static Matrix<T> CreateIdentity(int Dimension) {                                //Create a Identity
        Matrix<T> Result(Dimension, Dimension);                                     //Create a square matrix
        for (int k = 0; k < Dimension; ++k) (Result)(k, k) = UNIT;                  //Matrix(k, k) = Unity
        return Result;                                                              //Return Indentity
    }

    // ========================================================
    // =============     ELEMENTAL OPERATIONS    ==============
    // ========================================================

    // =============================================
    // =============     SWAP       ================
    // =============================================
    void SwapRow(int Origin, int Destination) {                                     //============ Change Row =====
        
        if (Origin == Destination) return;                                          //If you want to change nothing
        if (Origin < 0 || Destination < 0) throw invalid_argument("Negative Row");  //Get the fuck out
        if (Origin >= rows || Destination >= rows)                                  //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < columns; ++k)                                           //For each Row
            std::swap((*this)(Origin, k), (*this)(Destination, k));                 //Swap the element of the Row
    }
    void SwapColumn(int Origin, int Destination) {                                  //========= Change Column =====
        
        if (Origin == Destination) return;                                          //If you want to change nothing
        if (Origin < 0 || Destination < 0)                                          //If we want negative columns
            throw invalid_argument("Negative Column");                              //Get the fuck out
        if (Origin >= columns || Destination >= columns)                            //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < rows; ++k)                                              //For each Row
            std::swap((*this)(k, Origin), (*this)(k, Destination));                 //Swap the element of the Row
    }

    // =============================================
    // =============     SCALE       ===============
    // =============================================
    void ScaleRow(int RowNumber, T Scale) {                                         //============= Scale Row =====
        
        if (RowNumber < 0 || RowNumber >= rows)                                     //If a something go wrong
            throw std::invalid_argument("Error in Row Number or Scale");            //Get the fuck out

        for (int k = 0; k < columns; ++k)                                           //For each Row
            (*this)(RowNumber, k) = (*this)(RowNumber, k) * Scale;                  //Swap the element of the Row
    }
    void ScaleColumn(int ColumnNumber, T Scale) {                                   //============ Scale Column ===
        
        if (ColumnNumber < 0 || ColumnNumber >= columns)                            //If a something go wrong
            throw std::invalid_argument("Error in Column Number or Scale");         //Get the fuck out

        for (int k = 0; k < rows; ++k)                                              //For each Row
            (*this)(k, ColumnNumber) = (*this)(k, ColumnNumber) * Scale;            //Swap the element of the Row
    }        

    // =============================================
    // =============     PIVOT       ===============
    // =============================================
    void PivotRow(int Destination, int Reference, T Scale) {                        //============= Pivot Row =====

        if (Destination < 0 || Reference < 0)                                       //If we want negative rows
            throw std::invalid_argument("Negative Row");                            //Get the fuck out
        if (Destination >= rows || Reference >= rows)                               //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < columns; ++k)                                           //For each Row
            (*this)(Destination, k) += (*this)(Reference, k) * Scale;               //Swap the element of the Row
    }
    void PivotColumn(int Destination, int Reference, T Scale) {                     //============= Pivot Column ==
        
        if (Destination < 0 || Reference < 0)                                       //If we want negative rows
            throw std::invalid_argument("Negative Row");                            //Get the fuck out
        if (Destination >= columns || Reference >= columns)                         //If you want more that I have 
            throw std::invalid_argument("Out of Bounderies");                       //Get the fuck out

        for (int k = 0; k < rows; ++k)                                              //For each Row
            (*this)(k, Destination) += (*this)(k, Reference) * Scale;               //Swap the element of the Row
    }



    // ========================================================
    // =============     GAUSSIAN ELIMINATION    ==============
    // ========================================================
    void GaussianElimination() {                                                    //Gaussian Elimination Algorithm

        for (int ActualRow = 0, ActualColumn = 0; ActualRow < rows; ++ActualRow) {  //For each Row we will do this:

            if ( abs((*this)(ActualRow, ActualColumn)) <= ZERO)  {                  //If we top element is ZERO D:
                
                bool PivotExistInColumn = false;                                    //Suposse we will never find it
                for (int NewRow = 0; NewRow < rows; NewRow++) {                     //Foreach Row
                    if ( abs((*this)(ActualRow, ActualColumn)) <= ZERO ) continue;  //If this row is the same, pass

                    SwapRow(ActualRow, NewRow);                                     //Swap the rows now
                    PivotExistInColumn = true;                                      //We find the pivot :p
                    break;                                                          //So go the fuck out
                }
                if (PivotExistInColumn == false) {ActualColumn++; continue;}        //If no pivot, go to next row
            }

            ScaleRow(ActualRow, UNIT/((*this)(ActualRow, ActualColumn)) );          //Now put the top element to UNIT

            for (int i = ActualRow + 1; i < rows; i++)                              //Foreach row below
                PivotRow(i, ActualRow, -UNIT * (*this)(i, ActualColumn));           //Make the column to 0

            ActualColumn++;                                                         //Next element is one below
        }

        for (T &Element : data) if (abs(Element) <= ZERO) Element = abs(Element);   //Remove the stupid -0
    } 

};


    


