  function [Q,R] = clgs(A)
      [m,n] = size(A);
      Q = zeros(m, n);
      R = zeros(n, n);
      v = zeros(m,n);
      for j = 1:n
          v(:,j) = A(:,j);
          for i = 1:j-1
              R(i,j) = conj(Q(:,i)')*A(:,j);
              v(:,j) = v(:,j) - R(i,j)*Q(:,i);
          end
      R(j,j) = norm(v(:,j),2);
      Q(:,j) = (1/R(j,j))*v(:,j);
      end
  end
