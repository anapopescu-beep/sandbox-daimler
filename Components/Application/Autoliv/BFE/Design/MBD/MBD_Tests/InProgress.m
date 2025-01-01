%% --------------------------
%% From Workspace
%% --------------------------
assignin('base','SelectedProfile',xlsread('MBD_Tests\BFE_MBD_Test_00001.xlsx','Test_data','A7:B15007'));

assignin('base','SelectedProfile',[xlsread('MBD_Tests\BFE_MBD_Test_00001.xlsx','Test_data','A7:A15007') xlsread('MBD_Tests\BFE_MBD_Test_00001.xlsx','Test_data','C7:C15007')]);


%% --------------------------
%% 
%% --------------------------



% set Type property of object
dsdd('Set','/Pool/Variables/Kp','Type','Int8');

dsdd('Set','/Pool/Variables/BFE_Config_Data/CFG_au8StepsDefinitions','Value',a') %% avec a un vecteur colonne




%% Calibration data filled with the content of the Calibration sheet from test plan worksheet
% 'Transverse' actions to simplify the excel operations

% creation of the Workspace temp data
TempSteps=ddv('BFE_Config_Data/CFG_au8StepsDefinitions')';
TempProfiles=ddv('BFE_Config_Data/CFG_au8BeltProfilesDefinitions')';

% Assignment in the data dictionnary before test run
dsdd('Set','/Pool/Variables/BFE_Config_Data/CFG_au8StepsDefinitions','Value',TempSteps');
dsdd('Set','/Pool/Variables/BFE_Config_Data/CFG_au8BeltProfilesDefinitions','Value',TempProfiles');

%% -- END --

TempTable=ddv('BFE_Config_Data/CFG_au16AdaptCurrentLimitTempIdx')';
TempTable=[ TempTable ddv('BFE_Config_Data/CFG_au8AdaptCurrentLimitFactors')' ];
plot(TempTable(:,1),TempTable(:,2));

%% recuperation des logs

tl_access_logdata('GetLastSimulationLabel')

blocks = tl_access_logdata('GetLoggedBlocks', tl_access_logdata('GetLastSimulationLabel'));

signallogdata = tl_access_logdata('GetLoggedSignal', 'simlabel', tl_access_logdata('GetLastSimulationLabel'),'block',blocks)


============================> 
signallogdata = tl_access_logdata('GetLoggedSignal', 'simlabel', tl_access_logdata('GetLastSimulationLabel') ,'block',tl_access_logdata('GetLoggedBlocks', tl_access_logdata('GetLastSimulationLabel')));
<============================


%% Extraction des data des plots TL et migration vers un format plus conventionnel
b=timeseries(signallogdata(1,4).signal.y,signallogdata(1,4).signal.t);
b=setinterpmethod(b,'zoh');
c=resample(b,0:0.0004:2);
d=get(c,'Data');
e=squeeze(d);




signallogdata2 = tl_access_logdata('GetLoggedSignal', 'simlabel', tl_access_logdata('GetLastSimulationLabel'),'block','BFE_TestHarness/BFE_AC_BeltFunctionExecution/Subsystem/BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runScheduleStep/BFE_Core/TF_G_113/TempAdaptType_W');
TimeSerie = tl_access_logdata('GetLoggedSignal', 'simlabel', tl_access_logdata('GetLastSimulationLabel'),'block','BFE_TestHarness/BFE_AC_BeltFunctionExecution/Subsystem/BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runScheduleStep/BFE_Core/TF_G_113/TempAdaptType_W','format','timeseries');

