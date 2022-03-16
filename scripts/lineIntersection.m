function Position = lineIntersection(queryLine,refLine,RE,AE)
% Position = lineIntersection(queryLine,refLine,RE,AE)
% Given two line segments and flexibility conditions, this function will judge
% wether the two line segments intersect and, if so, where.
%
% Input:
%  queryLine, refLine: The two lines given as a vector of length 4 with
%  start end and point coordintes: [X1,Y1,X2,Y2]
%
% RE:
%   The relative epsilon, using to judge whether two lines  intersect
%   each other. Default value is 0.3.
% AE:
%   The absolute epsilon, using to judge whter two lines intersect 
%   each other. Default value is 2 pixels.
%
% Return:
% Position:
%   If the lines do intersect, the coordintes [x,y] of the intersection point.
%   Otherwise Position will be empty [].

% first some simple heuristics to kick out obvious cases
if min(queryLine([1,3])) > max(refLine([1,3])) || ...
   max(queryLine([1,3])) < min(refLine([1,3])) || ...
   min(queryLine([2,4])) > max(refLine([1,3])) || ...
   max(queryLine([2,4])) < min(refLine([2,4]))
    Position = [];
    return;
end

Ay = queryLine(3) - queryLine(1);
Ax = queryLine(4) - queryLine(2);
By = refLine(3) - refLine(1);
Bx = refLine(4) - refLine(2);
Cy = refLine(1) - queryLine(1);
Cx = refLine(2) - queryLine(2);

D = Ay * Bx - Ax * By;

warning('off','MATLAB:divideByZero'); % divide by zero is okay here
a = (Bx * Cy - By * Cx) / D;
b = (Ax * Cy - Ay * Cx) / D;

at=min( RE,  AE/max(abs(Ax),abs(Ay))); %calculate the threshold of the ratio
bt=min( RE,  AE/max(abs(Bx),abs(By))); %calculate the threshold of the ratio

if (-at<=a) && (a<=1+at) && (-bt <= b) && (b <= 1+bt)
    A1=queryLine(2)-queryLine(4);
    B1=queryLine(3)-queryLine(1);
    C1=queryLine(1)*queryLine(4)-queryLine(2)*queryLine(3);

    A2=refLine(2)-refLine(4);
    B2=refLine(3)-refLine(1);
    C2=refLine(1)*refLine(4)-refLine(2)*refLine(3);

    D=A1*B2-A2*B1;

    Position(1)=(B1*C2-B2*C1)/D;
    Position(2)=(A2*C1-A1*C2)/D;
else
    Position=[];
end

