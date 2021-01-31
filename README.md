### Laboratory Work 1

Hello, my name is Dilnaz, and here I have **.ino** files and screenshots of the circuits for Lab 1 and Lab 2.

## Lab 1:

1. SOS

> Circuit consists of simple red LED and resistor connected to the ground and pin. It shows the SOS in Morse code as three short, three long and again three short signals. The time for signals can be adjusted via variables at the beginning of the code.

2. Pedestrian

> Circuit consists of simple three LEDs - red, yellow and green, and simulate the traffic lights for the pedestrians. Firstly, starts with turning on the red signal for 4 seconds(can be adjusted), then yellow for shorter time, and finally green - 5 seconds.

3. Traffic Lights

> Circuit consists of two breadboards for simplicity, and three LEDs each colored red, yellow and green. The task is to simulate the traffic lights for crossroad - weast-east and south-north. When red light is turned on one side, the green and then yellow LEDs for the other side is on. Then, signals switch, and the same pattern will be shown for the other road.

## Lab 2:

1. Switch debouncing

> In this exercise, I did a simple circuit with one LED and resistor, along with **push button** to control the state of the LED. According to the task, I initialized the variables to set the delay time between button pushes, so that continuously pressing the button for many times will be controlled using the time from the last push, and appropriate time delay between button pushes. The phenomenon is called *Switch bounce*.

2. Multiple switches

> The task is similar to the previous, however, the circuit became complex by adding the second **push button**, so that the LED state can be controlled using to buttons simultaneously.

3. Potentiometer

> Potentiometer is defined as a 3 terminal variable resistor in which the resistance is manually varied to control the flow of electric current, and it acts as an adjustable voltage divider. In this task I connected potentimeter and LED on one board, and controlled LED's brightness by changing the potentiometer value.

4. Photoresistors

> Photoresistors are a light-controlled variable resistors. It's resistance decrease when light intensity on the photoresistor is increased. In the task, we have photoresistor and LED on one board, so that when the light is increased, the LED's brightness decrease, and vice-versa.

5. Motion Sensor

> Motion sensors are used to evaluate the sense motion, almost always used to detect whether a human has moved in or out of the sensors range. As in the previous exercises, I constructed a circuit with LED and PIR motion sensor, so that when we simulate object motion within the sensor area, LED turn on, turning off only after some time the object has left the zone on motion.

6. Light sensor

> Light sensors are the photoelectric devices that convert light energy detected to electrical energy. In this exercise, we connect the LED to alternating pin (~) so that the value from light sensors would gradually change the brightness of LED from 0 to 255. Also, the ambient light sensor, which I used in the simulator, needs the resistor to be adjusted to particular value, so that the analog value for LED will not go beyond the range. In my case, I used 6350 ohm for the resistor in series to light sensor.  

7. Proximity sensor

> Proximity sensors are devices to detect the presence of nearby object without physical contact, in other words, it emits electromagnetic waves and looks for the change in the returned field. For this task, we used ultrasound distance sensor, and only printed the detected distance in the serial monitor. However, there was some constraints - if object is too close(< 2cm), it shows the random value, and if it is out of range - the maximum value.

8. Cell phone

> In this last exercise, our aim is to make a simple brightness control of a cell phone, using the sensors described above. So, analyzing the initial given statements.
> 1. When the phone is **NOT** on call:
>   * the phone is close to the ear -> the brightness should be off
>   * the phone is far away from the ear (> 30cm)
>     ** if it is on **AUTO** mode -> adjust the brightness of the phone according to the *light sensor*
>     ** if it is on **MANUAL** mode -> the user adjusts the brightness using the *potentiometer*
> 2. When the phone is **ON** call:
    1. the phone is close to the hand of the user
      1. if it is on **AUTO** mode -> adjust the brightness of the phone according to the *light sensor*
      2. if it is on **MANUAL** mode -> the user adjusts the brightness using the *potentiometer*
    2. the phone is far away from the hand of the user (> 30cm) -> the brightness should be off
> In the above schema, the distance is measured using *Ultrasound distance sensor*, whether phone is on/off the call and auto/manually adjusting the brightness is kept track using the pushbuttons, and *light sensor* and *potentiometer* are used to adjust the brightness respectively. You can check the circuit and code above.
