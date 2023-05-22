%car parameter
Lf = 0.412;
Lr = 0.088;
Wb = 0.324;
Wd = 0.26;
Wr =0.05;
Ww = 0.04;

%car body vertex
x=[];
y=[];

%wheel center
xwo = [];
ywo = [];

%wheel vertex
xw = [];
yw = [];

%front left wheel vertex
xw_fl = [];
yw_fl = [];

%front right wheel vertex
xw_fr = [];
yw_fr = [];

%rear right wheel vertex
xw_rr = [];
yw_rr = [];

%rear left wheel vertex
xw_rl = [];
yw_rl = [];


for i=1:141
        
    %find car body vertex
    xfl = out.x_track(i) - Wd/2*sin(out.theta_track(i)) + Lf*cos(out.theta_track(i));
    yfl = out.y_track(i) + Wd/2*cos(out.theta_track(i)) + Lf*sin(out.theta_track(i));
    
    xfr = out.x_track(i) + Wd/2*sin(out.theta_track(i)) + Lf*cos(out.theta_track(i));
    yfr = out.y_track(i) - Wd/2*cos(out.theta_track(i)) + Lf*sin(out.theta_track(i));
    
    xrl = out.x_track(i) - Wd/2*sin(out.theta_track(i)) - Lr*cos(out.theta_track(i));
    yrl = out.y_track(i) + Wd/2*cos(out.theta_track(i)) - Lr*sin(out.theta_track(i));
    
    xrr = out.x_track(i) + Wd/2*sin(out.theta_track(i)) - Lr*cos(out.theta_track(i));
    yrr = out.y_track(i) - Wd/2*cos(out.theta_track(i)) - Lr*sin(out.theta_track(i));
    
    x(i, :) = [xfl xfr xrr xrl xfl];
    y(i, :) = [yfl yfr yrr yrl yfl];


    %find wheel center
    xwflo = out.x_track(i) - (Wd - Ww)/2*sin(out.theta_track(i)) + Wb*cos(out.theta_track(i));
    ywflo = out.y_track(i) + (Wd - Ww)/2*cos(out.theta_track(i)) + Wb*sin(out.theta_track(i));
    
    xwfro = out.x_track(i) + (Wd - Ww)/2*sin(out.theta_track(i)) + Wb*cos(out.theta_track(i));
    ywfro = out.y_track(i) - (Wd - Ww)/2*cos(out.theta_track(i)) + Wb*sin(out.theta_track(i));
    
    xwrlo = out.x_track(i) - (Wd - Ww)/2*sin(out.theta_track(i));
    ywrlo = out.y_track(i) + (Wd - Ww)/2*cos(out.theta_track(i));
    
    xwrro = out.x_track(i) + (Wd - Ww)/2*sin(out.theta_track(i));
    ywrro = out.y_track(i) - (Wd - Ww)/2*cos(out.theta_track(i));
    
    xwo (i, :)= [xwflo xwfro xwrro xwrlo];
    ywo (i, :) = [ywflo ywfro ywrro ywrlo];
    
    
    %find front_left wheel vertex
    
    xw_fl_fl = xwo(i,1) - Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) + Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fl_fl = ywo(i,1) + Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) + Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fl_fr = xwo(i,1) + Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) + Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fl_fr = ywo(i,1) - Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) + Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fl_rr = xwo(i,1) + Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) - Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fl_rr = ywo(i,1) - Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) - Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fl_rl = xwo(i,1) - Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) - Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fl_rl = ywo(i,1) + Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) - Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fl(i, :) = [xw_fl_fl xw_fl_fr xw_fl_rr xw_fl_rl xw_fl_fl];
    yw_fl(i, :) = [yw_fl_fl yw_fl_fr yw_fl_rr yw_fl_rl yw_fl_fl];
 
    
    %find front_right wheel vertex
    
    xw_fr_fl = xwo(i,2) - Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) + Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fr_fl = ywo(i,2) + Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) + Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fr_fr = xwo(i,2) + Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) + Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fr_fr = ywo(i,2) - Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) + Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fr_rr = xwo(i,2) + Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) - Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fr_rr = ywo(i,2) - Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) - Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fr_rl = xwo(i,2) - Ww/2*sin(out.theta_track(i) + out.steering_angle(i)) - Wr*cos(out.theta_track(i) + out.steering_angle(i));
    yw_fr_rl = ywo(i,2) + Ww/2*cos(out.theta_track(i) + out.steering_angle(i)) - Wr*sin(out.theta_track(i) + out.steering_angle(i));
    
    xw_fr(i, :) = [xw_fr_fl xw_fr_fr xw_fr_rr xw_fr_rl xw_fr_fl];
    yw_fr(i, :) = [yw_fr_fl yw_fr_fr yw_fr_rr yw_fr_rl yw_fr_fl];   
    
    
    %find rear_right wheel vertex
    
    xw_rr_fl = xwo(i,3) - Ww/2*sin(out.theta_track(i)) + Wr*cos(out.theta_track(i));
    yw_rr_fl = ywo(i,3) + Ww/2*cos(out.theta_track(i)) + Wr*sin(out.theta_track(i));
    
    xw_rr_fr = xwo(i,3) + Ww/2*sin(out.theta_track(i)) + Wr*cos(out.theta_track(i));
    yw_rr_fr = ywo(i,3) - Ww/2*cos(out.theta_track(i)) + Wr*sin(out.theta_track(i));
    
    xw_rr_rr = xwo(i,3) + Ww/2*sin(out.theta_track(i)) - Wr*cos(out.theta_track(i));
    yw_rr_rr = ywo(i,3) - Ww/2*cos(out.theta_track(i)) - Wr*sin(out.theta_track(i));
    
    xw_rr_rl = xwo(i,3) - Ww/2*sin(out.theta_track(i)) - Wr*cos(out.theta_track(i));
    yw_rr_rl = ywo(i,3) + Ww/2*cos(out.theta_track(i)) - Wr*sin(out.theta_track(i));
    
    xw_rr(i, :) = [xw_rr_fl xw_rr_fr xw_rr_rr xw_rr_rl xw_rr_fl];
    yw_rr(i, :) = [yw_rr_fl yw_rr_fr yw_rr_rr yw_rr_rl yw_rr_fl]; 
    
    
    %find rear_left wheel vertex
    
    xw_rl_fl = xwo(i,4) - Ww/2*sin(out.theta_track(i)) + Wr*cos(out.theta_track(i));
    yw_rl_fl = ywo(i,4) + Ww/2*cos(out.theta_track(i)) + Wr*sin(out.theta_track(i));
    
    xw_rl_fr = xwo(i,4) + Ww/2*sin(out.theta_track(i)) + Wr*cos(out.theta_track(i));
    yw_rl_fr = ywo(i,4) - Ww/2*cos(out.theta_track(i)) + Wr*sin(out.theta_track(i));
    
    xw_rl_rr = xwo(i,4) + Ww/2*sin(out.theta_track(i)) - Wr*cos(out.theta_track(i));
    yw_rl_rr = ywo(i,4) - Ww/2*cos(out.theta_track(i)) - Wr*sin(out.theta_track(i));
    
    xw_rl_rl = xwo(i,4) - Ww/2*sin(out.theta_track(i)) - Wr*cos(out.theta_track(i));
    yw_rl_rl = ywo(i,4) + Ww/2*cos(out.theta_track(i)) - Wr*sin(out.theta_track(i));
    
    xw_rl(i, :) = [xw_rl_fl xw_rl_fr xw_rl_rr xw_rl_rl xw_rl_fl];
    yw_rl(i, :) = [yw_rl_fl yw_rl_fr yw_rl_rr yw_rl_rl yw_rl_fl]; 
    
end