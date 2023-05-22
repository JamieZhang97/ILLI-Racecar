x = (0:0.01:10);
% y = -0.1*x.*x + 2*x;
y = 10*sin(pi/10*x);

CurrX = 1;
CurrY = 0;
CurrYaw = pi/2;
l_d = 2;

x_r = x;
y_r = y;

for i = 1:1001
    x_r(i) = (x(i) - CurrX)*cos(CurrYaw) + (y(i) - CurrY)*sin(CurrYaw);
    y_r(i) = (y(i) - CurrY)*cos(CurrYaw) - (x(i) - CurrX)*sin(CurrYaw);
end

j = 1;
while(y_r(j)<0)
    j = j + 1;
end
k = j;

while(sqrt(x_r(k)*x_r(k) + y_r(k)*y_r(k)) < l_d)
    k = k + 1;
end
x_lh_r = x_r(k);
y_lh_r = y_r(k);

x_lh = x_lh_r*cos(-CurrYaw) + y_lh_r*sin(-CurrYaw) + CurrX;
y_lh = y_lh_r*cos(-CurrYaw) - x_lh_r*sin(-CurrYaw) + CurrY;
