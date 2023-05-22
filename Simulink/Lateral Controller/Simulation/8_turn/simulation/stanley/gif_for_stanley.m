for i=1:361
    cla;
    hold on;
    
    title('Stanley Controller');
    xlabel('X(m)');
    ylabel('Y(m)');
    axis equal;
    grid on; 
    axis([-18,18,-9,9]);
    box on;

    
    %plot ground truth & track
    L(1) = plot(out.x_ref, out.y_ref,'linewidth',1)
    L(2) = plot(out.x_track, out.y_track, '--','linewidth',2)
    
    plot(out.x_ref(i), out.y_ref(i),'*b','linewidth',4)
    
    %plot car shape
    car(i) = polyshape(x(i,:), y(i,:));
    car_vis = plot(car(i));
    car_vis.FaceColor = 'blue';
    
    %plot plot two axles
    axle1 = plot([out.x_track(i) - (Wd-Ww)/2*sin(out.theta_track(i)) out.x_track(i) + (Wd-Ww)/2*sin(out.theta_track(i))],[out.y_track(i) + (Wd-Ww)/2*cos(out.theta_track(i)) out.y_track(i) - (Wd-Ww)/2*cos(out.theta_track(i))],'g', 'linewidth', 2)
    axle2 = plot([out.x_track(i) - (Wd-Ww)/2*sin(out.theta_track(i)) - Wb*cos(out.theta_track(i)) out.x_track(i) + (Wd-Ww)/2*sin(out.theta_track(i)) - Wb*cos(out.theta_track(i))],[out.y_track(i) + (Wd-Ww)/2*cos(out.theta_track(i)) - Wb*sin(out.theta_track(i)) out.y_track(i) - (Wd-Ww)/2*cos(out.theta_track(i)) - Wb*sin(out.theta_track(i))], 'g', 'linewidth',2)
    
    %plot velocity vector
    vector = plot([out.x_track(i) out.x_track(i)+0.3*cos(out.theta_track(i))], [out.y_track(i) out.y_track(i)+0.3*sin(out.theta_track(i))],'red', 'linewidth',1);
    
    x_tri = [out.x_track(i)+0.3*cos(out.theta_track(i)), out.x_track(i) + 0.3*cos(out.theta_track(i)) - 0.15*cos(out.theta_track(i)+0.2), out.x_track(i) + 0.3*cos(out.theta_track(i)) - 0.15*cos(out.theta_track(i)-0.2), out.x_track(i)+0.3*cos(out.theta_track(i))];
    y_tri = [out.y_track(i)+0.3*sin(out.theta_track(i)), out.y_track(i) + 0.3*sin(out.theta_track(i)) - 0.15*sin(out.theta_track(i)+0.2), out.y_track(i) + 0.3*sin(out.theta_track(i)) - 0.15*sin(out.theta_track(i)-0.2), out.y_track(i)+0.3*sin(out.theta_track(i))];
    arrow = polyshape(x_tri,y_tri);
    arr = plot(arrow);
    arr.FaceColor = 'red';
    arr.FaceAlpha = 1;
    arr.EdgeColor = 'red';
    
    %plot wheels
    
    wheel_fl = polyshape(xw_fl(i,:),yw_fl(i,:));
    wheel_fl_vis = plot(wheel_fl);
    wheel_fl_vis.FaceColor = 'black';
    wheel_fl_vis.FaceAlpha = 1;
    
    wheel_fr = polyshape(xw_fr(i,:),yw_fr(i,:));
    wheel_fr_vis = plot(wheel_fr);
    wheel_fr_vis.FaceColor = 'black';
    wheel_fr_vis.FaceAlpha = 1;
    
    wheel_rr = polyshape(xw_rr(i,:),yw_rr(i,:));
    wheel_rr_vis = plot(wheel_rr);
    wheel_rr_vis.FaceColor = 'black';
    wheel_rr_vis.FaceAlpha = 1;
    
    wheel_rl = polyshape(xw_rl(i,:),yw_rl(i,:));
    wheel_rl_vis = plot(wheel_rl);
    wheel_rl_vis.FaceColor = 'black';
    wheel_rl_vis.FaceAlpha = 1;
    
    
    
    frame=getframe(gcf);
    imind=frame2im(frame);
    [imind,cm] = rgb2ind(imind,256);
    if i==1
        imwrite(imind,cm,'test.gif','gif', 'Loopcount',inf,'DelayTime',0.0001);
    else
        imwrite(imind,cm,'test.gif','gif','WriteMode','append','DelayTime',0.0001);
    end
    
%     
%    legend(L([1,2]), 'ground truth', 'actual track');
%    set(car_vis,'handlevisibility','off');
%     set(get(get(car_vis,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');
%     set(get(get(axle1,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');
%     set(get(get(axle2,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');
%     set(get(get(vector,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');
%     set(get(get(arr,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');
%     set(get(get(wheel_fl_vis,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');   
%     set(get(get(wheel_fr_vis,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');    
%     set(get(get(wheel_rr_vis,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');   
%     set(get(get(wheel_rl_vis,'Annotation'),'LegendInformation'),'IconDisplayStyle','off');
   
end


