#ifndef SERIAL_H
#define SERIAL_H

#ifndef CLK_FREQ
	#define CLK_FREQ 32000000 
#endif

#ifndef UART_BRATE 
	#define UART_BRATE 9600
#endif

#if CLK_FREQ == 32000000 
	#if UART_BRATE == 9600
		#define UART_CLK_BIT 0x0d05 //UART_CLK_BIT = CLK_FREQ/UART_BRATE
		#define UART_CLK_BIT_H 0x0d
		#define UART_CLK_BIT_L 0x05
	#endif
#endif


void UART_setup();

#ifdef USE_UART_INTERRUPT
		#define EUSART1_TX_BUFFER_SIZE 8
	    #define EUSART1_RX_BUFFER_SIZE 8
	    	    
	    volatile unsigned char eusart1TxHead = 0;
		volatile unsigned char eusart1TxTail = 0;
		volatile unsigned char eusart1TxBuffer[EUSART1_TX_BUFFER_SIZE];
	    volatile unsigned char eusart1TxBufferRemaining = 0;	    
	    volatile unsigned char eusart1RxHead = 0;
		volatile unsigned char eusart1RxTail = 0;
		volatile unsigned char eusart1RxBuffer[EUSART1_RX_BUFFER_SIZE];
		//volatile eusart1_status_t eusart1RxStatusBuffer[EUSART1_RX_BUFFER_SIZE];
		volatile unsigned char eusart1RxCount;
		//volatile eusart1_status_t eusart1RxLastError;

	    	
	    	    	    
		//non-blocknig functions using interrupt + circular buffer
		void EUSART1_Write(unsigned char txData);
		unsigned char EUSART1_is_tx_ready(void);
		void EUSART1_Transmit_ISR(void);
		
		unsigned char EUSART1_Read(void);
		void EUSART1_Receive_ISR(void);
		
#else
		//blocking functions 
		unsigned char getchar();
		void putchar(unsigned char data);

#endif

void UART_setup()
{
	PBLAZEPORT[UART_OUT_CONFIG_L] = UART_CLK_BIT_L;
	PBLAZEPORT[UART_OUT_CONFIG_H] = UART_CLK_BIT_H;
	
	#ifdef USE_UART_INTERRUPT
		eusart1TxHead = 0;
		eusart1TxTail = 0;
		eusart1TxBufferRemaining = sizeof(eusart1TxBuffer);

		eusart1RxHead = 0;
		eusart1RxTail = 0;
		eusart1RxCount = 0;
		
		//intcon_enable_bit(UART_TX_INT_FLAG_BIT);
		intcon_enable_bit(UART_RX_INT_FLAG_BIT);
		update_intcon();
		
	#endif
}

unsigned char getchar()
{
	unsigned char rx,flags;
	
	do {
		flags = PBLAZEPORT[INT_IN_FLAGS];
		rx = flags & UART_RX_INT_FLAG_BIT;		
	} while (!rx);
	
	return PBLAZEPORT[UART_RX];
		
}

void putchar(unsigned char data)
{
	unsigned char tx, flags;
	
	do {
		flags = PBLAZEPORT[INT_IN_FLAGS];
		tx = flags & UART_TX_INT_FLAG_BIT;	
	} while (!tx);
	
	PBLAZEPORT[UART_TX] = data;
	
}

#ifdef USE_UART_INTERRUPT

void EUSART1_Write(unsigned char txData)
{
	unsigned char aux;
	aux = eusart1TxBufferRemaining;
	//while(0 == eusart1TxBufferRemaining)
	 while(0 == aux)
    {
    }
    
    intcon_disable_bit(UART_TX_INT_FLAG_BIT);
    update_intcon();
    
    eusart1TxBuffer[eusart1TxHead++] = txData;
    if(sizeof(eusart1TxBuffer) <= eusart1TxHead) {
            eusart1TxHead = 0;
    }
    
    aux--;
    eusart1TxBufferRemaining = aux;
       
    intcon_enable_bit(UART_TX_INT_FLAG_BIT);
    update_intcon();
    
}

unsigned char EUSART1_is_tx_ready(void)
{
	return eusart1TxBufferRemaining;
}

void EUSART1_Transmit_ISR(void)
{	
	unsigned char aux1;
	
	// add your EUSART1 interrupt custom code
    if(sizeof(eusart1TxBuffer) > eusart1TxBufferRemaining)
    {
		
        //TX1REG = eusart1TxBuffer[eusart1TxTail++];
        aux1 = eusart1TxTail;                
        PBLAZEPORT[UART_TX] = eusart1TxBuffer[aux1];
        aux1++;
        eusart1TxTail = aux1;
        
        
        if(sizeof(eusart1TxBuffer) <= aux1)
        {
			aux1 = 0;
            eusart1TxTail = aux1;
        }
        
        aux1 = eusart1TxBufferRemaining;
        aux1++;
        
        eusart1TxBufferRemaining = aux1;
    }
    else
    {
        //PIE3bits.TX1IE = 0;
        intcon_disable_bit(UART_TX_INT_FLAG_BIT);
        update_intcon();
        
    }
	
}

unsigned char EUSART1_Read(void)
{
    unsigned char readValue, aux1, aux2;
    
    aux1 = eusart1RxCount;
    while(0 == aux1)
    {
    }

    //eusart1RxLastError = eusart1RxStatusBuffer[eusart1RxTail];

	aux2 = eusart1RxTail;
	readValue = eusart1RxBuffer[aux2];
    aux2++;
    if(sizeof(eusart1RxBuffer) <= aux2)
    {
        aux2 = 0;
    }
    eusart1RxTail = aux2;
     
    intcon_disable_bit(UART_RX_INT_FLAG_BIT);
    update_intcon();
    
    aux1--;
    eusart1RxCount = aux1;
    
    intcon_enable_bit(UART_RX_INT_FLAG_BIT);
    update_intcon();

    return readValue;
}

void EUSART1_Receive_ISR(void) 
{
	unsigned char aux1, aux2;
	
	aux1 = eusart1RxHead;	
    eusart1RxBuffer[aux1] = PBLAZEPORT[UART_RX];
    aux1++;
    if(sizeof(eusart1RxBuffer) <= aux1)
    {
        aux1 = 0;
    }
    eusart1RxHead = aux1;
    
    aux2 = eusart1RxCount;
    aux2++;
    eusart1RxCount = aux2;

}



#endif //USE_UART_INTERRUPT

#endif //SERIAL_H
