classdef trajectory_class
    %TRAJECTORY_CLASS Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        flight_phases
    end
    
    methods
        function obj = trajectory_class(inputArg1,inputArg2)
            %TRAJECTORY_CLASS Construct an instance of this class
            %   Detailed explanation goes here
            obj.flight_phases = inputArg1 + inputArg2;
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 Summary of this method goes here
            %   Detailed explanation goes here
            outputArg = obj.flight_phases + inputArg;
        end
    end
end

