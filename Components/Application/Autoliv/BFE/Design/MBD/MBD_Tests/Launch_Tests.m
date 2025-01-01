%% Script to launch a test 

TestFileName='MBD_Tests\BFE_MBD_Test_00008.xlsx';

%TimeArray = xlsread(TestFileName,'Test_Data', ['A' int2str(TimeLineStart) ':A' int2str(TimeLineEnd)]);
%for iLoopIndex=1 : TimeLineEnd-TimeLineStart+1
%    TimeArray(iLoopIndex)= round(TimeArray(iLoopIndex)*10000)/10000;
%end
TimeArray=(0:0.0004:3)';

for iLoopIndex=1 : 1 : InputsSize
    assignin('base',InputsCfgArray{iLoopIndex,1}, [TimeArray  xlsread(TestFileName,'Test_Data',[InputsCfgArray{iLoopIndex,2} int2str(TimeLineStart) ':' InputsCfgArray{iLoopIndex,2} int2str(TimeLineEnd)])]);
end
for iLoopIndex=1 : 1 : OutputsSize
    assignin('base',OutputsCfgArray{iLoopIndex,1}, [TimeArray  xlsread(TestFileName,'Test_Data',[OutputsCfgArray{iLoopIndex,2} int2str(TimeLineStart) ':' OutputsCfgArray{iLoopIndex,2} int2str(TimeLineEnd)])]);
end

%TempSteps=ddv('BFE_Config_Data/CFG_au8StepsDefinitions')';
%TempProfiles=ddv('BFE_Config_Data/CFG_au8BeltProfilesDefinitions')';

dsdd('Set','/Pool/Variables/BFE_Config_Data/CFG_au8BeltProfilesDefinitions','Value',xlsread(TestFileName,'Calibration_Data','B5:B208')');
dsdd('Set','/Pool/Variables/BFE_Config_Data/CFG_au8StepsDefinitions','Value',xlsread(TestFileName,'Calibration_Data','C5:C484')');
%% Run the test after updating the Workspace global data
%sim('BFE_TestHarness');
tlsystems=get_tlsubsystems(bdroot);
for i=1:length(tlsystems)
   tlSubsysName = get_param(tlsystems{i}, 'Name');
end

% Deactivate 'clean code' option in order to be able to log internal data.
tl_set(bdroot,'codeopt.cleancode',0);

if isequal(tl_get_sim_mode('TlSubsystems', tlSubsysName),'TL_BLOCKS_HOST')
    tl_sim(bdroot);
end
if isequal(tl_get_sim_mode('TlSubsystems', tlSubsysName),'TL_CODE_HOST')
    tl_build_host;
    tl_sim(bdroot);
end
clear tlSubsysName tlsystems i;
