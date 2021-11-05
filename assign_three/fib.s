   AREA     fib, CODE, READONLY
     EXPORT __main
     IMPORT printMsg
     ENTRY 
__main  FUNCTION
		MOV  R10,#0x00;
		MOV  R11,#0x01;
		MOV R0, R10;
		BL printMsg;   
		MOV R0, R11;
		BL printMsg;     
		MOV R5,#0x6;    Printing a total of 6+2 numbers.
		
Loop    ADD R3, R10, R11;
        MOV R0,R3
		BL printMsg;      
		MOV  R10, R11;
		MOV  R11,R3;		
		SUB R5,#0x01;
        CMP R5,#0x00;   
		BNE Loop
	
stop    B stop ; stop program
	ENDFUNC
	END 
		