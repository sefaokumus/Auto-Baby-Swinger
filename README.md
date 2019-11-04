

# Auto-Baby-Swinger

An arduino project that allows you add a IR remote controlled servo to your baby swinger

  

Parenting triplets always force you to find quick solutions to real life problems. Swinging our babies was one of them. This project was a

successfull project that saved our lives many times and I wanted to share it.

  

### Parts Needed

  

- Manuel Baby Swinger which you can attach a servo on

- Arduino UNO Board

- Tower Pro MG996R Servo (This servo provide 10kg of torque with 6V input)

- 10 watt, 2 12 V output transformer (I used a led transformer that fix in my controller box)

- LM2596 Adjustable Regulator module board 

- RJ45 Cat5 Female - Male connectors

- A plastic box that holds the circuits and boards.

  

### Before we start

  

I have to say this project was never meant to be shared publicly that why I now realized I have not documented all the steps as I was going through them. There has been many challenges through out the projects and I would like to talk about them before we continue.  

First of all, I wanted this project to be as cordless as possible since it was already hard to move where three babies were around and nobody wants extra cables around their feet. That's why I first design the project to work with 2 9V batteries where one of them powers the board and the other powers the servo. But this was not an effective idea since the batteries died after 15 minutes of swinging and chaining it just for 15 minutes of swing was not financially logical.

  

Therefore, I decided to create one control box that allows swings to be attached and detached anytime we want which also uses only one power input (Attaching all swings to power supply individually was not a smart solution too).
  

### Board Connection
![Circuit Diagram](https://imgshare.io/images/2019/11/04/devre.png)

The schema shows how I connected the parts all together. We could have used arduino's 5v out to power Servo, but board will not be able to supply enough power to swing a  baby who is around 5-6 kg. Therefore, I used and external power supply which  can supply 10 watts with 2  12V DC outputs. Having 2 seperate outpus were important in this project since I used one output to directly power Arduino UNO ( The board works between 7~12V)

I used LM2596 Regulator to convert 12V to 6V since this was the max the MG996R Servo can handle.  LM2596 is a great board that you can set the output voltage by turning the screw above. You can find more information on [https://www.youtube.com/watch?v=tcvcq7X1YmY](https://www.youtube.com/watch?v=tcvcq7X1YmY)

I attached the servo on PIN 9 and IR receiver module on PIN 11


### Code

The Swinger.h module is to control the Servo 

|Method| Action  |
|--|--|
| Attach(int ppin) |  Attaches the output pin |
| Detach() |  Detach the output pin |
| setInterval(int val, int delayForNewRound) |  Sets the speed of the servo and delay time for the new loop |
| increaseInterval() |  Increases the speed of the servo |
| decreaseInterval() |  Decreases the speed of the servo |
| Update() |  Updates the servo Position |

The **main.ino** is the program that reads the Infrared Signals and change the Servo parameters accordingly. You can find more information on ([http://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/](http://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/))


### Connectors

We had three babies and I wanted to be able to control each swinger individually. That's why I used three separated circuits and fit them all in one box. I decided to use RJ45 Connector since the servo and IR receiver needs 6 cables in total and CAT5 has 8 which is more than enough. I also choose this connector since it is very easy to plug-in and out.

You can see some of the images of the connectors 

![arduino1.jpg](https://imgshare.io/images/2019/11/04/arduino1.jpg)

![top.jpg](https://imgshare.io/images/2019/11/04/top.jpg)
![front.jpg](https://imgshare.io/images/2019/11/04/front.jpg)


You can see the final version of the product here.

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/wsQ2aYfTehE/0.jpg)](https://www.youtube.com/watch?v=wsQ2aYfTehE)`


[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/FAx2ovjSzK4/0.jpg)](https://www.youtube.com/watch?v=FAx2ovjSzK4)`

