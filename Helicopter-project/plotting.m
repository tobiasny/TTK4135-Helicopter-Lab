%% Plotting

%load_system('helikopter_task3')
%sim('helikopter_task3')

load('measured_pitch.mat')
load('measured_travel.mat')
load('measured_time.mat')

figure(1)

subplot(211)
plot(measured_pitch(1,:),measured_pitch(2,:), 'LineWidth', 4)
hold on
plot(t,x3, '--', 'LineWidth', 4)
grid on
title(['Optimal trajectory of pitch $p*$ vs measured pitch p'], 'Interpreter', 'latex')
xlabel('t [s]'); ylabel('Angle [rad]')
legend({'$p$','$p*$'}, 'Interpreter', 'latex')

subplot(212)
plot(measured_travel(1,:),measured_travel(2,:), 'LineWidth', 4)
hold on
plot(t,x1, '--', 'LineWidth', 4)
grid on
title(['Optimal trajectory of travel $\lambda^*$ vs measured travel $\lambda$'], 'Interpreter', 'latex')
legend({'$\lambda$','$\lambda*$'}, 'Interpreter', 'latex')
xlabel('t [s]'); ylabel('Angle [rad]')




