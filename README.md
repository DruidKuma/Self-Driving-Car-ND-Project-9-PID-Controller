# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Overview

In this project I have implemented PID controller for calculating steering angle of the vehicle to keep it on the drivable portion of the track.

![](/result_img/result.png "Result")

## Reflection

Basically, in my results I have mostly used "P" and "D" gains in order to keep the vehicle on track. Very small number for "I" gain was added in the final version. Further tuning (or using algorithms like twiddle might give better results and maybe use also the "I" gain intensively).

So, "P" stands for "Proportional" and tells the car to move in proportion to the CTE (cross track error). To tell in easy words, it will try to move to the center by measuring how close is it to the right ledge (and move to the left), and vice versa. I have used this gain, but in my result it is pretty small (I think, large values would cause frequent and wide swinging across the road).

The "I" gain stands for "Integral" and basically tells the car to move in proportion to the sum of all CTE over time. I have not used this gain in the previous to final result, but then was really surprized that very very low  number gave me better results on sharp turns (described reason below)

The "D" gain stands for "Derivative" and it specifies the change in cross track error as the car moves in time. We are considering only current and previous timesteps instead of all as the change in time here is constant (1 second). This actually gives us smooth steering to center (and lighten the swing effect of the "P" gain) as the change in CTE become smaller with every change. In my results I used this gain mainly, as it has given me the best results on higher speeds.

I have used manual tuning. At the start I have assigned random values within range [0.5, 1] to the coefficients and played with them to understand what effect gives each of them. Then I started to slightly tune the gains to get acceptable result on low speed (I have set the trottle to 0.2 for the start). After I came up with pretty good performance, I started increasing the throttle by 0.1 and re-tune parameters. Usually, on higher speed I faced with a swinging effect, and reduced "P" coefficient while increasing "D" coefficient. Also at every change I've also reduced little by little the "I" coeeficient, though it was actually pretty small even at the start.
Lastly, I came up with P=0.15, I=0.0015, D=3.5 and throttle=0.5. At this speed these gains gave me pretty good results. Increasing speed even more (up to 0.6) would have passed the rubric, as it was staying within the drivable portion, but it swinged too much across the road, and I considered it much more unsafe. As for the "I" gain, on final stage when I was trying to add even small values (relative to others) to it, the car immediately begin losing the road and go over the ledges. Finally, I decided to cut the number until it would either give better results, or has no effect at all, and actually I managed to get it work!

Final solution allows the car to accelerate up to 57mph with keeping on the driveable portion of the track!

Points for improvements:

* Use twiddle algorithm or something similar to tune coefficients automatically
* Implement a PID for the throttle (or at least add some control to it to be able to slightly increase/decrease the speed of the vehicle depending on the steering angle - drive faster on straight road and slower on the sharp turns) 



## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

