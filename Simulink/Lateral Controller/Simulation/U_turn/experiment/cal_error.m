sum_t = 0;
sum_h = 0;
k_l = [];
e_t = [];
e_h = [];
s_l = [];
yaw = [];
pitch = [];
roll = [];
e_l = [];

q_temp = q_x;
q_x = q_y;
q_y = q_temp;
for i = 1:1709
    yaw(i) = atan2(2*(q_w(i)*q_x(i) + q_y(i)*q_z(i)), 1-2*(q_x(i)^2 + q_z(i)^2));  
    pitch(i) = asin(2*(q_w(i)*q_y(i) + q_x(i)*q_z(i)));
    roll(i) = atan2(2*(q_w(i)*q_z(i) + q_x(i)*q_y(i)), 1-2*(q_y(i)^2 + q_z(i)^2));  
    if i > 1045
        pitch(i) = -pi - pitch(i);
    end
    
    
    
    
%     heading(end+1) = atan2(2*q2(1)*q4(1) - 2*q1(1)*q3(1), 1-2*q2(1)^2 - 2*q3(1)^2);
%     attitude(end+1) = asin(2*q1(i)*q2(i) + 2*q3(i)*q4(i));
%     bank(end+1) = atan2(2*q1(i)*q4(i)-2*q2(i)*q3(i) , 1 - 2*q1(i)^2 - 2*q3(i)^2);
%     [yaw(end + 1), pitch(end + 1), roll(end + 1)] = quat2angle([q4(i) q1(i) q2(i) q3(i)]);
%     if yaw(i)<-pi/2
%         yaw(i) = yaw(i) + 2*pi;
%     end
%     if roll(i)>pi/2
%         roll(i) =roll(i) - 2*pi;
%     end
% end
%     plot(yaw);
    %plot(roll);
    %plot(pitch)
%     
%     if Y(i) < 1
%         if i < 1004
%             sum_t = sum_t + abs(X(i));
%             e_t(end + 1) = abs(X(i));   
%             sum_h = sum_h + abs(1.5707 - yaw(i));
%             e_h(end + 1) = abs(1.5707 - yaw(i))-pi/2;
%         else
%             sum_t = sum_t + abs(3 - X(i));
%             e_t(end + 1) = abs(3 - X(i));
%             sum_h = sum_h + abs(-1.5707 - yaw(i));
%             e_h(end + 1) = abs(-1.5707 - yaw(i))-pi/2;
%         end
%         
%     else
%         k = (Y(i)-1)/(X(i) - 1.5);
%         k_l(end+1) = k;
%         if k > 0
%     
%             sum_t = sum_t + abs((1.5 + 1.5/sqrt(k^2 + 1) - X(i))*sqrt(1 + k^2));
%             e_t(end + 1) = abs((1.5 + 1.5/sqrt(k^2 + 1) - X(i))*sqrt(1 + k^2));
%         else
%             sum_t = sum_t + abs((1.5 - 1.5/sqrt(k^2 + 1) - X(i))*sqrt(1 + k^2));
%             e_t(end + 1) = abs((1.5 - 1.5/sqrt(k^2 + 1) - X(i))*sqrt(1 + k^2));
%         end
%         sum_h = sum_h + abs(atan(-1/k) - yaw(i));
%         e_h(end + 1) = abs(atan(-1/k) - yaw(i))-pi/2;
%     end
% end
% 
% for i = 1:2006
%     heading(end + 1) = atan((Y(i+1) - Y(i))/(X(i+1) - X(i)));
% end
% avg_track_error = sum_t/2007
% avg_heading_error = sum_h/2007
% sd_t = std(e_t)
% sd_h = std(e_h)
% 
% 
% for i = 1:2007
%     if e_h(i) > pi/2
%         e_h(i) = pi - e_h(i);   
%     end
% end
end
% plot(roll);
% hold on
% plot(yaw);
% hold on
plot(pitch);
% hold off

for i = 1:1709
    if(i <= 581)
        Yref(i) = 0;
    elseif((i < 1396)&&(i >581))
        Yref(i) = -0.003855*i + 2.2396;
    else
        Yref(i) = -pi;
    end
    e_l(end + 1) = abs(Yref(i) - pitch(i));
    sum_h = sum_h + abs(Yref(i) - pitch(i));
end
a=std(e_l)
e_h = sum_h/1709