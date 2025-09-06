%% How to use

% From your desired SPOT Simulink diagram, copy the Data Logging Bus and
% attached data store inputs to a new Simulink Diagram. Additionally, copy
% over all data store initializers from the main page. Connect the Data
% Logging Bus to a Terminator. If any of your custom data stores require
% and inital value from the workspace, define them (then can use dummy
% values, but the arrays must be properly sized). Then run this script
% select the CSV and the Simulink diagram you created.

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
dataPacket_rt = importdata(CSV_FILEPATH);

% Extract the time data from the first column
timeVector = dataPacket_rt(:, 1);

% Initialize a struct to store the data
dataClass_rt = struct();

%% Get signal data

% Extract model name and 
model_name = SLX_FILE(1:end-4);
blockPath = [model_name '/Data Logging Bus'];

feval(model_name, [], [], [], 'compile');

ph = get_param(blockPath, 'PortHandles');
sh = get_param(ph.Inport, 'SignalHierarchy');
cpd = get_param(ph.Inport, 'CompiledPortDimensions');

feval(model_name, [], [], [], 'term');

%% Build dataClass

% Initialize column counter
dataCol = 1;

for signalIdx = 1:length(sh)

    % Define signal name, or use default if not available.
    if ~isempty(sh{signalIdx}.SignalName)
        signalName = sh{signalIdx}.SignalName;
    else
        signalName = sprintf('UnnamedSignal_%d', signalIdx);
    end

    % Get the signal dimensions from the port handle, index 2 is the value we care about, 
    % index 1 tells us if there are sub-signals (there wont be based on SPOT data logger structure)
    signalDim = cpd{signalIdx}(2);

    % Get the signal data from the packet
    signalData = dataPacket_rt(:, dataCol:(dataCol+signalDim-1));

    % Create a timeseries object for this signal
    ts = timeseries(signalData, timeVector);
    ts.Name = signalName;

    % Add this timeseries to the struct with the field name as signalName
    dataClass_rt.(matlab.lang.makeValidName(signalName)) = ts;

    % Update the data starting column
    dataCol = nextDataCol;
end
