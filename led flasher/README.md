## RGB LED  
There is an RGB LED present on the Tiva TM4C123G board connected to pins 1 2 3 and three of port F as follows.

| pin |  led  |
|:---:|:-----:|
|  1  |  Red  |
|  2  |  Blue |
|  3  | Green |  

## main.c

`GET_PTR` is a macro function which provides a convinient way to get pointer references to the desired registers. Simply pass in the address and a its deferenced version is returned.

