#include "timer.hpp"

bool flag = false;
bool flagA0 = false;
bool flagA1 = false;

ISR(TIMER1_COMPA_vect) {
  flag = true; // Avisa o loop principal que deu 1 segundo
}

void timer_config()
{
    cli(); // Desativa as interrupções globais temporariamente

  TCCR1A = 0; // Garante que o registrador de controle A comece zerado
  TCCR1B = 0; // Garante que o registrador de controle B comece zerado
  TCNT1  = 0; // Zera o contador do Timer

  // 1. Define o valor de comparação baseado no nosso cálculo
  OCR1A = 15624;

  // 2. Ativa o modo CTC mudando o bit WGM12 no registrador TCCR1B
  TCCR1B |= (1 << WGM12);

  // 3. Define o Prescaler para 1024 (Bits CS12 e CS10 em 1)
  TCCR1B |= (1 << CS12) | (1 << CS10);  

  // 4. Ativa a interrupção por igualdade de comparação no canal A (OCIE1A)
  TIMSK1 |= (1 << OCIE1A);

  sei(); // Reativa as interrupções globais
}

bool update_screen()
{
  // Se a flag estiver verdadeira, nós limpamos ela e retornamos true
  if (flag) {
    flag = false; // CRUCIAL: Zera a flag para esperar o próximo segundo!
    return true;
  }
  
  // Se não deu 1 segundo ainda, retorna false
  return false;
}