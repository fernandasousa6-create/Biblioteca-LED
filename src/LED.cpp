#include "LED.h"
/* fernanda de sousa
   14/04/2026
   Projeto: Led por Automação
*/

Led::Led(uint8_t pin) :
    pino(pin),
    estado(LOW),
    desligarPorTempo(false),
    desligarNoMomento(0),
    tempoAnteriorPiscar(false),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0)
{
    pinMode(pino, OUTPUT);
}
void Led::desligar()
{
    estadoPiscar = false;
    desligarPorTempo = false;
    estado = LOW;
}

void Led::ligar()
{
    estadoPiscar = false;
    desligarPorTempo = false;
    estadoPiscar = HIGH;
}

void Led::ligar(uint32_t tempoLigado_ms)
{
    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = (millis() + tempoLigado_ms);
}

void Led::alternar()
{
    estado = !estado;

}

void Led::update()
{
    if (desligarPorTempo) funcaoDesligamento();
    if (estadoPiscar) funcaoPiscar();

    digitalWrite(pino, estado);
}

bool Led::getEstado()
{
    return estado;
}

uint8_t Led::getPino()
{
    return pino;
}
void Led::setEstado(bool estado)
{
    this->estado = estado;
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar= millis();
    estado = HIGH;
}

void Led::piscar(float frequencia)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f* frequencia));
    tempoAnteriorPiscar= millis();
    estado = HIGH;
}


void Led::piscar(uint8_t frequencia, uint16_t repeticoes)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f/ (2.0f* frequencia));
    tempoAnteriorPiscar= millis();
    estado = HIGH;
    this-> repeticoes = repeticoes * 2;
}

void Led::funcaoPiscar()
{
    if(millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
    
        if(repeticoes > 0)
        {
            repeticoes --;
            if(repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}
void Led::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
        estado = LOW;
        desligarPorTempo = false;
    }
}