# Attiny85 I2C Peripheral

This is a simple I2C perihperhal device on the ATTiny85, implented
via the[ ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) Arduino core.

This code is meant as a template for building I2C periperhal devices using at
ATTiny85. Even that device does not have native I2C support, it can be used for
simpler deivces, like a basic sensor interface, thanks to its configurable
USART.

## Tools & Dependencies

You can use this code with the Arduino IDE or Arduino CLI. The scripts `compile.sh`
and `upload.sh` are included to make working with the CLI easier.

To install the ATTinyCore core in the Arduino CLI:

```sh
arduino-cli config add board_manager.additional_urls https://raw.githubusercontent.com/SpenceKonde/ReleaseScripts/refs/heads/master/package_drazzy.com_index.json
arduino-cli core install ATTinyCore:avr
```