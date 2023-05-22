sum_t = 0;
sum_h = 0;
k_l = [];
e_t = [];
e_h = [];

for i = 155:266
    if out.y_track(i) < 1
        if  out.x_track(i) < 1.5
            sum_t = sum_t + abs(out.x_track(i));
            e_t(end + 1) = abs(out.x_track(i));
            sum_h = sum_h + abs(1.5707 - out.theta_track(i));
            e_h(end + 1) = abs(1.5707 - out.theta_track(i));
            
        else
            sum_t = sum_t + abs(3 - out.x_track(i));
            e_t(end + 1) = abs(3 - out.x_track(i));
            sum_h = sum_h + abs(-1.5707 - out.theta_track(i));
            e_h(end + 1) = abs(-1.5707 - out.theta_track(i));
        end
        
    else
        k = (out.y_track(i)-1)/(out.x_track(i) - 1.5);
        k_l(end+1) = k;
        if k > 0
            sum_t = sum_t + abs((1.5 + 1.5/sqrt(k^2 + 1) - out.x_track(i))*sqrt(1 + k^2));
            e_t(end + 1) = abs((1.5 + 1.5/sqrt(k^2 + 1) - out.x_track(i))*sqrt(1 + k^2));
        else
            sum_t = sum_t + abs((1.5 - 1.5/sqrt(k^2 + 1) - out.x_track(i))*sqrt(1 + k^2));
            e_t(end + 1) = abs((1.5 - 1.5/sqrt(k^2 + 1) - out.x_track(i))*sqrt(1 + k^2));
        end
        sum_h = sum_h + abs(atan(-1/k) - out.theta_track(i));
        e_h(end + 1) = abs(atan(-1/k) - out.theta_track(i));
    end
end
avg_track_error = sum_t/112
avg_heading_error = (sum_h/111-4*pi)*180/pi
sd_t = std(e_t)
sd_h = std(e_h)*180/pi
