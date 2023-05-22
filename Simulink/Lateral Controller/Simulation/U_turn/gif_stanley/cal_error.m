sum_t = 0;
sum_h = 0;
k_l = [];

for i = 1:79
    if out.y_track(i) < 1
        if i < 40
            sum_t = sum_t + abs(out.x_track(i));
            sum_h = sum_h + abs(1.5707 - out.theta_track(i));
        else
            sum_t = sum_t + abs(3 - out.x_track(i));
            sum_h = sum_h + abs(-1.5707 - out.theta_track(i));
        end
        
    else
        k = (out.y_track(i)-1)/(out.x_track(i) - 1.5);
        k_l(end+1) = k;
        if k > 0
            sum_t = sum_t + abs((1.5 + 1.5/sqrt(k^2 + 1) - out.x_track(i))*sqrt(1 + k^2));
        else
            sum_t = sum_t + abs((1.5 - 1.5/sqrt(k^2 + 1) - out.x_track(i))*sqrt(1 + k^2));
        end
        sum_h = sum_h + abs(atan(-1/k) - out.theta_track(i));
    end
end
avg_track_error = sum_t/79
avg_heading_error = sum_h/79