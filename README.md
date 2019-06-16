# VideoToImages

Small program using opencv that opens a video file and outputs a bunch of images from the video.

I wrote this program to generate some images for my ImageMosaic project.

## Compiling with g++
```g++ src/videoToImages.cpp -o ./bin/videoToImages -I/usr/include/opencv4 -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio```
