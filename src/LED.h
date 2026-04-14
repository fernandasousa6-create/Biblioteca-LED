#ifndef LED_h
#define LED_h

#include <Arduino.h>
  
/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado,
 * piscar continuamente e piscar por quantidade definida.
 * 
 * @note O metodo update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
    uint8_t pino;
    bool estado;
    bool desligarPorTempo = false;
    uint32_t desligarNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;
    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar(); 
    /**
     * @brief Processa o desligamento temporizado
     */
    void funcaoDesligamento();

public:
    /**
     * @brief Constroi um objeto Led
     * @param pin Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pin); 

    /**
     * @brief Liga o LED por um tempo determinado.
     */
    void ligar();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado_ms Tempo, em milissegundo, que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos
     */
    void desligar();

    /**
     * @brief Inicia a piscada contínua em 1 Hz.
     */
    void piscar();

    void piscar(float frequencia);
    
    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia Frequência de piscadas em hertz.
     * @param repeticoes Quantidades de piscadas completas.
     */
    void piscar(uint8_t frequencia, uint16_t repeticoes);

    /**
     * @brief Define manualmente o estado do LED.
     * @param estado true para ligado, false para ligado.
     */
    bool getEstado();

    /**
     * @brief Define manualmente o valor do pino do LED.
     */
    uint8_t getPino();
    
    /**
     * @brief Define manualmente o estado do LED.
     * @param estado true para ligado, false para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief Define o LED com o estado oposto do atual
     * */
    void alternar();

    /**
     * @brief atualiza o estado do LED.
     */
    void update();
};

#endif