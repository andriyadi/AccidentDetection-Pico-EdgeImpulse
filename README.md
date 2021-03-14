# CarAccidentDetection-EdgeImpulse-Pico
Car state detection (idle, normal, accident), powered by TinyML and [Edge Impulse](https://edgeimpulse.com/). It's developed for Raspberry Pi RP2040/Pico board.
 
This demo projects were used during online webinar entitled "Pi Day: The Taste of Raspberry Pi Pico" to celebrate Pi Day, March 14, 2021. Webinar recording is on this [Youtube link](https://youtu.be/q7cf1reGiGM?t=7427), which you should watch it as I explained about this project. Sorry, in Bahasa Indonesia.

[![Youtube thumnail](http://i3.ytimg.com/vi/q7cf1reGiGM/hqdefault.jpg)](https://www.youtube.com/watch?v=q7cf1reGiGM)

## Edge Impulse
Public project: https://studio.edgeimpulse.com/public/21576/latest

The Edge Impulse project consists of dataset and Impulse design. Dataset contains acceleration data from IMU sensor with 3 labels: idle, run, incident, and are collected using a setup explained below. Dataset may only be working for that specific setup. But you should get the idea.

## Data Acquisition Setup
Acceleration data are retrieved from MPU6050 sensor, mounted in such as way as this photo.
![Car setup](https://github.com/andriyadi/AccidentDetection-Pico-EdgeImpulse/raw/main/assets/car_setup.jpg)

Obviously, to simplify data acquisition, I use a toy car. Yes, I'm a big fan of BMW cars and own one, and have some BMW car models in my collection.

As photo, I use two Pico boards, one is the target board, another as PicoBoard for flashing firmware, logging serial output, and debugging. You can use just 1 Pico board, though.

## Projects
There are two VSCode projects in this repository.
### [01_ei_carstate_acquisition](https://github.com/andriyadi/AccidentDetection-Pico-EdgeImpulse/tree/main/01_ei_carstate_acquisition) 
It's the firmware to acquire acceleration data, using the setup above. It essentially outputs the acceleration data (in axis X, Y, and Z) to serial port, formatted as tab-delimited data, as understood by [Edge Impulse data forwarder](https://docs.edgeimpulse.com/docs/cli-data-forwarder). Edge Impulse data forwarder will then forward that data to Edge Impulse Studio.

### [02_ei_carstate_recog](https://github.com/andriyadi/AccidentDetection-Pico-EdgeImpulse/tree/main/02_ei_carstate_recog) 
The firmware that actually does the inference/recognition of car state based on accelerometer data. This project already integrates C++ library and model data exported from Edge Impulse Studio.

Again, please watch Webinar recording [video](https://youtu.be/q7cf1reGiGM?t=7427) above which I demoed how to use those 2 projects, and work with Edge Impulse Studio. If you're impatient, jump to [this timemark](https://youtu.be/q7cf1reGiGM?t=9737) when I start to discuss and work with Edge Impulse and the projects.

## Credits
This project is heavily inspired and adopt some code from these:
* [example-standalone-inferencing-pico](https://github.com/AIWintermuteAI/example-standalone-inferencing-pico) by [@AIWintermuteAI](https://github.com/AIWintermuteAI)
* [Pico-Motion-Recognition](https://github.com/Mjrovai/Pico-Motion-Recognition) by [@Mjrovai](https://github.com/Mjrovai/)
