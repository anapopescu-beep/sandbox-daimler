
0) Before generating production code:
To obtain clean code:
- Check clean code option is set (this option is cleared by MIL SIL tests)
- Global logging option = "Do not log anything"
- Logging in referenced models = "Disable in all referenced model"
- Code generation mode = "AUTOSAR"
- Code generation target settings = "Generic ANSI-C"
- Enable sections/pragmas/inline/ISR/user attributes is set
- Remove specific MIL connections for:
     - MotorPowerOrder
     - BoostPowerOrder
  in BFE_runExecuteHighPowerStep/HP feature activated/CurrentRegulation block

1) How to launch MIL tests:

- Open BFE_TestHarness.mdl (it will automatically run file MBD_tests_init.m)
- To allow testing steps with high power option, connect specific MIL inputs for:
     - MotorPowerOrder
     - BoostPowerOrder
  in BFE_runExecuteHighPowerStep/HP feature activated/CurrentRegulation block
- Check Model-In-the-Loop mode is selected for TargetLink BFE_AC_BeltFunctionExecution block
- Global logging option = "Log according to block data"
- Logging in referenced models = "Enable in selected models"
- Clean code is disabled
- Open Launch_Tests.m
- Modify TestFileName='MBD_Tests\BFE_MBD_Test_00001.xlsx'; with xlsx scenario to launch
- Run file Launch_Tests.m to execute scenario
- Run file LoggedData.m to store results in xlsx scenario

2) How to launch SIL tests:

- Open BFE_TestHarness.mdl (it will automatically run file MBD_tests_init.m)
- Build SIL (TargetLink main dialog, use Visual Studio compiler)
- Check Software-In-the-Loop mode is selected for TargetLink BFE_AC_BeltFunctionExecution block
- Open Launch_Tests.m
- Modify TestFileName='MBD_Tests\BFE_MBD_Test_00001.xlsx'; with xlsx scenario to launch
- Run file Launch_Tests.m to execute scenario
- Run file LoggedData.m to store results in xlsx scenario

3) Little explanations for null in Excel:
- Formula with {} is usefull to apply formula to the whole column
- To display result use Home -> Conditional Formating, manage rules, new rule 
    "Use a formula to determine which cells to format"
    formula: =$N7<>$M7 and apply it to whole column

4) How updating test scenarii:
- Be careful max time stot = 2s



