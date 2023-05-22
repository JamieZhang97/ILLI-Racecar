Lf = 0.088;
Lr = 0.412;
Wb = 0.324;
Wd = 0.26;
Wr =0.05;
Ww = 0.04;

PI = 3.1415926;
% xo = [0 0 0.4280 2.0671 3.7418 3.9842 4];
% yo = [0.5 1.7569 3.1534 4.0006 2.9768 1.4906 0.2];
% theta = [1.5707 1.5707 0.8852 -0.0809 -1.1356 -1.5399 -1.577];

%draw track
figure
l1 = plot(out.x_ref,out.y_ref,'linewidth',1);
hold on;
l2 = plot(out.x_track,out.y_track, '--','linewidth',2);
hold on;


for i = 1:num_cars
    %find corner of body
    xfl = xo(i) - Wd/2*sin(theta(i)) + Lf*cos(theta(i));
    yfl = yo(i) + Wd/2*cos(theta(i)) + Lf*sin(theta(i));
    
    xfr = xo(i) + Wd/2*sin(theta(i)) + Lf*cos(theta(i));
    yfr = yo(i) - Wd/2*cos(theta(i)) + Lf*sin(theta(i));
    
    xrl = xo(i) - Wd/2*sin(theta(i)) - Lr*cos(theta(i));
    yrl = yo(i) + Wd/2*cos(theta(i)) - Lr*sin(theta(i));
    
    xrr = xo(i) + Wd/2*sin(theta(i)) - Lr*cos(theta(i));
    yrr = yo(i) - Wd/2*cos(theta(i)) - Lr*sin(theta(i));
    
    x = [xfl xfr xrr xrl xfl];
    y = [yfl yfr yrr yrl yfl];
    
    %find wheel center
    xwflo = xo(i) - (Wd - Ww)/2*sin(theta(i));
    ywflo = yo(i) + (Wd - Ww)/2*cos(theta(i));
    
    xwfro = xo(i) + (Wd - Ww)/2*sin(theta(i));
    ywfro = yo(i) - (Wd - Ww)/2*cos(theta(i));
    
    xwrlo = xo(i) - (Wd - Ww)/2*sin(theta(i)) - Wb*cos(theta(i));
    ywrlo = yo(i) + (Wd - Ww)/2*cos(theta(i)) - Wb*sin(theta(i));
    
    xwrro = xo(i) + (Wd - Ww)/2*sin(theta(i)) - Wb*cos(theta(i));
    ywrro = yo(i) - (Wd - Ww)/2*cos(theta(i)) - Wb*sin(theta(i));
    
    xwo = [xwflo xwfro xwrro xwrlo];
    ywo = [ywflo ywfro ywrro ywrlo];
    
    %draw front wheel
    for j = 1:2
        xw_fl = xwo(j) - Ww/2*sin(theta(i) + PI*psi(i)/180) + Wr*cos(theta(i) + PI*psi(i)/180);
        yw_fl = ywo(j) + Ww/2*cos(theta(i) + PI*psi(i)/180) + Wr*sin(theta(i) + PI*psi(i)/180);
        
        xw_fr = xwo(j) + Ww/2*sin(theta(i) + PI*psi(i)/180) + Wr*cos(theta(i) + PI*psi(i)/180);
        yw_fr = ywo(j) - Ww/2*cos(theta(i) + PI*psi(i)/180) + Wr*sin(theta(i) + PI*psi(i)/180);
        
        xw_rr = xwo(j) + Ww/2*sin(theta(i) + PI*psi(i)/180) - Wr*cos(theta(i) + PI*psi(i)/180);
        yw_rr = ywo(j) - Ww/2*cos(theta(i) + PI*psi(i)/180) - Wr*sin(theta(i) + PI*psi(i)/180);
        
        xw_rl = xwo(j) - Ww/2*sin(theta(i) + PI*psi(i)/180) - Wr*cos(theta(i) + PI*psi(i)/180);
        yw_rl = ywo(j) + Ww/2*cos(theta(i) + PI*psi(i)/180) - Wr*sin(theta(i) + PI*psi(i)/180);
        
        xw = [xw_fl xw_fr xw_rr xw_rl xw_fl];
        yw = [yw_fl yw_fr yw_rr yw_rl yw_fl];
        
        wheel = polyshape(xw, yw);
        wheel_vis = plot(wheel);
        wheel_vis.FaceColor = 'black';
        wheel_vis.FaceAlpha = 1;
    end
    
    %draw rear wheel
    for j = 3:4
        xw_fl = xwo(j) - Ww/2*sin(theta(i)) + Wr*cos(theta(i));
        yw_fl = ywo(j) + Ww/2*cos(theta(i)) + Wr*sin(theta(i));
        
        xw_fr = xwo(j) + Ww/2*sin(theta(i)) + Wr*cos(theta(i));
        yw_fr = ywo(j) - Ww/2*cos(theta(i)) + Wr*sin(theta(i));
        
        xw_rr = xwo(j) + Ww/2*sin(theta(i)) - Wr*cos(theta(i));
        yw_rr = ywo(j) - Ww/2*cos(theta(i)) - Wr*sin(theta(i));
        
        xw_rl = xwo(j) - Ww/2*sin(theta(i)) - Wr*cos(theta(i));
        yw_rl = ywo(j) + Ww/2*cos(theta(i)) - Wr*sin(theta(i));
        
        xw = [xw_fl xw_fr xw_rr xw_rl xw_fl];
        yw = [yw_fl yw_fr yw_rr yw_rl yw_fl];
        
        wheel = polyshape(xw, yw);
        wheel_vis = plot(wheel);
        wheel_vis.FaceColor = 'black';
        wheel_vis.FaceAlpha = 1;
    end
        
    car(i) = polyshape(x, y);
    car_vis = plot(car(i));
    car_vis.FaceColor = 'blue';
    plot([xo(i) - (Wd-Ww)/2*sin(theta(i)) xo(i) + (Wd-Ww)/2*sin(theta(i))],[yo(i) + (Wd-Ww)/2*cos(theta(i)) yo(i) - (Wd-Ww)/2*cos(theta(i))],'g', 'linewidth', 2);
    plot([xo(i) - (Wd-Ww)/2*sin(theta(i)) - Wb*cos(theta(i)) xo(i) + (Wd-Ww)/2*sin(theta(i)) - Wb*cos(theta(i))],[yo(i) + (Wd-Ww)/2*cos(theta(i)) - Wb*sin(theta(i)) yo(i) - (Wd-Ww)/2*cos(theta(i)) - Wb*sin(theta(i))], 'g', 'linewidth',2);
