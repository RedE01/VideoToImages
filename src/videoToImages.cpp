#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
	if(argc < 4) {
		std::cout << "Error: Not enough arguments provided" << std::endl;
		std::cout << "usage: ./videoToImages (string)filepath (string)outputFileName (int)numberOfImages" << std::endl;
		return -1;
	}

    int numberOfImages = std::stoi(argv[3]);
    if(numberOfImages < 1) {
        std::cout << "Error: Number of images must be more than one" << std::endl;
        return -1;
    }

	cv::VideoCapture video(argv[1]);

	if(!video.isOpened()) {
		std::cout << "Error: Could not load video " << argv[1] << std::endl;
        video.release();
		return -1;
	}

    cv::Mat frame;

    int frames = int(video.get(cv::CAP_PROP_FRAME_COUNT));
    int loops = frames / numberOfImages - 1;

    bool loop = true;
    int loopIndex = 0;
    while(loop) {
        video.read(frame);

        std::stringstream ss;
        ss << argv[2] << loopIndex++ << ".jpg";
        cv::imwrite(ss.str(), frame);

        for(int i = 0; i < loops; ++i) {
            video.read(frame);

            if(frame.empty()) {
                std::cout << "Done" << std::endl;
                loop = false;
                break;
            }
        }
    }

    video.release();

	return 0;
}
