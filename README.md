This is a car race game implemented in C++ from scratch.

The project is a completed in collaboration with Cem Özbay and Ekin Yılmaz. Feel free to contact me (erkayaguven@gmail.com) for anything related to the code. 

##### Map Design 

Three different racetracks are implemented. Three different images are added to the scene as background images and different objects such as wetlands, trees, audience etc. are integrated via the addItem() method.

Every racetrack is divided into rectangles of different sizes and they are stored in a road array to define the borders.
The car goes slowly if it is not on the racetrack which is tested by the insideRoad function


##### Collision

The insideMap function checks if the car is within the game window and if it is not, then it gets back to the start point.

Different collision points are hardcoded and stored in the decorArray.
When the car is in the same position with an object, then it's a collision and the car gets back to the start point.


