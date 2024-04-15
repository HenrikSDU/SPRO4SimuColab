    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
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
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (DroneModel_P)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% DroneModel_P.A
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% DroneModel_P.B
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 144;

                    ;% DroneModel_P.C
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 192;

                    ;% DroneModel_P.g
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 264;

                    ;% DroneModel_P.m
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 265;

                    ;% DroneModel_P.x0
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 266;

                    ;% DroneModel_P.Barometer_SampleTime
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 278;

                    ;% DroneModel_P.MPU9250_SampleTime
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 279;

                    ;% DroneModel_P.MotorThrusts_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 280;

                    ;% DroneModel_P.Multiply_Gain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 284;

                    ;% DroneModel_P.Step_Time
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 285;

                    ;% DroneModel_P.Step_Y0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 286;

                    ;% DroneModel_P.Step_YFinal
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 287;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
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
        nTotSects     = 3;
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
        ;% Auto data (DroneModel_B)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% DroneModel_B.StateSpace
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% DroneModel_B.Multiply
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 6;

                    ;% DroneModel_B.Subtract
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% DroneModel_B.MPU9250_o1
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% DroneModel_B.MPU9250_o2
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 3;

                    ;% DroneModel_B.MPU9250_o3
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% DroneModel_B.Barometer
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
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
        nTotSects     = 4;
        sectIdxOffset = 3;

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
        ;% Auto data (DroneModel_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% DroneModel_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% DroneModel_DW.obj_e
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% DroneModel_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% DroneModel_DW.Scope1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% DroneModel_DW.objisempty
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% DroneModel_DW.objisempty_o
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
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


    targMap.checksum0 = 2379884857;
    targMap.checksum1 = 1494586340;
    targMap.checksum2 = 2191468998;
    targMap.checksum3 = 2014791328;

