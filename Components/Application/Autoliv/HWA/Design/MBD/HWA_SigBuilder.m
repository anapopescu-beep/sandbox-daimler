%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 
%%% Project : PP4G HWA
%%% 
%%% Purpose : This file must be stored in the root directory of the
%%%           HWA_TestHarness model. This script is in charge to update the 
%%%           content of the signal builder block with the selected scenario data 
%%%          (in Startup interface).
%%% 
%%% Author  : FGI							Date : 23.07.2014
%%% Version : 1.
%%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


clc;

%% Load Scenarii File
XlsTestScenarioFile = 'TestScenariis_Results\HWA_MBD_TestsAndReport.xlsx';

%% Scenario List 
[~, XLSconfigCells] = xlsread(XlsTestScenarioFile, 'Sheet_Config', 'D5:D23');
[~, AllScenariisList] = xlsread(XlsTestScenarioFile , 'Test Synthesis', [XLSconfigCells{1},':',XLSconfigCells{2}]);
SelectedScenariisList = AllScenariisList';
TestsNumber = numel(SelectedScenariisList);
disp(['DEBUG: TestNumber = ',TestsNumber]);
disp(['DEBUG: SelectedScenariisList = ',SelectedScenariisList]);




%% Load Time Array
TimeRange = char(strcat(XLSconfigCells{4}, ':', XLSconfigCells{5}));
TimeArray = xlsread(XlsTestScenarioFile, 'Template_Tests', TimeRange);
% Permute dimension  .... Mathworks Genuine Inside .... :)
TimeArray = TimeArray';

Epsilon = (TimeArray(2)-TimeArray(1))/10;

for i=1:numel(TimeArray)
    if i==1
        TimeArrayExpand = [TimeArray(i)];
    elseif i==numel(TimeArray)
        TimeArrayExpand = [TimeArrayExpand TimeArray(i)];
    else
        TimeArrayExpand = [TimeArrayExpand TimeArray(i)-Epsilon TimeArray(i)-Epsilon];
    end   
end

%% Fill the SignalBuilder Block with the complete tests scenariis file data

% Load Signals names
SignalNamesRange = char(strcat(XLSconfigCells{7}, ':', XLSconfigCells{8}));
[~, headertext] = xlsread(XlsTestScenarioFile, 'Template_Tests', SignalNamesRange);

% update the SigBuilder Block
sbb = find_system(bdroot,'MaskType','Sigbuilder block');

if isempty(sbb)
    error('Autoliv: Cannot perform batch testing if no signal builder in model');
elseif numel(sbb) > 1
    error('Autoliv: Cannot perform batch testing if more than one signal builder in model');
else
    [~, ~, siglabels, grouplabels] = signalbuilder(sbb{1});
end

SignalBuilderGroupsContent = numel(grouplabels);
SignalBuilderSignalsContent = numel(siglabels);

for i=1:TestsNumber
    Signals_Inputs = xlsread( XlsTestScenarioFile , SelectedScenariisList{i} , strcat(XLSconfigCells{18},':',XLSconfigCells{19}) );
    [~,n] = size(Signals_Inputs);
    if n ~= SignalBuilderSignalsContent
        %error('Autoliv: Cannot update the SignalBuilder Block : Size error between XLS and existing block');
    end
    Signals_Inputs = Signals_Inputs';
    
    for k=1:numel(TimeArray)
        if k==1
            Signals_InputsExpand = [Signals_Inputs(:,k)];
        elseif k==numel(TimeArray)
            Signals_InputsExpand = [Signals_InputsExpand Signals_Inputs(:,k)];
        else
            Signals_InputsExpand = [Signals_InputsExpand Signals_Inputs(:,k-1) Signals_Inputs(:,k)];
        end   
    end
    
    Signals_Inputs2 = {Signals_InputsExpand(1,:)};
    for j=2:SignalBuilderSignalsContent
        Signals_Inputs2{j} = Signals_InputsExpand(j,:);
    end
    Signals_Inputs2 = Signals_Inputs2';
    
    assignin('base','Signals_Inputs2',Signals_Inputs2);
    
    signalbuilder( sbb{1} ,'append', TimeArrayExpand, Signals_Inputs2, headertext, SelectedScenariisList{i});
    disp ( ['-> Scenario ',SelectedScenariisList{i},' successfully added']);      
end

disp ( ['*** Update of Signal Builder block "',sbb{1},'" finished ***'] );
clear SelectedScenariisList Signals_Inputs2 Signals_Inputs TimeRange TimeArray i j n k siglabels grouplabels SignalBuilderGroupsContent SignalBuilderSignalsContent headertext XlsTestScenarioFile XLSconfigCells;

%% Launch Simulation
if debug == 0
    switch SimType_Selected
          case 'MIL'
            disp('###*** MIL TEST ***###')
            run_SignalBuilder_Tests(bdroot,TestsToBeLaunched_List,SimType_Selected,Coverage_Selected);
          case 'SIL'
            disp('###*** SIL TEST ***###')
            run_SignalBuilder_Tests(bdroot,TestsToBeLaunched_List,SimType_Selected,Coverage_Selected);
          case 'MIL & SIL'
            disp('###*** MIL & SIL ***###')
            run_SignalBuilder_Tests(bdroot,TestsToBeLaunched_List,SimType_Selected,Coverage_Selected);
          otherwise
            error('###*** Unknown TEST ??? ***###')
    end
else
    if TestsNumber >= 1
        signalbuilder(sbb{1}, 'activegroup', 2);
    end
end
clear sbb TestsNumber; 
