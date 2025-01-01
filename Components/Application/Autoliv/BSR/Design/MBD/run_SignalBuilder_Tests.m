function run_SignalBuilder_Tests( modelh, TestsList, TestType, Coverage )
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

XlsTestScenarioFile = 'TestScenariis_Results\BSR_MBD_TestsAndReport.xlsx';
ScenariisList = TestsList';

sbb = find_system(bdroot,'MaskType','Sigbuilder block');
if isempty(sbb)
    error('Autoliv: Cannot perform batch testing if no signal builder in model test harness');
elseif numel(sbb) > 1
    error('Autoliv: Cannot perform batch testing if more than one signal builder in model test harness');
else
    [~, ~, ~, grouplabels] = signalbuilder(sbb{1});
end

disp(['### Start Batch Testing for ', modelh, '.'])
for i=0:numel(ScenariisList)
    disp(['### Results stored in ', XlsTestScenarioFile])
end

switch TestType
    case 'MIL'
        xlswrite(XlsTestScenarioFile, {date}, 'Test Synthesis', 'C4');
        tl_set_sim_mode('simmode','TL_BLOCKS_HOST');
        for IndexTestGroup = 2:numel(grouplabels)
            signalbuilder(sbb{1}, 'activegroup', IndexTestGroup);
            sim(modelh);
            MIL_results = Simout.signals.values;
            
            warning off MATLAB:xlswrite:AddSheet
            [~, XLSconfigCells] = xlsread(XlsTestScenarioFile, 'Sheet_Config', 'D5:D23'); 
            xlswrite(XlsTestScenarioFile, double(MIL_results), grouplabels{IndexTestGroup}, XLSconfigCells{15});
            xlswrite(XlsTestScenarioFile, {date}, grouplabels{IndexTestGroup}, XLSconfigCells{10});
            warning on MATLAB:xlswrite:AddSheet
        end   
    case 'SIL'
        xlswrite(XlsTestScenarioFile, {date}, 'Test Synthesis', 'C5');
        if strcmp(Coverage, 'Decision coverage')        %DecisionCoverage
            tl_generate_code('SimMode','TL_CODE_HOST', 'CodeCoverageLevel', 2);
            tl_compile_host;
            tl_set_sim_mode('simmode','TL_CODE_HOST');
        elseif strcmp(Coverage, 'Statement coverage')   %StatementCoverage
            tl_generate_code('SimMode','TL_CODE_HOST', 'CodeCoverageLevel', 1);
            tl_compile_host;
            tl_set_sim_mode('simmode','TL_CODE_HOST');
        else                                            %NoCoverage
            tl_generate_code('SimMode','TL_CODE_HOST', 'CodeCoverageLevel', 0);
            tl_compile_host;
            tl_set_sim_mode('simmode','TL_CODE_HOST');
        end
       
        for IndexTestGroup = 2:numel(grouplabels)
            signalbuilder(sbb{1}, 'activegroup', IndexTestGroup);
            sim(modelh);
            SIL_results = Simout.signals.values;
            
            warning off MATLAB:xlswrite:AddSheet
            [~, XLSconfigCells] = xlsread(XlsTestScenarioFile, 'Sheet_Config', 'D5:D23'); 
            xlswrite(XlsTestScenarioFile, double(SIL_results), grouplabels{IndexTestGroup}, XLSconfigCells{16});
            xlswrite(XlsTestScenarioFile, {date}, grouplabels{IndexTestGroup}, XLSconfigCells{11});
            warning on MATLAB:xlswrite:AddSheet
        end
        
        if strcmp(Coverage, 'Decision coverage')        %DecisionCoverage
            disp(['### START Decision Coverage'])
            % Store report in specified location
            report_dest = [fileparts(which(bdroot)), '\Documents\DecisionCoverage\'];
            % Create Directory if needed
            if exist(fileparts(report_dest),'dir') ~= 7
                mkdir(report_dest);
            end
            tl_code_coverage('Report');
            movefile('CodeCoverageReport',report_dest);
            disp(['### The report has been generated in ', report_dest, '\CodeCoverageReport']);
            disp(['### END of Decision Coverage']);
        elseif strcmp(Coverage, 'Statement coverage')   %StatementCoverage
            disp(['### START Statement Coverage'])
            % Store report in specified location
            report_dest = [fileparts(which(bdroot)), '\Documents\StatementCoverage\'];
            % Create Directory if needed
            if exist(fileparts(report_dest),'dir') ~= 7
                mkdir(report_dest);
            end
            tl_code_coverage('Report');
            movefile('CodeCoverageReport',report_dest);
            disp(['### The report has been generated in ', report_dest, '\CodeCoverageReport']);
            disp(['### END of Decision Coverage']);
        end       
    case 'MIL & SIL'
        
        %MIL
        xlswrite(XlsTestScenarioFile, {date}, 'Test Synthesis', 'C4');
        tl_set_sim_mode('simmode','TL_BLOCKS_HOST');
        for IndexTestGroup = 2:numel(grouplabels)
            signalbuilder(sbb{1}, 'activegroup', IndexTestGroup);
            sim(modelh);
            MIL_results = Simout.signals.values;
            
            warning off MATLAB:xlswrite:AddSheet
            [~, XLSconfigCells] = xlsread(XlsTestScenarioFile, 'Sheet_Config', 'D5:D23'); 
            xlswrite(XlsTestScenarioFile, double(MIL_results), grouplabels{IndexTestGroup}, XLSconfigCells{15});
            xlswrite(XlsTestScenarioFile, {date}, grouplabels{IndexTestGroup}, XLSconfigCells{10});
            warning on MATLAB:xlswrite:AddSheet
        end
        
        %SIL
        xlswrite(XlsTestScenarioFile, {date}, 'Test Synthesis', 'C5');
        if strcmp(Coverage, 'Decision coverage')        %DecisionCoverage
            tl_generate_code('SimMode','TL_CODE_HOST', 'CodeCoverageLevel', 2);
            tl_compile_host;
            tl_set_sim_mode('simmode','TL_CODE_HOST');
        elseif strcmp(Coverage, 'Statement coverage')   %StatementCoverage
            tl_generate_code('SimMode','TL_CODE_HOST', 'CodeCoverageLevel', 1);
            tl_compile_host;
            tl_set_sim_mode('simmode','TL_CODE_HOST');
        else                                            %NoCoverage
            tl_generate_code('SimMode','TL_CODE_HOST', 'CodeCoverageLevel', 0);
            tl_compile_host;
            tl_set_sim_mode('simmode','TL_CODE_HOST');
        end
        
        for IndexTestGroup = 2:numel(grouplabels)
            signalbuilder(sbb{1}, 'activegroup', IndexTestGroup);
            sim(modelh);
            SIL_results = Simout.signals.values;
            
            warning off MATLAB:xlswrite:AddSheet
            [~, XLSconfigCells] = xlsread(XlsTestScenarioFile, 'Sheet_Config', 'D5:D23'); 
            xlswrite(XlsTestScenarioFile, double(SIL_results), grouplabels{IndexTestGroup}, XLSconfigCells{16});
            xlswrite(XlsTestScenarioFile, {date}, grouplabels{IndexTestGroup}, XLSconfigCells{11});
            warning on MATLAB:xlswrite:AddSheet
        end
        
        if strcmp(Coverage, 'Decision coverage')    %DecisionCoverage
            disp(['### START Decision Coverage'])
            % Store report in specified location
            report_dest = [fileparts(which(bdroot)), '\Documents\DecisionCoverage\'];
            % Create Directory if needed
            if exist(fileparts(report_dest),'dir') ~= 7
                mkdir(report_dest);
            end
            tl_code_coverage('Report');
            movefile('CodeCoverageReport',report_dest);
            disp(['### The report has been generated in ', report_dest, '\CodeCoverageReport']);
            disp(['### END of Decision Coverage']);
        elseif strcmp(Coverage, 'Statement coverage')    %StatementCoverage
            disp(['### START Statement Coverage'])
            % Store report in specified location
            report_dest = [fileparts(which(bdroot)), '\Documents\StatementCoverage\'];
            % Create Directory if needed
            if exist(fileparts(report_dest),'dir') ~= 7
                mkdir(report_dest);
            end
            tl_code_coverage('Report');
            movefile('CodeCoverageReport',report_dest);
            disp(['### The report has been generated in ', report_dest, '\CodeCoverageReport']);
            disp(['### END of Decision Coverage']);
        end
end
disp(['### End of Batch Testing  for ', modelh]);
clear all;
clc;
%close_system('BSR_TestHarness', 0);

