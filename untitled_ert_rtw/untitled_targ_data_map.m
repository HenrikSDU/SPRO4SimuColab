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
        ;% Auto data (untitled_P)
        ;%
<<<<<<< Updated upstream
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% untitled_P.Barometer_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_P.MovingAverage_ForgettingFactor
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_P._Y0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% untitled_P.Step3_Time
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% untitled_P.Step3_Y0
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% untitled_P.Step3_YFinal
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

=======
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_P.MPU9250_SampleTime
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

>>>>>>> Stashed changes
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
        ;% Auto data (untitled_B)
        ;%
<<<<<<< Updated upstream
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% untitled_B.sensor
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_B.height
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% untitled_B.In
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;
=======
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% untitled_B.MPU9250_o3
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_B.yaw
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
        nTotSects     = 4;
=======
        nTotSects     = 2;
>>>>>>> Stashed changes
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
        ;% Auto data (untitled_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

<<<<<<< Updated upstream
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.obj_n
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

=======
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% untitled_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% untitled_DW.Scope1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 3;

>>>>>>> Stashed changes
            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

<<<<<<< Updated upstream
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.Scope1_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% untitled_DW.SampleandHold3_SubsysRanBC
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

=======
>>>>>>> Stashed changes

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


<<<<<<< Updated upstream
    targMap.checksum0 = 444478754;
    targMap.checksum1 = 562653173;
    targMap.checksum2 = 55111515;
    targMap.checksum3 = 2687092507;
=======
    targMap.checksum0 = 2832103378;
    targMap.checksum1 = 3787077988;
    targMap.checksum2 = 4049721387;
    targMap.checksum3 = 4003714039;
>>>>>>> Stashed changes

