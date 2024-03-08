#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap;
    bool isCameraFound = false;

    // Try to open webcams from index 0 to 10
    for (int index = 0; index <= 10; ++index) {
        cap.open(index);
        if(cap.isOpened()) {
            std::cout << "Camera found at index " << index << std::endl;
            isCameraFound = true;
            break; // Exit the loop if a working camera is found
        }
    }

    if (!isCameraFound) {
        std::cout << "Could not open any camera" << std::endl;
        return -1;
    }

    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE); // Create a window for display.
    while (true) {
        cv::Mat frame;
        cap >> frame; // Get a new frame from camera
        if (frame.empty()) break; // Check if we succeeded

        cv::imshow("Webcam", frame); // Show our frame in "Webcam" window

        if (cv::waitKey(30) >= 0) break; // Wait for a keystroke in the window or 30ms timeout
    }
    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    cv::destroyAllWindows();

    return 0;
}
