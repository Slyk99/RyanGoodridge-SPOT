clc

%% Prompt user to pick a .csv file
[F,P] = uigetfile('*.*', 'Select your data file');
if isequal(F,0)
  error('No file selected.');
end
filepath = fullfile(P,F);

% Read the ascii into your matrix
dataPacket_rt = load(filepath, '-ascii');

%% Load Bus Path
mdlect = "MPC.slx";
mdl = "MPC";
open_system(mdlect)
blockPath = "MPC/Data Logger Subsystem/Data Logging Bus";

feval(mdl, [], [], [], 'compile');

ph = get_param(blockPath, 'PortHandles');
sh = get_param(ph.Inport, 'SignalHierarchy');
cpd = get_param(ph.Inport, 'CompiledPortDimensions');

feval(mdl, [], [], [], 'term');


%% Init Data
% Load Raw Exp Log File
% dataPacket_rt = load("ExpLog_new");

% Extract the time vector from the first column
timeVector = dataPacket_rt(:, 1);

% Initialize a struct to store each timeseries
dataClass_rt = struct();

%% Process data and build dataClass
% Iterate over each signal in sh, skipping the first column which is the time vector
columnCounter = 1;
for i = 1:size(sh,1)-1
    signal = sh{i};
    signalName = signal.SignalName;

    if isempty(signal.Children)
        signalDim = cpd{i};
    else
        signalDim = cpd{i}(3:end);
    end

    [signalData, ~, columnCounter] = buildSignalData(signal, signalDim, dataPacket_rt, columnCounter, timeVector);
    dataClass_rt.(matlab.lang.makeValidName(signalName)) = signalData;
end

if columnCounter <= size(dataPacket_rt,2)
    for i = columnCounter:size(dataPacket_rt,2)
        ts = timeseries(dataPacket_rt(:, i), timeVector, 'Name', sprintf('UnnamedSignal_%d', i-columnCounter+1));
        dataClass_rt.(matlab.lang.makeValidName(ts.Name)) = ts;
    end
end

% 1) Prompt the user
[saveFile, savePath] = uiputfile('*.mat', 'Save dataClass_rt as…', 'dataClass_rt.mat');
if isequal(saveFile,0) || isequal(savePath,0)
    disp('User canceled save.');
    return;
end

% 2) Build the full filename
fullSaveName = fullfile(savePath, saveFile);

% 3) Save your variable
save(fullSaveName, 'dataClass_rt');

fprintf('Saved dataClass_rt to %s\n', fullSaveName);



%% Functions

function [signalData, signalDim, columnCounter] = buildSignalData(signal, signalDim, dataPacket, columnCounter, timeVector)
    signalName = signal.SignalName;
    subSignals = signal.Children;
    
    % Check if the current signal has sub-signals
    if ~isempty(subSignals)
        % Process sub-signals
        for i = 1:size(subSignals)
            [subSignalData, signalDim, columnCounter] = buildSignalData(subSignals(i), signalDim, dataPacket, columnCounter, timeVector);
            signalData.(subSignals(i).SignalName) = subSignalData;
        end
    else
        % Process bottom level signal (data)
        [signalDim, signalSize] = deal(signalDim(:,3:end), signalDim(:,2));
    
        signalData = timeseries(dataPacket(:, columnCounter:(columnCounter + signalSize - 1)), ...
                                    timeVector, 'Name', signalName);
    
        columnCounter = columnCounter + signalSize;
    end
end
