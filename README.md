
# Projeto de Automação com Alexa e Wemos D1 ESP8266

Este projeto permite controlar o acendimento de uma lâmpada ou abajur utilizando a Alexa, integrando o dispositivo com o SinricPro para a comunicação com a nuvem. O código utiliza a placa **Wemos D1 ESP8266** e é baseado em um modelo simples de automação residencial.

## Pré-requisitos

- **Placa**: Wemos D1 ESP8266
- **Bibliotecas necessárias**:
  - **ESP8266WiFi**: Para conectar o dispositivo à rede WiFi.
  - **SinricPro**: Para integração com a nuvem SinricPro e controle via Alexa.
  - **SinricProSwitch**: Para controle de dispositivos de ligar/desligar (como um interruptor).

## Configuração do Ambiente

### 1. Adicionando a URL do Gerenciador de Pacotes

No Arduino IDE, adicione a URL do pacote para placas ESP8266:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

Vá para **Arquivo > Preferências** e insira a URL no campo **URLs adicionais para o Gerenciador de Placas**.

### 2. Instalar Bibliotecas

No Arduino IDE, adicione as seguintes bibliotecas:

- **ESP8266WiFi**
- **SinricPro**
- **SinricProSwitch**

Essas bibliotecas podem ser adicionadas em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**.

### 3. Configurações da IDE

Certifique-se de que a placa **Wemos D1 R1** está selecionada em **Ferramentas > Placa**.

A porta de comunicação deve ser configurada corretamente em **Ferramentas > Porta**.

## Como Testar

1. **Conecte a placa Wemos D1** ao computador via USB.
2. **Carregue o código** no Arduino IDE. Certifique-se de que o código já esteja disponível no repositório.
3. **Abra o monitor serial** no Arduino IDE para verificar a conexão do dispositivo com a rede WiFi. O IP será exibido na tela quando a conexão for estabelecida.
4. **Use a Alexa** para ligar e desligar o dispositivo com o comando de voz configurado no portal SinricPro.

### Passos finais

- Certifique-se de que a Alexa tenha detectado o dispositivo corretamente após a configuração no portal SinricPro.
- Utilize os comandos de voz para testar o funcionamento do controle de ligar e desligar o dispositivo.

## Considerações Finais

Este projeto demonstra como utilizar o ESP8266 para criar automações simples em casa, controladas por comandos de voz via Alexa. A integração com o SinricPro facilita a comunicação entre o dispositivo e a nuvem, proporcionando uma experiência de automação eficiente.
