// Factor A as A = LU
// @param: A a not singular matrix
// @return: L lower triangule matrix
// @return: U upper triangule matrix
// @return: P permutation matrix 

// To solve use A = LU
// y = FS(PL, Pb)
// x = BS(U, y)

function[L, U, P] = PartialLUDecomposition(A)
    [m, n] = size(A);
    P = eye(m, n);
    L = eye(m, n);
    U = A;

    for step = (1 : n - 1)
        
        maxPivotRow = step;
        for posibility = (step + 1 : n)
            if abs(U(posibility, step)) > U(maxPivotRow, step)
                maxPivotRow = posibility
            end
        end

        if (A(step, step) == 0)
            error('Error: Singular matrix');
            return;
        end

        Pstep = eye(m, n);
        ElimitationMatrix = eye(m, n);
        
        for element = (1 : n)
            temporal = U(step, element)
            U(step, element) = U(maxPivotRow, element)
            U(maxPivotRow, element) = temporal

            temporal = P(step, element)
            P(step, element) = P(maxPivotRow, element)
            P(maxPivotRow, element) = temporal

            temporal = Pstep(step, element)
            Pstep(step, element) = Pstep(maxPivotRow, element)
            Pstep(maxPivotRow, element) = temporal
        end
            
        for row = (step + 1 : n)
            ElimitationMatrix(row, step) = U(row, step) / U(step, step);

            for column = (1 : n)
                U(row, column) = U(row, column) - (ElimitationMatrix(row, step) * U(step, column));
            end
        end

        L = L * (Pstep' * ElimitationMatrix);
    end
endfunction


function [L,U,P]=LU_pivot(A)
    [n,n]=size(A);
    L=eye(n); 
    P=L;
    U=A;
    
    for k = (1:n)
        [pivot m] = max(abs(U(k:n,k)));
        m = m+k-1;
        
        if m~=k
            // interchange rows m and k in U

            disp(m)
            disp(k)

            temp=U(k,:);
            U(k,:)=U(m,:);
            U(m,:)=temp;

            // interchange rows m and k in P
            temp=P(k,:);
            P(k,:)=P(m,:);
            P(m,:)=temp;

            if k >= 2
                temp=L(k,1:k-1);
                L(k,1:k-1)=L(m,1:k-1);
                L(m,1:k-1)=temp;
            end
        end

        for j=k+1:n
            L(j,k)=U(j,k)/U(k,k);
            U(j,:)=U(j,:)-L(j,k)*U(k,:);
        end
    end
endfunction