function [x_lh, y_lh] = fcn(CurrX,CurrY,CurrYaw,l_d)
x = (0:0.01:10);
% y = -0.1*x.*x + 2*x;
y = 10*sin(pi/10*x);

% CurrX = 1;
% CurrY = 1;
% CurrYaw = 0;
% l_d = 1;
% 
x_r = x;
y_r = y;

for i = 1:1001
    x_r(i) = (x(i) - CurrX)*cos(CurrYaw) + (y(i) - CurrY)*sin(CurrYaw);
    y_r(i) = (y(i) - CurrY)*cos(CurrYaw) - (x(i) - CurrX)*sin(CurrYaw);
end

j = 1;
while(x_r(j)<0)
    j = j + 1;
    if j == 1001
        break
    end
end
k = j;

% while(sqrt(x_r(k)*x_r(k) + y_r(k)*y_r(k)) < l_d)
%     if k < 1001
%         k = k + 1;
%     else
%         k = 1001;
%         break
%     end
% end
%     x_lh_r = x_r(k);
%     y_lh_r = y_r(k);

if(sqrt(x_r(k)*x_r(k) + y_r(k)*y_r(k)) < l_d)
    if(k <= 1001)
        while(1)
            k = k + 1;
            if(sqrt(x_r(k)*x_r(k) + y_r(k)*y_r(k)) > l_d)
                x_lh_r = x_r(k);
                y_lh_r = y_r(k);
                break
            end
            if(k > 1001)
                x_lh_r = 2;
                y_lh_r = 0;
                break
            end
        end
    else
        x_lh_r = 2;
        y_lh_r = 0;
    end
else
    x_lh_r = 2;
    y_lh_r = 0;
end
        
x_lh = x_lh_r*cos(-CurrYaw) + y_lh_r*sin(-CurrYaw) + CurrX;
y_lh = y_lh_r*cos(-CurrYaw) - x_lh_r*sin(-CurrYaw) + CurrY;
