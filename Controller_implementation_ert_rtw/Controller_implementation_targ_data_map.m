    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Controller_implementation_P)
        ;%
            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% Controller_implementation_P.F
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_P.KV_rating
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 32;

                    ;% Controller_implementation_P.K_mm
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 33;

                    ;% Controller_implementation_P.Ki_D_lqi_reduced_a
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 49;

                    ;% Controller_implementation_P.Kx_D_lqi_reduced_a
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 65;

                    ;% Controller_implementation_P.Ts
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 97;

                    ;% Controller_implementation_P.battery_voltage
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 98;

                    ;% Controller_implementation_P.dis
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 99;

                    ;% Controller_implementation_P.drag_co
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 100;

                    ;% Controller_implementation_P.lift_co
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 101;

                    ;% Controller_implementation_P.Lykyhatkk1_Y0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 102;

                    ;% Controller_implementation_P.deltax_Y0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 103;

                    ;% Controller_implementation_P.MovingAverage_ForgettingFactor
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 104;

                    ;% Controller_implementation_P._Y0
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 105;

                    ;% Controller_implementation_P.A_Value
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 106;

                    ;% Controller_implementation_P.KalmanGainM_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 170;

                    ;% Controller_implementation_P.C_Value
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 226;

                    ;% Controller_implementation_P.KalmanGainL_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 282;

                    ;% Controller_implementation_P.B_Value
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 338;

                    ;% Controller_implementation_P.D_Value
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 370;

                    ;% Controller_implementation_P.Constant_Value
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 398;

                    ;% Controller_implementation_P.X0_Value
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 399;

                    ;% Controller_implementation_P.DiscreteTimeIntegrator_gainval
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 407;

                    ;% Controller_implementation_P.DiscreteTimeIntegrator_IC
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 408;

                    ;% Controller_implementation_P.PWMlimit_UpperSat
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 409;

                    ;% Controller_implementation_P.PWMlimit_LowerSat
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 410;

                    ;% Controller_implementation_P.SignConvention_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 411;

                    ;% Controller_implementation_P.Constant1_Value
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 415;

                    ;% Controller_implementation_P.Servolimit_UpperSat
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 419;

                    ;% Controller_implementation_P.Servolimit_LowerSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 420;

                    ;% Controller_implementation_P.Constant_Value_a
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 421;

                    ;% Controller_implementation_P.Gain_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 425;

                    ;% Controller_implementation_P.Gain_Gain_j
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 426;

                    ;% Controller_implementation_P.CovarianceZ_Value
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 427;

                    ;% Controller_implementation_P.Step3_Time
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 491;

                    ;% Controller_implementation_P.Step3_Y0
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 492;

                    ;% Controller_implementation_P.Step3_YFinal
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 493;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Controller_implementation_P.Enable_Value
                    section.data(1).logicalSrcIdx = 37;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_P.isSqrtUsed_Value
                    section.data(2).logicalSrcIdx = 38;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Controller_implementation_B)
        ;%
            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% Controller_implementation_B.z
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_B.Reshapexhat
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_B.Sum
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 9;

                    ;% Controller_implementation_B.PWMlimit
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 13;

                    ;% Controller_implementation_B.Sum_o
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 17;

                    ;% Controller_implementation_B.Gain
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 21;

                    ;% Controller_implementation_B.Gain_n
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 22;

                    ;% Controller_implementation_B.sensor
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 23;

                    ;% Controller_implementation_B.U
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 24;

                    ;% Controller_implementation_B.yaw
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 28;

                    ;% Controller_implementation_B.roll
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 29;

                    ;% Controller_implementation_B.pitch
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 30;

                    ;% Controller_implementation_B.height
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 31;

                    ;% Controller_implementation_B.In
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 32;

                    ;% Controller_implementation_B.MPU9250_o2
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 33;

                    ;% Controller_implementation_B.Product2
                    section.data(16).logicalSrcIdx = 20;
                    section.data(16).dtTransOffset = 36;

                    ;% Controller_implementation_B.Product3
                    section.data(17).logicalSrcIdx = 21;
                    section.data(17).dtTransOffset = 44;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Controller_implementation_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj_j
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj_n
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj_b
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.obj_h
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.obj_p
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 2;

                    ;% Controller_implementation_DW.obj_k
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Controller_implementation_DW.MemoryX_DSTATE
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Controller_implementation_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.SystemUMonitor_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 8;

                    ;% Controller_implementation_DW.TrackPWM_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 9;

                    ;% Controller_implementation_DW.DesiredU_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 10;

                    ;% Controller_implementation_DW.Scope1_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 11;

                    ;% Controller_implementation_DW.Pitch_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 18;

                    ;% Controller_implementation_DW.Roll_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 19;

                    ;% Controller_implementation_DW.Scope1_PWORK_m.LoggedData
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 20;

                    ;% Controller_implementation_DW.yaw_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 17;
                    section.data(9).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Controller_implementation_DW.SampleandHold3_SubsysRanBC
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.EnabledSubsystem_SubsysRanBC
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.MeasurementUpdate_SubsysRanBC
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Controller_implementation_DW.icLoad
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.EnabledSubsystem_MODE
                    section.data(2).logicalSrcIdx = 47;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.MeasurementUpdate_MODE
                    section.data(3).logicalSrcIdx = 48;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 872755696;
    targMap.checksum1 = 4005976953;
    targMap.checksum2 = 990198975;
    targMap.checksum3 = 537810445;

