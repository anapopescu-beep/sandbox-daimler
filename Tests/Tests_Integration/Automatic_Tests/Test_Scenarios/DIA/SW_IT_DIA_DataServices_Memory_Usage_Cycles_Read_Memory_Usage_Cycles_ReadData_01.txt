					Autoliv Electronics Document
--------------------------------------------------------------------------
Nightly test: No
Test type: Requirement-Based test
Regression Test: No
Fault injection method used: No
Resource usage evaluation: No
Priority: No
Safety relevant: No
Requirement under test: ARCH_SW_DIA_0355; ARCH_SW_DIA_0356; ARCH_SW_DIA_0357; ARCH_SW_DIA_0358; ARCH_SW_DIA_0359
ARCH_SW_DIA_0355: Service 0x22 (Read Data By Identifier) will be implemented for DID 01E4 (Memory Usage Cycles)
ARCH_SW_DIA_0356: The Read Memory usage Cycles service shall be available in the following sessions: Default Session (0x01) Programming (0x02) Extended Session (0x03) Supplier Session/Development Session (0x7E) Update Session (0x42)
ARCH_SW_DIA_0357: Read Memory usage Cycles service shall be available under the following forms of Authentication: Supplier Development ENHANCED Internal Diagnostic Test Tool
ARCH_SW_DIA_0358: DataIdentifier of the Read Memory usage Cycles shall be: 0x01E4
ARCH_SW_DIA_0359: Response data length shall be 5 bytes long: DataIdentifier of the Read Memory Usage Cycles shall be: 0x01E4 For each block there is a 5 byte response: Memory Block ID [1byte]: â¦[0x00] Please insert memory ID (e.g. Data Flash Bank0) Memory Usage Cycles [4 bytes] Note: Full Response length = 3 bytes + Response data length
--------------------------------------------------------------------------

Preconditions

	Step 1: Bench Initialization

	Step 2: Set breakpoint in function *DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData*.

Action: ARCH_SW_DIA_0355; ARCH_SW_DIA_0356; ARCH_SW_DIA_0357; ARCH_SW_DIA_0358; ARCH_SW_DIA_0359

	Step 3: Send diag request for 22 01 E4 
		Expected result:  Timeout received.

	Step 4: Check if breakpoint from function DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData was reached. 
		Expected result:  BP was reached.

	Step 5: Read Data variable 
		Expected result:  Variable read.

Postcondition

	Step 6: Return ECU to default values
