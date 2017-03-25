#ifndef _CAMRECORDER_RECORDER_H
#define _CAMRECORDER_RECORDER_H

#include <opencv2\opencv.hpp>

#include <string>

class Recorder {
public:
	Recorder();
	~Recorder();

	void writeFrame(const cv::Mat& image);
private:
	bool saveImages;
	bool saveVideo;
	int frameCount;
	std::string root;
	std::string videoname;
	cv::VideoWriter writer;
};

#endif
