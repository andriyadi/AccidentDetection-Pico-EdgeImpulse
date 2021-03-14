# CarAccidentDetection-EdgeImpulse-Pico
Car state detection (idle, normal, accident), powered by TinyML and [Edge Impulse](https://edgeimpulse.com/). It's developed for Raspberry Pi RP2040/Pico board.
 
This demo projects were used during online webinar entitled "Pi Day: The Taste of Raspberry Pi Pico" to celebrate Pi Day, March 14, 2021. Webinar recording is on this [Youtube link](https://www.youtube.com/watch?v=q7cf1reGiGM), which you should watch it as I explained about this project. Sorry, in Bahasa Indonesia.

[![Youtube thumnail](http://i3.ytimg.com/vi/q7cf1reGiGM/hqdefault.jpg)](https://www.youtube.com/watch?v=q7cf1reGiGM)

## Edge Impulse
Public project: https://studio.edgeimpulse.com/public/21576/latest

The Edge Impulse project consists of dataset and Impulse design. Dataset contains acceleration data from IMU sensor with 3 labels: idle, run, incident, and are collected using a setup explained below. Dataset may only be working for that specific setup. But you should get the idea.

## Credits
This project is heavily inspired and adopt some code from these:
* [example-standalone-inferencing-pico](https://github.com/AIWintermuteAI/example-standalone-inferencing-pico) by [@AIWintermuteAI](https://github.com/AIWintermuteAI)
* [Pico-Motion-Recognition](https://github.com/Mjrovai/Pico-Motion-Recognition) by [@Mjrovai](https://github.com/Mjrovai/)
