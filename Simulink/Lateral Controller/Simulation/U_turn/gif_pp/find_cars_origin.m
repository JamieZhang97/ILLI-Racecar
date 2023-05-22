num_points = size (out.x_track,1);
num_cars = 6;
len = 0;
xo = [];
yo = [];
theta = [];
psi = [];

for i = 1:(num_points - 1)
    dis = sqrt((out.x_track(i+1) - out.x_track(i))^2 + (out.y_track(i+1) - out.y_track(i))^2);
    len = len + dis;
end
len_list = linspace(0, len, num_cars)

for i = 1:num_cars
    j = 1;
    sum_len = 0;
    while(sum_len < len_list(i))
        sum_len = sum_len + sqrt((out.x_track(j+1) - out.x_track(j))^2 + (out.y_track(j+1) - out.y_track(j))^2);
        j = j + 1;
    end
    xo(end+1) = out.x_track(j)
    yo(end+1) = out.y_track(j);
    theta(end+1) = out.theta_track(j)
    psi(end+1) = out.steering_angle(j)
end