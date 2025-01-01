%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Script tests for MIL/SIL environment
% Inputs : MBD_Test_config.xlsx located in MBD_Tests folder
% Description : This script shall be first called to initialize 
%               some data into the workspace required to execute MIL/SIL
%               tests
% author : CSA
% Data   : 2013 Oct, 10
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% Valid if the template has not been changed
[~,Trigram,~] = xlsread('MBD_Tests\MBD_Test_config.xlsx','Config','I1');
Trigram = Trigram{1,1};

TimeLineStart = xlsread('MBD_Tests\MBD_Test_config.xlsx','Config','C3');
TimeLineEnd   = xlsread('MBD_Tests\MBD_Test_config.xlsx','Config','C4');

%% To be adapted according to the configuration table
% FOR loop limits to be adapted if required
DataArrayStart = 9;
DataArrayEnd   = 61;

InputRowStart = DataArrayEnd;
InputRowEnd   = DataArrayStart;

OutputRowStart = DataArrayEnd;
OutputRowEnd   = DataArrayStart;

InternalRowStart = DataArrayEnd;
InternalRowEnd   = DataArrayStart;

[~,txt,~]=xlsread('MBD_Tests\MBD_Test_config.xlsx','Config',['B' int2str(DataArrayStart) ':B' int2str(DataArrayEnd) ]);

% Cell range extraction
for iLoopIndex=DataArrayStart : 1 : length(txt)+DataArrayStart-1
    
    % Model global inputs - I_ for Inputs
    StartIndex = regexp(txt(iLoopIndex-DataArrayStart+1),'I_.*');
    if (not(isempty(StartIndex{1})))
        if (iLoopIndex < InputRowStart)
            InputRowStart = iLoopIndex;
        end
        if (iLoopIndex > InputRowEnd)
            InputRowEnd = iLoopIndex;
        end
    end
    
    % Model global outputs - O_ for Outputs
    StartIndex = regexp(txt(iLoopIndex-DataArrayStart+1),'O_.*');
    if (not(isempty(StartIndex{1})))
        if (iLoopIndex < OutputRowStart)
            OutputRowStart = iLoopIndex;
        end
        if (iLoopIndex > OutputRowEnd)
            OutputRowEnd = iLoopIndex;
        end
    end
    
    % Model internal signals to be monitored - W_ for Watched
    StartIndex = regexp(txt(iLoopIndex-DataArrayStart+1),'W_.*');
    if (not(isempty(StartIndex{1})))
        if (iLoopIndex < InternalRowStart)
            InternalRowStart = iLoopIndex;
        end
        if (iLoopIndex > InternalRowEnd)
            InternalRowEnd = iLoopIndex;
        end
    end
    
end
% Workspace clean up
clear txt iLoopIndex StartIndex DataArrayStart DataArrayEnd;
% Configuration for inputs

[~,InputsCfgArray,~] = xlsread('MBD_Tests\MBD_Test_config.xlsx','Config',['B' int2str(InputRowStart) ':C' int2str(InputRowEnd)]);

% Configuration for outputs
[~,OutputsCfgArray,~] = xlsread('MBD_Tests\MBD_Test_config.xlsx','Config',['B' int2str(OutputRowStart) ':G' int2str(OutputRowEnd)]);

% Configuration for internal data which are logged in order to check
% sub-modules outputs
[~,InternalsCfgArray,~] = xlsread('MBD_Tests\MBD_Test_config.xlsx','Config',['B' int2str(InternalRowStart) ':G' int2str(InternalRowEnd)]);

%% Workspace elements creation to be able to build the model

[InputsSize,~]=size(InputsCfgArray);
[OutputsSize,~]=size(OutputsCfgArray);
[InternalsSize,~]=size(InternalsCfgArray);

for iLoopIndex=1 : 1 : InputsSize
    assignin('base',InputsCfgArray{iLoopIndex,1}, [xlsread('MBD_Tests\MBD_Test_config.xlsx','Test_Template', ['A' int2str(TimeLineStart) ':A' int2str(TimeLineEnd)])  xlsread('MBD_Tests\MBD_Test_config.xlsx','Test_Template',[InputsCfgArray{iLoopIndex,2} int2str(TimeLineStart) ':' InputsCfgArray{iLoopIndex,2} int2str(TimeLineEnd)])]);
end
for iLoopIndex=1 : 1 : OutputsSize
    assignin('base',OutputsCfgArray{iLoopIndex,1}, [xlsread('MBD_Tests\MBD_Test_config.xlsx','Test_Template', ['A' int2str(TimeLineStart) ':A' int2str(TimeLineEnd)])  xlsread('MBD_Tests\MBD_Test_config.xlsx','Test_Template',[OutputsCfgArray{iLoopIndex,2} int2str(TimeLineStart) ':' OutputsCfgArray{iLoopIndex,2} int2str(TimeLineEnd)])]);
end

% NOT NEEDED 
% but kept for future application
%for iLoopIndex=1 : 1 : InternalsSize
%    assignin('base',InternalsCfgArray{iLoopIndex,1}, [xlsread('MBD_Tests\MBD_Test_config.xlsx','Test_Template', ['A' int2str(TimeLineStart) ':A' int2str(TimeLineEnd)])  xlsread('MBD_Tests\MBD_Test_config.xlsx','Test_Template',[InternalsCfgArray{iLoopIndex,2} int2str(TimeLineStart) ':' InternalsCfgArray{iLoopIndex,2} int2str(TimeLineEnd)])]);
%end

clear InputRowStart InputRowEnd OutputRowStart OutputRowEnd iLoopIndex InternalRowEnd InternalRowStart

%% Calibration data

% TODO CSA \o/
% Model adaptation required to extract the "CONSTANT" simulink blocks from
% the TargetLink subsystem.

