function ResultsZOH = zohMPCResults(Results)
% zohMPCResults  - Replace MPC skipped solver outputs (-1 rows) using ZOH
%
% Input:
%   Results : T x N matrix (e.g., T x 4) with -1 rows indicating skips
%
% Output:
%   ResultsZOH : same size as Results, with each -1 row replaced using
%                zero-order hold from the last valid row.
%
% Note:
%   Searches for first valid row (not all -1). If missing, returns zeros.

    % Copy input
    ResultsZOH = Results;

    % Dimensions
    [T, N] = size(Results);

    % Find first valid row (not all -1)
    isValid = any(Results ~= -1, 2);   % logical index of valid rows
    firstValidIdx = find(isValid, 1, 'first');

    % Handle case: all rows invalid
    if isempty(firstValidIdx)
        ResultsZOH = zeros(T, N);
        return;
    end

    % Initialize ZOH with the first valid row
    lastVal = Results(firstValidIdx, :);

    % For all rows up to firstValidIdx-1, fill with first valid value
    ResultsZOH(1:firstValidIdx, :) = repmat(lastVal, firstValidIdx, 1);

    % ZOH loop through remaining rows
    for k = firstValidIdx+1 : T
        if all(Results(k, :) == -1)
            % solver skipped → hold previous value
            ResultsZOH(k, :) = lastVal;
        else
            % new valid value → update hold
            lastVal = Results(k, :);
            ResultsZOH(k, :) = lastVal;
        end
    end
end
