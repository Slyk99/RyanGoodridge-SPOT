%% Select files

[CSV_FILE, CSV_DIR] = uigetfile('*', 'Select the CSV file', '../Saved Data/');
CSV_FILEPATH = strcat(CSV_DIR, CSV_FILE);

[SLX_FILE, SLX_DIR] = uigetfile({'*.slx;*.mdl', 'Simulink Models (*.slx, *.mdl)'}, ...
                                    'Select the Simulink Model');
SLX_FILEPATH = strcat(SLX_DIR, SLX_FILE);

%% Load/initialize data

% Open the Simulink diagram (if it is not open already)
open_system(SLX_FILEPATH)

% Load data packet from the CSV
dataPacket_rt = load(CSV_FILEPATH);

% Extract the time vector from the first column
timeVector = dataPacket_rt(:, 1);

% Initialize a struct to store each timeseries
dataClass_rt = struct();

%% Get signal data

model_name = SLX_FILE(1:end-4);
blockPath = [model_name '/Data Logger Subsystem/Data Logging Bus'];

feval(model_name, [], [], [], 'compile');

ph = get_param(blockPath, 'PortHandles');
sh = get_param(ph.Inport, 'SignalHierarchy');
cpd = get_param(ph.Inport, 'CompiledPortDimensions');

feval(model_name, [], [], [], 'term');

%% Process data and build dataClass

% Iterate over each signal in sh, skipping the first column which is the time vector
columnCounter = 1;
for i = 1:size(sh,1)
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