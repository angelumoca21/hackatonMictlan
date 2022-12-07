# hackatonMictlan

RECOLECTOR Y TRATAMIENTO DE AGUA DE LLUVIA

*Techo: 
    Sensor de lluvia para detectar:
        si: 
            0 && {sensorNivel}=1 => Activar {bomba1} para vaciar recolector de primeras lluvias.
            0 = no está lloviendo.
            1 = está lloviendo.
*Recolector de primeras lluvias: 
    Contenedor con "sensor de nivel" {sensorNivel}, cierre superior (mecánico con pelota) y bomba de expulsión {bomba1}.
*Cisterna:
    La cisterna se empezará a llenar con el agua no contenida por el recolector de primeras lluvias.
    En caso de que la cisterna esté llena y lloviendo, la bomba {bomba1} desecha el agua.
    Sensor de gas (MQ-9) indica si existe descomposicion de algun elemento organico, indicando que se debe ventilar y limpiar la cisterna.
    {Sensor de flujo} indicará el historico de agua que se ha ahorrado al usar el sistema.
*Tinaco: 
    Sensor ultrasonico para medir y saber el nivel del tinaco.