%     l3 = plot(xo, yo,'*r');
    hold on;
    plot([xo(i) xo(i) + 0.6*cos(theta(i))], [yo(i) yo(i) + 0.6*sin(theta(i))],'red', 'linewidth',1);
    x_tri = [xo(i)+0.6*cos(theta(i)), xo(i) + 0.6*cos(theta(i)) - 0.15*cos(theta(i)+0.2), xo(i) + 0.6*cos(theta(i)) - 0.15*cos(theta(i)-0.2), xo(i)+0.6*cos(theta(i))]
    y_tri = [yo(i)+0.6*sin(theta(i)), yo(i) + 0.6*sin(theta(i)) - 0.15*sin(theta(i)+0.2), yo(i) + 0.6*sin(theta(i)) - 0.15*sin(theta(i)-0.2), yo(i)+0.6*sin(theta(i))]
    arrow = polyshape(x_tri,y_tri);
    arr = plot(arrow) 
    arr.FaceColor = 'red';
    arr.FaceAlpha = 1;
    arr.EdgeColor = 'red'
    
end

xlim([-0.5 3.5]);
ylim([0 2.5]);
title('Stanley Controller');
xlabel('X(m)');
ylabel('Y(m)');
axis equal;
grid on
legend([l1, l2], 'ground truth', 'actual track');
