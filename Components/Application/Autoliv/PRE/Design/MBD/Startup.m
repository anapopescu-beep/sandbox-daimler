function varargout = Startup(varargin)
% STARTUP M-file for Startup.fig
%      STARTUP, by itself, creates a new STARTUP or raises the existing
%      singleton*.
%
%      H = STARTUP returns the handle to a new STARTUP or the handle to
%      the existing singleton*.
%
%      STARTUP('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in STARTUP.M with the given input arguments.
%
%      STARTUP('Property','Value',...) creates a new STARTUP or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Startup_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Startup_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Startup

% Last Modified by GUIDE v2.5 25-Jan-2012 10:45:05


% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Startup_OpeningFcn, ...
                   'gui_OutputFcn',  @Startup_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Startup is made visible.
function Startup_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Startup (see VARARGIN)

% Choose default command line output for Startup
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Startup wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Startup_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in SimType_listbox.
function SimType_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to SimType_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns SimType_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from SimType_listbox

handles.SimType_listbox = hObject;
list_entries = cellstr(get(handles.SimType_listbox,'String'));
index_selected = get(handles.SimType_listbox,'Value');
SimType_Selected = list_entries{index_selected};
if strcmp(SimType_Selected, 'MIL')
    set(handles.Coverage_listbox,'value',1);
    set(handles.Coverage_listbox, 'Visible', 'off');
    set(handles.Coverage_text, 'Visible', 'off');
    
    set(handles.Debug, 'Visible', 'on');
else
    set(handles.Coverage_listbox, 'Visible', 'on');
    set(handles.Coverage_text, 'Visible', 'on');
    
    set(handles.Debug,'Value',0);
    set(handles.Debug, 'Visible', 'off');
end

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function SimType_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SimType_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

handles.SimType_listbox = hObject;
list_entries = cellstr(get(handles.SimType_listbox,'String'));
index_selected = get(handles.SimType_listbox,'Value');
SimType_Selected = list_entries{index_selected};
if strcmp(SimType_Selected, 'MIL')
    set(handles.Coverage_listbox,'value',1);
    set(handles.Coverage_listbox, 'Visible', 'off');
    set(handles.Coverage_text, 'Visible', 'off');
    
    set(handles.Debug, 'Visible', 'on');
else
    set(handles.Coverage_listbox, 'Visible', 'on');
    set(handles.Coverage_text, 'Visible', 'on');
    
    set(handles.Debug,'Value',0);
    set(handles.Debug, 'Visible', 'off');
end

% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in OK_pushbutton.
function OK_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to OK_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

list_entries = cellstr(get(handles.SimType_listbox,'String'));
index_selected = get(handles.SimType_listbox,'Value');
handles.OK_pushbutton = list_entries{index_selected};
SimType_Selected = handles.OK_pushbutton;
assignin('base','SimType_Selected',SimType_Selected);

TestsToBeLaunched_List = cellstr(get(handles.TestsToLaunch_listbox,'String'));
assignin('base','TestsToBeLaunched_List',TestsToBeLaunched_List);

list_entries = cellstr(get(handles.Coverage_listbox,'String'));
index_selected = get(handles.Coverage_listbox,'Value');
handles.OK_pushbutton = list_entries{index_selected};
Coverage_Selected = handles.OK_pushbutton;
assignin('base','Coverage_Selected',Coverage_Selected);

debug = get(handles.Debug,'Value');
assignin('base','debug',debug);

% Update handles structure
guidata(hObject, handles);

% Open the model 
uiopen('PRE_TestHarness.mdl',1);

% load mat file 
load(strcat(pwd, '\Workspace\EnvVar.mat'));

% Launch BPA_SigBuilder.m
PRE_SigBuilder;

clear all;
clc;
close all;

% --- Executes on button press in Add_pushbutton.
function Add_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to Add_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

Exist = 0;

list_entries = get(handles.AllTests_listbox,'String');
index_selected = get(handles.AllTests_listbox,'Value');
handles.Add_pushbutton = list_entries{index_selected};

old_str = get(handles.TestsToLaunch_listbox,'String');
old_str_cell = cellstr(old_str);
new_str = strvcat(old_str,handles.Add_pushbutton);
new_str_cell = cellstr(new_str);

NbElements = numel(old_str_cell);
for i=1 : NbElements
    if strcmp(old_str_cell{i},handles.Add_pushbutton)
       Exist = 1;
    end
end
if Exist ~= 1
    set(handles.TestsToLaunch_listbox,'String',new_str);
    set(handles.OK_pushbutton, 'Enable', 'on');
end

% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in Remove_pushbutton.
function Remove_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to Remove_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.Remove_pushbutton = hObject;

set(handles.TestsToLaunch_listbox,'String',[]);
set(handles.OK_pushbutton, 'Enable', 'off');
 
% Update handles structure
guidata(hObject, handles);


% --- Executes on selection change in AllTests_listbox.
function AllTests_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to AllTests_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns AllTests_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from AllTests_listbox

handles.AllTests_listbox = hObject;

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function AllTests_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to AllTests_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

handles.AllTests_listbox = hObject;

XlsTestScenarioFile = 'TestScenariis_Results\PRE_MBD_TestsAndReport.xlsx';
[~, XLSconfigCells] = xlsread(XlsTestScenarioFile, 'Sheet_Config', 'D5:D23');
[~, ScenariiList] = xlsread(XlsTestScenarioFile , 'Test Synthesis', [XLSconfigCells{1},':',XLSconfigCells{2}]);
set(hObject,'String',ScenariiList);

% Update handles structure
guidata(hObject, handles);


% --- Executes on selection change in TestsToLaunch_listbox.
function TestsToLaunch_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to TestsToLaunch_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns TestsToLaunch_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from TestsToLaunch_listbox

handles.TestsToLaunch_listbox = hObject;

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function TestsToLaunch_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to TestsToLaunch_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

handles.TestsToLaunch_listbox = hObject;

% Update handles structure
guidata(hObject, handles);


% --- Executes on selection change in Coverage_listbox.
function Coverage_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to Coverage_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Coverage_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Coverage_listbox

handles.Coverage_listbox = hObject;

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function Coverage_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Coverage_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

handles.Coverage_listbox = hObject;

% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in Debug.
function Debug_Callback(hObject, eventdata, handles)
% hObject    handle to Debug (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Debug

handles.Debug = hObject;

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function Debug_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Debug (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

handles.Debug = hObject;

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function Coverage_text_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Coverage_text (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

handles.Coverage_text = hObject;

% Update handles structure
guidata(hObject, handles);