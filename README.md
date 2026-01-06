# Attiny85 I2C Peripheral

Asimple I2C perihperhal device built on the ATTiny85, implemented
via the [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) Arduino core.

This code is a template for building I2C periperhal devices using an
ATTiny8 microcontroller. Even though the ATTiny85 lacks native I2C support, it
can be used for simpler devices, like a basic sensor interface, thanks to its
configurable USART.

## Tools & Dependencies

You can use this code with the Arduino IDE or Arduino CLI. The scripts `compile.sh`
and `upload.sh` are included to make working with the CLI easier.

To install the ATTinyCore core in the Arduino CLI:

```sh
arduino-cli config add board_manager.additional_urls https://raw.githubusercontent.com/SpenceKonde/ReleaseScripts/refs/heads/master/package_drazzy.com_index.json
arduino-cli core install ATTinyCore:avr
```

There is also a [PlatformIO](https://platformio.org) config, so you can build this like so:

```
pio run
```