# Megamind, Arduino Firmware
Brincadeira de horas vagas...

### Modelo: 
![Expectativa](Modelo/modelo_circuito.svg)

### Componentes:
* Sensor LDR (Luminosidade)
* Sensor LM35 (Temperatura ambiente)
* LED de alto brilho ~5V

### Objetivo
Receber comandos via porta serial e executar o comando e enviar respostas equivalentes pela porta seria em formato JSON

### Build
```
cmake .
make
make upload  #Faz upload para a placa (verificar porta USB usada em CMakeLists.txt e a permissão de escrita)
