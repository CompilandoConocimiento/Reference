// Factor A as PA = LU = Pb
// @param: A a not singular matrix
// @return: L lower triangule matrix
// @return: U upper triangule matrix
// @return: P permutation matrix 

function[L, U, P] = PartialLUDecomposition(A)
    [m,n]=size(A);//Obtenemos las dimensión de la matriz
    M=eye(m,n);//Matriz que guarda la inversa de cada matriz de eliminación 
    P=eye(n,n);//Matriz que guarda la matriz de permutación
    L=eye(n,n);//Matriz que guarda la matriz L
    for k=(1:n-1)
        [A,Pi]=PivoteoP(A,k)//Obtenemos las matrices Pi y permutamos A
        P=Pi*P;
        for i=(k+1:n)
            M(i,k)=A(i,k)/A(k,k);//Guardamos las inversas de M
        end
        PinvM=Pi'*M;
        //Obtenemos la matriz L
        L=L*PinvM;
        for j=(1:n)
            for i=(k+1:n)
                A(i,j)=A(i,j)-M(i,k)*A(k,j);//Renombramos la matriz A con eliminación 
            end
        end
        M=eye(m,n);
    end
    //Finalmente obtenemos la matriz U;
    U=A;
endfunction
//Parámetros de entrada
//P:Matriz de permutación 
//L,U: Matrices de nxn que cumplen que LU=A (L no es necesariamente triángular inferior)

//Función que realiza el intercamcio de filas 
//del pivoteo parcial según el índice i
//Parámetros de entrada 
//A: Una matriz mxn
//i: Indice que hace refrerencia sobre que columna de A se hace el pivoteo
function[A,Pi]=PivoteoP(A,i)
   [m,n]=size(A);//Obtenemos la dimensión de A
   Pi=eye(m,n);//Matriz de permutación Pi corrspondiente 
   [num,pos]= max(abs(A(i:n,i)));//Obtenemos la posición del máximo por columna 
   pos=pos+(i-1);//Reasignamos el valor de la posición del máximo de acuerdo a la diagonal i
   Pi=CambiaF(Pi,i,pos);//Intercambinamos las filas de acuerdo a pos e i 
   A=CambiaF(A,i,pos);;//Obtenemos la permutación de Pi de A
endfunction
//Parámetros de Salida
//A:Matriz con Pivoteo Parcial en la i-ésima columna 
//Pi:Matriz de la i-ésiama permutación

//Función que realiza el intercamcio de filas 
//dados un índice i y j 
//Parámetros de entrada 
//M: Una matriz mxn
//i,j: Indices de referencia para el intercambio de filas
function[M]=CambiaF(M,i,j)
    //Realizamo el intercambio de filas 
    aux=M(i,:);
    M(i,:)=M(j,:);
    M(j,:)=aux;
endfunction
//Parámetros de Salida
//M:Matriz con intercambio de fila i,j
