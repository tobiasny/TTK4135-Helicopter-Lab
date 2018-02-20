%% Initialization and model definition
init09; % Change this to the init file corresponding to your helicopter

%% The new state-space model with elevation and elevation rate
Ac = [0,1,0,0,0,0 ; 0,0,-K_2,0,0,0 ; 0,0,0,1,0,0 ; 0,0,-K_1*K_pp, -K_1*K_pd,0,0; 0,0,0,0,0,1; 0,0,0,0,-K_3*K_ep,-K_3*K_ed];
Bc = [0,0; 0,0; 0,0; K_1*K_pp,0;0,0;0,K_3*K_ep];
delta_t = 0.25;

Ad = eye(6) + delta_t*Ac;
Bd = delta_t*Bc;

% Discrete time system model. x = [lambda r p p_dot]'
delta_t	= 0.25; % sampling time
A1 = Ad;
B1 = Bd;

% Number of states and inputs
mx = size(A1,2); % Number of states (number of columns in A)
mu = size(B1,2); % Number of inputs(number of columns in B)

%Define values for inequality constraints 
alpha = 0.2;
beta = 20;
lambda_t = 2*pi/3; 


% Initial values
x1_0 = pi;                              % Lambda
x2_0 = 0;                               % r
x3_0 = 0;                               % p
x4_0 = 0;                               % p_dot
x5_0 = 0;                               % e
x6_0 = 0;                               % e_dot
x0 = [x1_0 x2_0 x3_0 x4_0 x5_0 x6_0]';  % Initial values

% Time horizon and initialization
N  = 40;                                % Time horizon for states
M  = N;                                 % Time horizon for inputs
z  = zeros(N*mx+M*mu,1);                % Initialize z for the whole horizon
z0 = z;                                 % Initial value for optimization

% Bounds
ul 	    = [-30*pi/180, -inf]';          % Lower bound on control
uu 	    = [30*pi/180, inf]';            % Upper bound on control

xl      = -Inf*ones(mx,1);              % Lower bound on states (no bound)
xu      = Inf*ones(mx,1);               % Upper bound on states (no bound)

xl(3)   = ul(1);                        % Lower bound on state x3
xu(3)   = uu(1);                        % Upper bound on state x3
%xl(6)   = -0.5;
%xu(6)   = 0.5;
xl(2)   = -0.3;
xu(2)   = 0.3;

% Generate constraints on measurements and inputs
[vlb,vub]       = gen_constraints(N,M,xl,xu,ul,uu); % hint: gen_constraints
vlb(N*mx+M*mu)  = 0;                    % We want the last input to be zero
vub(N*mx+M*mu)  = 0;                    % We want the last input to be zero

% Generate the matrix Q and the vector c (objecitve function weights in the QP problem) 
Q1 = zeros(mx,mx);
q1 = 1;
q2 = 1;
Q1(1,1) = 2;                            % Weight on state x1
Q1(2,2) = 0;                            % Weight on state x2
Q1(3,3) = 0;                            % Weight on state x3
Q1(4,4) = 0;                            % Weight on state x4
Q1(5,5) = 0;
Q1(6,6) = 0;
P1 = diag([q1 q2]);                      % Weight on input
Q = gen_q(Q1,P1,N,M);                   % Generate Q, hint: gen_q
c = zeros(320,1)';                      % Generate c, this is the linear constant term in the QP

%% Generate system matrixes for linear model
Aeq = gen_aeq(A1,B1,N,mx,mu);             % Generate A, hint: gen_aeq
beq = zeros(240,1);
b_vector = A1*x0;
for i=1:6
    beq(i)=b_vector(i);
end
[vlb,vub] = gen_constraints(N,M,xl,xu,ul,uu);
A = zeros(320);
B = zeros(320,1);
z0 = zeros(320,1);
z0(1) = pi;

f_objective = @(z) 0.5*z'*Q*z;
lambda_tv = ones(N,1)*lambda_t;
nonl_cons = @(z) deal(alpha.*exp(-beta*(z(1:mx:(N*mx))-lambda_tv).^2) - z(5:mx:N*mx),[]);
opts = optimoptions(@fmincon,'Algorithm','sqp');

tic
z = fmincon(f_objective,z0,A,B,Aeq,beq,vlb,vub,nonl_cons,opts);
t1 = toc;

% Calculate objective value
phi1 = 0.0;
PhiOut = zeros(N*mx+M*mu,1);
for i=1:N*mx+M*mu
  phi1=phi1+Q(i,i)*z(i)*z(i);
  PhiOut(i) = phi1;
end

%% Extract control inputs and states
u1  = [z(N*mx+1:mu:N*mx+M*mu);z((N*mx+M*mu)-1)]; % Control input from solution
u2  = [z(N*mx+2:mu:N*mx+M*mu);z(N*mx+M*mu)]; % Control input from solution

x1 = [x0(1);z(1:mx:N*mx)];              % State x1 from solution
x2 = [x0(2);z(2:mx:N*mx)];              % State x2 from solution
x3 = [x0(3);z(3:mx:N*mx)];              % State x3 from solution
x4 = [x0(4);z(4:mx:N*mx)];              % State x4 from solution
x5 = [x0(5);z(5:mx:N*mx)];              % State x5 from solution
x6 = [x0(6);z(6:mx:N*mx)];              % State x6 from solution

num_variables = 5/delta_t;
zero_padding = zeros(num_variables,1);
unit_padding  = ones(num_variables,1);

u1   = [zero_padding; u1; zero_padding];
u2   = [zero_padding; u2; zero_padding];
x1  = [pi*unit_padding; x1; zero_padding];
x2  = [zero_padding; x2; zero_padding];
x3  = [zero_padding; x3; zero_padding];
x4  = [zero_padding; x4; zero_padding];
x5  = [zero_padding; x5; zero_padding];
x6  = [zero_padding; x6; zero_padding];


%% LQR

Qd = diag([4,2,1,1,10,1]);
Rd = diag([1 1]);

[K,S,e] = dlqr(A1,B1,Qd,Rd);


%% Plotting
t = 0:delta_t:delta_t*(length(u1)-1);

input1.time = t;
input1.signals.values = u1;

input2.time = t;
input2.signals.values = u2;

x1_in.time = t;
x1_in.signals.values = x1;

x2_in.time = t;
x2_in.signals.values = x2;

x3_in.time = t;
x3_in.signals.values = x3;

x4_in.time = t;
x4_in.signals.values = x4;

x5_in.time = t;
x5_in.signals.values = x5;

x6_in.time = t;
x6_in.signals.values = x6;


figure(2)
subplot(811)
stairs(t,u1),grid
ylabel('u1')
subplot(812)
stairs(t,u2),grid
ylabel('u2')
subplot(813)
plot(t,x1,'m',t,x1,'mo'),grid
ylabel('lambda')
subplot(814)
plot(t,x2,'m',t,x2','mo'),grid
ylabel('r')
subplot(815)
plot(t,x3,'m',t,x3,'mo'),grid
ylabel('p')
subplot(816)
plot(t,x4,'m',t,x4','mo'),grid
xlabel('tid (s)'),ylabel('pdot')
subplot(817)
plot(t,x5,'m',t,x5','mo'),grid
xlabel('tid (s)'),ylabel('e')
subplot(818)
plot(t,x6,'m',t,x6','mo'),grid
xlabel('tid (s)'),ylabel('edot')
