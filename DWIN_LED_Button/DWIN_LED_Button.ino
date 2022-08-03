unsigned char buff[9];

void usart_init (void) {
  UCSR0A = (1<<U2X0);
  UCSR0B = (1<<RXEN0);
  UCSR0C = (1<< UCSZ01)|(1<<UCSZ00);  
  UBRR0 = 16;                   
}
unsigned char usart_receive(void) {
  while (!(UCSR0A & (1<<RXC0)));
  return UDR0;
}
void setup (){
  usart_init();
  
  DDRB = 0xFF;
  PORTB = 0x00;
} 
void loop(){  
    for (uint8_t c = 0; c <= 8; c++)
    {
      buff[c] = usart_receive();
    }

    if (buff[8] == 0x01)
    {
      PORTB |= (1<<5);
    }
    else
    {
      PORTB &= ~(1<<5);
    }   
}
