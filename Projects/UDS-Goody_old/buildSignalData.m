
        function [signalData, signalDim, columnCounter] = buildSignalData(signal, signalDim, dataPacket, columnCounter, timeVector)
            signalName = signal.SignalName;
            subSignals = signal.Children;

            disp(signalName)

            if strcmp(signalName, 'CTL')
                disp("hI")
            end
            
            % Check if the current signal has sub-signals
            if ~isempty(subSignals)
                % Process sub-signals recursively
                for i = 1:size(subSignals)
                    [subSignalData, signalDim, columnCounter] = buildSignalData(subSignals(i), signalDim, dataPacket, columnCounter, timeVector);
                    signalData.(subSignals(i).SignalName) = subSignalData;
                end
            else
                % Process bottom level signal (data)
                [signalDim, signalSize] = deal(signalDim(:,3:end), signalDim(:,2));

                dataCol = dataPacket(:, columnCounter:(columnCounter + signalSize - 1));
                dataCol(isnan(dataCol)) = -1;

                signalData = timeseries(dataCol, ...
                                            timeVector, 'Name', signalName);

                columnCounter = columnCounter + signalSize;
            end
        end