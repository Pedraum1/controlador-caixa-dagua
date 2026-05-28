#include "utils.hpp"

uint16_t calc_volume(uint16_t distancia)
{
    // 1. Limites do sensor e da caixa em centímetros
    // Altura total com tampa = 97cm. Altura sem tampa = 76cm. (Tampa = 21cm)
    
    // Se a distância for maior ou igual a 97cm, a caixa está vazia.
    if (distancia >= 97) {
        return 0;
    }
    
    // Se a distância for menor ou igual a 21cm, a água atingiu a tampa (Caixa Cheia).
    if (distancia <= 21) {
        return 1000;
    }

    // 2. Converter a distância para metros para aplicar na fórmula geométrica
    float distancia_metros = distancia / 100.0f;

    // 3. Calcular a altura real do líquido em metros (a partir do fundo da caixa)
    float h = 0.97f - distancia_metros; 

    // 4. Dimensões do tronco de cone (corpo da caixa em metros)
    const float R = 1.51f / 2.0f;  // Raio do topo (0.755m)
    const float r = 1.16f / 2.0f;  // Raio da base (0.580m)
    const float H = 0.76f;         // Altura do corpo (76cm)

    // 5. Calcular o raio na superfície atual do líquido
    float r_liq = r + ((R - r) / H) * h;

    // 6. Calcular o volume em metros cúbicos (Tronco de Cone)
    float volume_m3 = (1.0f / 3.0f) * M_PI * h * ((r_liq * r_liq) + (r_liq * r) + (r * r));

    // 7. Converter para litros (1 m³ = 1000 litros)
    float volume_litros = volume_m3 * 1000.0f;

    // Trava de segurança para não estourar a capacidade nominal
    if (volume_litros > 1000.0f) {
        return 1000;
    }

    return (uint16_t)roundf(volume_litros);
}