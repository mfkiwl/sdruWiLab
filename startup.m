% Generate Path for folders
if exist('pathdef.m', 'file') == 2
	system('rm pathdef.m');
end
P = genpath(pwd);
addpath(P);
savepath;

% Setup SDRU
sdruPath = '../USRPDriver';
addpath(genpath(sdruPath));
setupsdru(sdruPath);
usrp_startup;
