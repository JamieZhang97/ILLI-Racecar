a_3 = -5;
a_2 = 0;
a_1 = 0;
a_0 = 0;
l_h = 0.5
i = 0;
xo = [];
yo = [];

while(1)
    x_t = i;
    y_t = a_3*i^3 + a_2*i^2 + a_1*i + a_0;
    xo(end+1) = x_t;
    yo(end+1) = y_t;
    d_t = sqrt(x_t^2 + y_t^2);
    if(d_t >= l_h)
        x_lh = x_t;
        y_lh = y_t;
        break;  
    else
    i = i + 0.01;
    end
  
end

    plot(xo,yo);