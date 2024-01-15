# Polargraph Library Arduino

***

**Authors:**

   * Duque Bran, Andrés Felipe 

   * Jasselauire, Adrien

   * Chabassier, Titouan
   
***

### Description

This repository contains a library with a class that allows to control a pointer through the [Arduino Software (IDE)](https://www.arduino.cc/en/software), and emplyoing a setup that consists of two unipolar stepper motors and a servo motor for determining the distance between the drawing artefact and the canvas. However, the description of this setup is not a matter of importance for this code.

***

### Installation

In order to properly install this library, it is compulsory to clone this repository in the ```libraries``` folder located inside the Arduino directory that is automatically created after the instalation of the **Arduino IDE**. This can be posibly done by two different methods:

  1. Execute the following command in your terminal after being inside the directory ```*/Arduino/libraries```:

      1. With HTTPS:
  
         ```
          git clone https://github.com/afduquebr/Polargraph.git
         ```

      2. With SSH:

         ```
          git clone git@github.com:afduquebr/Polargraph.git
         ```

  2. Download the ZIP folder and directly locate it inside the directory ```*/Arduino/libraries``` after decompression.

***

### Execution

One of the perks of a polargraph is its adaptavility to canvas with different sizes. Based on this, the length and with of the canvas have to be manually set in the file ```Polargraph.h```. Similarly, due to the differences that may arise on the specifications of the mechanical design, the number of steps per revolution from the stepper motors employed and the radius of the strings or belts employed with respect to the axis of the tree from each motor must be specified in the same file before execution ```Polargraph.h```. 

Additionally, a simulator is provided to monitore the expected position that the pointer should follow through the canvas, it is located inside the ```Simulator``` directory. This file is developped in C++ as it is intented to be employed without the need of an Arduino platform. Examples are also provided for proper illustration.

***

*This work was developped as a project for the lecture* **_Experimental Project_** *given in the programme of Master 2 Fundamental Physics and Applications in the path of Universe and Particles at the* **_Université Clermont Auvergne._** * Its development was performed under the guidance of the professor Calvet, David.*
