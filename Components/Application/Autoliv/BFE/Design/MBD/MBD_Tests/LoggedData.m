%% extract Logged data

% obsolete ----------------------------------------------------------------
%blocks = tl_access_logdata('GetLoggedBlocks', tl_access_logdata('GetLastSimulationLabel'));
%[LoopMax ~] = size(blocks);
% obsolete ----------------------------------------------------------------
tlsystems=get_tlsubsystems(bdroot);
for i=1:length(tlsystems)
   tlSubsysName = get_param(tlsystems{i}, 'Name');
   fprintf('TlSubsystem %s is in %s mode\n', ...
      tlSubsysName, ...
      tl_get_sim_mode('TlSubsystems', tlSubsysName));
end

if isequal(tl_get_sim_mode('TlSubsystems', tlSubsysName),'TL_BLOCKS_HOST')
    ColumnResultIndex = 3;
end
if isequal(tl_get_sim_mode('TlSubsystems', tlSubsysName),'TL_CODE_HOST')
    ColumnResultIndex = 4;
end
clear tlSubsysName tlsystems i;
%%
% for internal signals only - Loop on the Logger structure provided by
% TargetLink with resampling and finally allocation in the excel test
% report
for iLoopIndex=1 : InternalsSize
    % extraction from Logger data server handled by TL
    TempTimeSerie = tl_access_logdata('GetLoggedSignal', 'simlabel', tl_access_logdata('GetLastSimulationLabel'),'block',InternalsCfgArray{iLoopIndex,6});
    % reformating in timeserie 
    TempTimeSerie2=timeseries(TempTimeSerie.signal.y,TempTimeSerie.signal.t);
    % Interpolation method changed before resampling
    TempTimeSerie2=setinterpmethod(TempTimeSerie2,'zoh');
    % resampling
    % TODO ---> time vector to be optimized !!!!!!
    TempTimeSerie2=resample(TempTimeSerie2,0:0.0004:3);
    % Extraction of data for one signal after preprocessing
    TempDataTimeSeries=get(TempTimeSerie2,'Data');
    % Clean up the matrix
    TempDataTimeSeries=squeeze(TempDataTimeSeries);
    % Write results in the right location on the excel test report
    xlswrite(TestFileName, TempDataTimeSeries, 'Test_Data', [InternalsCfgArray{iLoopIndex,ColumnResultIndex} int2str(TimeLineStart)]);
end


for iLoopIndex=1 : OutputsSize
    % Extract outputs results from 'To Workspace' simulink blocks
    TempResult= evalin('base',OutputsCfgArray{iLoopIndex,6});
    TempResult= TempResult.signals.values;
    % Write results in the right location on the excel test report
    xlswrite(TestFileName, TempResult, 'Test_Data', [OutputsCfgArray{iLoopIndex,ColumnResultIndex} int2str(TimeLineStart)]);
    
end

% Workspace clean up
clear TempTimeSerie iLoopIndex TempTimeSerie2 TempDataTimeSeries TempResult ColumnResultIndex;