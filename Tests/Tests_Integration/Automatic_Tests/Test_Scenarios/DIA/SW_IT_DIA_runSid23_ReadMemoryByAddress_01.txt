					Autoliv Electronics Document
--------------------------------------------------------------------------
Nightly test: No
Test type: Requirement-Based test
Regression Test: No
Fault injection method used: No
Resource usage evaluation: No
Priority: No
Safety relevant: No
Requirement under test: ARCH_SW_DIA_0040; ARCH_SW_DIA_0177; ARCH_SW_DIA_0178; ARCH_SW_DIA_0179; ARCH_SW_DIA_0180; ARCH_SW_DIA_0181; ARCH_SW_DIA_0182; ARCH_SW_DIA_0042; ARCH_SW_DIA_0043; ARCH_SW_DIA_0044
ARCH_SW_DIA_0040: Service 0x23 will be implemented
ARCH_SW_DIA_0177: Service shall be available in Development session
ARCH_SW_DIA_0178: Runnable shall return data with the length of maximum 300 byes
ARCH_SW_DIA_0179: MemoryIdentifier shall represent Address and Length format identifier
ARCH_SW_DIA_0180: MemoryAddress shall represent the address to read from
ARCH_SW_DIA_0181: MemorySize shall represent the size to read
ARCH_SW_DIA_0182: MemoryData shall return data to be read with parameters above
ARCH_SW_DIA_0042: Service 10 shall support the following sessions: Default, Programming, Extended and Development Session
ARCH_SW_DIA_0043: Service 10 shall be available in the following sessions: Default, Programming, Extended, Development Session and DefaultSession (of the Bootloader)
ARCH_SW_DIA_0044: Transition to Development Session will be done only with authentication
--------------------------------------------------------------------------

Preconditions

	Step 1: Bench Initialization

	Step 2: Enter development session.

Action: ARCH_SW_DIA_0040; ARCH_SW_DIA_0177; ARCH_SW_DIA_0178; ARCH_SW_DIA_0179; ARCH_SW_DIA_0180; ARCH_SW_DIA_0181; ARCH_SW_DIA_0182; ARCH_SW_DIA_0042; ARCH_SW_DIA_0043; ARCH_SW_DIA_0044

	Step 3: Send diag request for Memory Read and wait for timeout error 
		Expected result:  Timeout reached.

Postcondition

	Step 4: Return ECU to default values
