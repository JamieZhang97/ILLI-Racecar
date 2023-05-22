sum_t = 0;
sum_h = 0;
k_l = [];
e_t = [];
e_h = [];

for i = 1:1:251
    
    if out.x_track(i) >= 0
        k = (out.y_track(i))/(out.x_track(i) - 1);
        k_l(end+1) = k;
        sum_t = sum_t + abs(sqrt((out.x_track(i) - 1)^2 + out.y_track(i)^2) - 1);
        e_t(end + 1) = abs(sqrt((out.x_track(i) - 1)^2 + out.y_track(i)^2) - 1);
    else
        k = (out.y_track(i))/(out.x_track(i) + 1);
        k_l(end+1) = k;
        sum_t = sum_t + abs(sqrt((out.x_track(i) + 1)^2 + out.y_track(i)^2) - 1);
        e_t(end + 1) = abs(sqrt((out.x_track(i) + 1)^2 + out.y_track(i)^2) - 1);
    end
    
    h = abs(atan(-1/k) - out.theta_track(i));
    if (h > 2)
        h = h-pi;
        if (h > 2)
            h = h-pi;
        end
    end
    sum_h = sum_h + h;
    e_h(end + 1) = h;
    
end


avg_track_error = sum_t/251
avg_heading_error = (sum_h/251)*180/pi
sd_t = std(e_t)
sd_h = std(e_h)*180/pi
