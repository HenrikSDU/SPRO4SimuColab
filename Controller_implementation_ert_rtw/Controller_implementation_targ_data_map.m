    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
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
            section.nData     = 45;
            section.data(45)  = dumData; %prealloc

                    ;% Controller_implementation_P.KV_rating
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_P.K_D_LQR_reduced
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_P.K_mm
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 33;

                    ;% Controller_implementation_P.Ts
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 49;

                    ;% Controller_implementation_P.battery_voltage
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 50;

                    ;% Controller_implementation_P.dis
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 51;

                    ;% Controller_implementation_P.drag_co
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 52;

                    ;% Controller_implementation_P.lift_co
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 53;

                    ;% Controller_implementation_P.CompareToConstant1_const
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 54;

                    ;% Controller_implementation_P.Lykyhatkk1_Y0
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 55;

                    ;% Controller_implementation_P.deltax_Y0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 56;

                    ;% Controller_implementation_P._Y0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 57;

                    ;% Controller_implementation_P.DigitalRead_SampleTime
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 58;

                    ;% Controller_implementation_P.MovingAverage_ForgettingFactor
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 59;

                    ;% Controller_implementation_P._Y0_l
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 60;

                    ;% Controller_implementation_P.CovarianceZ_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 61;

                    ;% Controller_implementation_P.C_Value
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 125;

                    ;% Controller_implementation_P.KalmanGainL_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 181;

                    ;% Controller_implementation_P.KalmanGainM_Value
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 237;

                    ;% Controller_implementation_P.PulseGenerator_Amp
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 293;

                    ;% Controller_implementation_P.PulseGenerator_Period
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 294;

                    ;% Controller_implementation_P.PulseGenerator_Duty
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 295;

                    ;% Controller_implementation_P.PulseGenerator_PhaseDelay
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 296;

                    ;% Controller_implementation_P.Delay_x_InitialCondition
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 297;

                    ;% Controller_implementation_P.C_Gain
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 298;

                    ;% Controller_implementation_P.D_Gain
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 299;

                    ;% Controller_implementation_P.B_Gain
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 300;

                    ;% Controller_implementation_P.A_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 301;

                    ;% Controller_implementation_P.A_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 302;

                    ;% Controller_implementation_P.B_Value
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 366;

                    ;% Controller_implementation_P.D_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 398;

                    ;% Controller_implementation_P.Step_Time
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 426;

                    ;% Controller_implementation_P.Step_Y0
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 427;

                    ;% Controller_implementation_P.Step_YFinal
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 428;

                    ;% Controller_implementation_P.Gain_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 429;

                    ;% Controller_implementation_P.Gain1_Gain
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 430;

                    ;% Controller_implementation_P.Constant_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 431;

                    ;% Controller_implementation_P.Step_Time_a
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 439;

                    ;% Controller_implementation_P.Step_Y0_h
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 440;

                    ;% Controller_implementation_P.Step_YFinal_b
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 441;

                    ;% Controller_implementation_P.Constant_Value_k
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 442;

                    ;% Controller_implementation_P.PWMlimit_UpperSat
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 443;

                    ;% Controller_implementation_P.PWMlimit_LowerSat
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 444;

                    ;% Controller_implementation_P.SignConvention_Gain
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 445;

                    ;% Controller_implementation_P.Constant1_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 449;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Controller_implementation_P._Y0_b
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_P.TmpLatchAtSampleandHoldInport1_
                    section.data(2).logicalSrcIdx = 46;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Controller_implementation_P.isSqrtUsed_Value
                    section.data(1).logicalSrcIdx = 47;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_P.Enable_Value
                    section.data(2).logicalSrcIdx = 48;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Controller_implementation_P.DiscreteTimeIntegrator_IC
                    section.data(1).logicalSrcIdx = 49;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_P.Gain_Gain_d
                    section.data(2).logicalSrcIdx = 50;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_P.Initial1_Value
                    section.data(3).logicalSrcIdx = 51;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
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
        nTotSects     = 4;
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
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Controller_implementation_B.RateTransition
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_B.Gain1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Controller_implementation_B.Reshapexhat
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% Controller_implementation_B.Gain_f
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 13;

                    ;% Controller_implementation_B.PWMlimit
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 17;

                    ;% Controller_implementation_B.Sum
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 21;

                    ;% Controller_implementation_B.U
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 25;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Controller_implementation_B.roll
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_B.pitch
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_B.In
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% Controller_implementation_B.In_c
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% Controller_implementation_B.Product2
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 10;

                    ;% Controller_implementation_B.Product3
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 18;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_B.In_d
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_B.DigitalRead
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
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
        nTotSects     = 13;
        sectIdxOffset = 4;

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

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj_b
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj_bh
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.obj_h
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.obj_p
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% Controller_implementation_DW.obj_k
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.obj_d
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Controller_implementation_DW.Delay_x_DSTATE
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.MemoryX_DSTATE
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.TmpRTBAtMeasurementUpdateInport
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 9;

                    ;% Controller_implementation_DW.TmpRTBAtEnabledSubsystemInport2
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 65;

                    ;% Controller_implementation_DW.TmpRTBAtMeasurementUpdateInpo_p
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 121;

                    ;% Controller_implementation_DW.TmpRTBAtEnabledSubsystemInport1
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 177;

                    ;% Controller_implementation_DW.RateTransition_Buffer
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 233;

                    ;% Controller_implementation_DW.RateTransition_Buffer_c
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 234;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Controller_implementation_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.Scope2_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 8;

                    ;% Controller_implementation_DW.SystemUMonitor_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 9;

                    ;% Controller_implementation_DW.TrackPWM_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 10;

                    ;% Controller_implementation_DW.DesiredU_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 11;

                    ;% Controller_implementation_DW.Scope1_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.clockTickCounter
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Controller_implementation_DW.TmpLatchAtSampleandHoldInport1_
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.RateTransition1_Buffer
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Controller_implementation_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% Controller_implementation_DW.TmpRTBAtMeasurementUpdateInpo_j
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.TmpRTBAtEnabledSubsystemInpor_n
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.TmpRTBAtMeasurementUpdateInp_pv
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 2;

                    ;% Controller_implementation_DW.TmpRTBAtEnabledSubsystemInpor_l
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 3;

                    ;% Controller_implementation_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 4;

                    ;% Controller_implementation_DW.SampleandHold_SubsysRanBC
                    section.data(6).logicalSrcIdx = 39;
                    section.data(6).dtTransOffset = 5;

                    ;% Controller_implementation_DW.SampleandHold_SubsysRanBC_p
                    section.data(7).logicalSrcIdx = 40;
                    section.data(7).dtTransOffset = 6;

                    ;% Controller_implementation_DW.SampleandHold_SubsysRanBC_k
                    section.data(8).logicalSrcIdx = 41;
                    section.data(8).dtTransOffset = 7;

                    ;% Controller_implementation_DW.EnabledSubsystem_SubsysRanBC
                    section.data(9).logicalSrcIdx = 42;
                    section.data(9).dtTransOffset = 8;

                    ;% Controller_implementation_DW.MeasurementUpdate_SubsysRanBC
                    section.data(10).logicalSrcIdx = 43;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Controller_implementation_DW.RateTransition2_Buffer
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

                    ;% Controller_implementation_DW.icLoad
                    section.data(2).logicalSrcIdx = 45;
                    section.data(2).dtTransOffset = 1;

                    ;% Controller_implementation_DW.EnabledSubsystem_MODE
                    section.data(3).logicalSrcIdx = 62;
                    section.data(3).dtTransOffset = 2;

                    ;% Controller_implementation_DW.MeasurementUpdate_MODE
                    section.data(4).logicalSrcIdx = 63;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
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


    targMap.checksum0 = 4090667322;
    targMap.checksum1 = 4238883022;
    targMap.checksum2 = 3073939861;
    targMap.checksum3 = 597155423;

